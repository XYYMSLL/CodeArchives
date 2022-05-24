#pragma once

#include <iostream>
#include <string>

#include "Times.h"

class TimeSlot
{
public:

  TimeSlot() = default;
  ~TimeSlot() = default;

  TimeSlot(const Time &s, const Time &e) : m_StartingTime(s), m_EndingTime(e) { }

  friend std::ostream& operator << (std::ostream & out, const TimeSlot & slot);
  friend std::istream& operator >> (std::istream & in, TimeSlot & slot);
  bool operator == (const TimeSlot & slot);

  template<class Archive>
  void serialize(Archive & ar)
  {
    ar(m_StartingTime, m_EndingTime);
  }

private:

  Time m_StartingTime;
  Time m_EndingTime;

};
