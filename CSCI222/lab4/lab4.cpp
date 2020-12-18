//#include "torch/torch.h"
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

// the number of "most frequent" words you keep in the vector
#define NUM_WORDS_MOST_FREQUENT 1000

/*
For increased prediction accuracy, I changed these things:
1) the options when using svm-train in commandline (i changed svm_type and
kernel_type)
2) number of "most frequent" words you keep (decreased from 3000 to 1000)

tinkering with those, I got accuracy from 51% to 69%

this is command line args for 69% accuracy (as in screenshot) from SVM_code
folder
./svm-train -s 0 -t 0 ../train-data.txt
./svm-predict ../test-data.txt ./train-data.txt.model ../predictions.txt
*/

// NOTE I used Ling-spam corpus training/test data found at this
// link: https://www.dropbox.com/s/yjiplngoa430rid/ling-spam.zip because the
// enron linked in the prompt did not actually have stop words removed or
// lemmatization done to it.

using namespace std;

// gets the contents of the file located at filePath
//@param string filePath the path to the file
//@return the contents of the file in a string vector
vector<string> getFileContents(string filePath) {
  vector<string> data; // raw input data from file
  ifstream infile;
  infile.open(filePath); // open the filename supplied
  string line;

  // while there are lines to read in the file
  while (getline(infile, line)) {
    // push those lines to the end of the vector
    data.push_back(line);
  }
  infile.close();
  // return our vector
  return data;
}

// Comparator function to sort pairs
// according to second value
// used later when determining which words are most frequent
// @param a first pair to compare
// @param b second pair to compare
// @return true if the value of a is less than value of b, false otherwise
bool cmp(pair<string, int> a, pair<string, int> b) {
  return a.second < b.second;
}

// create the map of most frequent words and return it
// @param fileNames list of all file names in directory
// @param pathToEMails path to the directory with train/test map
// @return map of most frequent words of size NUM_WORDS_MOST_FREQUENT
map<string, int> makeMap(const vector<string> fileNames,
                         const string pathToEMails) {
  // initialize variables so c++ doesn't get mad
  unordered_map<string, int> allWords;
  vector<string> currentFile;
  string currentWord;
  unordered_map<string, int>::iterator search;

  // for each file
  for (size_t i = 0; i < fileNames.size(); i++) {
    // get and store the contents of that file
    currentFile = getFileContents(pathToEMails + fileNames[i]);

    // for each line of the file
    for (size_t j = 0; j < currentFile.size(); j++) {
      // if it's the second line, that's where the body of email is
      if (j == 2) {
        // read each word of the file using an input string stream
        istringstream iss(currentFile[j], istringstream::in);
        // while there's a word to read on this line
        while (iss >> currentWord) {
          // check if it's in the map already
          search = allWords.find(currentWord);
          // if it is in the map...
          if (search != allWords.end()) {
            // increase the count of that value in the map
            allWords[currentWord]++;
          } else {
            // make a new key with value 1 because it's the first instance of
            // the word
            allWords[currentWord] = 1;
          }
        }
      }
    }
  }
  unordered_map<string, int> cleanedWords; // get rid of punctuation and stuff
  bool wordIsAlpha = true;
  for (auto i : allWords) {
    wordIsAlpha = true; // assume it's got only alphabet characters
    if (i.first.size() == 1) {
      // if it's of size 1, we don't want it according to prompt, so continue
      continue;
    }
    for (int j = 0; j < i.first.size(); j++) {
      // check if each character is a letter
      if (!isalpha(i.first.at(j))) {
        // if one of the characters is not a letter, we don't want it
        wordIsAlpha = false;
        break;
      }
    }
    // if all characters of the word are letters, add it to clean list
    if (wordIsAlpha) {
      cleanedWords[i.first] = i.second;
    }
  }
  map<string, int> mostFrequentWords;
  vector<pair<string, int> > pairs;
  // Copy key-value pair from Map to vector of pairs
  for (auto it : cleanedWords) {
    pairs.push_back(it);
  }

  // Sort using comparator function defined above
  sort(pairs.begin(), pairs.end(), cmp);

  // start from the back of the vector and add the NUM_WORDS_MOST_FREQUENT
  // number of most frequent words to our final map
  for (int i = pairs.size() - 1; i >= pairs.size() - NUM_WORDS_MOST_FREQUENT;
       i--) {
    mostFrequentWords[pairs[i].first] = pairs[i].second;
  }

  // finally we can return the map
  return mostFrequentWords;
}

