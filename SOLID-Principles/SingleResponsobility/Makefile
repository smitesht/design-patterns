
CXX = g++

CXXFLAGS = -Wall -std=c++20

DFLAGS = -g

TARGET = srp.exe

SRCS = main.cpp

OBJS = $(SRCS:%.cpp=%.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	@echo ---------------------------------------------------------
	@echo building $@ ....
	$(CXX) $(CXXFLAGS) $(DFLAGS) -o $@ $^
	@echo $@ built!
	@echo ---------------------------------------------------------

clean:
	@echo ---------------------------------------------------------
	@echo cleaning
	-rm -rf *.o
	-rm $(TARGET)
	-rm -f *~
	@echo Project cleaned!
	@echo ---------------------------------------------------------