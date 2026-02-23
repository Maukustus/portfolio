#pragma once

#include <iostream>

//class for handling complex numbers as objects.
class Complex
{


	//friend functions for overloading plus operator
	friend Complex operator+(Complex &l1, Complex &l2);
	friend Complex operator+(double l1,   Complex &l2);
	friend Complex operator+(Complex &l1, double l2);

	//ditto, for minus operator
	friend Complex operator-(Complex &l1, Complex &l2);
	friend Complex operator-(double l1,   Complex &l2);
	friend Complex operator-(Complex &l1, double l2);

	//ditto, for multiplication
	friend Complex operator*(Complex &l1, Complex &l2);
	friend Complex operator*(double l1,   Complex &l2);
	friend Complex operator*(Complex &l1, double l2);

	//ditto, for division
	friend Complex operator/(Complex &l1, Complex &l2);
	friend Complex operator/(double l1,   Complex &l2);
	friend Complex operator/(Complex &l1, double l2);

public:
	Complex(double r, double i);
	Complex();

	~Complex();

	void print();

	double getMagnitude();

	Complex operator=(double l);

private:
	//parts of the complex number
	double real;
	double imaginary;

};

