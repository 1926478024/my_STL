CXX       :=  g++
CXXFLAGS  :=  -std=c++11
TARGET    :=  main

all:$(TARGET)

$(TARGET):main.cpp sorting.h
	$(CXX) $(CXXFLAGS) $^ -o $(TARGET)

run:$(TARGET)
	./$(TARGET)
clean:
	rm -f $(TARGET)
.PHONY:all run clean
