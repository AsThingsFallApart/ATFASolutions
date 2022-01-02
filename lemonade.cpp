#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

/* implementation notes: */
// context: unlimited capital (no need to minimize costs)
// - extra sugar/lemon CARRY OVER into next day
// goal: calculate the MINIMUM_COST of buying lemons/sugar such that
// each customer has as many cups as they want to buy

// sugar is sold in FIVE_POUND_BAGS
// 1 pound = 16 ounces
// therefore, sugar is bought in intervals of 80

// scenario:
// morning: buy lemons and sugar such that total cups sold that day are can be made
// after morning: sell lemonade
// - update running values
// -- currentLemons -= cupsSoldInDay * lemonsConsumedPerCup;
// -- currentSugar -= cupsSoldInDay * priceOfEightyOuncesOfSugar;
// -- dailyCost = ((cupsSoldInDay * lemonsConsumedPerCup) * priceOfSingleLemon)
//    + ((cupsSoldInDay * sugarConsumedPerCup) *

int main() {
  int daysSpentSellingLemonade = 0, lemonsConsumedPerCup = 0, sugarConsumedPerCup = 0;
  int i = 0;
  int epochCounter = 0;
  int cupsSoldInDay = 0, priceOfSingleLemon = 0, priceOfEightyOuncesOfSugar = 0;
  int sugarInStorage = 0;
  int totalCost = 0;
  int rollingMinimumLemon = 51;
  vector<int> rollingMinimumsLemon;
  vector<int> rollingMinimumsLemonEpochStart;
  int rollingMinimumSugar = 501;
  vector<int> rollingMinimumsSugar;
  vector<int> rollingMinimumsSugarEpochStart;
  int cupsSoldPerDay[daysSpentSellingLemonade];

  cin >> daysSpentSellingLemonade >> lemonsConsumedPerCup >> sugarConsumedPerCup;

  // if we have:
  //  1. rolling minimums and time periods for lemons
  //  2. rolling minimums and time periods for sugar
  //  3. cups sold for each day
  // the total minimum cost can be calculated.
  for(i = 0; i < daysSpentSellingLemonade; i++) {
    cin >> cupsSoldInDay >> priceOfSingleLemon >> priceOfEightyOuncesOfSugar;

    // organize cups sold each day (3) into an array
    cupsSoldPerDay[i] = cupsSoldInDay;

    // organize rolling minimums for lemons and their start days (1) into vectors
    if(priceOfSingleLemon < rollingMinimumLemon) {
      rollingMinimumLemon = priceOfSingleLemon;
      rollingMinimumsLemon.push_back(rollingMinimumLemon);
      rollingMinimumsLemonEpochStart.push_back(i);
    }

    // organize rolling minimums for sugar and their start days (2) into vectors
    if(priceOfEightyOuncesOfSugar < rollingMinimumSugar) {
      rollingMinimumSugar = priceOfEightyOuncesOfSugar;
      rollingMinimumsSugar.push_back(rollingMinimumSugar);
      rollingMinimumsSugarEpochStart.push_back(i);
    }
  }

  // number of epochs = rollingMinimumLemonEpochStart.size();
  // so we have total number of epochs and when the epochs begin
  // I need to initialize epochCounter before printing rollingMinimums



  cout << "day\tcupsSoldPerDay\trollingMinimumLemons\trollingMinimumsSugar\n";

  for(i = 0; i < daysSpentSellingLemonade; i++) {
    cout << i << "\t" << cupsSoldPerDay[i];


  }


  return 0;
}
