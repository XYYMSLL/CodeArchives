#pragma once

#include <istream>
#include <ostream>
#include <iostream>

class Date
{
public:

  Date() = default;
  ~Date() = default;

  Date(int year, int mon, int day);
  Date(const Date &d);

  /**
   *  Define operators to allow the Date
   *  class to handle its own input/output
   */

  friend std::ostream& operator << (std::ostream & out, const Date & date);

  friend std::istream& operator >> (std::istream & in, Date & date);

  int Month() const;
  int Year() const;
  int Day() const;

  friend bool operator == (const Date & date1, const Date & date2);

  friend bool operator < (const Date & date1, const Date & date2);

  friend bool operator > (const Date & date1, const Date & date2);

  friend bool operator <= (const Date & date1, const Date & date2);

  friend bool operator >= (const Date & date1, const Date & date2);

  template<class Archive>
  void serialize(Archive & ar)
  {
    ar(m_Month, m_Day, m_Year);
  }

private:

  bool ValidateDate();

  int m_Month = 0;
  int m_Day = 0;
  int m_Year = 0;

};
