#pragma once
#include <iostream>
#include <string> // Needed to use strings
#include "Additional.h"
using namespace std;

void krestiki_noliki()
{
    system("chcp 1251>nul");
    const int N = 3;
    int amount1, amount2, bettingAmount1, bettingAmount2, x, y, k, dgt;
    char A[N][N], c, z, element, choice;
    string s, a, b, name1, name2;

    drawLine(80, '_');
    cout << "\n\n\t\t����  ��������-������\n\n\n";
    drawLine(80, '_');

    cout << "\t\t������� ����\n";
    drawLine(80, '-');
    cout << "\t1. � ���� ��������� ������� ��� ������, ������� �� ������� ������ ��������/������ � ��������� �������.\n";
    cout << "\t2. ���������� ���, ��� ������ �������� � ��� ��� ����� �����.\n";
    cout << "\t3. ���� �� ���������, �� �������� � 10 ��� ������ �����, ��� ���������.\n";
    cout << "\t4. ���� �� ��� �������� �������� ���, �� �� ��������� ����� ����� ������.\n\n";
    drawLine(80, '-');;

    cout << "\n\t������� ��� ������� ������: ";
    cin.get();
    getline(cin, name1);

    cout << "\n\t������� ��� ������� ������: ";

    getline(cin, name2);

    while (true)
    {
        cout << "\n\n\t������� ����� �������� 1-�� ������, ����� ������ ����: $ ";
        cin >> amount1;
        cin.ignore();

        cout << "\n\n\t������� ����� �������� 2-�� ������, ����� ������ ����: $";
        cin >> amount2;

        if (amount1 <= 0 || amount2 <= 0)
            cout << "\n\t�� ����� ����������� ������\n"
            << "\n\t��������� ���� ������\n ";
        else break;
    }
    do
    {


        while (true)
        {
            cout << "\n\t" << name1 << ", ������� ����� ����� ������: $ ";
            cin >> bettingAmount1;

            cout << "\n\t" << name2 << ", ������� ����� ����� ������: $ ";
            cin >> bettingAmount2;

            if (bettingAmount1 > amount1 || bettingAmount2 > amount2) cout << "\n\t���� ������ ������� �������" << "\n\t��������� ���� ������\n";
            else break;
        }

        system("cls");
        cout << "\n\t" << name1 << ", ��� ������ $ " << amount1 << ", � ������ $" << bettingAmount1 << "\n";
        cout << "\n\t" << name2 << ", ��� ������ $ " << amount2 << ", � ������ $" << bettingAmount2 << "\n";

        a = "������";
        b = "��������";
        z = '0';
        c = 'X';
        while (true)
        {
            cout << "\n\t�� ���� ����� ������ �����?(������� 0 ��� X): ";

            cin >> element;
            if (element == 'X' or element == 'x')
            {
                dgt = 2;
                break;
            }
            else if (element == '0')
            {
                dgt = 1;
                break;
            }
            else cout << "\n\t ���������� ��� ���.\n";
        }
        cout << "\n";
        for (int i = 0; i < N; i++)
        {
            cout << "\t";
            for (int j = 0; j < N; j++)
            {
                A[i][j] = '?';
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
        for (int i = 0; i < 9; i++)
        {
            if ((!(i % 2)) && (dgt == 1)) s = a;
            if ((!(i % 2)) && (dgt == 2)) s = b;
            if ((i % 2) && (dgt == 1)) s = b;
            if ((i % 2) && (dgt == 2)) s = a;
        mylabel:
            cout << "\n\t�������� ��� ��� (" << s << ")" << endl;
            cout << "\n\t������: ";
            cin >> x;
            cout << "\t�������: ";
            cin >> y;
            x--;
            y--;
            if (A[x][y] != '?')
            {
                system("cls");
                cout << "\n";
                for (int i = 0; i < N; i++)
                {
                    cout << "\t";
                    for (int j = 0; j < N; j++)
                    {
                        cout << A[i][j] << " ";
                    }
                    cout << endl;
                }
                cout << "\t������ ������� ������!" << endl;
                goto mylabel;
            }
            if ((!(i % 2)) && (dgt == 1)) A[x][y] = z;
            if ((!(i % 2)) && (dgt == 2)) A[x][y] = c;
            if ((i % 2) && (dgt == 1)) A[x][y] = c;
            if ((i % 2) && (dgt == 2)) A[x][y] = z;
            system("cls");
            k = 0;
            cout << "\n";
            for (int i = 0; i < N; i++)
            {
                cout << "\t";
                for (int j = 0; j < N; j++)
                {
                    cout << A[i][j] << " ";
                }
                cout << endl;
            }
            if (((A[0][0] == '0') && (A[0][1] == '0') && (A[0][2] == '0')) ||
                ((A[1][0] == '0') && (A[1][1] == '0') && (A[1][2] == '0')) ||
                ((A[2][0] == '0') && (A[2][1] == '0') && (A[2][2] == '0')) ||
                ((A[0][0] == '0') && (A[1][0] == '0') && (A[2][0] == '0')) ||
                ((A[0][1] == '0') && (A[1][1] == '0') && (A[2][1] == '0')) ||
                ((A[0][2] == '0') && (A[1][2] == '0') && (A[2][2] == '0')) ||
                ((A[0][0] == '0') && (A[1][1] == '0') && (A[2][2] == '0')) ||
                ((A[2][0] == '0') && (A[1][1] == '0') && (A[0][2] == '0')) ||
                ((A[0][0] == 'X') && (A[0][1] == 'X') && (A[0][2] == 'X')) ||
                ((A[1][0] == 'X') && (A[1][1] == 'X') && (A[1][2] == 'X')) ||
                ((A[2][0] == 'X') && (A[2][1] == 'X') && (A[2][2] == 'X')) ||
                ((A[0][0] == 'X') && (A[1][0] == 'X') && (A[2][0] == 'X')) ||
                ((A[0][1] == 'X') && (A[1][1] == 'X') && (A[2][1] == 'X')) ||
                ((A[0][2] == 'X') && (A[1][2] == 'X') && (A[2][2] == 'X')) ||
                ((A[0][0] == 'X') && (A[1][1] == 'X') && (A[2][2] == 'X')) ||
                ((A[2][0] == 'X') && (A[1][1] == 'X') && (A[0][2] == 'X')))
            {
                k++;
                cout << "\t���� ���������! ";
                if ((A[x][y] == z) && (dgt == 1))
                {
                    cout << "\n\t" << name1 << " �������(a)! �� ��������: " << bettingAmount1 * 10 << ". ������ ����� �� ����� ����� ����������: " << amount1 + bettingAmount1 * 10 << "\n "
                        << "\t" << name2 << " ��������(�)! �� ���������: " << bettingAmount2 << ". ������ ����� �� ����� ����� ����������: " << amount2 - bettingAmount2 << endl;
                    amount1 = amount1 + bettingAmount1 * 10;
                    amount2 = amount2 - bettingAmount2;
                }
                else if ((A[x][y] == c) && (dgt == 2))
                {
                    cout << "\n\t" << name1 << " �������(�)! �� ��������: " << bettingAmount1 * 10 << ". ������ ����� �� ����� ����� ����������: " << amount1 + bettingAmount1 * 10 << "\n "
                        << "\t" << name2 << " ��������(�)! �� ���������: " << bettingAmount2 << ". ������ ����� �� ����� ����� ����������: " << amount2 - bettingAmount2 << endl;
                    amount1 = amount1 + bettingAmount1 * 10;
                    amount2 = amount2 - bettingAmount2;
                }
                else if ((A[x][y] == c) && (dgt == 1))
                {
                    cout << "\n\t" << name2 << " �������(�)! �� ��������: " << bettingAmount2 * 10 << ". ������ ����� �� ����� ����� ����������: " << amount2 + bettingAmount2 * 10 << "\n"
                        << "\t" << name1 << " ��������(�)! �� ���������: " << bettingAmount1 << ". ������ ����� �� ����� ����� ����������: " << amount1 - bettingAmount1 << endl;
                    amount1 = amount1 - bettingAmount1;
                    amount2 = amount2 + bettingAmount2 * 10;
                }
                else if ((A[x][y] == z) && (dgt == 2))
                {
                    cout << "\n\t" << name2 << " �������(�)! �� ��������: " << bettingAmount2 * 10 << ". ������ ����� �� ����� ����� ����������: " << amount2 + bettingAmount2 * 10 << "\n"
                        << "\t" << name1 << " ��������(�)! �� ���������: " << bettingAmount1 << ". ������ ����� �� ����� ����� ����������: " << amount1 - bettingAmount2 << endl;
                    amount1 = amount1 - bettingAmount1;
                    amount2 = amount2 + bettingAmount2 * 10;
                }
                break;
            }

        }
        if (!(k)) cout << "\n\t���� ����������� ������!" << endl;
        cout << "\n\n\t������ ���������� ����? ( �� - 1 / ��� - 0 )? ";
        cin >> choice;

    } while (choice == '1');

    cout << "\n\n\n";
    drawLine(70, '=');
    cout << "\n\n\t������� �� ����. ��� ������ ����������: " << name1 << " = " << amount1 << ", " << name2 << " = " << amount2 << "\n\n";
    drawLine(70, '=');
   
}
