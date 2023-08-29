// Emilio Berber Maldonado
// A01640603
// Algoritmo: 8 reinas - min_conflicts

#include <iostream>
#include <vector>
#include <random>

using namespace std;

struct Queen {
    int x, y; // declaro esto para que hayan coordenadas
    Queen(int x, int y) : x(x), y(y) {} // constructor
};

// Función para contar los conflictos en una posición específica
// # conflictos en una posición específica (si hay reinas en la misma col o diagonal)
int countConflicts(const vector<Queen> &queens, int row, int col) {
    int conflicts = 0; // numero de conflictos al momento
    for (int i = 0; i < queens.size(); ++i) {
        if (i == row) continue;
        // Verificar si hay conflicto en la misma columna o en la misma diagonal
        if (queens[i].x == col || abs(i - row) == abs(queens[i].x - col)) {
            conflicts++;
        }
    }
    return conflicts;
}

// Función para encontrar la columna que minimiza los conflictos para una fila
int findMinConflictCol(const vector<Queen> &queens, int row) {
    int minConflicts = queens.size();
    vector<int> minConflictCols;
    for (int col = 0; col < queens.size(); ++col) {
        int conflicts = countConflicts(queens, row, col);
        // determinar si es los conflictos es menor al minimo de conlfictos para actualizar minimo de conflictos
        if (conflicts < minConflicts) {
            minConflicts = conflicts;
            minConflictCols.clear();
            minConflictCols.push_back(col);
        } else if (conflicts == minConflicts) {
            minConflictCols.push_back(col);
        }
    }
    // Seleccionar una columna aleatoriamente entre las que minimizan conflictos
    random_device rd;
    mt19937 gen(rd()); // generador de nnúmeros aleatorios
    uniform_int_distribution<int> dist(0, minConflictCols.size() - 1); // 0 al n-1
    return minConflictCols[dist(gen)];
}

vector<Queen> minConflicts(const vector<Queen> &initialQueens, int maxSteps) {
    vector<Queen> queens = initialQueens; // copia del vector queens
    for (int step = 0; step < maxSteps; ++step) {
        int totalConflicts = 0;
        for (int row = 0; row < queens.size(); ++row) {
            totalConflicts += countConflicts(queens, row, queens[row].x);
        }
        // En caso de que encontremos que no hay conflictos en el tablero regresamos el vector
        if (totalConflicts == 0) {
            return queens;
        }

        // Elegir una fila con conflictos aleatoriamente
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dist(0, queens.size() - 1);
        int row = dist(gen);
        
        // Encontrar la columna que minimiza conflictos para esta fila
        int col = findMinConflictCol(queens, row);
        
        // Mover la reina a la posición con menos conflictos
        queens[row].x = col;
    }
    return {}; // No se encontró solución en el número máximo de pasos
}

int main() {
    const int tablero = 8;
    const int maxSteps = 50000;

    vector<Queen> initialQueens;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, tablero - 1);
    
    // Inicializar las reinas aleatoriamente en diferentes filas
    for (int i = 0; i < tablero; ++i) {
        initialQueens.emplace_back(dist(gen), i);
    }

    cout << "Posicion de las reinas [Q1-Q8]:" << endl;
    for (const Queen &queen : initialQueens) {
        cout << "(" << queen.x << ", " << queen.y << ") ";
    }
    cout << endl;

    vector<Queen> solution = minConflicts(initialQueens, maxSteps);
    if (!solution.empty()) {
        cout << "Solucion encontrada:" << endl;
        for (const Queen &queen : solution) {
            cout << "(" << queen.x << ", " << queen.y << ") ";
        }
        cout << endl;
    } else {
        cout << "No se encontro solucion en el numero maximo de pasos." << endl;
    }

    return 0;
}
