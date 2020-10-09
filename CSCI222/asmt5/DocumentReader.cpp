#include <iostream>
#include <string.h>
#include <string>
#include <vector>

#define MAX_LENGTH 100

using namespace std;

int searchVector(const vector<char *> *words, string word) {
  char **myWord;
  for (int i = 0; i < words->size(); i++) {
    if (word == (*words)[i]) {
      myWord = &(*words)[i];
      words->push_back(*myWord);
      return i;
    }
  }
  char *newWord = new char[word.length() + 1];
  strcpy(newWord, word.c_str());
  words->push_back(newWord);
  return words->size() - 1;
}

int main() {
  vector<char *> words;
  // vector<char **> document;
  /*int a = 10;
  int *p = &a;
  int *q = p;
  cout << *p << " " << *q << endl;
  a = 11;
  cout << *p << " " << *q << endl;*/

  char *temp;
  int x;
  string word;
  do {
    cin >> word;
    cout << searchVector(&words, word) << " ";
  } while (word != "quit");
  words.pop_back();

  for (int i = 0; i < words.size(); i++) {
    cout << words[i] << " " << *words[i] << " " << &words[i] << endl;
  }
  words[0] = (char *)"jkjk";
  cout << "\n\n";
  for (int i = 0; i < words.size(); i++) {
    cout << words[i] << " " << &words[i] << endl;
  }
  return 0;
}