// extract the features of each file given the word frequency map
// @param fileNames list of all file names in directory
// @param pathToEMails path to the directory with train/test map
// @param frequencyMap of most frequent words of size NUM_WORDS_MOST_FREQUENT
// @return 2D vector with word counts of words in frequencyMap
vector<vector<int> > extractFeatures(const vector<string> fileNames,
                                     const string pathToEMails,
                                     map<string, int> frequencyMap) {
  // initialize variables
  vector<string> currentFile;
  string currentWord;
  int wordID = 0;
  // this constructs a fileNames.size() x frequencyMap.size() vector
  // and initializes all values to 0
  vector<vector<int> > features(fileNames.size(),
                                vector<int>(frequencyMap.size(), 0));

  // for each email in the directory
  for (int docID = 0; docID < fileNames.size(); docID++) {
    // save contents of current file
    currentFile = getFileContents(pathToEMails + fileNames[docID]);
    // for each line of file
    for (size_t j = 0; j < currentFile.size(); j++) {
      // this is the body
      if (j == 2) {
        // read each word
        istringstream iss(currentFile[j], istringstream::in);
        // while there are words left to read
        while (iss >> currentWord) {
          // reset wordID to 0
          wordID = 0;

          for (auto x : frequencyMap) {
            // if the word is in our most frequent map
            if (x.first == currentWord) {
              // set the wordID to be the unique pseudo-index of the pair in the
              // map
              wordID =
                  distance(frequencyMap.begin(), frequencyMap.find(x.first));
              // increment the corresponding value in the 2D features matrix
              features[docID][wordID]++;
              // don't need to check any more words in the map
              break;
            }
          }
        }
      }
    }
  }

  // return the finalised features matrix
  return features;
}

// formats the data according to SVM_code specifications
// and outputs it to a separate txt file
// @param labels labels matrix to classify which are spam and non spam
// @param features the word counts of each file
// @param type (train or test)
// @param pathToEMails path to the directory with train/test map
void formatAndOutputData(vector<int> labels, vector<vector<int> > features,
                         string type, string pathToEMails) {
  // create output stream
  ofstream outFile(pathToEMails + "../" + type + "-data.txt");
  // for each file
  for (int i = 0; i < features.size(); i++) {
    // label output has to be +1 and -1, so if it's 1 start with a +
    // if it's -1 the - gets outputted automatically
    if (labels[i] > 0) {
      outFile << "+";
    }
    // output the label first for formatting
    outFile << labels[i] << " ";
    // for every feature
    for (int j = 0; j < features[i].size(); j++) {
      // output the index, a colon, then the feature
      outFile << (j + 1) << ":" << features[i][j];
      // output a space if it's not the last one on the line
      if (j != features[i].size() - 1) {
        outFile << " ";
      }
      // output a newline otherwise, unless it's the last feature in the set
      else if (i != features.size() - 1) {
        outFile << "\n";
      }
    }
  }
  // close the file
  outFile.close();
}

// Display usage information to cout
void usage() {
  cout << "Input path to ling-spam directory in command line" << endl;
  cout << "Example: g++ lab4.cpp ./CSCI222/lab4/ling-spam" << endl;
  cout << "note: must have these sub-directories in ling-spam: "
          "\n/train-mails with trainFileNames.txt in it\nand /test-mails with "
          "testFileNames.txt in it."
       << endl;
}

int main(int argc, const char *argv[]) {
  // if there isn't 1 argument (argv[0] is filename)
  if (argc != 2) {
    usage();  // display usage info
    return 0; // exit program
  }
  // get path to train and test mails based on CLI arg
  string pathToTrainMails = argv[1];
  pathToTrainMails += "/train-mails/";
  string pathToTestMails = argv[1];
  pathToTestMails += "/test-mails/";

  // access the train and test file names where they are supposed to be
  vector<string> trainFileNames =
      getFileContents(pathToTrainMails + "trainFileNames.txt");
  vector<string> testFileNames =
      getFileContents(pathToTestMails + "testFileNames.txt");

  // get the map of most frequent words
  map<string, int> trainWords = makeMap(trainFileNames, pathToTrainMails);
  // create feature 2D vector out of that
  vector<vector<int> > trainFeatures =
      extractFeatures(trainFileNames, pathToTrainMails, trainWords);
  // make labels for each file, first half aren't  spam, next half are
  vector<int> trainLabels(trainFileNames.size(), -1);
  for (int i = trainLabels.size() / 2; i < trainLabels.size(); i++) {
    trainLabels[i] = 1;
  }
  // output to separate file
  formatAndOutputData(trainLabels, trainFeatures, "train", argv[1]);

  // same as training, not recommenting
  map<string, int> testWords = makeMap(testFileNames, pathToTestMails);
  vector<vector<int> > testFeatures =
      extractFeatures(testFileNames, pathToTestMails, testWords);
  vector<int> testLabels(testFileNames.size(), -1);
  for (int i = testLabels.size() / 2; i < testLabels.size(); i++) {
    testLabels[i] = 1;
  }
  formatAndOutputData(testLabels, testFeatures, "test", argv[1]);
  return 0;
}
