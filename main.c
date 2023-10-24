#include <stdio.h>

void selection(int arr[],int n,int* swaps, int* outIts, int* inIts){
    int min;
    for (int i = 0; i < n-1; ++i) {
        min = i;
        for (int j = i+1; j < n; ++j) {
            (*inIts)++;
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        if (min != i) {
            (*swaps)++;
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
        (*outIts)++;
    }
}
void insertion(int arr[], int n, int* swap_i, int* outIti, int* inIti) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            (*inIti)++;
            (*swap_i)++;
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        (*outIti)++;
    }
}
int main() {
    FILE *fin;
    fin = fopen("sort.txt","r");
    if(fin == NULL){
        printf("error");
        return 1;
    }
    int number_of_sequence;
    fscanf(fin,"%d",&number_of_sequence);
    for (int i = 1;i <number_of_sequence +1; ++i) {
        int length;
        fscanf(fin,"%d",&length);
        int sequence[length];
        for (int j = 0; j < length; ++j) {
            fscanf(fin,"%d",&sequence[j]);
        }
        printf("Sequence %d:\n", i);
        printf("Selection Sort:\n");

        int swaps = 0;
        int outIts = 0;
        int inIts = 0;

        selection(sequence, length, &swaps, &outIts, &inIts);
        printf("Swaps: %d\n", swaps);
        printf("Outer Loop Iterations: %d\n", outIts);
        printf("Inner Loop Iterations per Outer Iteration: %d\n", inIts / outIts);

        printf("Insertion Sort:\n");
        int swap_i = 0;
        int outIti = 0;
        int inIti = 0;


        insertion(sequence, length, &swap_i, &outIti, &inIti);

        printf("Swaps: %d\n", swap_i);
        printf("Outer Loop Iterations: %d\n", outIti);
        printf("Inner Loop Iterations per Outer Iteration: %d\n", inIti / outIti);

        printf("\n");
    }
    fclose(fin);
    return 0;
}
