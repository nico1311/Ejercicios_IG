/*************************************************************************\
 Juego de Ordenar las Letras
 El sistema muestra la palabra desordenada y el jugador tiene que
 deducirla. Con la palabra "ayuda" el sistema da una pista.
\*************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Constantes enumeradas:
// La primer columna tiene la palabra para adivinar.
// La segunda columna tiene la pista.
// El tercer valor guarda la cantidad de columnas (2).
// Recordar que esto sería equivalente a usar tres constantes:
// const int PALABRA = 0;
// const int AYUDA = 1;
// const int CANTIDAD_COLUMNAS = 2;
enum columnas
{
  PALABRA,
  AYUDA,
  CANTIDAD_COLUMNAS
};

const int CANTIDAD_PALABRAS = 5;
const int PUNTOS_BASE = 100;       // Puntos base por adivinar una palabra
const int PUNTOS_POR_LETRA = 20;   // Puntos adicionales por cada letra
const int PENALIZACION_AYUDA = 30; // Puntos que se restan al usar ayuda

// Matriz de 5 filas por 2 columnas PALABRAS[5][2]
string PALABRAS[CANTIDAD_PALABRAS][CANTIDAD_COLUMNAS] =
    {
        {"pared", "¿Sentís como si te estuvieses dando la cabeza contra algo?"},
        {"anteojos", "Pueden ayudarte a ver la solución."},
        {"aburrido", "Un juego no debería serlo."},
        {"perseverar", "Importante para triunfar."},
        {"ordenar", "Es de lo que se trata el juego."}};

int main()
{
  srand(time(0));

  int puntajeTotal = 0;
  int puntajeRonda = 0;
  int intentos = 0;
  int ayudasUsadas = 0;
  bool jugarDeNuevo = true;

  cout << "\t\t\tBienvenido al juego del orden!\n\n";
  cout << "Descubre la palabra formada por las letras desordenadas.\n";
  cout << "Escribe 'ayuda' para obtener una pista.\n";
  cout << "Escribe 'salir' para salir del juego.\n\n";

  while (jugarDeNuevo)
  {
    int eleccion = (rand() % CANTIDAD_PALABRAS);

    // Obtiene de la matriz la palabra que hay que adivinar.
    // La posición es fila 'eleccion' y columna 0 [ PALABRA ].
    string laPalabra = PALABRAS[eleccion][PALABRA];

    // La ayuda para adivinar la palabra está en la posición fila
    // 'eleccion' y columna 1 [ AYUDA ].
    string laAyuda = PALABRAS[eleccion][AYUDA];

    // Guardamos la palabra que luego vamos a desordenar.
    string palabraDesordenada = laPalabra;

    int cantidadCaracteresPalabra = palabraDesordenada.size();

    // Calcular el puntaje máximo posible para esta palabra
    puntajeRonda = PUNTOS_BASE + (cantidadCaracteresPalabra * PUNTOS_POR_LETRA);
    ayudasUsadas = 0;
    intentos = 0;

    // Desordenamos la palabra intercambiando de a dos caracteres.
    for (int i = 0; i < cantidadCaracteresPalabra * 2; i++)
    {
      // Elegimos dos posiciones de caracteres al azar.
      int index1 = (rand() % cantidadCaracteresPalabra);
      int index2 = (rand() % cantidadCaracteresPalabra);
      // Guardamos el primer caracter en una variable temporal.
      char auxiliar = palabraDesordenada[index1];
      // Guardamos el segundo caracter en el lugar del primero.
      palabraDesordenada[index1] = palabraDesordenada[index2];
      // Guardamos el primer caracter en el lugar del segundo.
      palabraDesordenada[index2] = auxiliar;
    }

    cout << "\n-----------------------------------------------------\n";
    cout << "La palabra desordenada es: " << palabraDesordenada << endl;
    cout << "Puntos posibles para esta palabra: " << puntajeRonda << endl;
    cout << "-----------------------------------------------------\n";

    string solucion;
    bool rondaTerminada = false;

    // Ciclo de la ronda actual
    while (!rondaTerminada)
    {
      cout << "\nTu solución: ";
      cin >> solucion;
      intentos++;

      if (solucion == laPalabra)
      {
        // Calcular puntaje final de la ronda (restando penalizaciones por ayuda)
        int puntajeFinal = puntajeRonda - (ayudasUsadas * PENALIZACION_AYUDA);
        if (puntajeFinal < 0)
          puntajeFinal = 0;

        puntajeTotal += puntajeFinal;

        cout << "\n¡Correcto! Has adivinado la palabra '" << laPalabra << "'.\n";
        cout << "Usaste " << intentos << " intentos y " << ayudasUsadas << " ayudas.\n";
        cout << "Puntos ganados en esta ronda: " << puntajeFinal << endl;
        cout << "Puntaje total acumulado: " << puntajeTotal << endl;

        rondaTerminada = true;
      }
      else if (solucion == "ayuda")
      {
        ayudasUsadas++;
        cout << "PISTA: " << laAyuda << endl;
        cout << "¡Has usado una ayuda! Se restarán " << PENALIZACION_AYUDA << " puntos.\n";
        cout << "Ayudas usadas: " << ayudasUsadas << endl;
      }
      else if (solucion == "salir")
      {
        rondaTerminada = true;
        jugarDeNuevo = false;
      }
      else
      {
        cout << "Lo lamento pero no es la solución. Sigue intentando.\n";
      }
    }

    // Preguntar si quiere jugar otra ronda
    if (jugarDeNuevo)
    {
      char respuesta;
      cout << "\n¿Quieres jugar otra ronda? (s/n): ";
      cin >> respuesta;

      if (respuesta != 's' && respuesta != 'S')
      {
        jugarDeNuevo = false;
      }
    }
  }

  cout << "\n-----------------------------------------------------\n";
  cout << "Fin del juego\n";
  cout << "Tu puntaje final es: " << puntajeTotal << endl;
  cout << "¡Gracias por jugar!\n";
  cout << "-----------------------------------------------------\n";

  return 0;
}
