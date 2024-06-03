//Вариант 3
#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

int main()
{
    setlocale(0, "ru");
    int i, j, n, m;
    //создаем массив
    cout << "Число уравнений: ";
    cin >> n;
    cout << "Число неизвестных: ";
    cin >> m;
    m += 1;
    float** matrix = new float* [n];
    for (i = 0; i < n; i++)
        matrix[i] = new float[m];

    //инициализируем

    for (i = 0; i < n; i++)

        for (j = 0; j < m; j++)
        {
            if (j < m - 1)
            {
                cout << j + 1 << " элемент " <<
                    i + 1 << " уравнения: ";

                cin >> matrix[i][j]; 
            }
            if (j == m - 1)
            {
                cout << "Результат " <<
                    i + 1 << " уравнения: ";

                cin >> matrix[i][j];
            }
        }

    //выводим массив
    cout << "матрица: " << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    //Метод Гаусса
    //Прямой ход, приведение
    //к верхнетреугольному виду
    float  tmp;
    int k;
    float* xx = new float[m];

    for (i = 0; i < n; i++)
    {
        tmp = matrix[i][i];
        for (j = n; j >= i; j--)
            matrix[i][j] /= tmp;
        for (j = i + 1; j < n; j++)
        {
            tmp = matrix[j][i];
            for (k = n; k >= i; k--)
                matrix[j][k] -= tmp * matrix[i][k];
        }
    }
    /*обратный ход*/
    xx[n - 1] = matrix[n - 1][n];
    for (i = n - 2; i >= 0; i--)
    {
        xx[i] = matrix[i][n];
        for (j = i + 1; j < n; j++) xx[i] -=
            matrix[i][j] * xx[j];
    }

    //Выводим решения
    for (i = 0; i < n; i++)
        cout << "x" << i + 1 << " = " <<
        xx[i] << " " << endl;

    delete[] matrix;
    return 0;
}