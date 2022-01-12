#include <iostream>
#include <cmath>
using namespace std;

// notes:
// given two things:
//  1. radius of a circle
//  2. length of a square
// contextually, the circle is below the square and they are coaxial
// rain falls through the square straight down into the circle
// the algorithm should calculate the amount of "skylight rain area" covered by the circle
// is this not just
// skylightRainArea = (squareLength * squareLength) - (M_PI * (circleRadius * circleRadius));
// ...?
// 1/11/22 edit:
// water falls in each unit squared of the square
// skylightRainArea is how much of the square is also the circle
// therefore, skylightRainArea is always a number from
//  0 (the circle is nonexistent) to
//  squareLength * squareLength (the circle covers all the square area)
// I feel like I understand the context better
// Does the algorithm require calculus...?
//  Probably not since these questions are designed to be solved by high schoolers

int main() {
  int squareLength = 0, circleRadius = 0;
  double pi = 3.14159265358979;
  double skylightRainArea = 0.0;

  cin >> squareLength >> circleRadius;

  int areaSquare = squareLength * squareLength;
  double areaCircle = pi * (circleRadius * circleRadius);

  cout << "areaSquare: " << areaSquare << "\n";
  cout << "areaCircle: " << areaCircle << "\n";
  cout << "squareLengthHalved: " << squareLength / 2.0 << "\n";

  // case: circle completely enclosed by square
  // logic: if the circle is completely inside the square,
  // the amount of area covered is all inside the square.
  // No skylightRainArea needs to be pruned...
  if(squareLength / 2.0 >= circleRadius) {
    skylightRainArea = areaCircle;
  }
  // case: square completely enclosed by circle
  // breakpoint: when the radius is 4/3 times the length,
  // the circle completely encloses the square
  else if((circleRadius * 4) / 3 >= squareLength) {
    skylightRainArea = areaSquare;
  }

  // round to two (100 represents the hundredth place, 1000 for three decimal places, etc) decimal places
  skylightRainArea = round(skylightRainArea * 100) / 100;

  cout << "\nskylightRainArea: " << skylightRainArea;

  return 0;
}
