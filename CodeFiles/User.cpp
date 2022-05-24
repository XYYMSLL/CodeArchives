#include "User.h"

std::ostream& operator << (std::ostream & out, const User & user)
{
  /*
  For a simple example, names are just displayed as First Last
  */
  out << user.m_LastName << ", " << user.m_FirstName;
  //out << user.m_FirstName << " " << user.m_LastName;
  return out;
}

std::istream& operator >> (std::istream & in, User & user)
{
  /*
  To keep it simple, names are just read in as First Last (separated by spaces)
  */

  if (!(in >> user.m_FirstName >> user.m_LastName))
  {
    throw std::runtime_error("Invalid name entered (enter as First Last, separated by spaces)");
  }

  in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return in;
}

bool operator == (const User & user1, const User & user2)
{
  return
    (
    (user1.m_FirstName == user2.m_FirstName) &&
      (user1.m_LastName == user2.m_LastName)
      );
}
