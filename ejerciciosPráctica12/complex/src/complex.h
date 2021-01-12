/**
* Universidad de La Laguna
* Escuela Superior de Ingeniería y Tecnología
* Grado en Ingeniería Informática
* Asignatura: Informática Básica
* Curso: 1º
*
* @brief complex_main.cc functions and classes declaration
*/

#ifndef COMPLEX_H
#define COMPLEX_H

class Complex {
 public:
  //Constructors
  Complex() = default;
  Complex(double real, double imaginary);
  //Getters
  double real() const {return real_;}
  double imaginary() const {return imaginary_;}
  //Class functions declaraction
  void printComplexNumber();
  Complex addComp(Complex complex_1, Complex complex_2);
  Complex substractComp(Complex complex_1, Complex complex_2);
  Complex multiplyComp(Complex complex_1, Complex complex_2);
  Complex divideComplex(Complex complex_1, Complex complex_2);
 private:
  double real_ {0};
  double imaginary_ {0};
};

//Overloaded operators
Complex operator+(const Complex& complex_1, const Complex& complex_2);
Complex operator-(const Complex& complex_1, const Complex& complex_2);
Complex operator*(const Complex& complex_1, const Complex& complex_2);
Complex operator/(const Complex& complex_1, const Complex& complex_2);
bool operator==(const Complex& complex_1, const Complex& complex_2);

#endif