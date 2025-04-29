#include <iostream>
using namespace std;

int main() {
  cout << "Múltiplos de 6 del 6 al 30:" << endl;

  for (int i = 6; i <= 30; i += 6) {
      cout << i;
      if (i < 30) cout << ", ";
  }

  cout << endl;
  return 0;
}
