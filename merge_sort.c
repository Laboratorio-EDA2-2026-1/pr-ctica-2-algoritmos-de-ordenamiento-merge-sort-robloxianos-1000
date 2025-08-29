#include <stdio.h>
#include <stdlib.h>

/*
    Ejercicio: Implementación de Merge Sort

    Descripción:
    Se reciben n arreglos lineales, cada uno de tamaño n.
    El programa debe combinarlos en un solo arreglo de tamaño n*n
    y ordenarlo en orden creciente usando Merge Sort.

    Entrada:
    - Un número entero n
    - n arreglos de tamaño n (n*n enteros en total)

    Salida:
    - Un solo arreglo de tamaño n*n con los elementos ordenados en orden creciente

    Ejemplo:

    Input:
    3
    3 1 5
    2 9 4
    8 7 6

    Output:
    1 2 3 4 5 6 7 8 9
*/

int *crearArreglo(int tam) {
    int *arr = (int *)malloc(tam * sizeof(int));
    if (arr == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        exit(1); // Salimos si no hay memoria
    }
    return arr;
}

// ---- Prototipos ----
void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);

int main() {
    int n;
    printf("DAME TAMAÑO DE ARREGLOS:\n");
    scanf("%d", &n);  // Leer el número de arreglos

    int total = n * n;  
    int *arr = (int *)malloc(total * sizeof(int));

    printf("DAME VALORES:\n");

    // Leer n arreglos de tamaño n
    for (int i = 0; i < total; i++) {
        scanf("%d", &arr[i]);
    }

    // Ordenar usando merge sort
    mergeSort(arr, 0, total - 1);

    // Imprimir el arreglo ordenado
    for (int i = 0; i < total; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}

// ---- Implementación de mergeSort ----
void mergeSort(int arr[], int left, int right) {
     if (left >= right) {
         return;
     }
     
     int mid = (left + right) / 2;
     
     mergeSort(arr, left, mid);
     mergeSort(arr, mid + 1, right);
     merge(arr, left, mid, right);
}

// ---- Implementación de merge ----
void merge(int arr[], int left, int mid, int right) {
    int nL = mid - left + 1;
    int nR = right - mid;
    
    int *arregloL = crearArreglo(nL);
    int *arregloR = crearArreglo(nR);
    
    // Copiar elementos a los arreglos temporales (CORREGIDO)
    for (int i = 0; i < nL; i++) {
        arregloL[i] = arr[left + i];
    }
    
    for (int j = 0; j < nR; j++) {
        arregloR[j] = arr[mid + 1 + j];
    }
    
    int i = 0;
    int j = 0;
    int k = left;
    
    // Fusionar los arreglos temporales
    while (i < nL && j < nR) {
        if (arregloL[i] <= arregloR[j]) {
            arr[k] = arregloL[i];
            i++;
        } else {
            arr[k] = arregloR[j];
            j++;
        }
        k++;
    }
    
    // Copiar los elementos restantes del arreglo izquierdo
    while (i < nL) {
        arr[k] = arregloL[i];
        i++;
        k++;
    }
    
    // Copiar los elementos restantes del arreglo derecho
    while (j < nR) {
        arr[k] = arregloR[j];
        j++;
        k++;
    }
    
    free(arregloL);
    free(arregloR);
}
