#include <iostream>
#include <string.h>
#include <string>
#include <vector>

#define MAX_LENGTH 100

using namespace std;

int searchVector(vector<char **> *document, vector<char *> *words, string word,
                 char **newWord) {
  // char **myWord;
  int lastWordIndex;
  int lastVectIndex;
  for (vector<char **>::size_type j = 0; j < document->size(); j++) {
    if (!(*document)[j]) {
      lastVectIndex = j;
      break;
    }
  }
  for (vector<char *>::size_type i = 0; i < words->size(); i++) {
    if ((*words)[i] && word == (*words)[i]) {
      // myWord = &(*words)[i];
      (*document)[lastVectIndex] = &(*words)[i];
      // document->push_back(&(*words)[i]);
      return i;
    } else if (!(*words)[i]) {
      lastWordIndex = i;
      break;
    }
  }

  strcpy(*newWord, word.c_str());
  (*words)[lastWordIndex] = (*newWord);
  (*document)[lastVectIndex] = &(*words)[lastWordIndex];
  /*words->push_back(*newWord);
  document->push_back(&(*words)[words->size() - 1]);*/
  return lastWordIndex;
}

int main() {
  vector<char *> words(MAX_LENGTH);
  vector<char **> document(MAX_LENGTH);

  cout << "Type contents of document, ending with \"quit\" followed by enter "
          "to stop reading the document"
       << endl
       << endl;

  string word = " ";
  char *temp;
  do {
    cin >> word;
    temp = new char[word.length() + 1];
    searchVector(&document, &words, word, &temp);
  } while (word != "quit");
  document.pop_back();

  cout << "\n\nOriginal contents of document: " << endl;
  for (vector<char **>::size_type i = 0; i < document.size(); i++) {
    if (!document[i])
      break;
    cout << *(document[i]) << " ";
  }
  cout << "\n\nUnique words in document: " << endl;
  for (vector<char *>::size_type i = 0; i < words.size(); i++) {
    if (!words[i])
      break;
    cout << (words[i]) << " ";
  }

  cout << "\n\nIllustrating that the pointer works by changing the value of "
          "words[0] to something else: "
       << endl;

  words[0] = (char *)"something else";
  for (vector<char **>::size_type i = 0; i < document.size(); i++) {
    if (!document[i])
      break;
    cout << *(document[i]) << " ";
  }
  return 0;
}