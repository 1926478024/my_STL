CXX       :=  g++
CXXFLAGS  :=  -std=c++11
TARGET    :=  main
SRCS      :=  main.cpp

all:$(TARGET)

$(TARGET):$(SRCS) Vector.h
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET) Vector
run:$(TARGET)
	./$(TARGET)

.PHONY:all clean run
