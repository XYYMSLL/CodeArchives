#include "Event.h"

std::ostream& operator << (std::ostream & out, const Event & event)
{
  out << "Event on: " << event.m_Date << "\nTimes:";
  for (const auto & slot : event.m_TimeSlots)
  {
    out << "\t" << slot << "\n";
  }

  out << "Attendees:\n";
  for (const auto & user : event.m_Users)
  {
    out << "\t" << user << "\n";
  }

  return out;
}

std::istream& operator >> (std::istream & in, Event & event)
{
  return in;
}
