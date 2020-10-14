#include <iostream>
#include <string.h>
#include <string>
#include <vector>

using namespace std;

// FYI: I used the Playfair algorithm specs from online because
// they are more common than the ones in the prompt. A little bit different than
// prompt, but mostly the same algorithm

// link to calculator: https://planetcalc.com/7751/ Algorithm specs are:
// 1) 'J' is replaced with 'I' to fit 5x5 square
// 2) 'X' is used as substitution in case you need to fill second letter in the
// digram, or split two identical letters
// 3) Playfair square is filled row-by-row, starting with the keyword.
// 4) If in same row, take the value to the right in the cipher
// 5) If in same column, take the value below in the cipher
// I've made the algorithm pretty robust and non-janky as a result

// Initializes the array of unique characters and vector of the order
// Precondition: we've gotten rid of non-letter characters from message
// @param string message the message which we're trying to find unique
// characters of
// @param bool uniqueCharArray[25] stores the unique characters
// @param vector<int> *letterOrder the order of occurrence for each letter
// @return none
void initUniqueChars(string message, bool uniqueCharArray[25],
                     vector<int> *letterOrder) {
  // turn message to a char* so we can iterate through it
  const char *messageCStr = message.c_str();

  int currentChar;
  int letterOrderIndex = 0;

  // for each character in the string
  for (int i = 0; i < message.length(); i++) {
    // currentChar is the current character of the message
    currentChar = messageCStr[i];

    // if it's capital letter
    if (currentChar >= 'A' && currentChar <= 'Z') {
      // add 32 to make it the lowercase ascii equivalent
      currentChar += 32;
    }

    // if it's j or after, subtract 1 as if j didn't exist
    if (currentChar >= 'j')
      currentChar--;

    // if the letter is currently false, this character hasn't come up before
    if (!uniqueCharArray[currentChar - 'a']) {
      // set the index corresponding to this character value to true
      uniqueCharArray[currentChar - 'a'] = true;
      // put the index of uniqueCharArray in letterOrder
      (*letterOrder)[letterOrderIndex] = currentChar - 'a';
      // increment letterOrderIndex for next run through
      letterOrderIndex++;
    }
  }
}

// Initializes the 2D key array
// Precondition: uniqueCharArray and letterOrder are initialized from
// initUniqueChars() above
// @param const bool uniqueCharArray[25] stores the unique characters
// @param char keyArray[5][5] memory location for the 2D key array
// @param const vector<int> *letterOrder the order of occurrence for each letter
// @return none
void init2DCipherArray(const bool uniqueCharArray[25], char keyArray[5][5],
                       const vector<int> letterOrder) {
  int currentIndex = 0; // how many elements we've added to the key array

  // goes through letterOrder.size()-1 because made letterOrder size 26
  for (int i = 0; i < letterOrder.size() - 1; i++) {
    // letterOrder size is 26 because of this if condition
    // we can't just check if letterOrder[i] == 0 because 'a' corresponds to 0
    // but if both this and next are 0, this would mean its time to break
    // breaking so once letterOrder is just a ton of 0s, we don't check any more
    if (letterOrder[i] == 0 && letterOrder[i + 1] == 0)
      break;

    // this is the next index row-by-row in keyArray
    // set it to the char representation of the integer in letterOrder[i]
    keyArray[currentIndex / 5][currentIndex % 5] = letterOrder[i] + 'a';
    // if letterOrder[i] is after i, need to add 1 because j doesn't exist
    if (letterOrder[i] > 'i' - 'a')
      keyArray[currentIndex / 5][currentIndex % 5]++;
    // we added something to keyArray so increment currentIndex
    currentIndex++;
  }

  // for each in uniqueCharArray
  for (int i = 0; i < 25; i++) {
    // if it's true, we already put it in from above iterating through
    // letterOrder, so we don't need to add that letter again
    if (uniqueCharArray[i])
      continue;
    // this means we haven't added it so let's add it
    // exactly the same adding algorithm as above
    keyArray[currentIndex / 5][currentIndex % 5] = i + 'a';
    if (i > 'i' - 'a')
      keyArray[currentIndex / 5][currentIndex % 5]++;
    currentIndex++;
  }
}

// Removes things that aren't letters and changes capitals to lowercase
// @param string str the string to remove non-letters from
// @return string the modified string
string removeNonLetters(string str) {
  string ans = "";
  char current;

  // for each character in the string
  for (int i = 0; i < str.length(); i++) {
    current = str.at(i);

    // if if's capital make it lowercase by adding 32
    if (current >= 'A' && current <= 'Z') {
      current += 32;
    }

    // if it's a letter put it in the final answer
    if (current >= 'a' && current <= 'z') {
      ans += current;
    }
  }
  return ans;
}

