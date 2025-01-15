#include <iostream>
#include "Header.h" // Подключаем заголовочный файл

using namespace std;

int main() {

    setlocale(LC_ALL, "ru");

    int n;

    // Ввод n с проверкой
    cout << "Введите n (n >= 3): ";
    while (true) {
        cin >> n;
        if (cin.fail() || n < 3) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Некорректный ввод. Пожалуйста, введите целое число n (n >= 3)!" << endl;
        }
        else {
            break;
        }
    }

    // Вычисляем (n!)!
    string result = factorial2(n);
    cout << "Точное значение (" << n << "!)! = " << result << endl;

    return 0;
}
