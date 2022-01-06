#include <iostream>
using namespace std;

int main() {
  int i = 0;
  int strLen = 0;
  bool seventeen = false;
  bool eighteen = false;
  int temp = 0;
  int nums[10];
  string inputLine;
  string tempNum = "";

  // put in container
  getline(cin, inputLine);

  for(char c : inputLine) {
    //cout << "c: " << c << endl;
    //cout << "i: " << i << endl;
    //cout << "tempNum: " << tempNum << endl << endl;

    if(c == ' ') {
      nums[i] = stoi(tempNum);
      //cout << "nums[" << i << "]: " << nums[i] << endl << endl;
      i++;
      tempNum = "";
    }
    else if((strLen + 1) == inputLine.length()) {
      tempNum += c;
      nums[i] = stoi(tempNum);
    }
    else {
      tempNum += c;
    }

    strLen++;
  }

  // check elements in container
  for(i = 0; i < 10; i++) {
    if(nums[i] == 17) {
      seventeen = true;
    }
    if(nums[i] == 18) {
      eighteen = true;
    }
  }

  // there are four output cases: 1.) "17", 2.) "18", 3.) "both", 4.) "none"
  if(seventeen && eighteen) {
    cout << "both";
  }
  else if(seventeen) {
    cout << "17";
  }
  else if(eighteen) {
    cout << "18";
  }
  else {
    cout << "none";
  }

  return 0;
}
