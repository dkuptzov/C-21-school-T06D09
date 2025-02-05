#include <stdio.h>
#define NMAX 10

int input(int *a, int *n, int *c);
int sdvig(int *a, int n, int c);
int output(int *a, int n);

int main() {
    int n, c, arr[NMAX];
    // ввод данных и проверка на корректность
    int error = input(arr, &n, &c);
    if (error == 1) {
        printf("n/a");
        return 0;
    }
    sdvig(arr, n, c);
    output(arr, n);
    return 0;
}

int input(int *a, int *n, int *c) {
    if (!scanf("%d", n) || (*n > 10) || (*n <= 0)) {
        return 1;
    }
    for (int *p = a; p - a < *n; p++) {
        if (!scanf("%d", p)) {
			return 1;
        }
    }
    if (!scanf("%d", c)) {
        return 1;
    }
    if (*c > 10)
    {
        *c /= 10;
    }
    return 0;
}

int sdvig(int *a, int n, int c)
{
    int arr_temp[n], count = 0, its_cnange = 0;
    if (c > 0)
    {
        its_cnange = c;
    }
    else if (c < 0)
    {
        c *= -1;
        its_cnange = n - c;
    }
    for (int i = its_cnange; i < n; i ++)
    {
        arr_temp[count] = a[i];
        count++;
    }
    for (int j = 0; j < its_cnange; j++)
    {
        arr_temp[count] = a[j];
        count++;
    }
    for (int x = 0; x < n; x++)
    {
        a[x] = arr_temp[x];
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
