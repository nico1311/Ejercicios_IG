#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    vector<string> juegos;
    vector<string>::iterator iter;
    bool mostrarMenu = true;

    // Agregar juegos de ejemplo
    juegos.push_back("The Legend of Zelda: Breath of the Wild");
    juegos.push_back("Super Mario Odyssey");

    do
    {
        cout << "\n=== GESTOR DE JUEGOS ===" << endl;
        cout << "1. Ver lista de juegos" << endl;
        cout << "2. Agregar un juego" << endl;
        cout << "3. Eliminar un juego" << endl;
        cout << "4. Salir" << endl;
        cout << "========================" << endl;
        cout << "Seleccione una opción (1-4): ";
        
        int opcion = 0;
        cin >> opcion;

        // Validación de entrada
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nError: Debe ingresar un número válido.\n" << endl;
            continue;
        }

        if (opcion < 1 || opcion > 4)
        {
            cout << "\nError: Opción incorrecta. Seleccione 1-4.\n" << endl;
            continue;
        }

        switch (opcion)
        {
        case 1:
        {
            cout << "\n=== LISTA DE JUEGOS ===" << endl;
            if (juegos.empty())
            {
                cout << "La lista está vacía." << endl;
            }
            else
            {
                cout << "Total de juegos: " << juegos.size() << endl;
                cout << "-------------------" << endl;
                size_t contador = 1;
                for (iter = juegos.begin(); iter != juegos.end(); ++iter)
                {
                    cout << contador++ << ". " << *iter << endl;
                }
            }
            break;
        }
        case 2:
        {
            cout << "\nIngrese el nombre del juego: ";
            string nuevoJuego;
            cin.ignore(1000, '\n');
            getline(cin, nuevoJuego);
            
            // Validar entrada no vacía
            if (nuevoJuego.empty())
            {
                cout << "Error: El nombre del juego no puede estar vacio." << endl;
                break;
            }
            
            // Verificar si ya existe
            if (find(juegos.begin(), juegos.end(), nuevoJuego) != juegos.end())
            {
                cout << "El juego '" << nuevoJuego << "' ya está en la lista." << endl;
            }
            else
            {
                juegos.push_back(nuevoJuego);
                cout << "Juego '" << nuevoJuego << "' agregado correctamente." << endl;
            }
            break;
        }
        case 3:
        {
            if (juegos.empty())
            {
                cout << "\nNo hay juegos para eliminar." << endl;
                break;
            }
            
            cout << "\nIngrese el nombre del juego a eliminar: ";
            string juegoAEliminar;
            cin.ignore(1000, '\n');
            getline(cin, juegoAEliminar);
            
            if (juegoAEliminar.empty())
            {
                cout << "Error: Debe ingresar un nombre válido." << endl;
                break;
            }
            
            iter = find(juegos.begin(), juegos.end(), juegoAEliminar);
            if (iter != juegos.end())
            {
                juegos.erase(iter);
                cout << "Juego '" << juegoAEliminar << "' eliminado correctamente." << endl;
            }
            else
            {
                cout << "Error: Juego '" << juegoAEliminar << "' no encontrado." << endl;
            }
            break;
        }
        case 4:
        {
            cout << "\n¡Gracias por usar el gestor de juegos!" << endl;
            mostrarMenu = false;
            break;
        }
        }

        // Pausa solo si no es salir
        if (mostrarMenu)
        {
            cout << "\nPresione Enter para volver al menú..." << endl;
            cin.ignore().get();
        }
        
    } while (mostrarMenu);

    return 0;
}
