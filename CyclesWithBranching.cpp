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
  const double liquidViscosity = 0.009;
  const double averageHeight = 0.1;
  const double radius = 15.0;

  const double dynamicSpeed[] = {
	  0.1, 0.2, 0.5, 1.0, 2.0, 5.0
  };

  double k;
  double relativeRoughness;
  double coefficientDrag;
  
  relativeRoughness = averageHeight / radius;

  for (int stepIndex = 0; stepIndex < 6; ++stepIndex) {
	  k = log10(dynamicSpeed[stepIndex] * averageHeight / liquidViscosity);

	  if (k < 0.55) {
		coefficientDrag = 1.0 / pow(0.7 + 2.0 * k - 2.0 * log10(relativeRoughness), 2.0);
	  } else if (k > 0.55) {
		coefficientDrag = 1.0 / pow(1.18 + 1.13 * k - 2.0 * log10(relativeRoughness), 2.0);
	  } else {
		cout << setw(16) << dynamicSpeed[stepIndex]
			 << setw(16) << k
			 << setw(16) << "Undefined" << '\n';
		continue;
	  }

	  cout << setw(16) << dynamicSpeed[stepIndex]
		   << setw(16) << k
		   << setw(16) << coefficientDrag << '\n';
  }
	  return 0;
}