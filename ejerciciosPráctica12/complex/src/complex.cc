/**
* Universidad de La Laguna
* Escuela Superior de Ingeniería y Tecnología
* Grado en Ingeniería Informática
* Asignatura: Informática Básica
* Curso: 1º
*
* @brief complex_main.cc functions and classes definition
*/

#include <iostream>

#include "complex.h"

/**
* Declaration of the constructor in Complex class.
*
* @param real, value of the real part of the complex number.
* @param imaginary, value of the imaginary part of the complex number.
* @return It is a constructor of Complex class so it doesn't return nothing.
*/

Complex::Complex(double real, double imaginary) {real_ = real; imaginary_ = imaginary;}

/**
* Definition of a function from Complex class that prints a complex number
* in the form 'a + bi'.
*
* @param ## There is no parameter.
* @return It is a void function so it doesn't return nothing.
*/

void Complex::printComplexNumber() {
  if(imaginary_ > 0) {std::cout << real_ << " + " << imaginary_ << "i\n";}
  else if(imaginary_ < 0) {std::cout << real_ << " + (" << imaginary_ << ")i\n";}
}

/**
* Definition of a function from Date class that sums two complex numbers.
*
* @param complex_1, object from Complex class which represents a complex number.
* @param complex_2, same as 'complex_1'. 
* @return An object from Complex class that is the addition of the two Complex parameters.
*/

Complex Complex::addComp(Complex complex_1, Complex complex_2) {Complex addition(complex_1 + complex_2); return addition;}

/**
* Definition of a function from Date class that substracts two complex numbers.
*
* @param complex_1, object from Complex class which represents a complex number.
* @param complex_2, same as 'complex_1'. 
* @return An object from Complex class that is the substraction of the two Complex parameters.
*/

Complex Complex::substractComp(Complex complex_1, Complex complex_2) {Complex substraction(complex_1 - complex_2); return substraction;}

/**
* Definition of a function from Date class that multiplies two complex numbers.
*
* @param complex_1, object from Complex class which represents a complex number.
* @param complex_2, same as 'complex_1'. 
* @return An object from Complex class that is the multiplication of the two Complex parameters.
*/

Complex Complex::multiplyComp(Complex complex_1, Complex complex_2) {Complex multiplication(complex_1 * complex_2); return multiplication;}

/**
* Definition of a function from Date class that divides two complex numbers.
*
* @param complex_1, object from Complex class which represents a complex number.
* @param complex_2, same as 'complex_1'. 
* @return An object from Complex class that is the divsion of the two Complex parameters.
*/

Complex Complex::divideComplex(Complex complex_1, Complex complex_2) {Complex division(complex_1 / complex_2); return division;}

/**
* Definition of a function that overloads the '+' operator to allow the addition of two objects from 
* Complex class.
*
* @param complex_1, a constant reference to an object from Complex class.
* @param complex_2, the same as 'complex_1'.
* @returns A call to the constructor from Complex class to construct the addition object.
*/

Complex operator+(const Complex& complex_1, const Complex& complex_2) {
  return Complex(complex_1.real() + complex_2.real(), complex_1.imaginary() + complex_2.imaginary());
}

/**
* Definition of a function that overloads the '-' operator to allow the substraction of two objects from 
* Complex class.
*
* @param complex_1, a constant reference to an object from Complex class.
* @param complex_2, the same as 'complex_1'.
* @returns A call to the constructor from Complex class to construct the substraction object.
*/

Complex operator-(const Complex& complex_1, const Complex& complex_2) {
  return Complex(complex_1.real() - complex_2.real(), complex_1.imaginary() - complex_2.imaginary());
}

/**
* Definition of a function that overloads the '*' operator to allow the multiplication of two objects from 
* Complex class.
*
* @param complex_1, a constant reference to an object from Complex class.
* @param complex_2, the same as 'complex_1'.
* @returns A call to the constructor from Complex class to construct the multiplication object.
*/

Complex operator*(const Complex& complex_1, const Complex& complex_2) {
  return Complex(complex_1.real() * complex_2.real() - complex_1.imaginary() * complex_2.imaginary(), 
  complex_1.real() * complex_2.imaginary() + complex_2.real() * complex_1.imaginary());
}

/**
* Definition of a function that overloads the '/' operator to allow the division of two objects from 
* Complex class.
*
* @param complex_1, a constant reference to an object from Complex class.
* @param complex_2, the same as 'complex_1'.
* @returns A call to the constructor from Complex class to construct the division object.
*/

Complex operator/(const Complex& complex_1, const Complex& complex_2) {
  double denominator = (complex_2.real() * complex_2.real()) + (complex_2.imaginary() * complex_2.imaginary());
  return Complex((complex_1.real() * complex_2.real() + complex_1.imaginary() * complex_2.imaginary()) / denominator, 
  (complex_2.real() * complex_1.imaginary() - complex_1.real() * complex_2.imaginary()) / denominator);
}

/**
* Definition of a function that overloads the '==' operator to allow comparing two objects from 
* Complex class.
*
* @param complex_1, a constant reference to an object from Complex class.
* @param complex_2, the same as 'complex_1'.
* @returns True or false wether the objects are equal or not.
*/

bool operator==(const Complex& complex_1, const Complex& complex_2) {
  if((complex_1.real() == complex_2.real()) && (complex_1.imaginary() == complex_2.imaginary())) {return true;}
  else if((complex_1.real() != complex_2.real()) || (complex_1.imaginary() != complex_2.imaginary())) {return false;}
  return false;
}