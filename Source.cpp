#include <iostream>
#include <string>
#include "Header.h" 

using namespace std;

// Функция для умножения длинного числа (строка) на целое число
string ymnojenie(const string& num, int x) {
    string result; // Хранит результат умножения
    int perenos = 0; // Перенос

    // Умножаем поразрядно
    for (int i = num.size() - 1; i >= 0; --i) {
        int prod = (num[i] - '0') * x + perenos; // Умножение с переносом
        perenos = prod / 10; // Обновляем перенос
        result += (prod % 10) + '0'; // Сохраняем остаток
    }

    // Если есть перенос, добавляем его
    while (perenos) {
        result += (perenos % 10) + '0';
        perenos /= 10;
    }

    // Результат необходимо перевернуть
    reverse(result.begin(), result.end());
    return result; // Возвращаем результат
}

// Функция для вычисления факториала n! в виде строки
string factorial1(int n) {
    string result = "1"; // Начальное значение факториала

    for (int i = 2; i <= n; ++i) {
        result = ymnojenie(result, i); // Умножаем на текущее i
    }
    return result; // Возвращаем n!
}

// Функция для вычисления ! (n!)
string factorial2(int n) {
    string factN = factorial1(n); // Вычисляем n!
    string result = "1"; // Начальное значение для ! (n!)

    // Преобразуем n! в long long для цикла
    long long fact1 = 0; // Используем long long для хранения n!
    for (char c : factN) {
        fact1 = fact1 * 10 + (c - '0'); // Преобразуем строку в long long
    }

    // Вычисляем ! (n!)
    for (long long i = 2; i <= fact1; ++i) {
        result = ymnojenie(result, i); // Умножаем результат на текущее i
    }

    return result; // Возвращаем ! (n!)
}
