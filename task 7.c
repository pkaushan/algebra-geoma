#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#define N 100
#define EPS 0.000001

void swap(double *a, double *b){ //меняем значение двух переменных
    double tmp = *a;
    *a=*b;
    *b=tmp;
}

void gauss (double a[N][N], int n, int m) { //метод гаусса
    for (int col=0, row=0; col < n && row < m; ++col) {
        int sel = row;
        for (int i=row; i < m; ++i)
            if (fabs (a[i][col]) > fabs (a[sel][col]))
                sel = i;
        for (int i=col; i < n; ++i)
            swap (&a[sel][i], &a[row][i]);

        for (int i=0; i < m; ++i)
            if (i != row) {
                if (a[row][col] != 0){
                    double c = a[i][col] / a[row][col];
                    for (int j=col; j < n; ++j)
                        a[i][j] -= a[row][j] * c;
                }
            }
        ++row;
    }
}

void divide_row (double a[N][N], int n, int row_num, double divider ) { //деление всей строки на какое то значение
    for (int i = 0; i<n; i++){
        a[row_num][i] /=divider;
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    int n, m;
    double a[N][N];
    scanf("%d%d" , &m, &n);
    for (int i=0; i < m; i++)
        for ( int j=0; j<n; j++)
            scanf("%lf", &a[i][j]); //считывание матрицы
    gauss(a, n, m);
    for (int row = 0; row < m; row++){
        for (int col = 0; col < n; col++){
            if (a[row][col] != 0) { //поиск первого ненулевого элемента, деление строки на его значение
                divide_row(a, n, row, a[row][col]);
                break;
            }
        }
    }

    for (int i =0; i < m; i++){ //вывод
        for(int j = 0; j<n; j++){
            if (a[i][j] != 0){
                printf("x%d = ", j);
                _Bool plusNeeded = 0;
                for (int k = j+1; k<n; k++){
                    if (plusNeeded) printf(" + ");
                    if (a[i][k] != 0){
                        printf("%lf*x%d", -a[i][k], k); //вывод значения с минусом, так как переносим на другую сторону
                        plusNeeded = 1;
                    }
                }
                break;
            }
        }
        printf("\n");
    }
}
