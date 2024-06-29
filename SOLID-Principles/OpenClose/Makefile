CXX = g++

CXXFLAGS = -Wall -std=c++20

DFLAGS = -g

TARGET = ocp.exe

SRCS = main.cpp

OBJS = $(SRCS: %.cpp = %.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	@echo -------------------------------------------------------
	@echo building $@ ...
	$(CXX) $(CXXFLAGS) $(DFLAGS) -o $@ $^
	@echo $@ built!
	@echo -------------------------------------------------------

clean:
	@echo -------------------------------------------------------
	@echo cleaning
	-rm -rf *.o
	-rm -rf $(TARGET)
	-rm -rf *~
	@echo Project cleaned!
	@echo -------------------------------------------------------