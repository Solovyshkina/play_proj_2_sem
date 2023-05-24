#pragma once
#include <iostream>
#include <cstdlib> // Needed to use random numbers
#include <ctime>
#include "Additional.h"
using namespace std;

void play_guess_the_number()
{
    system("chcp 1251>nul");
    string playerName;
    int amount; // hold player's balance amount
    int bettingAmount;
    int guess;
    int dice; // hold computer generated number
    char choice;

    srand(time(NULL)); // "Seed" the random generator

    drawLine(80, '_');
    cout << "\n\n\t\t����  ������ �����\n\n\n";
    drawLine(80, '_');

    cout << "\t\t������� ����\n";
    drawLine(80, '-');
    cout << "\t1. �������� ����� �� 1 �� 10\n";
    cout << "\t2. ���� �� ���������, �� ���� ������ ���������� � 10 ���\n";
    cout << "\t3. ���� �� ����������, �� ��������� ����� ������ ����� ������\n\n";
    drawLine(80, '-');;

    cin.get();
    cout << "\n\n\t������� ��� ������: ";
    getline(cin, playerName);
    while (true)
    {
        cout << "\n\n\t������� �������� ��������, ����� ������ ����: $";
        cin >> amount;
        cin.ignore();
        if (amount > 0) break;
        else cout << "\t���������� ��� ��� \n";
    }
    do
    {
        cout << "\n\n";
        drawLine(80, '-');

        // Get player's betting amount
        while (true)
        {
            cout << "\t" << playerName << ", �������� ������: $ ";
            cin >> bettingAmount;

            cin.ignore();
            if (bettingAmount <= 0)
                cout << "\t���� ������������ ������\n" << "\t��������� ���� ������\n";
            else if (bettingAmount > amount)  cout << "\t���� ������ ������� �������\n" << "\n\t��������� ���� ������\n ";
            else break;
        }
        system("cls");
        cout << "\n\n\t�������� ������ $ " << amount << "\n";
        cout << "\t������ $ " << bettingAmount << "\n\n";


        // Get player's numbers
        do
        {
            cout << "\t�������� ����� �� 1 �� 10: ";
            cin >> guess; //���������� ��������� ��������
            if (guess <= 0 || guess > 10)
                cout << "\t��������� �����!! ��� ������ ���� �� 1 �� 10 \n"
                << "\n\t������� ��� ���\n ";
        } while (guess <= 0 || guess > 10);

        dice = rand() % 10 + 1; // Will hold the randomly generated integer between 1 and 10

        if (dice == guess)
        {
            cout << "\n\n\t�� �������!! ��� ������� " << bettingAmount * 10;
            amount = amount + bettingAmount * 10;
        }
        else
        {
            cout << "\n\n\t����� ���� �� �� ����� �������! �� ��������� $ " << bettingAmount << "\n";
            amount = amount - bettingAmount;
        }

        cout << "\n\t���������� �����: " << dice << "\n";
        cout << "\n\t" << playerName << ", �� ����� ����� $ " << amount << "\n";
        if (amount == 0)
        {
            cout << "\t� ��� ������ ��� �������, ����� ���������� ����.";
            break;
        }
        cout << "\n\n\t-->������ ����� ( 1 - �� / 0 - ��� )? ";
        cin >> choice;
    } while (choice == '1');

    cout << "\n\n\n";
    drawLine(70, '=');
    cout << "\n\n\t������� �� ����. ��� ������ ���������� $ " << amount << "\n\n";
    drawLine(70, '=');

}

