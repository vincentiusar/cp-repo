#include "testlib.h"
#include <iostream>
using namespace std;

int main(int argc,char* argv[]) {
  registerInteraction(argc, argv);
  long double jurysAnswer = ans.readReal();
  long double participantsAnswer = ouf.readReal();

  long double EPS = 1e-4;
  if (abs(jurysAnswer - participantsAnswer) <= EPS) {
    quitf(_ok, "Correct");
  } else {
    quitf(_wa, "Wrong");
  }
}