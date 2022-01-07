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
  int i = 0, j = 0;
  int cupsSoldInDay = 0, priceOfSingleLemon = 0, priceOfEightyOuncesOfSugar = 0;
  int sugarInStorage = 0, sugarNeededTodayInOunces = 0, sugarPurchasedTodayInOunces = 0;
  double bagsOfSugarNeeded = 0.0;
  int minimumCostTotal = 0, minimumCostThisEpoch = 0, minimumCostLemons = 0, minimumCostSugar = 0;
  int costPerDay = 0;
  int rollingMinimumLemon = 51;
  vector<int> rollingMinimumsLemon;
  vector<int> rollingMinimumsLemonEpochStart;
  int rollingMinimumSugar = 501;
  vector<int> rollingMinimumsSugar;
  vector<int> rollingMinimumsSugarEpochStart;

  cin >> daysSpentSellingLemonade >> lemonsConsumedPerCup >> sugarConsumedPerCup;
  int cupsSoldPerDay[daysSpentSellingLemonade];

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

//  cout << "day\tcupsSoldPerDay\n";

//  for(i = 0; i < daysSpentSellingLemonade; i++) {
//    cout << i << "\t" << cupsSoldPerDay[i] << "\n";
//  }

//  cout << "\nLEMONS:\n";

  // loop through lemon epochs
  for(i = 0; i < rollingMinimumsLemonEpochStart.size(); i++) {
//    if(rollingMinimumsLemonEpochStart.at(i) == rollingMinimumsLemonEpochStart.front() && rollingMinimumsLemonEpochStart.size() == 1) {
//      cout << "Epoch 0: Days 0 - " << (daysSpentSellingLemonade - 1) << "\n";
//      cout << "Rolling minimum: " << rollingMinimumsLemon.at(i) << " cents\n";
//    }
//    else if(rollingMinimumsLemonEpochStart.at(i) == rollingMinimumsLemonEpochStart.back()) {
//      cout << "Epoch " << i << ": Days " << rollingMinimumsLemonEpochStart.at(i) << " - " << (daysSpentSellingLemonade - 1) << "\n";
//      cout << "Rolling minimum: " << rollingMinimumsLemon.at(i) << " cents\n";
//    }
//    else {
//      cout << "Epoch " << i << ": Days " << rollingMinimumsLemonEpochStart.at(i) << " - " << (rollingMinimumsLemonEpochStart.at(i + 1) - 1) << "\n";
//      cout << "Rolling minimum: " << rollingMinimumsLemon.at(i) << " cents\n";
//    }

    // in an epoch, there are one or more days: loop through days in an epoch
    // case: only one epoch
    if(rollingMinimumsLemonEpochStart.size() == 1) {
      for(j = rollingMinimumsLemonEpochStart.at(i); j < daysSpentSellingLemonade; j++) {
        costPerDay = (cupsSoldPerDay[j] * lemonsConsumedPerCup) * rollingMinimumsLemon.at(i);
//        cout << "Day " << j << ": (" << cupsSoldPerDay[j] << " * " << lemonsConsumedPerCup << ") * " << rollingMinimumsLemon.at(i) << "\n";
        minimumCostThisEpoch += costPerDay;
      }
    }
    // case: first epoch of several
    else if(rollingMinimumsLemonEpochStart.at(i) == rollingMinimumsLemonEpochStart.front() && rollingMinimumsLemonEpochStart.size() > 1) {
      for(j = rollingMinimumsLemonEpochStart.at(i); j < rollingMinimumsLemonEpochStart.at(i + 1); j++) {
        costPerDay = (cupsSoldPerDay[j] * lemonsConsumedPerCup) * rollingMinimumsLemon.at(i);
//        cout << "Day " << j << ": (" << cupsSoldPerDay[j] << " * " << lemonsConsumedPerCup << ") * " << rollingMinimumsLemon.at(i) << "\n";
        minimumCostThisEpoch += costPerDay;
      }
    }
    // case: last epoch of several
    else if(rollingMinimumsLemonEpochStart.at(i) == rollingMinimumsLemonEpochStart.back()) {
      for(j = rollingMinimumsLemonEpochStart.at(i); j < daysSpentSellingLemonade; j++) {
        costPerDay = (cupsSoldPerDay[j] * lemonsConsumedPerCup) * rollingMinimumsLemon.at(i);
//        cout << "Day " << j << ": (" << cupsSoldPerDay[j] << " * " << lemonsConsumedPerCup << ") * " << rollingMinimumsLemon.at(i) << "\n";
        minimumCostThisEpoch += costPerDay;
      }
    }
    // case: middle epoch
    else {
      for(j = rollingMinimumsLemonEpochStart.at(i); j < rollingMinimumsLemonEpochStart.at(i + 1); j++) {
        costPerDay = (cupsSoldPerDay[j] * lemonsConsumedPerCup) * rollingMinimumsLemon.at(i);
//        cout << "Day " << j << ": (" << cupsSoldPerDay[j] << " * " << lemonsConsumedPerCup << ") * " << rollingMinimumsLemon.at(i) << "\n";
        minimumCostThisEpoch += costPerDay;
      }
    }

//    cout << "minimumCostThisEpoch: " << minimumCostThisEpoch << "\n\n";

    minimumCostLemons += minimumCostThisEpoch;
    minimumCostThisEpoch = 0;
  }


