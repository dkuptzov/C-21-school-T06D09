#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
int sort(int *a, int n);
int output(int *a, int n);

int main() {
    int n = 10, arr[NMAX];
    // ввод данных и проверка на корректность
    int error = input(arr, &n);
    // printf("%d", n);
    if (error == 1) {
        printf("n/a");
        return 0;
    }
    sort(arr, n);
    output(arr, n);
    return 0;
}

// функция ввода данных в массив
int input(int *a, int *n) {
    // if (!scanf("%d", n) || (*n > 10) || (*n <= 0)) {
    //     return 1;
    // }
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

int sort(int *a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[i]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
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
