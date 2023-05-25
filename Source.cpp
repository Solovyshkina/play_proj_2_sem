#include <iostream>
#include <string> // Needed to use strings
#include <cstdlib> // Needed to use random numbers
#include <ctime>
#include <array>

#include "Additional.h"
#include "play_guess_the_number.h"
#include "play_wheel_of_fortune.h"
#include "krestiki_noliki.h"
#include "victorina.h"
#include "Additional.h"

using namespace std;

int main()
{
    system("chcp 1251");
    setlocale(LC_ALL, "ru");
    int n, choice;
    start();
    do 
    {
        drawLine(80, '-');
        cout << "\t������� ����:\n\t " << "1 - ������ ����� \n\t 2 - ������ �������\n\t 3 - �������� - ������\n\t 4 - ���������\n\t " << endl;
        drawLine(80, '-');

        cout << "\t��� �����: ";
        cin >> n;
        system("cls");

        if (n == 1)
        {
            play_guess_the_number();
        }
        if (n == 2)
        {
            play_wheel_of_fortune();
        }
        if (n == 3)
        {
            krestiki_noliki();
        }
        if (n == 4)
        {
            victorina();
        }

        cout << "\n\t��� ������ ������ ���� �������� - 1 \n";
        cout << "\n\t��� ������ �������� - 0\n";

        cin >> choice;
        system("cls");
    } while (choice == 1);
    cout << "\n\t������� �� ����! �� ����� ������!";
    return 0;
}