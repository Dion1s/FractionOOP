#include "CFraction.h"
#include <string>

void main() {
	size_t ARRAY_SIZE = NULL;
	std::cout << "Enter array size: \n";
	std::cin >> ARRAY_SIZE;
	Fraction* fractions = new Fraction[ARRAY_SIZE];

	std::cout << "Enter " << ARRAY_SIZE << " fractions:\n";
	for (int i = 0; i < ARRAY_SIZE; ++i) {
		std::cin >> fractions[i];
	}

    Fraction sum;
    Fraction product = 1;
    Fraction smallest = fractions[0];
    Fraction largest = fractions[0];

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        sum += fractions[i];
        product *= fractions[i];
        if (fractions[i] < smallest) {
            smallest = fractions[i];
        }
        if (fractions[i] > largest) {
            largest = fractions[i];
        }
    }
    
    sum.reduce();
    product.reduce();

    Fraction average = sum;
    average /= ARRAY_SIZE;

    average.reduce();

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Product: " << product << std::endl;
    std::cout << "Average: " << average << std::endl;
    std::cout << "Smallest: " << smallest << std::endl;
    std::cout << "Largest: " << largest << std::endl;

    std::cout << "Up array: \n";
    sortFractionsAscending(fractions, ARRAY_SIZE);
    printFractions(fractions, ARRAY_SIZE);
    std::cout << "Down array: \n";
    sortFractionsDescending(fractions, ARRAY_SIZE);
    printFractions(fractions, ARRAY_SIZE);

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        std::cout << "Fraction " << i << " - numerator: " << fractions[i][std::string("numerator")]
            << ", denominator: " << fractions[i][std::string("denominator")] << std::endl;
    }

    Fraction fraction1(3, 4);
    Fraction fraction2(1, 2);
    Fraction fraction3(5, 8);

    Fraction result1 = fraction1 + fraction2;
    Fraction result2 = fraction1 - fraction2;
    Fraction result3 = fraction1 * fraction2;
    Fraction result4 = fraction1 / fraction2;


    bool isEqual = fraction1 == fraction2;
    bool isNotEqual = fraction1 != fraction2;
    bool isLess = fraction1 < fraction2;
    bool isGreater = fraction1 > fraction2;
    bool isLessOrEqual = fraction1 <= fraction2;
    bool isGreaterOrEqual = fraction1 >= fraction2;

    fraction1 += fraction2;
    fraction1 -= fraction2;
    fraction1 *= fraction2;
    fraction1 /= fraction2;

    std::cout << "Fraction 1: " << fraction1 << std::endl;
    std::cout << "Fraction 2: " << fraction2 << std::endl;
    std::cout << "Fraction 3: " << fraction3 << std::endl;
    std::cout << "Result 1: " << result1 << std::endl;
    std::cout << "Result 2: " << result2 << std::endl;
    std::cout << "Result 3: " << result3 << std::endl;
    std::cout << "Result 4: " << result4 << std::endl;

    std::cout << std::boolalpha;
    std::cout << "Is Equal: " << isEqual << std::endl;
    std::cout << "Is Not Equal: " << isNotEqual << std::endl;
    std::cout << "Is Less: " << isLess << std::endl;
    std::cout << "Is Greater: " << isGreater << std::endl;
    std::cout << "Is Less or Equal: " << isLessOrEqual << std::endl;
    std::cout << "Is Greater or Equal: " << isGreaterOrEqual << std::endl;

    double fractionAsDouble = static_cast<double>(fraction1);
    int fractionAsInt = static_cast<int>(fraction1);

    Fraction fraction4 = fraction1++;
    Fraction fraction5 = ++fraction2;
    
    delete[] fractions;

}