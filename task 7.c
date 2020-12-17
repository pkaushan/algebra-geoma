#include <stdio.h>
#include <stdlib.h>
#include "math.h"

#define N 100
#define EPS 0.000001

void swap(double *a, double *b) { //меняем значение двух переменных
    double tmp = *a;
    *a = *b;
    *b = tmp;
}

void gauss(double a[N][N], int n, int m) { //метод гаусса
    for (int col = 0, row = 0; col < n && row < m; ++col) {
        int sel = row;
        for (int i = row; i < m; ++i)
            if (fabs(a[i][col]) > fabs(a[sel][col]))
                sel = i;
        for (int i = col; i < n; ++i)
            swap(&a[sel][i], &a[row][i]);

        for (int i = 0; i < m; ++i)
            if (i != row) {
                if (a[row][col] != 0) {
                    double c = a[i][col] / a[row][col];
                    for (int j = col; j < n; ++j)
                        a[i][j] -= a[row][j] * c;
                }
            }
        ++row;
    }
}

void divide_row(double a[N][N], int n, int row_num, double divider) { //деление всей строки на какое то значение
    for (int i = 0; i < n; i++) {
        a[row_num][i] /= divider;
    }
}

_Bool isIdentityMatrix(double a[N][N], int n, int m) {
    if (m == 1){
        int non_zero_vals = 0;
        for (int i = 0;i<n;i++){
            if (a[m-1][i] !=0) non_zero_vals++;
        }
        if (non_zero_vals >1){
            return 0;
        } else return 1;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] != 0 && i != j) return 0;
        }
    }

    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    int n, m;
    double a[N][N];
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%lf", &a[i][j]); //считывание матрицы
    gauss(a, n, m);
    for (int row = 0; row < m; row++) {
        for (int col = 0; col < n; col++) {
            if (a[row][col] != 0) { //поиск первого ненулевого элемента, деление строки на его значение
                divide_row(a, n, row, a[row][col]);
                break;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lf ", a[i][j]);
        }
        printf("\n");
    }


    _Bool printedValues[N] = {0};
    if (!isIdentityMatrix(a, n, m)) {
        for (int i = 0; i < m; i++) { //вывод
            _Bool printed = 0;
            for (int j = 0; j < n; j++) {
                if (a[i][j] != 0) {
                    printedValues[j] = 1;
                    printf("x%d = ", j);
                    printed = 0;
                    if (j == n - 1) {
                        printf("1");
                        printedValues[j] = 1;
                    }
                    for (int k = j + 1; k < n; k++) {
                        if (a[i][k] > EPS) {
                            if (printed) printf(" + ");
                            printf("%lf*x%d", -a[i][k],
                                   k); //вывод значения с минусом, так как переносим на другую сторону
                            printed = 1;
                        }
                    }
                    if (!printed) printf("0");
                    printf("\n");
                    break;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (!printedValues[i]) printf("x%d = 1\n", i);
        }
    } else {
        for (int i = 0; i < n; i++) {
            printf("x%d = 0\n", i);
        }
    }

}
