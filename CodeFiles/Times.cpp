#include "Times.h"

std::ostream& operator << (std::ostream & out, const Time & time)
{
  out << std::setw(2) << std::setfill('0') << std::right << time.m_Hour << "::"
    << std::setw(2) << std::setfill('0') << std::right << time.m_Minute;
  return out;
}

std::istream& operator >> (std::istream & in, Time & time)
{
  /*
  Assume user enters time like:
  HH:MM
  */
  try
  {
    std::string hourString, minuteString;

    std::getline(in, hourString, ':');
    std::getline(in, minuteString, '\n');

    time.m_Hour = std::stoi(hourString);
    time.m_Minute = std::stoi(minuteString);
  }
  catch (const std::exception &)
  {
    throw std::runtime_error("Error reading time from input (be sure it is formatted HH:MM)");
  }

  /*
  Now you can validate that a valid time was entered
  */

  if (time.m_Hour < 0 || time.m_Hour > 24 || time.m_Minute < 0 || time.m_Minute > 59)
    throw std::runtime_error("Time entered is invalid. Enter hours 0-24 and mintues 0-59");

  return in;
}

bool Time::operator == (const Time & time)
{
  return ((m_Hour == time.m_Hour) && (m_Minute == time.m_Minute));
}

bool Time::operator < (const Time & time)
{
  return ((m_Hour < time.m_Hour) || (m_Minute < time.m_Minute));
}

bool Time::operator > (const Time & time)
{
  return ((m_Hour > time.m_Hour) || (m_Minute > time.m_Minute));
}

bool Time::operator <= (const Time &time)
{
  return ((m_Hour <= time.m_Hour) || (m_Minute <= time.m_Minute));
}

bool Time::operator >= (const Time & time)
{
  return ((m_Hour >= time.m_Hour) || (m_Minute >= time.m_Minute));
}
