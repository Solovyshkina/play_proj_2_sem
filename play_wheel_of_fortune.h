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
    cout << "\n\n\t\tИГРА  КОЛЕСО ФОРТУНЫ\n\n\n";
    drawLine(80, '_');

    cout << "\t\tПРАВИЛА ИГРЫ\n";
    drawLine(80, '-');
    cout << "\t1. Когда начинается игра, запускается колесо фортуны.\n";
    cout << "\t2. Только судьба повлияет на исход игры. Вы одержите победу, если выподает три одинаковых слова.\n";
    cout << "\t3. Одержав победу, ваша ставка увеличится в 10 раз.\n";
    cout << "\t4. Если проиграете, то выш баланс уменьшится на величину ставки.\n\n";
    drawLine(80, '-');

    while (true)
    {
        cout << "\n\n\tВведите величину депозита, чтобы начать игру: $ ";
        cin >> amount;
        cin.ignore();
        if (amount > 0) break;
        else cout << "\tПопробуйте еще раз \n";
    }

    array <string, 9> a_1 = { "CHERRY","WATERMELON","BANANA", "CHERRY","WATERMELON","BANANA", "CHERRY","WATERMELON","BANANA" };
    array <string, 9> a_2 = { "BANANA","CHERRY","WATERMELON", "BANANA","CHERRY","WATERMELON", "BANANA","CHERRY","WATERMELON" };
    array <string, 9> a_3 = { "WATERMELON","BANANA","CHERRY", "WATERMELON","BANANA","CHERRY", "WATERMELON","BANANA","CHERRY" };

    do {
        do
        {
            cout << "\tВаша ставка: $ ";
            cin >> bettingAmount;
            if (bettingAmount > amount or bettingAmount <= 0)
                cout << "\tНекорректные данные \n"
                << "\n\tПопробуйте еще раз \n ";
        } while (bettingAmount > amount or bettingAmount < 0);

        system("cls");
        cout << "\n\tВаш баланс $ " << amount << "\n";
        cout << "\n\tВаша ставка $ " << bettingAmount << "\n";

        string v1, v2, v3;
        v1 = a_1[rand() % 9];
        v2 = a_2[rand() % 9];
        v3 = a_3[rand() % 9];
        drawLine(80, '=');
        cout << "\n\t" << v1 << " " << v2 << " " << v3 << "\n" << endl;
        drawLine(80, '=');

        if (v1 == v2 && v2 == v3)
        {
            cout << "\n\n\tПоздравляем! Вы выиграли $ " << bettingAmount * 10 << "\n";
            amount = amount + bettingAmount * 10;
        }
        else
        {
            cout << "\tНеудача! Вы проиграли $ " << bettingAmount << "\n";
            amount = amount - bettingAmount;
        }
        cout << "\n\t" << "На вашем счету $ " << amount << "\n";
        if (amount == 0)
        {
            cout << "\n\tУ вас закончились средства!";
            break;
        }
        cout << "\n\n\tХотите продолжить игру? ( да - 1 / нет - 0 )? ";
        cin >> choice;
    } while (choice == '1');

    cout << "\n\n\n";
    drawLine(70, '=');
    cout << "\n\n\tСпасибо за игру. Ваш баланс составляет $ " << amount << "\n\n";
    drawLine(70, '=');
  
}
