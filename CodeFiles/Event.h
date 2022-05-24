#pragma once

#include <vector>
#include <iostream>

#include "User.h"
#include "Times.h"
#include "TimeSlot.h"
#include "Date.h"

class Event
{
public:

  //methods

  Event() = default;
  Event(const std::vector<User> &users, const std::vector<TimeSlot> &slots, const Date & date)
    : m_Users(users), m_TimeSlots(slots), m_Date(date) { }

  template<class Archive>
  void serialize(Archive & ar)
  {
    ar(m_Users, m_TimeSlots, m_Date);
  }

  friend std::ostream& operator << (std::ostream & out, const Event & event);
  friend std::istream& operator >> (std::istream & in, Event & event);

private:

  std::vector<User> m_Users;
  std::vector<TimeSlot> m_TimeSlots;
  Date m_Date;

};
