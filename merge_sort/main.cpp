// Emilio Berber Maldonado 
// A01640603
// Algoritmo: MERGE SORT

#include <iostream>
#include <vector>
#include <chrono> // Librería para calcular el tiempo de ejecución

using namespace std;
using namespace chrono;

// Función MERGE: para combinar dos arrays ordenados
vector<int> merge(vector<int> array1, vector<int> array2) {
    vector<int> combinado; 
    int i = 0;
    int j = 0;
    
    while (i < array1.size() && j < array2.size()) {
        if (array1[i] < array2[j]) {
            combinado.push_back(array1[i]);
            i++;
        } else {
            combinado.push_back(array2[j]);
            j++;
        }
    }
    
    // Agregar los elementos restantes de los arrays
    // en caso de que los arrays ya estén vacíos
    while (i < array1.size()) {
        combinado.push_back(array1[i]);
        i++;
    }
    
    while (j < array2.size()) {
        combinado.push_back(array2[j]);
        j++;
    }

    return combinado;
}

// Función MERGESORT: para dividir el array a la mitad
// y luego aplicar la función MERGE
vector<int> mergeSort(vector<int> array) {
    if (array.size() == 1) {
        return array;
    }

    // DIVIE!:
    int mitad = array.size() / 2;

    // CONQUISTA!: Dividir el array en dos mitades
    vector<int> izquierda(array.begin(), array.begin() + mitad);
    vector<int> derecha(array.begin() + mitad, array.end());

    // COMBINA!: Ordenar y combinar las dos mitades
    return merge(mergeSort(izquierda), mergeSort(derecha));
}

int main() {

    // Array que queremos ordenar:
    vector<int> arrayOriginal = {7, 4, 8, 1, 2, 0, 3, 9};

    // Medir el tiempo de ejecución
    auto inicio = high_resolution_clock::now();
    vector<int> arrayOrdenado = mergeSort(arrayOriginal);
    auto fin = high_resolution_clock::now();

    // Imrimir el array ordenado y no ordenado
    cout << "Array Original:";
    for (int num : arrayOriginal) {
        cout << " " << num;
    }
    cout << "\nArray Ordenado:";
    for (int num : arrayOrdenado) {
        cout << " " << num;
    }

    // Calcular y mostrar el tiempo de ejecución
    auto duracion = duration_cast<microseconds>(fin - inicio);
    cout << "\nTiempo de ejecucion: " << duracion.count() << " microsegundos" ;
    // Convertir microsegundos a segundos:
    double segundos = duracion.count() / 1000000.0;  
    cout << "\nTiempo de ejecucion: " << segundos << " segundos" << endl;

    return 0;
}