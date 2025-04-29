#include <iostream>
using namespace std;

int main() {
  int suma = 0;

  for (int i = 1; i <= 10; i++) {
      suma += i;
  }

  cout << "La suma de los números del 1 al 10 es: " << suma << endl;
  return 0;
}
