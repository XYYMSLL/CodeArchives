#pragma once

#include <istream>
#include <ostream>
#include <iomanip>
#include <string>

class Time
{
public:

  Time() = default;
  ~Time() = default;

  Time(int h, int m) : m_Hour(h), m_Minute(m) { }

  friend std::ostream& operator << (std::ostream & out, const Time & time);
  friend std::istream& operator >> (std::istream & in, Time & time);

  bool operator == (const Time & time);
  bool operator < (const Time & time);
  bool operator > (const Time & time);
  bool operator <= (const Time &time);
  bool operator >= (const Time & time);

  template<class Archive>
  void serialize(Archive & ar)
  {
    ar(m_Hour, m_Minute);
  }

private:

  int m_Hour = 0;
  int m_Minute = 0;

};
