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
    cout << "\n\n\t\tИГРА  УГАДАЙ ЧИСЛО\n\n\n";
    drawLine(80, '_');

    cout << "\t\tПРАВИЛА ИГРЫ\n";
    drawLine(80, '-');
    cout << "\t1. Выберете число от 1 до 10\n";
    cout << "\t2. Если вы выиграете, то выша ставка увеличится в 10 раз\n";
    cout << "\t3. Если вы проиграете, то потеряете сумму равную вашей ставке\n\n";
    drawLine(80, '-');;

    cin.get();
    cout << "\n\n\tВведите имя игрока: ";
    getline(cin, playerName);
    while (true)
    {
        cout << "\n\n\tВведите величину депозита, чтобы начать игру: $";
        cin >> amount;
        cin.ignore();
        if (amount > 0) break;
        else cout << "\tПопробуйте еще раз \n";
    }
    do
    {
        cout << "\n\n";
        drawLine(80, '-');

        // Get player's betting amount
        while (true)
        {
            cout << "\t" << playerName << ", Сделайте ставку: $ ";
            cin >> bettingAmount;

            cin.ignore();
            if (bettingAmount <= 0)
                cout << "\tВвод некорректный данных\n" << "\tПовторный ввод данных\n";
            else if (bettingAmount > amount)  cout << "\tВаша ставка слишком большая\n" << "\n\tПовторный ввод данных\n ";
            else break;
        }
        system("cls");
        cout << "\n\n\tНынешний баланс $ " << amount << "\n";
        cout << "\tСтавка $ " << bettingAmount << "\n\n";


        // Get player's numbers
        do
        {
            cout << "\tВыберете число от 1 до 10: ";
            cin >> guess; //считывание введенных значений
            if (guess <= 0 || guess > 10)
                cout << "\tПроверьте число!! оно должно быть от 1 до 10 \n"
                << "\n\tВведите еще раз\n ";
        } while (guess <= 0 || guess > 10);

        dice = rand() % 10 + 1; // Will hold the randomly generated integer between 1 and 10

        if (dice == guess)
        {
            cout << "\n\n\tВы угадали!! Ваш выигрыш " << bettingAmount * 10;
            amount = amount + bettingAmount * 10;
        }
        else
        {
            cout << "\n\n\tУдача была не на вашей стороне! Вы проиграли $ " << bettingAmount << "\n";
            amount = amount - bettingAmount;
        }

        cout << "\n\tЗагаданное число: " << dice << "\n";
        cout << "\n\t" << playerName << ", На вашем счету $ " << amount << "\n";
        if (amount == 0)
        {
            cout << "\tУ вас больше нет средств, чтобы продолжить игру.";
            break;
        }
        cout << "\n\n\t-->Играть снова ( 1 - да / 0 - нет )? ";
        cin >> choice;
    } while (choice == '1');

    cout << "\n\n\n";
    drawLine(70, '=');
    cout << "\n\n\tСпасибо за игру. Ваш баланс составляет $ " << amount << "\n\n";
    drawLine(70, '=');

}

