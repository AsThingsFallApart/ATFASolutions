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

int main() {
  int squareLength = 0, circleRadius = 0;
  double pi = 3.14159265358979;
  double skylightRainArea = 0.0;

  cin >> squareLength >> circleRadius;

  cout << "areaSquare: " << squareLength * squareLength << "\n";
  cout << "areaCircle: " << pi * (circleRadius * circleRadius) << "\n";

  skylightRainArea = (squareLength * squareLength) - (pi * (circleRadius * circleRadius));

  // round to two (100 represents the hundredth place, 1000 for three decimal places, etc) decimal places
  skylightRainArea = ceil(skylightRainArea * 100) / 100;

  cout << "\nskylightRainArea: " << skylightRainArea;

  return 0;
}
