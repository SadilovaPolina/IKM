#include <iostream>
#include <string>
#include "Header.h" 

using namespace std;

// ������� ��� ��������� �������� ����� (������) �� ����� �����
string ymnojenie(const string& num, int x) {
    string result; // ������ ��������� ���������
    int perenos = 0; // �������

    // �������� ����������
    for (int i = num.size() - 1; i >= 0; --i) {
        int prod = (num[i] - '0') * x + perenos; // ��������� � ���������
        perenos = prod / 10; // ��������� �������
        result += (prod % 10) + '0'; // ��������� �������
    }

    // ���� ���� �������, ��������� ���
    while (perenos) {
        result += (perenos % 10) + '0';
        perenos /= 10;
    }

    // ��������� ���������� �����������
    reverse(result.begin(), result.end());
    return result; // ���������� ���������
}

// ������� ��� ���������� ���������� n! � ���� ������
string factorial1(int n) {
    string result = "1"; // ��������� �������� ����������

    for (int i = 2; i <= n; ++i) {
        result = ymnojenie(result, i); // �������� �� ������� i
    }
    return result; // ���������� n!
}

// ������� ��� ���������� ! (n!)
string factorial2(int n) {
    string factN = factorial1(n); // ��������� n!
    string result = "1"; // ��������� �������� ��� ! (n!)

    // ����������� n! � long long ��� �����
    long long fact1 = 0; // ���������� long long ��� �������� n!
    for (char c : factN) {
        fact1 = fact1 * 10 + (c - '0'); // ����������� ������ � long long
    }

    // ��������� ! (n!)
    for (long long i = 2; i <= fact1; ++i) {
        result = ymnojenie(result, i); // �������� ��������� �� ������� i
    }

    return result; // ���������� ! (n!)
}
