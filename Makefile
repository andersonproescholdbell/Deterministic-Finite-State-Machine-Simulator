# Anderson Proescholdbell

CXX = clang++
CXXFLAGS = -g -Wall
OBJECTS = main.o DFA.o

a.out: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o a.out
	@echo "Compiled!"

main.o: main.cpp DFA.h
DFA.o: DFA.cpp DFA.h


.PHONY: clean
clean:
	-rm -f *.o *~ a.out
