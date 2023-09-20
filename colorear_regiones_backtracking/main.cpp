// Emilio Berber Maldonado 
// A01640603
// Backtracking -- Ejercicio de colorar regiones

#include <iostream>
#include <vector>
using namespace std;

const int numRegiones = 11;
const int numColores = 4;
const string regiones[numRegiones] = {"Mark", "Julia", "Brian", "Steve", "Amanda", "Derek", "Kelly", "Allan", "Michelle", "Joanne", "Chris"};

vector<vector<bool>> adyacencias(numRegiones, vector<bool>(numRegiones, false));
vector<int> colores(numRegiones, -1);
int solucionesEncontradas = 0;

// Función para verificar si se puede pintar una región 
bool pintarTrue(int region, int color) {
    for (int i = 0; i < numRegiones; i++) {
        if (adyacencias[region][i] && colores[i] == color) {
            return false;
        }
    }
    return true;
}

// Función para encontrar las posibles soluciones de pintar 
void pintarRegiones(int region) {
    if (region == numRegiones) {
        // Hemos pintado todas las regiones, mostramos la solución
        cout << "Posibilidad " << ++solucionesEncontradas << ": ";
        for (int i = 0; i < numRegiones; i++) {
            cout << regiones[i] << ": ";
            switch (colores[i]) {
                case 0: cout << "Rojo "; break;
                case 1: cout << "Verde "; break;
                case 2: cout << "Azul "; break;
                case 3: cout << "Gris "; break;
            }
        }
        cout << endl;
        return;
    }

    for (int color = 0; color < numColores; color++) {
        if (pintarTrue(region, color)) {
            colores[region] = color;
            pintarRegiones(region + 1);
            colores[region] = -1; // BACKTRACKING
        }
    }
}

int main() {
    // Se crea una matriz de adyacencias para determinar cuales estan juntas 
    adyacencias[0][1] = adyacencias[1][0] = true;
    adyacencias[0][3] = adyacencias[3][0] = true;
    adyacencias[0][4] = adyacencias[4][0] = true;
    adyacencias[1][2] = adyacencias[2][1] = true;
    adyacencias[1][4] = adyacencias[4][1] = true;
    adyacencias[2][4] = adyacencias[4][2] = true;
    adyacencias[3][5] = adyacencias[5][3] = true;
    adyacencias[3][6] = adyacencias[6][3] = true;
    adyacencias[4][7] = adyacencias[7][4] = true;
    adyacencias[5][8] = adyacencias[8][5] = true;
    adyacencias[6][7] = adyacencias[7][6] = true;
    adyacencias[6][9] = adyacencias[9][6] = true;
    adyacencias[7][8] = adyacencias[8][7] = true;
    adyacencias[7][10] = adyacencias[10][7] = true;
    adyacencias[8][10] = adyacencias[10][8] = true;
    adyacencias[9][10] = adyacencias[10][9] = true;

    pintarRegiones(0);

    cout << "Total de soluciones validas encontradas: " << solucionesEncontradas << endl;

    return 0;
}
