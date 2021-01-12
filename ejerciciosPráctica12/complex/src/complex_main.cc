/**
* Universidad de La Laguna
* Escuela Superior de Ingeniería y Tecnología
* Grado en Ingeniería Informática
* Informática Básica
*
* @file complex_main.cc
* @author Daniel Méndez alu0101391793@ull.edu.es
* @date 10 Enero 2021
* @brief Desarrolle un programa cliente que permita operar con números complejos y haga uso de la clase Complejo que diseñe. 
*        La clase Complejo ha de contener al menos métodos que permitan (print()) imprimir un número complejo así como sumar 
*        (Add()) y restar (Sub()) números complejos.Incluya (discrecionalmente) cualesquiera otras operaciones que considere 
*        adecuadas como métodos en la clase Complejo.
* @bug No hay bugs conocidos.
* @see https://github.com/ULL-ESIT-IB-2020-2021/IB-P12-Classes-GTests-Exercism.git
* @see https://github.com/danielmdzrgz/IB-P12-IntroduccionALaOOP.Clases.GTest.Exercism.git
*/

#include <iostream>

#include "complex.h"

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
  return 0;
}