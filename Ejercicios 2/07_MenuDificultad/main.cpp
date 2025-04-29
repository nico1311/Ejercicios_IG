#include <iostream>
using namespace std;


enum Dificultad {
    FACIL = 1,
    NORMAL,
    DIFICIL
};

int main()
{
    bool correcto = false;
    unsigned short int numero;

    while (!correcto)
    {
        system("clear");

        cout << "Nivel de dificultad\n\n";
        cout << "1 - Fácil\n";
        cout << "2 - Normal\n";
        cout << "3 - Difícil\n\n";

        cout << "Ingrese Opción: ";
        cin >> numero;

        switch (numero)
        {
        case FACIL:
            cout << "Seleccionó nivel Fácil." << endl;
            correcto = true;
            break;
        case NORMAL:
            cout << "Seleccionó nivel Normal." << endl;
            correcto = true;
            break;
        case DIFICIL:
            cout << "Seleccionó nivel Difícil." << endl;
            correcto = true;
            break;
        default:
            cout << "¡Opción incorrecta!\n" << endl;
            cout << "Presione ENTER para continuar..." << endl;
            cin.ignore().get();
            correcto = false;
            break;
        }
    }

    cout << "\n¡Arrancamos el juego con la dificultad seleccionada!" << endl;
    return 0;
}
