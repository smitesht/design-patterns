CXX = g++

CXXFLAGS = -Wall -std=c++20

DFLAGS = -g

TARGET = lsp.exe

SRCS = main.cpp

OBJS = $(SRCS: %.cpp = %.o )

all: $(TARGET)

$(TARGET): $(OBJS)
	@echo -----------------------------------------------
	@echo Building $@ ...
	$(CXX) $(CXXFLAGS) $(DFLAGS) -o $@ $^
	@echo $@ Built!
	@echo -----------------------------------------------

clean:
	@echo -----------------------------------------------
	@echo Cleaning
	-rm -rf *.o
	-rm -rf $(TARGET)
	-rm -rf *~
	@echo Project Cleaned!
	@echo -----------------------------------------------
