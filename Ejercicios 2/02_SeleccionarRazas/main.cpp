#include <iostream>
using namespace std;

enum Raza {
    HUMANOS = 1,
    ELFOS,
    GNOMOS,
    ENANOS,
    SEMIORCOS
};

int main() {
    int opcion;

    cout << "Seleccione una raza:" << endl;
    cout << "1. Humanos" << endl;
    cout << "2. Elfos" << endl;
    cout << "3. Gnomos" << endl;
    cout << "4. Enanos" << endl;
    cout << "5. Semiorcos" << endl;
    cout << "Ingrese un número: ";
    cin >> opcion;

    cout << endl;

    switch (opcion) {
        case HUMANOS:
            cout << "Raza: Humanos" << endl;
            cout << "Los humanos constituyen la raza predominante en Faerun." << endl;
            cout << "Gobiernan la mayoría de los reinos e imperios más importantes en los Reinos Olvidados." << endl;
            break;
        case ELFOS:
            cout << "Raza: Elfos" << endl;
            cout << "Los elfos son normalmente más bajos y delgados que los humanos." << endl;
            cout << "Sus rasgos son finos y delicados, hablan con entonación melódica." << endl;
            cout << "Se les considera frívolos y distantes." << endl;
            break;
        case GNOMOS:
            cout << "Raza: Gnomos" << endl;
            cout << "Emparentados con los enanos, los gnomos son significativamente más pequeños que sus primos lejanos." << endl;
            cout << "Los gnomos, como ellos mismos sostienen con orgullo, son también menos rechonchos que los enanos." << endl;
            break;
        case ENANOS:
            cout << "Raza: Enanos" << endl;
            cout << "Los enanos son unos individuos pequeños y robustos, fácilmente reconocibles por su forma y estatura." << endl;
            cout << "Tienen los mofletes rosados y los ojos y el cabello oscuros. Los enanos tienden a ser ariscos." << endl;
            break;
        case SEMIORCOS:
            cout << "Raza: Semiorcos" << endl;
            cout << "Estos individuos, famosos por su gran fuerza, son el fruto de la unión de un progenitor humano y otro orco." << endl;
            cout << "Poseen la misma estatura que los humanos, pero pesan algo más debido a su complexión musculosa." << endl;
            break;
        default:
            cout << "Opción no válida, ingrese un número entre 1 y 5." << endl;
    }

    return 0;
}
