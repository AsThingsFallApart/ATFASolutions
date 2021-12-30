#include <iostream>
#include <cmath>
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
  int cupsSoldInDay = 0, priceOfSingleLemon = 0, priceOfEightyOuncesOfSugar = 0;
  int sugarInStorage = 0;
  int totalCost = 0;
  int lemonsNeededToday = 0;
  int priceOfLemonsNeededToday = 0;
  int sugarNeededToday = 0;
  int priceOfSugarNeededToday = 0;
  double fivePoundBagsSugarNeeded = 0.0;
  int sugarBoughtInOunces = 0;

  cin >> daysSpentSellingLemonade >> lemonsConsumedPerCup >> sugarConsumedPerCup;

  for(i = 0; i < daysSpentSellingLemonade; i++) {
    cin >> cupsSoldInDay >> priceOfSingleLemon >> priceOfEightyOuncesOfSugar;

    cout << "\nDay " << (i + 1) << ": \n";

    lemonsNeededToday = cupsSoldInDay * lemonsConsumedPerCup;
    priceOfLemonsNeededToday = lemonsNeededToday * priceOfSingleLemon;

    cout << "Money(cents) spent buying lemons: " << priceOfLemonsNeededToday << "\n";

    sugarNeededToday = (cupsSoldInDay * sugarConsumedPerCup) - sugarInStorage;
    fivePoundBagsSugarNeeded = sugarNeededToday / 80.0;

    cout << "sugarInStorage: " << sugarInStorage << "\n";
    cout << "sugarNeededToday: " << sugarNeededToday << "\n";
    cout << "fivePoundBagsSugarNeeded: " << fivePoundBagsSugarNeeded << "\n";

    if(ceil(fivePoundBagsSugarNeeded) > fivePoundBagsSugarNeeded) {
      priceOfSugarNeededToday = ceil(fivePoundBagsSugarNeeded) * priceOfEightyOuncesOfSugar;
      sugarBoughtInOunces = ceil(fivePoundBagsSugarNeeded) * 80;
      sugarInStorage = sugarBoughtInOunces - sugarNeededToday;
    }
    else {
      priceOfSugarNeededToday = fivePoundBagsSugarNeeded * priceOfEightyOuncesOfSugar;
      sugarBoughtInOunces = fivePoundBagsSugarNeeded * 80;
      sugarInStorage = sugarBoughtInOunces - sugarNeededToday;
    }

    cout << "Money(cents) spent buying sugar: " << priceOfSugarNeededToday << "\n";

    totalCost += priceOfLemonsNeededToday + priceOfSugarNeededToday;

    cout << "totalCost: " << totalCost;
  }

  return 0;
}