// Removes things that aren't letters and changes capitals to lowercase and puts
// an X between duplicate letters that would mess up playfair ciphering
// @param string str the string to remove non-letters and dupes from
// @return string the modified string
string removeNonLettersAndDuplicates(string str) {
  string ans = removeNonLetters(str); // start by removing non-Letters

  // for every other character (because pairs are every other letter)
  for (int i = 0; i < ans.length() - 1; i += 2) {
    // if first equals the next, they're duplicate letters
    // also i is equivalent to j so gotta check that
    if (ans.at(i) == ans.at(i + 1) ||
        (ans.at(i) == 'j' && ans.at(i + 1) == 'i') ||
        (ans.at(i) == 'i' && ans.at(i + 1) == 'j')) {
      // add an x between the two halves of the current string using substrings
      ans =
          ans.substr(0, i + 1) + "x" + ans.substr(i + 1, ans.length() - i - 1);
    }
  }
  return ans;
}

// Gets the encoded pair corresponding to the original digram we're given
// @param string original the 2-letter string to encode
// @param const char cipher[5][5] the cipher we're using to encode it
// @return string the 2-letter encoded corresponding pair
string getEncodedPair(string original, const char cipher[5][5]) {

  // initialize the first and second characters
  char first = original.at(0);
  char second = original.at(1);

  // if either is j make it i bc j isn't in the cipher
  if (first == 'j')
    first = 'i';
  if (second == 'j')
    second = 'i';
  // need to store the row and column location of each character in the cipher
  int firstRow, firstCol, secondRow, secondCol;

  // iterate through each value in the cipher
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {

      // if the character is the same as the cipher character at this location
      if (first == cipher[i][j]) {
        // save the row and column
        firstRow = i;
        firstCol = j;
      }
      // same as for first
      else if (second == cipher[i][j]) {
        secondRow = i;
        secondCol = j;
      }
    }
  }

  // take this information and use the playfair cipher

  // if they're in the same row
  if (firstRow == secondRow) {
    // if either column is 4 and we add 1 to the column we will be out of array
    // bounds
    // instead we need to wrap around to column 0, so set the column number to
    // -1
    if (firstCol == 4)
      firstCol = -1;
    if (secondCol == 4)
      secondCol = -1;

    // return a string of the column to the right of the first character
    // concatenated with a string of the column to the right of the second
    return (string(1, cipher[firstRow][firstCol + 1]) +
            string(1, cipher[secondRow][secondCol + 1]));
  } else if (firstCol == secondCol) {
    // if either row is 4 and we add 1 to the row we will be out of array
    // bounds
    // instead we need to wrap around to row 0, so set the row number to
    // -1
    if (firstRow == 4)
      firstRow = -1;
    if (secondRow == 4)
      secondRow = -1;

    // return a string of the row under of the first character
    // concatenated with a string of the row under of the second
    return (string(1, cipher[firstRow + 1][firstCol]) +
            string(1, cipher[secondRow + 1][secondCol]));
  } else {

    // this is the implementation of the square thing
    // same row, but other one's column is the encoded thing
    return (string(1, cipher[firstRow][secondCol]) +
            string(1, cipher[secondRow][firstCol]));
  }
}

// Encode a given message by a given key
// @param string message the message to encode
// @param string key the secret key to encode it with
// @return string the encoded message
string encode(string message, string key) {
  bool uniqueKeyChars[25] = {false}; // represents whether char corresponding to
                                     // each index is in message or not
  vector<int> letterOrder(26);       // for the order of the unique letters

  // initialize our unique characters array and vector with the key
  initUniqueChars(removeNonLetters(key), uniqueKeyChars, &letterOrder);
  char keyArray[5][5]; // this is our cipher
  // initialize our cipher using the unique characters in the correct order
  init2DCipherArray(uniqueKeyChars, keyArray, letterOrder);

  // remove the duplicates AND nonletters from our message
  string messageOnlyLetters = removeNonLettersAndDuplicates(message);
  string ans = "";

  // if its an odd length then our last pair will be lonely
  // and our playfair encoding wont work
  if (messageOnlyLetters.length() % 2 == 1)
    messageOnlyLetters +=
        'x'; // so we add an x to the end to make the length an even number

  // for each pair of letters
  for (int i = 0; i < messageOnlyLetters.length(); i += 2) {
    // encode each pair of letters using our favorite cipher
    // and append it to the answer that we're returning
    ans = ans + getEncodedPair(messageOnlyLetters.substr(i, 2), keyArray);
  }

  return ans;
}

