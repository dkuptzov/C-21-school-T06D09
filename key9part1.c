/*------------------------------------
        Здравствуй, человек!
        Чтобы получить ключ
        поработай с комментариями.
-------------------------------------*/

#include <stdio.h>
#define NMAX 10

int input(int *buffer, int *length);
void output(int *buffer, int *length);
int sum_numbers(int const *buffer, int length);
int find_numbers(int *buffer, int length, int number);

/*------------------------------------
        Функция получает массив данных
        через stdin.
        Выдает в stdout особую сумму
        и сформированный массив
        специальных элементов
        (выбранных с помощью найденной суммы):
        это и будет частью ключа
-------------------------------------*/
int main() {
    int length, arr[NMAX];
    int error = input(arr, &length);
    if (error == 1) {
        printf("n/a");
        return 0;
    }
    int sum = sum_numbers(arr, length);
    printf("%d\n", sum);
    find_numbers(arr, length, sum);
    return 0;
}

int input(int *buffer, int *length) {
    if (!scanf("%d", length) || (*length > 10) || (*length <= 0)) {
        return 1;
    }
    for (int *p = buffer; p - buffer < *length; p++) {
        if (!scanf("%d", p)) {
            return 1;
        }
    }
    return 0;
}

/*------------------------------------
        Функция должна находить
        сумму четных элементов
        с 0-й позиции.
-------------------------------------*/
int sum_numbers(int const *buffer, int length) {
    int sum = 0;

    for (int i = 0; i < length; i++) {
        if (buffer[i] == 0) {
            continue;
        } else if (buffer[i] % 2 == 0) {
            sum = sum + buffer[i];
        }
    }
    return sum;
}

/*------------------------------------
        Функция должна находить
        все элементы, на которые нацело
        делится переданное число и
        записывает их в выходной массив.
-------------------------------------*/
int find_numbers(int *buffer, int length, int number) {
    int space = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] == 0) {
            continue;
        } else if (number % buffer[i] == 0) {
            if (space == 1) {
                printf(" ");
            }
            printf("%d", buffer[i]);
            space = 1;
        }
    }
    return 0;
}
