#ifndef DFA_H
#define DFA_H

#include <vector>
#include <map>
using namespace std;

class DFA {
 public:
  DFA();
  ~DFA();
  void addState(int num, bool start, bool accepting);
  void addTransition(int start, int end, char c);
  pair<int, bool> transition(char c);
  bool end();
 private:
  int currentState;
  map<int, bool> states;
  map<int, map<char, int>> transitions;
};

#endif