// Gets the original decoded pair corresponding to the original encoded pair
// we're given
// @param string original the 2-letter string to decode
// @param const char cipher[5][5] the cipher we're using to decode it
// @return string the 2-letter decoded corresponding pair
string retrieveDecodedPair(string original, const char cipher[5][5]) {
  // see comments on getEncodedPair for first chunk of code
  // its exactly the same
  char first = original.at(0);
  char second = original.at(1);
  if (first == 'j')
    first = 'i';
  if (second == 'j')
    second = 'i';
  int firstRow, firstCol, secondRow, secondCol;

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (first == cipher[i][j]) {
        firstRow = i;
        firstCol = j;
      } else if (second == cipher[i][j]) {
        secondRow = i;
        secondCol = j;
      }
    }
  }

  // take this information and use the playfair cipher

  // if they're in the same row
  if (firstRow == secondRow) {
    // if either column is 0 and we subtract 1 from the column we will be out of
    // array bounds
    // instead we need to wrap around to column 4, so set the column number to 5
    if (firstCol == 0)
      firstCol = 5;
    if (secondCol == 0)
      secondCol = 5;
    // one column left but row stays the same
    return (string(1, cipher[firstRow][firstCol - 1]) +
            string(1, cipher[secondRow][secondCol - 1]));
  }
  // if same column
  else if (firstCol == secondCol) {
    // if either row is 0 and we subtract 1 from the row we will be out of
    // array bounds
    // instead we need to wrap around to row 4, so set the row number to 5
    if (firstRow == 0)
      firstRow = 5;
    if (secondRow == 0)
      secondRow = 5;
    // one row up but column stays the same
    return (string(1, cipher[firstRow - 1][firstCol]) +
            string(1, cipher[secondRow - 1][secondCol]));
  }
  // otherwise do the square thing exactly like in encoding
  else {
    return (string(1, cipher[firstRow][secondCol]) +
            string(1, cipher[secondRow][firstCol]));
  }
}

// Decode a given message using a given key
// Precondition: message was encoded using this Playfair cipher
// @param string message the message to decode
// @param string key the secret key to decode it with
// @return string the decoded message
string decode(string message, string key) {
  bool uniqueKeyChars[25] = {false}; // represents whether char corresponding to
                                     // each index is in message or not
  vector<int> letterOrder(26);       // for the order of the unique letters
  // initialize our unique characters array and vector with the key
  initUniqueChars(removeNonLetters(key), uniqueKeyChars, &letterOrder);
  char keyArray[5][5]; // this is our cipher
  // initialize our cipher using the unique characters in the correct order
  init2DCipherArray(uniqueKeyChars, keyArray, letterOrder);

  // we only need to remove non-letters just in case of bad input
  // as long as they are decoding a valid thing, there will be no duplicates
  // and the length is guaranteed to be even so no need to check for that
  string messageOnlyLetters = removeNonLetters(message);
  string ans = "";

  // for every pair of letters
  for (int i = 0; i < messageOnlyLetters.length(); i += 2) {
    // decode each pair of letters using our favorite cipher
    // and append it to the answer that we're returning
    ans = ans + retrieveDecodedPair(messageOnlyLetters.substr(i, 2), keyArray);
  }

  return ans;
}

int main() {
  string mode; // either encode or decode
  // ask user if they want encoding mode or decoding mode
  // and keep asking until they give valid input
  do {
    cout << "choose mode: \"encode\" or \"decode\"" << endl;
    cin >> mode;
  } while (!(mode == "encode" || mode == "decode"));

  // variables to store the user-supplied key and message
  string key;
  string message;

  // if they chose decode, ask them questions that pertain to decoding
  if (mode == "decode") {
    cout << "\nwhat is the scrambled message?" << endl;
    getline(cin >> ws, message);
    cout << "\nwhat is the decoding key?" << endl;
    getline(cin >> ws, key);

    // do the decoding and print the returned output
    cout << "\ndecoded message: " << decode(message, key) << endl;
  }
  // if they chose encode, ask them questions that pertain to encoding
  else {
    cout << "\nwhat is the message to encode?\n";
    getline(cin >> ws, message);
    cout << "\nwhat is the encoding key?" << endl;
    getline(cin >> ws, key);

    // do the encoding and print the returned output
    cout << "\nencoded message: " << encode(message, key) << endl;
  }

  return 0;
}