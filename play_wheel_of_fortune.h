#pragma once
#include <iostream>
#include <string> // Needed to use strings
#include <cstdlib> // Needed to use random numbers
#include <ctime>
#include <array>
#include "Additional.h"

using namespace std;

void play_wheel_of_fortune()
{
    srand(time(NULL)); // "Seed" the random generator
    // Get player's betting amount
    char choice;
    int amount, bettingAmount;
    drawLine(80, '_');
    cout << "\n\n\t\t����  ������ �������\n\n\n";
    drawLine(80, '_');

    cout << "\t\t������� ����\n";
    drawLine(80, '-');
    cout << "\t1. ����� ���������� ����, ����������� ������ �������.\n";
    cout << "\t2. ������ ������ �������� �� ����� ����. �� �������� ������, ���� �������� ��� ���������� �����.\n";
    cout << "\t3. ������� ������, ���� ������ ���������� � 10 ���.\n";
    cout << "\t4. ���� ����������, �� ��� ������ ���������� �� �������� ������.\n\n";
    drawLine(80, '-');

    while (true)
    {
        cout << "\n\n\t������� �������� ��������, ����� ������ ����: $ ";
        cin >> amount;
        cin.ignore();
        if (amount > 0) break;
        else cout << "\t���������� ��� ��� \n";
    }

    array <string, 9> a_1 = { "CHERRY","WATERMELON","BANANA", "CHERRY","WATERMELON","BANANA", "CHERRY","WATERMELON","BANANA" };
    array <string, 9> a_2 = { "BANANA","CHERRY","WATERMELON", "BANANA","CHERRY","WATERMELON", "BANANA","CHERRY","WATERMELON" };
    array <string, 9> a_3 = { "WATERMELON","BANANA","CHERRY", "WATERMELON","BANANA","CHERRY", "WATERMELON","BANANA","CHERRY" };

    do {
        do
        {
            cout << "\t���� ������: $ ";
            cin >> bettingAmount;
            if (bettingAmount > amount or bettingAmount <= 0)
                cout << "\t������������ ������ \n"
                << "\n\t���������� ��� ��� \n ";
        } while (bettingAmount > amount or bettingAmount < 0);

        system("cls");
        cout << "\n\t��� ������ $ " << amount << "\n";
        cout << "\n\t���� ������ $ " << bettingAmount << "\n";

        string v1, v2, v3;
        v1 = a_1[rand() % 9];
        v2 = a_2[rand() % 9];
        v3 = a_3[rand() % 9];
        drawLine(80, '=');
        cout << "\n\t" << v1 << " " << v2 << " " << v3 << "\n" << endl;
        drawLine(80, '=');

        if (v1 == v2 && v2 == v3)
        {
            cout << "\n\n\t�����������! �� �������� $ " << bettingAmount * 10 << "\n";
            amount = amount + bettingAmount * 10;
        }
        else
        {
            cout << "\t�������! �� ��������� $ " << bettingAmount << "\n";
            amount = amount - bettingAmount;
        }
        cout << "\n\t" << "�� ����� ����� $ " << amount << "\n";
        if (amount == 0)
        {
            cout << "\n\t� ��� ����������� ��������!";
            break;
        }
        cout << "\n\n\t������ ���������� ����? ( �� - 1 / ��� - 0 )? ";
        cin >> choice;
    } while (choice == '1');

    cout << "\n\n\n";
    drawLine(70, '=');
    cout << "\n\n\t������� �� ����. ��� ������ ���������� $ " << amount << "\n\n";
    drawLine(70, '=');
  
}
