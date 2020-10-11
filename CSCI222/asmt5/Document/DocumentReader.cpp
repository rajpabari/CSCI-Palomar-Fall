#include <iostream>
#include <string.h>
#include <string>
#include <vector>

#define MAX_NUM_WORDS 100 // the maximum number of words in the "document"

using namespace std;

// Searches the vector words for a word
// if it's in uniqueWords, add a pointer to that word to the document
// otherwise, put the word in uniqueWords and add pointer to document
// @param vector<char **> *document the document to modify
// @param vector<char *> *uniqueWords the vector of unique words in the document
// @param string currentWord the word to add to the document
// @param char **newWord memory to store word if a new word needs to be made
// @return index of uniqueWords where c string of currentWord is
int addWordToDocument(vector<char **> *document, vector<char *> *uniqueWords,
                      string currentWord, char **newWord) {
  // init index variables
  int lastWordIndex;
  int lastDocIndex;

  // determine the last non-null index in the document
  for (vector<char **>::size_type j = 0; j < document->size(); j++) {
    // if its null
    if (!(*document)[j]) {
      // thats where we should put the pointer to the word
      lastDocIndex = j;
      break;
    }
  }

  // check if word is already in unique words
  for (vector<char *>::size_type i = 0; i < uniqueWords->size(); i++) {
    // if it's non-null and it's equal to the word we're tryna add to the
    // document
    if ((*uniqueWords)[i] && currentWord == (*uniqueWords)[i]) {
      // then we should add a pointer to the word in uniqueWords to the document
      (*document)[lastDocIndex] = &(*uniqueWords)[i];
      // return so we don't evaluate anything else
      return i;
    }
    // if it's null, it's not in unique words
    else if (!(*uniqueWords)[i]) {
      // we're going to add a word to this null space, so set lastWordIndex
      lastWordIndex = i;
      // dont check any more
      break;
    }
  }

  // if we made it here, this is a word that hasn't been in the document before
  // copy the char* of the word to the memory location allocated by newWord
  strcpy(*newWord, currentWord.c_str());

  // add this word to the first null index in uniqueWords
  (*uniqueWords)[lastWordIndex] = (*newWord);
  // add a pointer to the newly created word to the document
  (*document)[lastDocIndex] = &(*uniqueWords)[lastWordIndex];

  // the index of uniqueWords where our word is is lastWordIndex, so return it
  return lastWordIndex;
}

int main() {
  vector<char *> uniqueWords(MAX_NUM_WORDS); // stores unique words
  vector<char **> document(MAX_NUM_WORDS);   // stores pointers to unique words

  // prompt user to input document contents
  cout << "Type contents of document, ending with \"quit\" followed by enter "
          "to stop reading the document"
       << endl
       << endl;

  string word = " ";
  char *temp;

  // handle input
  do {
    // get word from cin
    cin >> word;

    // allocate memory for a c string of the word
    temp = new char[word.length() + 1];
    // call the method to add the word to the document
    addWordToDocument(&document, &uniqueWords, word, &temp);
  } while (word != "quit"); // do it until user types in quit

  // print contents of document vector back out to user
  cout << "\n\nOriginal contents of document: " << endl;
  for (vector<char **>::size_type i = 0; i < document.size(); i++) {
    // make sure it's non-null
    if (!document[i])
      break;
    cout << *(document[i]) << " ";
  }

  // print unique words back out to user
  cout << "\n\nUnique words in document: " << endl;
  for (vector<char *>::size_type i = 0; i < uniqueWords.size(); i++) {
    if (!uniqueWords[i])
      break;
    cout << (uniqueWords[i]) << " ";
  }

  cout << "\n\nIllustrating that the pointer works by changing the value of "
          "uniqueWords[0] to something else: "
       << endl;

  // change the first word that it's pointing to to something else
  // this will modify all of the pointers to this word in the document
  uniqueWords[0] = (char *)"something else";
  for (vector<char **>::size_type i = 0; i < document.size(); i++) {
    if (!document[i])
      break;
    cout << *(document[i]) << " ";
  }
  cout << "\n";
  return 0;
}