#include "Complex.h"

//constructor
Complex::Complex(double r, double i) {
	real = r;
	imaginary = i;
}

//default constructor
Complex::Complex() {
	real = 0;
	imaginary = 0;
}

//destructor
Complex::~Complex(){}

//overloading plus operator
Complex operator+(Complex &l1, Complex &l2){
	Complex result(l1.real + l2.real, l1.imaginary + l2.imaginary);
	return result;
}

Complex operator+(double l1, Complex &l2){
	Complex result(l1 + l2.real, l2.imaginary);
	return result;
}

Complex operator+(Complex &l1, double l2){
	Complex result(l1.real + l2, l1.imaginary);
	return result;
}

//overloading minus operator
Complex operator-(Complex &l1, Complex &l2){
	Complex result(l1.real - l2.real, l1.imaginary - l2.imaginary);
	return result;
}

Complex operator-(double l1, Complex &l2){
	Complex result(l1 - l2.real, l2.imaginary);
	return result;
}

Complex operator-(Complex &l1, double l2){
	Complex result(l1.real - l2, l1.imaginary);
	return result;
}

//overloading multiplication, the fun stuff
Complex operator*(Complex &l1, Complex &l2){
	Complex result((l1.real * l2.real) - (l1.imaginary * l2.imaginary), (l1.real * l2.imaginary) + (l1. imaginary * l2.real));
	return result;
}

Complex operator*(double l1, Complex &l2){
	Complex result(l1 * l2.real, l1 * l2.imaginary);
	return result;
}

Complex operator*(Complex &l1, double l2){
	Complex result(l1.real * l2, l1.imaginary * l2);
	return result;
}

//overloading division, more of the fun stuff
Complex operator/(Complex &l1, Complex &l2){
	Complex result;
	result.real = ((l1.real * l2.real) + (l1.imaginary * l2.imaginary)) / (l2.real * l2.real + l2.imaginary * l2.imaginary); //compute real part			(ac+bd)/(c^2+d^2)
	result.imaginary = ((l1.imaginary * l2.real) - (l1.real * l2.imaginary)) / (l2.real * l2.real + l2.imaginary * l2.imaginary); //compute imaginary part	(bc-ad)/(c^2+d^2)

	return result;
}

Complex operator/(double l1, Complex &l2){
	Complex result;
	result.real = (l1 * l2.real) / (l2.real * l2.real + l2.imaginary * l2.imaginary); //compute real part
	result.imaginary = -(l1 * l2.imaginary) / (l2.real * l2.real + l2.imaginary * l2.imaginary); //compute imaginary part
	
	return result;
}

Complex operator/(Complex &l1, double l2){
	Complex result(l1.real / l2, l1.imaginary / l2);
	return result;
}

Complex Complex::operator=(double l) {
	Complex ret = (*this);
	real = l;
	imaginary = 0;
	return ret;
}

//print for printing the complex number
void Complex::print(){
	if(imaginary >= 0){
		std::cout << real << "+" << imaginary << "i" << std::endl;
	}else{
		std::cout << real << imaginary << "i" << std::endl;
	}
}

//return the magnitude of the vector from 0+0i to x+yi
double Complex::getMagnitude() {
	return sqrt(real * real + imaginary * imaginary);
}