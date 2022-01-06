#include <iostream>
using namespace std;

// use the newline character ("\n") instead of the end line manipulator for basic printing
// the end line manipulator has additional behavior to FLUSH the output stream
// FLUSHING the output stream incurs an overhead and might cause delays on some machines
// in other words: in most cases, using the newline character to start a newline is faster

int main() {
  int numStudents, numBrownies, numGroups;

  // cout << "Please enter brownie scenario:\n";

  cin >> numStudents >> numBrownies >> numGroups;

//  cout << "\nnumStudents: " << numStudents << "\nnumBrownies: " << numBrownies;
//  cout << "\nnumGroups: " << numGroups;

  int i, numStudentsInGroupM = 0;
  string output = "";
  string temp = "";

  /* the algorithmic black box's behavior DEPENDS ON the output format */

  for(i = 0; i < numGroups; i++) {
      cin >> numStudentsInGroupM;

      while(numBrownies <= numStudentsInGroupM) {
        numBrownies *= 2;
      }

      numBrownies = numBrownies - numStudentsInGroupM;
//      cout << "numStudentsInGroupM: " << numStudentsInGroupM << "\n";
//      cout << "numBrownies: " << numBrownies << "\n";
      temp = to_string(numStudentsInGroupM) + " " + to_string(numBrownies);

      output += temp;
      if(i < numGroups - 1) {
        output += "\n";
      }

//      cout << "\noutput: \"" << output << "\"\n";
  }

  cout << output;

//  for(i = 0; i < numGroups; i++) {
//    cout << "groups[" << i << "]: " << groups[i] << "\n";
//  }

  return 0;
}
