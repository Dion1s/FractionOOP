#include "CFraction.h"

Fraction::Fraction(int num, int den) :numerator(num), denominator(den){
    simplify();
}

int Fraction::getNumerator() const
{
	return numerator;
}

int Fraction::getDeniminator() const
{
	return denominator;
}

void Fraction::simplify() {
    int gcdValue = gcd(abs(numerator), abs(denominator));
    numerator /= gcdValue;
    denominator /= gcdValue;
}

Fraction  Fraction::operator+() const {
    return *this;
}

Fraction  Fraction::operator-() const {
    return Fraction(-numerator, denominator);
}

Fraction  Fraction::operator+(const Fraction& other) const {
    int commonDenominator = denominator * other.denominator;
    int sumNumerator = numerator * other.denominator + other.numerator * denominator;
    return Fraction(sumNumerator, commonDenominator);
}

Fraction  Fraction::operator-(const Fraction& other) const {
    int commonDenominator = denominator * other.denominator;
    int diffNumerator = numerator * other.denominator - other.numerator * denominator;
    return Fraction(diffNumerator, commonDenominator);
}


Fraction  Fraction::operator*(const Fraction& other) const {
    return Fraction(numerator * other.numerator, denominator * other.denominator);
}

Fraction  Fraction::operator/(const Fraction& other) const {
    return Fraction(numerator * other.denominator, denominator * other.numerator);
}

bool  Fraction::operator==(const Fraction& other) const {
    return (numerator == other.numerator) && (denominator == other.denominator);
}

bool  Fraction::operator!=(const Fraction& other) const {
    return !(*this == other);
}

bool  Fraction::operator<(const Fraction& other) const {
    int commonDenominator = denominator * other.denominator;
    int thisNumerator = numerator * other.denominator;
    int otherNumerator = other.numerator * denominator;
    return thisNumerator < otherNumerator;
}

bool  Fraction::operator>(const Fraction& other) const {
    return other < *this;
}

bool  Fraction::operator<=(const Fraction& other) const {
    return !(other < *this);
}

bool  Fraction::operator>=(const Fraction& other) const {
    return !(*this < other);
}

Fraction& Fraction::operator+=(const Fraction& other) {
    *this = *this + other;
    return *this;
}

Fraction& Fraction::operator-=(const Fraction& other) {
    *this = *this - other;
    return *this;
}

Fraction& Fraction::operator*=(const Fraction& other) {
    *this = *this * other;
    return *this;
}

Fraction& Fraction::operator/=(const Fraction& other) {
    *this = *this / other;
    return *this;
}

int& Fraction::operator[](int index) {
    if (index == 0) {
        return numerator;
    }
    else if (index == 1) {
        return denominator;
    }
    else {
        throw std::out_of_range("Invalid index");
    }
}

int& Fraction::operator[](const std::string& index) {
    if (index=="numerator") {
        return numerator;
    }
    else if (index == "denominator") {
        return denominator;    
    }
    else {
        throw std::out_of_range("Invalid index");
    }
}

std::ostream& operator<<(std::ostream& out, const Fraction& fraction) {
    out << fraction.numerator << "/" << fraction.denominator;
    return out;
}

std::istream& operator>>(std::istream& in, Fraction& fraction) {
    char slash;
    in >> fraction.numerator >> slash >> fraction.denominator;
    fraction.simplify();
    return in;
}

Fraction::operator double() const {
    return static_cast<double>(numerator) / denominator;
}

Fraction::operator int() const {
    return numerator / denominator;
}

Fraction& Fraction::reduce() {
    simplify();
    return *this;
}

Fraction& Fraction::operator++() {
    numerator += denominator;
    return *this;
}

Fraction Fraction::operator++(int) {
    Fraction temp(*this);
    numerator += denominator;
    return temp;
}


static int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void sortFractionsAscending(Fraction fractions[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (fractions[j] > fractions[j + 1]) {
                std::swap(fractions[j], fractions[j + 1]);
            }
        }
    }
}

void sortFractionsDescending(Fraction fractions[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (fractions[j] < fractions[j + 1]) {
                std::swap(fractions[j], fractions[j + 1]);
            }
        }
    }
}

void printFractions(const Fraction* fractions, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << fractions[i] << "\t";
    }
    std::cout << std::endl;
}
