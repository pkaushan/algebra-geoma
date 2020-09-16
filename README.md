# algebra-geoma
#include<iostream>
#include<complex.h>
#include<complex>

using namespace std;

int main()

{
    setlocale(LC_ALL, "Russian"); 
    int n; 
    double x, y;
    cout << "Комплексные числа: x + iy\n";
    cout << "Введите x: ";
    cin >> x;
    cout << "Введите y: ";
    cin >> y;
    complex< double > z(x, y);

    cout << "\nz = " << z << "\n"; 
    cout << "\nИмеет вещественную часть = " << real(z) << endl;
    cout << "Имеет мнимую часть = " << imag(z) << endl;

    double rho = abs(z); 
    cout << "\nМодуль комплексного числа: "  << abs(z) << endl;
    double phi = arg(z); 
    cout << "\nАргумент комплексного числа: " << arg(z) << endl;

    cout << "\nТригонометрическая форма комплексного числа" << endl;
    cout << rho << "*(cos(" << phi << ") + i*sin(" << phi << "))" << endl;

    cout << endl << "Обратное к z число: " << pow(z, -1) << endl;

    cout << "\nВведите степень: ";
    cin >> n;
    cout << "Число z в степени n: " << pow(z, n) << endl;

    cout << "\nКорни n-ной степени из z: " << endl;
    for (int i = 0; i < n; i++)
        cout << pow(rho, 1. / n) << "(cos((" << phi << "+" << 2 * i << "Pi)/" << n << ") + i(sin((" << phi << "+" << 2 * i << "Pi)/" << n << ")" << endl;

    system("pause");
    return 0;
}
