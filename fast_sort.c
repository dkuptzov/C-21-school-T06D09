#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
int copy(int const *a, int *b, int n);
int qsort(int *a, int low, int high);
// int piramida_sort(int *b, int n);
int output(int *a, int n);

int main() {
    int n = 10, arr[NMAX], arr2[NMAX];
    // ввод данных и проверка на корректность
    int error = input(arr, &n);
    if (error == 1) {
        printf("n/a");
        return 0;
    }
    // копия введенных данных
    copy(arr, arr2, n);
    qsort(arr, 0, n - 1);
    output(arr, n);
    printf("\n");
    output(arr, n);
    return 0;
}

// функция ввода данных в массив
int input(int *a, int *n) {
    int count = 0;
    for (int *p = a; p - a < *n; p++) {
        if (!scanf("%d", p)) {
            return 1;
        }
        count++;
    }
    if ((count > 10) || (count <= 0)) {
        return 1;
    }
    *n = count;
    return 0;
}

int copy(int const *a, int *b, int n) {
    for (int i = 0; i < n; i++) {
        b[i] = a[i];
    }
    return 0;
}

// функция быстрой сортировки
int qsort(int *a, int low, int high) {
    int i = low, j = high;
    int center = a[(high + low) / 2];
    while (a[i] < center) {
        i++;
    }
    while (a[j] > center) {
        j--;
    }
    if (i <= j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        i++;
        j--;
    }
    if (low < j) {
        qsort(a, low, j);
    }
    if (i < high) {
        qsort(a, i, high);
    }
    return 0;
}

int output(int *a, int n) {
    for (int i = 0; i < n - 1; ++i) {
        printf("%d ", a[i]);
    }
    printf("%d", a[n - 1]);
    return 0;
}
