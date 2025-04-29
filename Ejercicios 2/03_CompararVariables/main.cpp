#include <iostream>
using namespace std;

int main() {
  int x = 0, y = 0;

  cout << "Ingrese un valor entero para x: ";
  cin >> x;

  cout << "Ingrese un valor entero para y: ";
  cin >> y;

  if (x > y) {
      cout << "La variable x es mayor." << endl;
  } else if (y > x) {
      cout << "La variable y es mayor." << endl;
  } else {
      cout << "Los valores son iguales." << endl;
  }

  return 0;
}
