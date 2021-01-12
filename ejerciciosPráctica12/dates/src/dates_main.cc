/**
* Universidad de La Laguna
* Escuela Superior de Ingeniería y Tecnología
* Grado en Ingeniería Informática
* Informática Básica
*
* @file dates_main.cc
* @author Daniel Méndez alu0101391793@ull.edu.es
* @date 9 Enero 2021
* @brief Desarrolle una clase Fecha que permita representar y gestionar fechas. Incorpore en la clase los 
*        miembros de datos y métodos que considere adecuados para la finalidad que se persigue en este ejercicio. 
*        Incluya un método que permita determinar si el año correspondiente a una fecha es un año bisiesto o no. 
*        Realice un programa cliente fechas.cc que tome como parámetros dos nombres de ficheros correspondientes 
*        a sendos ficheros de texto. El programa deberá imprimir en el fichero de salida (segundo parámetro) todas 
*        las fechas que se encuentran en el fichero de entrada pero escritas en orden ascendente cronológicamente. 
* @bug No hay bugs conocidos.
* @see https://github.com/ULL-ESIT-IB-2020-2021/IB-P12-Classes-GTests-Exercism.git
* @see https://github.com/danielmdzrgz/IB-P12-IntroduccionALaOOP.Clases.GTest.Exercism.git
*/

#include <iostream>
#include <string>
#include <vector>

#include "dates.h"

int main(int argc, char* argv[]) {
  Usage(argc, argv);
  const std::string kInputFile {argv[1]};
  const std::string kOutputFile {argv[2]};
  Date date;
  std::vector<Date> sorted_dates = date.sortDatesVector(kInputFile);
  date.outputFilePrint(kInputFile, kOutputFile, date);
  return 0;
}