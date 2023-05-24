#pragma once
#include <iostream>
#include <string> // Needed to use strings
#include <cstdlib> // Needed to use random numbers
#include <ctime>
#include <array>
using namespace std;

void victorina()
{
    system("chcp 1251>nul");

    int amount, bettingAmount;
    char choice;

    drawLine(80, '_');
    cout << "\n\n\t\t����  ���������\n\n\n";
    drawLine(80, '_');

    cout << "\t\t������� ����\n";
    drawLine(80, '-');
    cout << "\t1. ��� ����� ���������� ������� � � �������� ��������� - ���������� ����, ������������ � ������.\n";
    cout << "\t2. �� ������ ��������� ��������� ����� ��� ������ ����� �������.\n";
    cout << "\t3. ���� �� �������� ������ �����, �� ��������� � �������� � 10 ��� ������ �����, ��� ���������.\n";
    cout << "\t4. ��� ����� � ��� ����� 10 �������, ����� ���� ���������� �������������. \n";
    cout << "\t5. ���� �� �� �������� ������ �����, �� �� ��������� ����� ����� ������.\n\n";
    drawLine(80, '-');

    while (true)
    {
        cout << "\n\n\t������� ����� ��������, ����� ������ ����: $";
        cin >> amount;
        if (amount <= 0) cout << "\n\t ���� ������������ ������\n";
        else break;
    }


    string question[5] = { "����� ������, ����������� ��� ������������ ������, ���������� ��������? ","��������, ����������� �������� ����������� ����� �������� �������� ������������� � ����� ��������� ���� �������� �� �������� � ������? ",
        "����������� ������ ��������? ", "��������, ����������� ������������ ���� ��� ��� ����������� ��������, ����� ��� ����������� �������? ",
        "�����, ��� �������� ��������� � ������ ������ � ������� ���������� ������������� ��� �������� ������� ������? " };// ������
    string word[5] = { "����������","������������","������","�����������","�����������" }; // �����
    string abc, xword; // �������� �����, ������� � ������

    do
    {
        while (true)
        {
            cout << "\n\t������� ����� ��� ������: $";
            cin >> bettingAmount;
            if (bettingAmount > amount)
                cout << "\n\t����� ����� ������ ������, ��� ��� ������� ������\n"
                << "\n\t��������� ���� ������\n ";
            else break;
        }


        cout << "\n\t��� ������ - " << amount << "$, � ������ - " << bettingAmount << "$\n";

        srand(time(NULL)); // ��������� ���������� �������� ��� ���������� ��������� �����
        int index = 1 + rand() % 4, p = 0, abcSize = 0; // ��������� ���������� �������, ������ �������, ������ ������ �����
        const int wordsize = word[index].length();  // ������ ������ �� �������
        xword.clear();
        for (int i = 0; i < wordsize; i++) xword.append("�");// ������������ �������


        do {
            system("cls");
            cout << "\n\t��� ������ - " << amount << "$, � ������ - " << bettingAmount << "$\n";

            cout << "\n\n\t������� �" << p + 1;
            cout << "\n\n\t" << question[index] << "\n\n\t\t" << xword << "\n\n\t������� ����� > ";
            cin >> abc; 
            abcSize = abc.size();

            if (abcSize > wordsize) { cout << "\n\n\t������! ������������ �����!"; system("pause>nul"); continue; }


            if (abc == word[index]) { p++; break; } // ���� ����� ����� ����� 

            else if (abcSize > 1) { p++; cout << "\n\t������������ �����, ��������� ��� \n"; system("pause>nul"); continue; }//������� ������� ����� �������(����� 1)
            else {
                for (int i = 0; i < wordsize; i++)
                    for (int j = 0; j < abcSize; j++) if (word[index][i] == abc[j]) xword[i] = abc[j]; // ������������ ��������� 
                p += abcSize;
            }


            if (p == 10)break;

        } while (xword != word[index]);



        system("cls");
        cout << "\n\n\t" << question[index];
        if ((xword == word[index]) || abc == word[index])
        {
            cout << "\n\n\t��� �����: " << word[index] << "\n\n\t���������� ������� : " << p << ". �� �������� : " << bettingAmount * 10 << ". ������ ����� �� ����� ����� ���������� : " << amount + bettingAmount * 10 << endl;
            amount = amount + bettingAmount * 10;
        }
        else
        {
            cout << "\n\n\t���������� �����: " << word[index] <<
                "\n\n\t������� �����������!" << " �� ���������: " << bettingAmount << ". ������ ����� �� ����� ����� ���������� : " << amount - bettingAmount << endl;
            amount = amount - bettingAmount;
        }
        if (amount == 0)
        {
            cout << "\n\t� ��� ����������� ��������!";
            break;
        }

        cout << "\n\n\t������ ���������� ����? ( �� - 1 / ��� - 0 )? ";
        cin >> choice;

    } while (choice == '1');

    cout << "\n\n\n";
    drawLine(80, '=');
    cout << "\n\n\t������� �� ����. ��� ������ ���������� $ " << amount << "\n\n";
    drawLine(80, '=');
}

