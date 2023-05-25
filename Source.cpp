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
        cout << "\tВыбрать игру:\n\t " << "1 - Угадай число \n\t 2 - Колесо фортуны\n\t 3 - Крестики - нолики\n\t 4 - Викторина\n\t " << endl;
        drawLine(80, '-');

        cout << "\tВаш выбор: ";
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

        cout << "\n\tДля выбора другой игры напишите - 1 \n";
        cout << "\n\tДля выхода напишите - 0\n";

        cin >> choice;
        system("cls");
    } while (choice == 1);
    cout << "\n\tСпасибо за игру! До новых встреч!";
    return 0;
}