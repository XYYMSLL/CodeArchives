#include <fstream>#include "cereal/cereal.hpp"#include "cereal/archives/portable_binary.hpp"
#include "cereal/types/vector.hpp"
#include "cereal/types/string.hpp"

#include "Date.h"
#include "Times.h"
#include "User.h"
#include "TimeSlot.h"
#include "Event.h"int main(){  Event event1, event2;  std::ifstream infile("events.obj");
  {
    cereal::PortableBinaryInputArchive archive(infile);    archive(event1, event2);  }  infile.close();
  std::cout << event1 << "\n" << event2 << "\n";

  return 0;
}
