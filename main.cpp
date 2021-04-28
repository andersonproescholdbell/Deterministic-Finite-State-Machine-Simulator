#include <iostream>
#include <unistd.h>
#include "DFA.h"
using namespace std;

int main(int argc, char* argv[]) {
  // create DFA here

  DFA dfa = DFA();

  // simple 3 state DFA where you can traverse anywhere
  /*dfa.addState(0, true, false);
  dfa.addState(1, false, true);
  dfa.addState(2, false, false);
  dfa.addTransition(0, 1, 'a');
  dfa.addTransition(1, 0, 'b');
  dfa.addTransition(1, 2, 'c');
  dfa.addTransition(2, 1, 'd');
  dfa.addTransition(2, 0, 'e');
  dfa.addTransition(0, 2, 'f');*/

  // example from week two where binary string must be divisible by 8 to be accepted
  dfa.addState(0, true, true);
  dfa.addState(1, false, false);
  dfa.addState(2, false, false);
  dfa.addState(3, false, false);
  dfa.addTransition(0, 0, '0');
  dfa.addTransition(0, 1, '1');
  dfa.addTransition(1, 1, '1');
  dfa.addTransition(1, 2, '0');
  dfa.addTransition(2, 1, '1');
  dfa.addTransition(2, 3, '0');
  dfa.addTransition(3, 1, '1');
  dfa.addTransition(3, 0, '0');

  // set delay
  cout << "Give a delay in ms: ";
  unsigned int delay;
  cin >> delay;
  
  // give DFA chars here
  cout << "Give a string for the DFA to process: ";
  string s;
  cin >> s;

  for (int i = 0; i < s.length(); i++) {
    pair<int, bool> p = dfa.transition(s[i]);
    if (p.second) {
      cout << "DFA processed " << s.substr(0, i+1) << " and is now in state " << to_string(p.first) << " which is an ACCEPT state." << endl;
    } else {
      cout << "DFA processed " << s.substr(0, i+1) << " and is now in state " << to_string(p.first) << " which is a REJECT state." << endl;
    }
    usleep(delay * 1000);
  }
    
  bool accepted = dfa.end();
  if (accepted) {
    cout << "The DFA ended in an ACCEPT state";
  } else {
    cout << "The DFA ended in a REJECT state";
  }
  cout << " on input " << s << endl;

  return 0;
}
