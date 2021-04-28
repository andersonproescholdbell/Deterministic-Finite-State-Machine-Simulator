#include <vector>
#include <map>
#include <unistd.h>
#include "DFA.h"
using namespace std;

DFA::DFA() {
  currentState = 0;
}

DFA::~DFA() {

}

void DFA::addState(int num, bool start, bool accepting) {
  if (start) {
    currentState = num;
  }
  states.insert(pair<int, bool>(num, accepting));
}

void DFA::addTransition(int start, int end, char c) {
  if (transitions.find(start) == transitions.end()) {
    map<char, int> m;
    m.insert(pair<char, int>(c, end));
    transitions.insert(pair<int, map<char, int>>(start, m));
  } else {
    transitions.find(start)->second.insert(pair<char, int>(c, end));
  }
}

pair<int, bool> DFA::transition(char c) {
  int state = transitions.find(currentState)->second.find(c)->second;
  bool accepting = states.find(state)->second;
  currentState = state;
  return pair<int, bool>(state, accepting);
}

bool DFA::end() {
  return states.find(currentState)->second;
}
