#include <iostream>
#include <vector>
#include <cmath>
#include <random>

using namespace std;

struct Punto {
    int x, y;
};

// Función para calcular la distancia entre dos puntos
double distancia(const Punto& p1, const Punto& p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

// Función para calcular la longitud total de un trazo que pasa por los puntos dados
double calcularLongitudCamino(const vector<Punto>& puntos) {
    double longitudTotal = 0.0;
    for (size_t i = 0; i < puntos.size() - 1; ++i) {
        longitudTotal += distancia(puntos[i], puntos[i + 1]);
    }
    return longitudTotal;
}

// Algoritmo para encontrar el trazo más corto  (minDrawing)
void trazoMinimo(vector<Punto>& P, int maxIteraciones) {
    double longitudActual = calcularLongitudCamino(P);

    
    random_device rd; // Generador de números aleatorios
    mt19937 gen(rd());
    uniform_int_distribution<size_t> distribucion(0, P.size() - 1);

    for (int iter = 0; iter < maxIteraciones; ++iter) {
        size_t idx1 = distribucion(gen); 
        size_t idx2 = distribucion(gen);

        if (idx1 != idx2) { // Evitar intercambio de un punto consigo mismo
            swap(P[idx1], P[idx2]); // Intercambiar los puntos
            double nuevaLongitud = calcularLongitudCamino(P); // Calcular longitud del trazo con nueva ordenación

            if (nuevaLongitud < longitudActual) {
                longitudActual = nuevaLongitud; // Actualizar longitud si es más corta (avaro)
            } else {
                swap(P[idx1], P[idx2]);  // Revertir el intercambio si no mejora la longitud
            }
        }
    }
}

int main() {
    vector<Punto> puntos = {{20, 20}, {20, 40}, {20, 160}, {30, 120}, {40, 140}, {40, 150}, {50, 20}, {60, 40}, 
    {60, 80}, {60, 200}, {70, 200}, {80, 150}, {90, 170}, {90, 170}, {100, 50}, {100, 40}, {100, 130}, {100, 150}, 
    {110, 10}, {110, 70}, {20, 80}, {130, 70}, {130, 170}, {140, 140}, {140, 180}, {150, 50}, {160, 20}, {170, 100}, 
    {180, 70}, {180, 200}, {200, 30}, {200, 70}, {200, 100}}; // Puntos iniciales
    
    int maxIteraciones = 10000; // Número máximo de iteraciones

    cout << "Orden original de los puntos:" << endl;
    for (const Punto& p : puntos) {
        cout << "(" << p.x << ", " << p.y << ") ";
    }

    trazoMinimo(puntos, maxIteraciones); 

    cout << "\nOrden mas corto:" << endl;
    for (const Punto& p : puntos) {
        cout << "(" << p.x << ", " << p.y << ") ";
    }

    return 0;
}