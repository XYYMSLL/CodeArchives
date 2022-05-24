#include "Date.h"

bool operator>=(const Date & date1, const Date & date2)
{
  return
    (
      ( date1.m_Year  >= date2.m_Year  ) ||
      ( date1.m_Month >= date2.m_Month ) ||
      ( date1.m_Day   >= date2.m_Day   )
    );
}

bool operator<=(const Date & date1, const Date & date2)
{
  return
    (
      ( date1.m_Year  <= date2.m_Year  ) ||
      ( date1.m_Month <= date2.m_Month ) ||
      ( date1.m_Day   <= date2.m_Day   )
    );
}

bool operator>(const Date & date1, const Date & date2)
{
  return
    (
      ( date1.m_Year  > date2.m_Year  ) ||
      ( date1.m_Month > date2.m_Month ) ||
      ( date1.m_Day   > date2.m_Day   )
    );
}

bool operator<(const Date & date1, const Date & date2)
{
  return
    (
      ( date1.m_Year  < date2.m_Year  ) ||
      ( date1.m_Month < date2.m_Month ) ||
      ( date1.m_Day   < date2.m_Day   )
    );
}

bool operator==(const Date & date1, const Date & date2)
{
  return
    (
      ( date1.m_Year  == date2.m_Year  ) &&
      ( date1.m_Month == date2.m_Month ) &&
      ( date1.m_Day   == date2.m_Day   )
    );
}

std::istream& operator>>(std::istream & in, Date & date)
{
  /*
    For this example, dates are read as MM DD YYYY (separated by spaces)
  */

  if (!(in >> date.m_Month >> date.m_Day >> date.m_Year) || !date.ValidateDate())
  {
    date.m_Month = date.m_Year = date.m_Day = 0;
    throw std::runtime_error("Invalid date entered");
  }

  return in;
}

std::ostream& operator<<(std::ostream & out, const Date & date)
{
  /*
    In this case, dates will print out like MM/DD/YYYY
  */
  out << date.m_Month << "/" << date.m_Day << "/" << date.m_Year;
  return out;
}

Date::Date(const Date &d) : m_Day(d.m_Day), m_Month(d.m_Month), m_Year(d.m_Year)
{

}

Date::Date(int year, int mon, int day) : m_Year(year), m_Month(mon), m_Day(day)
{

}

int Date::Month() const
{
  return m_Month;
}

int Date::Year() const
{
  return m_Year;
}

int Date::Day() const
{
  return m_Day;
}

bool Date::ValidateDate()
{
  return
    (
      ( m_Month > 0 && m_Month < 13) &&
      ( m_Day   > 0 && m_Day   < 32) &&
      ( m_Year  > 2017)
    );
}
