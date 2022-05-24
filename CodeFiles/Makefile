CC=g++
CFLAGS=-c -std=c++0x -I.
LDFLAGS=
SOURCES=main.cpp Date.cpp Event.cpp Times.cpp TimeSlot.cpp User.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=example

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o
	rm example
