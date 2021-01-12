#ifndef DATES_H
#define DATES_H

/**
* Universidad de La Laguna
* Escuela Superior de Ingeniería y Tecnología
* Grado en Ingeniería Informática
* Asignatura: Informática Básica
* Curso: 1º
*
* @brief dates_main.cc functions and classes declaration
*/

#include <string>
#include <vector>

void Usage(int argc, char *argv[]);

class Date {
 private:
  int day_ {0}, month_ {0}, year_ {0};
 public:
  Date(const int& day = 0, const int& month = 0, const int& year = 0) : day_ {day}, month_ {month}, year_ {year} {}
  friend std::vector<Date> InputFileVector(std::string kInputFile);
  std::vector<Date> sortDatesVector(std::string kInputFile);
  std::string leapYear();
  void outputFilePrint(std::string kInputFile, std::string kOutputFile, Date date);
  friend bool operator< (const Date &date_1, const Date &date_2);
  friend std::ostream& operator<< (std::ostream &cout, const Date &date_object);
};

#endif