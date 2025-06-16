#include <iostream>
using namespace std;

int encontrarMayor(int arr[], int tamaño) {
    int mayor = arr[0];

    // Recorrer desde el segundo elemento
    for (int i = 1; i < tamaño; i++) {
        if (arr[i] > mayor) {
            mayor = arr[i];
        }
    }
    
    return mayor;
}

int main() {
    int numeros[] = {15, 8, 23, 42, 16, 4, 35, 12};
    
    // Calcular el tamaño del array
    int tamaño = sizeof(numeros) / sizeof(numeros[0]);

    int numeroMayor = encontrarMayor(numeros, tamaño);

    cout << "El número mayor es: " << numeroMayor << endl;
    
    return 0;
}
