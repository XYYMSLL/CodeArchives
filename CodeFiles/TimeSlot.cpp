#include "TimeSlot.h"

std::ostream& operator << (std::ostream & out, const TimeSlot & slot)
{
  out << slot.m_StartingTime << " - " << slot.m_EndingTime;
  return out;
}

std::istream& operator >> (std::istream & in, TimeSlot & slot)
{
  try
  {
    in >> slot.m_StartingTime >> slot.m_EndingTime;
    return in;
  }
  catch (const std::exception &exc)
  {
    std::string err(exc.what());
    throw std::runtime_error("Error reading TimeSlot: " + err);
  }
}

bool TimeSlot::operator == (const TimeSlot & slot)
{
  return ((m_StartingTime == slot.m_StartingTime) && (m_EndingTime == slot.m_EndingTime));
}
