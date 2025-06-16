#include <iostream>
using namespace std;

string invertirCadena(string cadena) {
    string resultado = "";

    // Recorrer la cadena como un array de caracteres
    for (int i = cadena.length() - 1; i >= 0; i--) {
        resultado += cadena[i];
    }

    return resultado;
}

int main() {
    string cadena = "Hola Mundo";
    cout << "La cadena original es: " << cadena << endl;

    string cadenaInvertida = invertirCadena(cadena);
    cout << "La cadena invertida es: " << cadenaInvertida << endl;

    return 0;
}
