//#include "torch/torch.h"
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

// ./svm-train ../train-data.txt
// ./svm-predict ../test-data.txt ./train-data.txt.model ../predictions.txt

/*
First time:
cd ./CSCI222/lab4/build
To run each time, paste these commands:
cmake -DCMAKE_PREFIX_PATH=$PWD/../../libtorch ..
cmake --build . --config Debug
./lab4

*/

// NOTE Professor, I used Ling-spam corpus training/test data found at this
// link: https://www.dropbox.com/s/yjiplngoa430rid/ling-spam.zip because the
// enron linked in the prompt did not have stop words removed or lemmatization
// done to it.

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
bool cmp(pair<string, int> a, pair<string, int> b) {
  return a.second < b.second;
}

map<string, int> makeMap(const vector<string> trainFileNames,
                         const string pathToTrainMails) {
  unordered_map<string, int> allWords;
  vector<string> currentFile;
  string currentWord;
  unordered_map<string, int>::iterator search;
  for (size_t i = 0; i < trainFileNames.size(); i++) {
    currentFile = getFileContents(pathToTrainMails + trainFileNames[i]);
    for (size_t j = 0; j < currentFile.size(); j++) {
      if (j == 2) {
        istringstream iss(currentFile[j], istringstream::in);
        while (iss >> currentWord) {
          search = allWords.find(currentWord);
          if (search != allWords.end()) {
            allWords[currentWord]++;
          } else {
            allWords[currentWord] = 1;
          }
        }
      }
    }
  }
  unordered_map<string, int> cleanedWords;
  // int leastFreq = INT_MAX;
  bool wordIsAlpha = true;
  for (auto i : allWords) {
    wordIsAlpha = true;
    if (i.first.size() == 1) {
      continue;
    }
    for (int j = 0; j < i.first.size(); j++) {
      if (!isalpha(i.first.at(j))) {
        wordIsAlpha = false;
        break;
      }
    }
    if (wordIsAlpha) {
      cleanedWords[i.first] = i.second;
    }
  }
  map<string, int> top3kWords;
  // Declare vector of pairs
  vector<pair<string, int> > pairs;
  // Copy key-value pair from Map
  // to vector of pairs
  for (auto it : cleanedWords) {
    pairs.push_back(it);
  }

  // Sort using comparator function
  sort(pairs.begin(), pairs.end(), cmp);

  // Print the sorted value
  for (int i = pairs.size() - 1; i >= pairs.size() - 3000; i--) {
    top3kWords[pairs[i].first] = pairs[i].second;
  }

  return top3kWords;
}

vector<vector<int> > extractFeatures(const vector<string> trainFileNames,
                                     const string pathToTrainMails,
                                     map<string, int> frequencyMap) {
  vector<string> currentFile;
  string currentWord;
  int wordID = 0;
  vector<vector<int> > features(trainFileNames.size(), vector<int>(3000, 0));
  for (int docID = 0; docID < trainFileNames.size(); docID++) {
    currentFile = getFileContents(pathToTrainMails + trainFileNames[docID]);
    for (size_t j = 0; j < currentFile.size(); j++) {
      if (j == 2) {
        istringstream iss(currentFile[j], istringstream::in);
        while (iss >> currentWord) {
          wordID = 0;
          for (auto x : frequencyMap) {
            if (x.first == currentWord) {
              wordID =
                  distance(frequencyMap.begin(), frequencyMap.find(x.first));
              features[docID][wordID]++;
              break;
            }
          }
        }
      }
    }
  }
  return features;
}

void outputAndFormatData(vector<int> labels, vector<vector<int> > features,
                         string type) {
  ofstream outFile;
  outFile.open("./CSCI222/lab4/" + type + "-data.txt");
  for (int i = 0; i < features.size(); i++) {
    if (labels[i] > 0) {
      outFile << "+";
    }
    outFile << labels[i] << " ";
    for (int j = 0; j < features[i].size(); j++) {
      outFile << j << ":" << features[i][j];
      if (j != features[i].size() - 1) {
        outFile << " ";
      } else if (i != features.size() - 1) {
        outFile << "\n";
      }
    }
  }
  outFile.close();
}

int main(int argc, char const *argv[]) {
  string pathToTrainMails = "./CSCI222/lab4/ling-spam/train-mails/";
  string pathToTestMails = "./CSCI222/lab4/ling-spam/test-mails/";
  vector<string> trainFileNames =
      getFileContents(pathToTrainMails + "trainFileNames.txt");
  vector<string> testFileNames =
      getFileContents(pathToTestMails + "testFileNames.txt");

  map<string, int> trainWords = makeMap(trainFileNames, pathToTrainMails);
  vector<vector<int> > trainFeatures =
      extractFeatures(trainFileNames, pathToTrainMails, trainWords);
  vector<int> trainLabels(trainFileNames.size(), -1);
  for (int i = trainLabels.size() / 2; i < trainLabels.size(); i++) {
    trainLabels[i] = 1;
  }
  outputAndFormatData(trainLabels, trainFeatures, "train");
  /* verify that the features matrix is working
  int ans = 0;
  for (int i = 0; i < trainFeatures.size(); i++) {
    ans += trainFeatures[i][705];
  }
  cout << ans << " " << trainWords["deat"] << endl;*/

  map<string, int> testWords = makeMap(testFileNames, pathToTestMails);
  vector<vector<int> > testFeatures =
      extractFeatures(testFileNames, pathToTestMails, testWords);
  vector<int> testLabels(testFileNames.size(), -1);
  for (int i = testLabels.size() / 2; i < testLabels.size(); i++) {
    testLabels[i] = 1;
  }
  outputAndFormatData(testLabels, testFeatures, "test");
  return 0;
}
