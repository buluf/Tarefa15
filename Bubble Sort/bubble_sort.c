#include <stdio.h>
#include <stdlib.h>

int array [100000];
void bubble_sort(){
    int n = sizeof(array)/sizeof(array[0]);
    int aux;
    for (int i = 0; i < n-1; i++) {
        #pragma omp parallel for schedule(dynamic, 1000) shared (n, array) private(aux)
        for (int j = 0; j < (n/2); j++) {
            if (array[2*j] > array[2*j + 1]) {
                aux            = array[2*j];
                array[2*j]     = array[2*j + 1];
                array[2*j + 1] = aux;
            }
        }
        #pragma omp parallel for schedule(dynamic, 100) shared (n, array) private(aux)
        for (int j = 0; j < (n/2)-1; j++) {
            if (array[2*j + 1] > array[2*j + 2]) {
                aux            = array[2*j + 1];
                array[2*j + 1] = array[2*j + 2];
                array[2*j + 2] = aux;
            }
        }

    }
}
void fill_array(){
    int n = sizeof(array)/sizeof(array[0]);
    for(int i = 0; i < n; i++){
        array[i] = n - i; // array decrescente
    }
}
void print_array(){
    int n = sizeof(array)/sizeof(array[0]);
    for(int i = 0; i < n; i++){
        printf("%d ", array[i]);
    }
}
int main(){

    fill_array();
    bubble_sort();
    print_array();
    return 0;
}

