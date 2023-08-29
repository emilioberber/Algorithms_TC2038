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
    vector<int> arrayOriginal = {25, 64, 73, 91, 47, 8, 59, 28, 87, 15, 84, 53, 62, 48, 78, 37, 51, 95, 17, 71, 33, 10, 56, 29, 3, 45, 23, 12, 69, 38, 99, 83, 43, 93, 92, 61, 39, 60, 68, 85, 11, 26, 20, 89, 40, 70, 9, 2, 65, 46, 90, 18, 72, 1, 79, 98, 74, 76, 49, 86, 34, 21, 97, 13, 7, 42, 22, 6, 96, 80, 5, 14, 77, 81, 19, 30, 50, 36, 54, 31, 75, 44, 41, 27, 66, 88, 16, 63, 32, 67,1, 8, 3, 7, 23, 98, 56, 34, 9, 10, 25, 12, 45, 2, 90, 8, 7, 10, 3, 33, 749, 9, 2, 67, 102, 34, 23, 89, 68, 90, 91, 92, 93, 91,
    8, 12, 32, 134, 23, 9, 90, 7, 2, 43, 23, 90, 11, 2, 42, 9, 4, 6, 87, 92, 43, 47, 8, 59, 28, 87, 15, 12, 13, 14, 17, 11, 13, 32, 1, 22, 34, 23, 90, 32, 53, 22, 29, 103, 24, 134, 242, 8, 42, 242, 134, 239, 20, 13, 24, 22, 90, 89, 23, 12, 90, 44, 1, 2, 4, 2, 4, 2, 3, 4, 5, 6, 7, 8, 10, 11, 12, 2, 90, 132, 98, 18, 43, 78, 37, 51, 95, 17, 71, 33, 10, 56, 29, 3, 45, 23, 12, 69, 38, 99, 83, 43, 93, 92, 61, 39, 60, 68, 85, 11, 26, 20, 89, 40, 70, 9, 2, 65, 46, 90, 18, 72, 1, 79, 98, 74, 76, 49, 86, 34, 
    21, 97, 13, 7, 42, 22, 6, 96, 80, 5, 14, 77, 81, 19, 30, 50, 36, 54, 31, 75, 44, 41, 27, 66, 88, 16, 63, 32, 67,1, 8, 3, 7, 23, 98, 56, 34, 9, 10, 25, 12, 45, 78, 37, 51, 95, 17, 71, 33, 10, 56, 29, 3, 45, 23, 12, 69, 38, 99, 83, 43, 93, 92, 61, 39, 60, 68, 85, 11, 26, 20, 89, 40, 70, 9, 2, 65, 46, 90, 18, 72, 1, 79, 98, 74, 76, 49, 86, 34, 21, 97, 13, 7, 42, 22, 6, 96, 80, 5, 14, 77, 81, 19, 30, 50, 36, 54, 31, 75, 44, 41, 27, 66, 88, 16, 63, 32, 67,1, 8, 3, 7, 23, 98, 56, 34, 9, 10, 25, 12, 45, 
    79, 98, 74, 76, 49, 86, 34, 76, 99, 21, 120, 132, 19, 90, 4, 25, 64, 73, 91, 47, 8, 59, 28, 87, 15, 84, 53, 62, 48, 78, 37, 51, 95, 17, 71, 33, 10, 56, 29, 3, 45, 23, 12, 69, 38, 99, 83, 43, 93, 92, 61, 39, 60, 68, 85, 11, 26, 20, 89, 40, 70, 9, 2, 65, 46, 90, 18, 72, 1, 79, 98, 74, 76, 49, 86, 34, 21, 97, 13, 7, 42, 22, 6, 96, 80, 5, 14, 77, 81, 19, 30, 50, 36, 54, 31, 75, 44, 41, 27, 66, 88, 16, 63, 32, 67,1, 8, 3, 7, 23, 98, 56, 34, 9, 10, 25, 12, 45, 2, 90, 8, 7, 10, 3, 33, 749, 9, 2, 67, 102, 34, 23, 89, 68, 90, 91, 92, 93, 91,
    8, 12, 32, 134, 23, 9, 90, 7, 2, 43, 23, 90, 11};

    int n = arrayOriginal.size(); // tamaño del vector 

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

    // Mostrar el tamaño del vector: 
    cout << "\nn: " << n ;

    // Calcular y mostrar el tiempo de ejecución
    auto duracion = duration_cast<microseconds>(fin - inicio);
    cout << "\nTiempo de ejecucion: " << duracion.count() << " microsegundos" ;
    // Convertir microsegundos a segundos:
    double segundos = duracion.count() / 1000000.0;  
    cout << "\nTiempo de ejecucion: " << segundos << " segundos" << endl;

    return 0;
}



/***************************/
