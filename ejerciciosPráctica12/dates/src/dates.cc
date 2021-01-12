/**
* Universidad de La Laguna
* Escuela Superior de Ingeniería y Tecnología
* Grado en Ingeniería Informática
* Asignatura: Informática Básica
* Curso: 1º
*
* @brief dates_main.cc functions and classes definition
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>

#include "dates.h"

/**
* It is not a function.
* A string used in the next function when a certain parameter is introduced. 
*/

const std::string kHelpText {
"dates -- Date management.\n\
Usage: ./dates input_file.txt output_file.txt\n\
\n\
input_file.txt:      File with all the dates that will be sorted with the form: dd/mm/yyyy\n\
output_file.txt:     File with the dates sorted chronologically\n"
};

/**
* Assures the program can function correctly with the exact number of parameters
* and shows a help text y the parameter '--help' is introduced, in which an extense
* explanation of the functioning and introduction of parameters is held.
*
* @param argc, number of parameters introduced by command line.
* @param argv, values of those parameters.
* @return It is a void function so it does not return nothing.
*/

void Usage(int argc, char *argv[]) {
  if((argc == 2) && (strcmp(argv[1], "--help") == 0)) {
    std::cout << kHelpText;
    exit(EXIT_SUCCESS);
  }
  else if(argc != 3) {
    std::cout << 
    "dates -- Date management\n\
Usage: ./dates input_file.txt output_file.txt\n\
Try './dates --help' for more information.\n";
    exit(EXIT_SUCCESS);
  }
}

/**
* Definition of a function from Date class that reads the kInputFile file and collects all dates with the form 
* dd/mm/yyyy in a Date vector.
*
* @param kInputFile, string with the name of the file in which are located the dates.
* @return A Date class vector with all the dates in the kInputFile file.
*/

std::vector<Date> InputFileVector(std::string kInputFile) {
  std::ifstream input_file(kInputFile, std::ios_base::in);
  std::vector<Date> dates_to_sort;
  int day, month, year;
  char slash {'/'};
  while(input_file) {
    int i = 0;
    if(input_file >> day >> slash >> month >> slash >> year) {
      Date date[i];
      date[i].day_ = day;
      date[i].month_ = month;
      date[i].year_ = year;
      dates_to_sort.emplace_back(date[i]);
    }
    ++i;
  }
  return dates_to_sort;
}

/**
* Definition of a function from Date class that sorts chronogically a Date vctor using 
* the overloaded '<' operator.
*
* @param kInputFile, string with the name of the file in which are located the dates.
* @return A Date class vector with all the dates from the kInputFile file sorted.
*/

std::vector<Date> Date::sortDatesVector(std::string kInputFile) {
  std::vector<Date> dates_to_sort = InputFileVector(kInputFile);
  std::sort(dates_to_sort.begin(), dates_to_sort.end());
  std::vector<Date> sorted_dates = dates_to_sort;
  return sorted_dates;
}

/**
* Definition of a function from Date class that determines and returns wether a date's year is
* a leap year or not in a string.
*
* @param ## There is no parameter.
* @return A string whith wehter a year is a leap year or not.
*/

std::string Date::leapYear() {
  std::string leap_year {"This is not a leap year"};
  if((year_ % 4) == 0) {
    if(year_ % 100 == 0) {
      if(year_ % 400 == 0) {leap_year = "This is a leap year"; return leap_year;}
      else {return leap_year;}
    }
    else {leap_year = "This is a leap year"; return leap_year;}
  }
  else {return leap_year;}
  return leap_year;
}

/**
* Definition of a function from Date class that writes in a kOutputFileName the kNumberOfDates after user's date
* which have a time lapse of a day.
*
* @param kOutputFileName, string with the name of the file where the dates will be written.
* @param kNumberOfDates, number of dates with a time lapse of 1 day after user's date written on output file.
* @return It is a void function so it doesn't return nothing.
*/

void Date::outputFilePrint(std::string kInputFile, std::string kOutputFile, Date date) {
  std::ofstream output_file(kOutputFile, std::ios_base::out);
  std::vector<Date> sorted_dates = date.sortDatesVector(kInputFile);
  for(Date date : sorted_dates) {
    std::string leap_year = date.leapYear(); 
    output_file << date << " --- " << leap_year << "\n";
  }
}

/**
* A function that overloads the '<' operator.
* 
* @param date_1, constant reference to an object from Date class.
* @param date_2, the same as date_1.
* @returns True or false after comparing the objects to see if date_1 < date_2.
*/

bool operator< (const Date &date_1, const Date &date_2) {
  if(date_1.year_ < date_2.year_) {return 1;}
  else if(date_1.year_ > date_2.year_) {return 0;}
  else if(date_1.year_ == date_2.year_) {
    if(date_1.month_ < date_2.month_) {return 1;}
    else if(date_1.month_ > date_2.month_) {return 0;}
    else if(date_1.month_ == date_2.month_) {
      if(date_1.day_ < date_2.day_) {return 1;}
      else if(date_1.day_ > date_2.day_) {return 0;}
      else if(date_1.day_ == date_2.day_) {
        std::cerr << "ERROR: Error in comparison between 2 Date class objects.\n\
--- Both objects are equal ---\n\
Do not use the comparison ('<') operator with 2 equal objects.\n";
        exit(EXIT_SUCCESS);
      }
    }
  }
  return 1;
}

/**
* A function that overloads the '<<' operator to allow printing an object from Date class.
* 
* @param cout, constant reference to an object from std::ostream.
* @param date_object, constant reference to an object from Date class.
* @returns An object from std::ostream which allows to print an object from Date class.
*/

std::ostream& operator<< (std::ostream &cout, const Date &date_object) {
  cout << date_object.day_ << "/" << date_object.month_ << "/" << date_object.year_;
  return cout;
}