// Emilio Berber Maldonado 
// A01640603
// Programación dinámica y recursiva para problema de la varilla

#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

// Función recursiva para calcular la ganancia máxima
int gananciaMaximaRecursiva(vector<int>& precios, int n) {
    if (n <= 0) {
        return 0;
    }

    int gananciaMaxima = 0;

    for (int i = 0; i < n; i++) {
        int gananciaActual = precios[i] + gananciaMaximaRecursiva(precios, n - i - 1);
        if (gananciaActual > gananciaMaxima) {
            gananciaMaxima = gananciaActual;
        }
    }

    return gananciaMaxima;
}

// Función programación dinámica para calcular la ganancia máxima
int gananciaMaximaDinamica(vector<int>& precios, int n) {
    vector<int> ganancias(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        int gananciaMaxima = 0;
        for (int j = 0; j < i; j++) {
            int gananciaActual = precios[j] + ganancias[i - j - 1];
            if (gananciaActual > gananciaMaxima) {
                gananciaMaxima = gananciaActual;
            }
        }
        ganancias[i] = gananciaMaxima;
    }

    return ganancias[n];
}

int main() {
    vector<int> precios = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int n = 10;

    // Tiempo usando chrono para recurisva
    auto start = high_resolution_clock::now();
    int gananciaRecursiva = gananciaMaximaRecursiva(precios, n);
    auto stop = high_resolution_clock::now();
    auto durationRecursiva = duration_cast<microseconds>(stop - start);

    // Tiempo usando chrono para dinámica
    start = high_resolution_clock::now();
    int gananciaDinamica = gananciaMaximaDinamica(precios, n);
    stop = high_resolution_clock::now();
    auto durationDinamica = duration_cast<microseconds>(stop - start);

    // PRINTS
    cout <<endl<< "RECURSIVA:" <<endl;
    cout << "Ganancia maxima de longitud n : " << n << " es: " << gananciaRecursiva << endl;
    cout << "Tiempo: " << durationRecursiva.count() << " microsegundos" << endl;

    cout << endl <<"PROGRAMACION DINAMICA:" <<endl;
    cout << "Ganancia maxima de longitud n : " << n << " es: " << gananciaDinamica << endl;
    cout << "Tiempo: " << durationDinamica.count() << " microsegundos" << endl<<endl;

    return 0;
}