//  cout << "\nminimumCostLemons: " << minimumCostLemons << "\n";

  // plan: do the same thing for sugar that was done for lemons
  // with special consideration for units and overflow
//  cout << "\nSUGAR:" << "\n";
  for(i = 0; i < rollingMinimumsSugarEpochStart.size(); i++) {
//    if(rollingMinimumsSugarEpochStart.at(i) == rollingMinimumsSugarEpochStart.front() && rollingMinimumsSugarEpochStart.size() == 1) {
//      cout << "Epoch 0: Days 0 - " << (daysSpentSellingLemonade - 1) << "\n";
//      cout << "Rolling minimum: " << rollingMinimumsSugar.at(i) << " cents\n";
//    }
//    else if(rollingMinimumsSugarEpochStart.at(i) == rollingMinimumsSugarEpochStart.back()) {
//      cout << "Epoch " << i << ": Days " << rollingMinimumsSugarEpochStart.at(i) << " - " << (daysSpentSellingLemonade - 1) << "\n";
//      cout << "Rolling minimum: " << rollingMinimumsSugar.at(i) << " cents\n";
//    }
//    else {
//      cout << "Epoch " << i << ": Days " << rollingMinimumsSugarEpochStart.at(i) << " - " << (rollingMinimumsSugarEpochStart.at(i + 1) - 1) << "\n";
//      cout << "Rolling minimum: " << rollingMinimumsSugar.at(i) << " cents\n";
//    }

    // case: only one epoch
    if(rollingMinimumsSugarEpochStart.size() == 1) {
      for(j = rollingMinimumsSugarEpochStart.at(i); j < daysSpentSellingLemonade; j++) {
        sugarNeededTodayInOunces = (cupsSoldPerDay[j] * sugarConsumedPerCup) - sugarInStorage;
        bagsOfSugarNeeded = sugarNeededTodayInOunces / 80.0;

        if(ceil(bagsOfSugarNeeded) > bagsOfSugarNeeded) {
          sugarPurchasedTodayInOunces = ceil(bagsOfSugarNeeded) * 80;
          sugarInStorage = sugarPurchasedTodayInOunces - sugarNeededTodayInOunces;

          costPerDay = ceil(bagsOfSugarNeeded) * rollingMinimumsSugar.at(i);
//          cout << "Day " << j << ": " << ceil(bagsOfSugarNeeded) << " * " << rollingMinimumsSugar.at(i) << "\n";
          minimumCostThisEpoch += costPerDay;
        }
        else {
          sugarPurchasedTodayInOunces = int(bagsOfSugarNeeded) * 80;
          sugarInStorage = sugarPurchasedTodayInOunces - sugarNeededTodayInOunces;

          costPerDay = ceil(bagsOfSugarNeeded) * rollingMinimumsSugar.at(i);
//          cout << "Day " << j << ": " << ceil(bagsOfSugarNeeded) << " * " << rollingMinimumsSugar.at(i) << "\n";
          minimumCostThisEpoch += costPerDay;
        }
      }
    }
    // case: first epoch of several
    else if(rollingMinimumsSugarEpochStart.at(i) == rollingMinimumsSugarEpochStart.front() && rollingMinimumsSugarEpochStart.size() > 1) {
      for(j = rollingMinimumsSugarEpochStart.at(i); j < rollingMinimumsSugarEpochStart.at(i + 1); j++) {
        sugarNeededTodayInOunces = (cupsSoldPerDay[j] * sugarConsumedPerCup) - sugarInStorage;
        bagsOfSugarNeeded = sugarNeededTodayInOunces / 80.0;

        if(ceil(bagsOfSugarNeeded) > bagsOfSugarNeeded) {
          sugarPurchasedTodayInOunces = ceil(bagsOfSugarNeeded) * 80;
          sugarInStorage = sugarPurchasedTodayInOunces - sugarNeededTodayInOunces;

          costPerDay = ceil(bagsOfSugarNeeded) * rollingMinimumsSugar.at(i);
//          cout << "Day " << j << ": " << ceil(bagsOfSugarNeeded) << " * " << rollingMinimumsSugar.at(i) << "\n";
          minimumCostThisEpoch += costPerDay;
        }
        else {
          sugarPurchasedTodayInOunces = int(bagsOfSugarNeeded) * 80;
          sugarInStorage = sugarPurchasedTodayInOunces - sugarNeededTodayInOunces;

          costPerDay = ceil(bagsOfSugarNeeded) * rollingMinimumsSugar.at(i);
//          cout << "Day " << j << ": " << ceil(bagsOfSugarNeeded) << " * " << rollingMinimumsSugar.at(i) << "\n";
          minimumCostThisEpoch += costPerDay;
        }
      }
    }
    // case: last epoch of several
    else if(rollingMinimumsSugarEpochStart.at(i) == rollingMinimumsSugarEpochStart.back()) {
      for(j = rollingMinimumsSugarEpochStart.at(i); j < daysSpentSellingLemonade; j++) {
        sugarNeededTodayInOunces = (cupsSoldPerDay[j] * sugarConsumedPerCup) - sugarInStorage;
        bagsOfSugarNeeded = sugarNeededTodayInOunces / 80.0;

        if(ceil(bagsOfSugarNeeded) > bagsOfSugarNeeded) {
          sugarPurchasedTodayInOunces = ceil(bagsOfSugarNeeded) * 80;
          sugarInStorage = sugarPurchasedTodayInOunces - sugarNeededTodayInOunces;

          costPerDay = ceil(bagsOfSugarNeeded) * rollingMinimumsSugar.at(i);
//          cout << "Day " << j << ": " << ceil(bagsOfSugarNeeded) << " * " << rollingMinimumsSugar.at(i) << "\n";
          minimumCostThisEpoch += costPerDay;
        }
        else {
          sugarPurchasedTodayInOunces = int(bagsOfSugarNeeded) * 80;
          sugarInStorage = sugarPurchasedTodayInOunces - sugarNeededTodayInOunces;

          costPerDay = ceil(bagsOfSugarNeeded) * rollingMinimumsSugar.at(i);
//          cout << "Day " << j << ": " << ceil(bagsOfSugarNeeded) << " * " << rollingMinimumsSugar.at(i) << "\n";
          minimumCostThisEpoch += costPerDay;
        }
      }
    }
    // case: middle epoch
    else {
      for(j = rollingMinimumsSugarEpochStart.at(i); j < rollingMinimumsSugarEpochStart.at(i + 1); j++) {
        sugarNeededTodayInOunces = (cupsSoldPerDay[j] * sugarConsumedPerCup) - sugarInStorage;
        bagsOfSugarNeeded = sugarNeededTodayInOunces / 80.0;

        if(ceil(bagsOfSugarNeeded) > bagsOfSugarNeeded) {
          sugarPurchasedTodayInOunces = ceil(bagsOfSugarNeeded) * 80;
          sugarInStorage = sugarPurchasedTodayInOunces - sugarNeededTodayInOunces;

          costPerDay = ceil(bagsOfSugarNeeded) * rollingMinimumsSugar.at(i);
//          cout << "Day " << j << ": " << ceil(bagsOfSugarNeeded) << " * " << rollingMinimumsSugar.at(i) << "\n";
          minimumCostThisEpoch += costPerDay;
        }
        else {
          sugarPurchasedTodayInOunces = int(bagsOfSugarNeeded) * 80;
          sugarInStorage = sugarPurchasedTodayInOunces - sugarNeededTodayInOunces;

          costPerDay = ceil(bagsOfSugarNeeded) * rollingMinimumsSugar.at(i);
//          cout << "Day " << j << ": " << ceil(bagsOfSugarNeeded) << " * " << rollingMinimumsSugar.at(i) << "\n";
          minimumCostThisEpoch += costPerDay;
        }
      }
    }

//    cout << "minimumCostThisEpoch: " << minimumCostThisEpoch << "\n";

    minimumCostSugar += minimumCostThisEpoch;
    minimumCostThisEpoch = 0;
  }

  //cout << "\n\nminimumCostSugar: " << minimumCostSugar;

  minimumCostTotal = minimumCostLemons + minimumCostSugar;
  //cout << "\n\nminimumCostTotal: " << minimumCostTotal;
  cout << minimumCostTotal;

  return 0;
}
