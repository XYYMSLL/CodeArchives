#pragma once

#include <ostream>
#include <istream>
#include <iostream>
#include <string>
#include <limits>

class User
{
public:

  User() = default;
  ~User() = default;

  User(const std::string &first, const std::string &last) : m_FirstName(first), m_LastName(last) { }
  User(const User &) = default;

  friend std::ostream& operator << (std::ostream & out, const User & user);
  friend std::istream& operator >> (std::istream & in, User & user);
  friend bool operator == (const User & user1, const User & user2);

  template<class Archive>
  void serialize(Archive & ar)
  {
    ar(m_FirstName, m_LastName);
  }

private:

  std::string m_FirstName = "";
  std::string m_LastName = "";

};
