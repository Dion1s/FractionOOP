#pragma once
#include<iostream>
#include<cmath>
#include<string>

class Fraction {
private:
	int numerator;
	int denominator;
public:
	Fraction(int num = 0, int den = 1);

	int getNumerator()const;
	int getDeniminator()const;

	void simplify();

	Fraction operator+() const;
	Fraction operator-() const;

	Fraction operator+(const Fraction& other) const;
	Fraction operator-(const Fraction& other) const;

	Fraction operator*(const Fraction& other) const;
	Fraction operator/(const Fraction& other) const;

	bool operator==(const Fraction& other) const;
	bool operator!=(const Fraction& other) const;
	bool operator<(const Fraction& other) const;
	bool operator>(const Fraction& other) const;
	bool operator<=(const Fraction& other) const;
	bool operator>=(const Fraction& other) const;

	Fraction& operator+=(const Fraction& other);
	Fraction& operator-=(const Fraction& other);
	Fraction& operator*=(const Fraction& other);
	Fraction& operator/=(const Fraction& other);

	int& operator[](int index);
	int& operator[](const std::string& index);

	operator double() const;
	explicit operator int() const;

	Fraction& reduce();

	Fraction& operator++();
	Fraction operator++(int);
		

	friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction);
	friend std::istream& operator>>(std::istream& in, Fraction& fraction);

};

static int gcd(int a, int b);
void sortFractionsAscending(Fraction fractions[], int size);
void sortFractionsDescending(Fraction fractions[], int size);
void printFractions(const Fraction* fractions, int size);