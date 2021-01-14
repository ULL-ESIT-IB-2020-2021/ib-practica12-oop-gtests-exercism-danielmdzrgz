/**
* Universidad de La Laguna
* Escuela Superior de Ingeniería y Tecnología
* Grado en Ingeniería Informática
* Informática Básica
*
* @file complex_mod_main.cc
* @author Daniel Méndez alu0101391793@ull.edu.es
* @date 14 Enero 2021
* @brief Modificación del programa complex para permitir la multiplicación de un complejo por un real y un complejo por
*        entero. 
* @see https://github.com/ULL-ESIT-IB-2020-2021/IB-P12-Classes-GTests-Exercism.git
* @see https://github.com/danielmdzrgz/IB-P12-IntroduccionALaOOP.Clases.GTest.Exercism.git
*/

#include <iostream>

#include "complex_mod.h"

/**
* Main function of complex program.
*/

int main() {
  Complex complex_1 {5,8};
  std::cout << "The first complex number to operate with is: "; complex_1.printComplexNumber();
  Complex complex_2 {2,10};
  std::cout << "The second complex number to operate with: "; complex_2.printComplexNumber();
  Complex result_complex;
  result_complex = result_complex.addComp(complex_1, complex_2);
  std::cout << "\nThe complex result from addition is: "; result_complex.printComplexNumber();
  result_complex = result_complex.substractComp(complex_1, complex_2);
  std::cout << "\nThe complex result from substraction is: "; result_complex.printComplexNumber();
  result_complex = result_complex.multiplyComp(complex_1, complex_2);
  std::cout << "\nThe complex result from multiplication is: "; result_complex.printComplexNumber();
  result_complex = result_complex.divideComplex(complex_1, complex_2);
  std::cout << "\nThe complex result from division is: "; result_complex.printComplexNumber();

  Complex mod_complex {1,5};
  std::cout << "\nComplex number: " << mod_complex;
  int real {3}; double number {7.5};
  Complex real_and_complex = mod_complex * real;
  std::cout << "Complex number * real(3): " << real_and_complex;
  Complex number_and_complex = mod_complex * number;
  std::cout << "Complex number * number(7.5): " << number_and_complex;
  return 0;
}