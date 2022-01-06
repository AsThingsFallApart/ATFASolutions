// medal.cpp
// plan:
//  1. process input line into containers
//  2. check if USA wins by color (medalCount[0] > medalCount[3])
//  3. cascade if statements to check lower colors
//    silver: medalCount[1] > medalCount[4]
//    bronze: medalCount[2] > medalCount[5]
//  4. otherwise, check if USA can win by count
//    if(medalCount[0] + medalCount[1] + medalCount[2] > medalCount[3] + medalCount[4] + medalCount[5])

#include <iostream>
using namespace std;

int main() {
  string inputStr;
  int i = 0;
  int j = 0;
  char temp;
  int medalCount[6];
  string buffer = "";
  bool winByColor = false;
  bool winByCount = false;
  bool failedFlag = false;

  getline(cin, inputStr);
  //cout << "length: " << inputStr.length() << endl;
  //cout << "inputStr[13]: " << inputStr[13] << endl << endl;

  for(i = 0; i < inputStr.length(); i++) {
    //cout << "i: " << i << endl;
    //cout << "buffer: " << buffer << endl;

    if(inputStr[i] == ' ') {
      medalCount[j] = stoi(buffer);
      j++;
      buffer = "";
    }
    // edge case: record the last character in string
    else if((i + 1) == inputStr.length()) {
      buffer += inputStr[i];
      medalCount[j] = stoi(buffer);
    }
    else {
      buffer += inputStr[i];
    }
  }

  //for(i = 0; i < 6; i++) {
    //cout << medalCount[i] << endl;
  //}

  // check for win cons
  // USA wins by color:
  if(medalCount[0] > medalCount[3]) {
    winByColor = true;
  }
  else if((medalCount[1] > medalCount[4]) && !(medalCount[0] < medalCount[3])) {
    winByColor = true;
  }
  else if((medalCount[2] > medalCount[5]) && !(medalCount[1] < medalCount[4])) {
    winByColor = true;
  }

  // USA win by count:
  if(medalCount[0] + medalCount[1] + medalCount[2] > medalCount[3] + medalCount[4] + medalCount[5]) {
    winByCount = true;
  }

  // print win cons:
  if(winByColor && winByCount) {
    cout << "both";
  }
  else if(winByColor) {
    cout << "color";
  }
  else if(winByCount) {
    cout << "count";
  }
  else {
    cout << "none";
  }

  return 0;
}
