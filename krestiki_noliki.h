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
    cout << "\n\n\t\tИГРА  КРЕСТИКИ-НОЛИКИ\n\n\n";
    drawLine(80, '_');

    cout << "\t\tПРАВИЛА ИГРЫ\n";
    drawLine(80, '-');
    cout << "\t1. В игре принимают участие два игрока, которые по очереди рисуют крестики/нолики в свободных ячейках.\n";
    cout << "\t2. Выигрывает тот, кто первый поставил в ряд три своих знака.\n";
    cout << "\t3. Если вы выиграете, то получите в 10 раз больше денег, чем поставили.\n";
    cout << "\t4. Если же ваш соперник опередит вас, то вы потеряете сумму своей ставки.\n\n";
    drawLine(80, '-');;

    cout << "\n\tВведите имя первого игрока: ";
    cin.get();
    getline(cin, name1);

    cout << "\n\tВведите имя второго игрока: ";

    getline(cin, name2);

    while (true)
    {
        cout << "\n\n\tВведите сумму депозита 1-го игрока, чтобы начать игру: $ ";
        cin >> amount1;
        cin.ignore();

        cout << "\n\n\tВведите сумму депозита 2-го игрока, чтобы начать игру: $";
        cin >> amount2;

        if (amount1 <= 0 || amount2 <= 0)
            cout << "\n\tВы ввели некоректные данные\n"
            << "\n\tПовторный ввод данных\n ";
        else break;
    }
    do
    {


        while (true)
        {
            cout << "\n\t" << name1 << ", введите сумму вашей ставки: $ ";
            cin >> bettingAmount1;

            cout << "\n\t" << name2 << ", введите сумму вашей ставки: $ ";
            cin >> bettingAmount2;

            if (bettingAmount1 > amount1 || bettingAmount2 > amount2) cout << "\n\tВаша ставка слишком большая" << "\n\tПовторный ввод данных\n";
            else break;
        }

        system("cls");
        cout << "\n\t" << name1 << ", ваш баланс $ " << amount1 << ", а ставка $" << bettingAmount1 << "\n";
        cout << "\n\t" << name2 << ", ваш баланс $ " << amount2 << ", а ставка $" << bettingAmount2 << "\n";

        a = "НОЛИКИ";
        b = "КРЕСТИКИ";
        z = '0';
        c = 'X';
        while (true)
        {
            cout << "\n\tЗа кого ходит первый игрок?(введите 0 или X): ";

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
            else cout << "\n\t Попробуйте ещё раз.\n";
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
            cout << "\n\tСделайте ваш ход (" << s << ")" << endl;
            cout << "\n\tСтрока: ";
            cin >> x;
            cout << "\tСтолбец: ";
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
                cout << "\tДанная позиция занята!" << endl;
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
                cout << "\tИгра закончена! ";
                if ((A[x][y] == z) && (dgt == 1))
                {
                    cout << "\n\t" << name1 << " победил(a)! Вы выиграли: " << bettingAmount1 * 10 << ". Теперь сумма на вашем счету составляет: " << amount1 + bettingAmount1 * 10 << "\n "
                        << "\t" << name2 << " проиграл(а)! Вы проиграли: " << bettingAmount2 << ". Теперь сумма на вашем счету составляет: " << amount2 - bettingAmount2 << endl;
                    amount1 = amount1 + bettingAmount1 * 10;
                    amount2 = amount2 - bettingAmount2;
                }
                else if ((A[x][y] == c) && (dgt == 2))
                {
                    cout << "\n\t" << name1 << " победил(а)! Вы выиграли: " << bettingAmount1 * 10 << ". Теперь сумма на вашем счету составляет: " << amount1 + bettingAmount1 * 10 << "\n "
                        << "\t" << name2 << " проиграл(а)! Вы проиграли: " << bettingAmount2 << ". Теперь сумма на вашем счету составляет: " << amount2 - bettingAmount2 << endl;
                    amount1 = amount1 + bettingAmount1 * 10;
                    amount2 = amount2 - bettingAmount2;
                }
                else if ((A[x][y] == c) && (dgt == 1))
                {
                    cout << "\n\t" << name2 << " победил(а)! Вы выиграли: " << bettingAmount2 * 10 << ". Теперь сумма на вашем счету составляет: " << amount2 + bettingAmount2 * 10 << "\n"
                        << "\t" << name1 << " проиграл(а)! Вы проиграли: " << bettingAmount1 << ". Теперь сумма на вашем счету составляет: " << amount1 - bettingAmount1 << endl;
                    amount1 = amount1 - bettingAmount1;
                    amount2 = amount2 + bettingAmount2 * 10;
                }
                else if ((A[x][y] == z) && (dgt == 2))
                {
                    cout << "\n\t" << name2 << " победил(а)! Вы выиграли: " << bettingAmount2 * 10 << ". Теперь сумма на вашем счету составляет: " << amount2 + bettingAmount2 * 10 << "\n"
                        << "\t" << name1 << " проиграл(а)! Вы проиграли: " << bettingAmount1 << ". Теперь сумма на вашем счету составляет: " << amount1 - bettingAmount2 << endl;
                    amount1 = amount1 - bettingAmount1;
                    amount2 = amount2 + bettingAmount2 * 10;
                }
                break;
            }

        }
        if (!(k)) cout << "\n\tИгра закончилась вничью!" << endl;
        cout << "\n\n\tХотите продолжить игру? ( да - 1 / нет - 0 )? ";
        cin >> choice;

    } while (choice == '1');

    cout << "\n\n\n";
    drawLine(70, '=');
    cout << "\n\n\tСпасибо за игру. Ваш баланс составляет: " << name1 << " = " << amount1 << ", " << name2 << " = " << amount2 << "\n\n";
    drawLine(70, '=');
   
}
