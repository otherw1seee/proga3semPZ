CXX = g++
CXXFLAGS = -std=c++17 -O2 -fexec-charset=UTF-8
TARGET = main
SOURCES = main.cpp DynamicArray.cpp 
OBJECTS = $(SOURCES:.cpp=.o)

all:$(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -rf *.o main