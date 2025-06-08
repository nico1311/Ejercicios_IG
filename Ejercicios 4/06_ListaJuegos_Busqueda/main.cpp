#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

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
        cout << "4. Buscar un juego" << endl;
        cout << "5. Salir" << endl;
        cout << "========================" << endl;
        cout << "Seleccione una opción (1-5): ";

        int opcion = 0;
        cin >> opcion;

        // Validación de entrada
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nError: Debe ingresar un número válido.\n"
                 << endl;
            continue;
        }

        if (opcion < 1 || opcion > 5)
        {
            cout << "\nError: Opción incorrecta. Seleccione 1-5.\n"
                 << endl;
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
            if (juegos.empty())
            {
                cout << "\nNo hay juegos para buscar." << endl;
                break;
            }

            cout << "\nIngrese el nombre del juego a buscar: ";
            string juegoABuscar;
            cin.ignore(1000, '\n');
            getline(cin, juegoABuscar);

            if (juegoABuscar.empty())
            {
                cout << "Error: Debe ingresar un nombre válido." << endl;
                break;
            }

            // Convertir el string ingresdo a minúsculas
            string juegoABuscarLower = juegoABuscar;
            transform(juegoABuscarLower.begin(), juegoABuscarLower.end(), juegoABuscarLower.begin(), ::tolower);
            bool encontrado = false;

            for (iter = juegos.begin(); iter != juegos.end(); ++iter)
            {
                // Convertir cada juego a minúsculas para la comparación
                string juegoActualLower = *iter;
                transform(juegoActualLower.begin(), juegoActualLower.end(), juegoActualLower.begin(), ::tolower);

                // Buscar coincidencias
                if (juegoActualLower.find(juegoABuscarLower) != string::npos)
                {
                    cout << "Juego encontrado: " << *iter << endl;
                    encontrado = true;
                }
            }

            if (!encontrado)
            {
                cout << "No se encontraron juegos que coincidan con '" << juegoABuscar << "'." << endl;
            }

            break;
        }

        case 5:
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
