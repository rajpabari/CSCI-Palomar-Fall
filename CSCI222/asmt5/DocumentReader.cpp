#include <iostream>
#include <string.h>
#include <string>
#include <vector>

#define MAX_LENGTH 100

using namespace std;

int searchVector(vector<char *> *words, char **word) {
  for (int i = 0; i < words->size(); i++) {
    if (strcmp(*word, (*words)[i]) == 0) {
      words->push_back((*words)[i]);
      return i;
    }
  }
  words->push_back(*word);
  return words->size() - 1;
}

int main() {
  vector<char *> words;

  char *word = new char[MAX_LENGTH];
  int x;
  do {
    word = new char[MAX_LENGTH];
    cin >> word;
    searchVector(&words, &word);
  } while (strcmp(word, "quit") != 0);
  words.pop_back();

  for (int i = 0; i < words.size(); i++) {
    cout << &words[i] << " ";
  }
  return 0;
}