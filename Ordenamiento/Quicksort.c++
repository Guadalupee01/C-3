#include <iostream>
using namespace std;

// Función para realizar el quicksort
void quickSort(int arreglo[], int izq, int der) {
    if (izq >= der) {
        return; 
    }

    // Selección del pivote
    int pivote = arreglo[izq];
    int i = izq;
    int d = der;

    while (i < d) {
        while (arreglo[d] >= pivote && i < d) {
            d--; // Decrementa el índice derecho
        }
        while (arreglo[i] < pivote && i < d) {
            i++; // Incrementa el índice izquierdo
        }
        if (i < d) { // Intercambia elementos
            int aux = arreglo[i];
            arreglo[i] = arreglo[d];
            arreglo[d] = aux;
        }
    }

    // Coloca el pivote en su posición correcta
    arreglo[izq] = arreglo[i];
    arreglo[i] = pivote;

    // Llamadas recursivas para ordenar las sublistas
    quickSort(arreglo, izq, i - 1);
    quickSort(arreglo, i + 1, der);
}

int main() {
    int n;
    cout << "Ingrese el tamaño del arreglo: ";
    cin >> n;

    int arreglo[n];
    cout << "Ingrese " << n << " números para el arreglo: ";
    for (int i = 0; i < n; i++) {
        cin >> arreglo[i];
    }

    // Llama a quicksort
    quickSort(arreglo, 0, n - 1);

    // Muestra el arreglo ordenado
    cout << "Arreglo ordenado: ";
    for (int i = 0; i < n; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;

    return 0;
}
