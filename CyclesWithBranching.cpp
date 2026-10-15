/***********************
* Платонова Софья      *
* Циклы с ветвлениями  *
* Вариант 22           *
* *********************/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
  double liquidViscosity = 0.009;
  double averageHeight = 0.1;
  double radius = 15.0;
  double k, relativeRoughness, coefficientDrag;
  int stepCount;

  cout << "How many times should the loop be executed? ";
  cin >> stepCount;

  relativeRoughness = averageHeight / radius;

  for (int stepIndex = 0; stepIndex < stepCount; ++stepIndex) {
	  double dynamicSpeed;

	  cout << "Enter the value of the quantity. ";
	  cin >> dynamicSpeed;

	  k = log10(dynamicSpeed * averageHeight / liquidViscosity);

	  if (k < 0.55) {
		coefficientDrag = 1.0 / pow(0.7  + 2.0  * k - 2.0 * log10(relativeRoughness), 2.0);
	  } else {
		coefficientDrag = 1.0 / pow(1.18 + 1.13 * k - 2.0 * log10(relativeRoughness), 2.0);
	  }

	  cout << "\t" << k
		   << "\t" << coefficientDrag << '\n';
  }
	  return 0;
}