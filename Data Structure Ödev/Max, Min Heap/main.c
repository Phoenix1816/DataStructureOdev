#include <stdio.h>

#define MAX 100

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// i dizininden aþaðýya doðru heapify (max-heap)
void heapifyMax(int arr[], int n, int i) {
    int largest = i;        // kök
    int left = 2 * i + 1;   // sol çocuk
    int right = 2 * i + 2;  // sað çocuk

    // sol çocuk daha büyükse
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // sað çocuk daha büyükse
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // en büyük kök deðilse, swap + devam
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapifyMax(arr, n, largest);
    }
}

// Diziyi max-heap'e çevir
void buildMaxHeap(int arr[], int n) {
    // yapraklar zaten heap, sondan yukarýya doðru düzelt
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyMax(arr, n, i);
    }
}

// Max elemaný döndür (kök)
int getMax(int arr[], int n) {
    if (n <= 0) return -1; // basit hata durumu
    return arr[0];
}

// Max elemaný çýkar ve heap'i güncelle
int extractMax(int arr[], int *n) {
    if (*n <= 0) return -1;

    int max = arr[0];
    arr[0] = arr[*n - 1]; // son elemaný köke taþý
    (*n)--;
    heapifyMax(arr, *n, 0); // baþtan aþaðý düzelt

    return max;
}

int main() {
    int arr[] = {3, 10, 5, 6, 2, 8, 9};
    int n = 7;

    buildMaxHeap(arr, n);

    printf("Max eleman: %d\n", getMax(arr, n));

    int m = extractMax(arr, &n);
    printf("Extract edilen max: %d\n", m);
    printf("Yeni max: %d\n", getMax(arr, n));

    return 0;
}
