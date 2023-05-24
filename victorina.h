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
    cout << "\n\n\t\tИГРА  ВИКТОРИНА\n\n\n";
    drawLine(80, '_');

    cout << "\t\tПРАВИЛА ИГРЫ\n";
    drawLine(80, '-');
    cout << "\t1. Вам будут предложены вопросы и в качестве подсказки - количество букв, содержащихся в ответе.\n";
    cout << "\t2. Вы можете проверять отдельные буквы или ввести слово целиком.\n";
    cout << "\t3. Если вы угадаете нужное слово, то выиграете и получите в 10 раз больше денег, чем поставили.\n";
    cout << "\t4. Для этого у вас будет 10 попыток, после игра завершится автоматически. \n";
    cout << "\t5. Если вы не угадаете нужное слово, то вы потеряете сумму своей ставки.\n\n";
    drawLine(80, '-');

    while (true)
    {
        cout << "\n\n\tВведите сумму депозита, чтобы начать игру: $";
        cin >> amount;
        if (amount <= 0) cout << "\n\t Ввод некорректных данных\n";
        else break;
    }


    string question[5] = { "Метод класса, применяемый для освобождения памяти, занимаемой объектом? ","Механизм, посредством которого производный класс получает элементы родительского и может дополнять либо изменять их свойства и методы? ",
        "Экземпляром класса является? ", "Средство, позволяющее использовать одно имя для обозначения действий, общих для родственных классов? ",
        "Метод, имя которого совпадает с именем класса и который вызывается автоматически при создании объекта класса? " };// вопрос
    string word[5] = { "деструктор","наследование","объект","полиморфизм","конструктор" }; // ответ
    string abc, xword; // вводимый ответ, витрина с иксами

    do
    {
        while (true)
        {
            cout << "\n\tВведите сумму для ставки: $";
            cin >> bettingAmount;
            if (bettingAmount > amount)
                cout << "\n\tСумма вашей ставки больше, чем ваш текущий баланс\n"
                << "\n\tПовторный ввод данных\n ";
            else break;
        }


        cout << "\n\tВаш баланс - " << amount << "$, а ставка - " << bettingAmount << "$\n";

        srand(time(NULL)); // установка стартового значения для генератора случайных чисел
        int index = 1 + rand() % 4, p = 0, abcSize = 0; // генерация случайного вопроса, посчёт попыток, размер текста ввода
        const int wordsize = word[index].length();  // длинна ответа из массива
        xword.clear();
        for (int i = 0; i < wordsize; i++) xword.append("Х");// формирования витрины


        do {
            system("cls");
            cout << "\n\tВаш баланс - " << amount << "$, а ставка - " << bettingAmount << "$\n";

            cout << "\n\n\tПопытка №" << p + 1;
            cout << "\n\n\t" << question[index] << "\n\n\t\t" << xword << "\n\n\tВведите букву > ";
            cin >> abc; 
            abcSize = abc.size();

            if (abcSize > wordsize) { cout << "\n\n\tОшибка! Переполнение ввода!"; system("pause>nul"); continue; }


            if (abc == word[index]) { p++; break; } // если ввели целое слово 

            else if (abcSize > 1) { p++; cout << "\n\tНеправильное слово, подумайте еще \n"; system("pause>nul"); continue; }//попытка угадать слово целиком(штраф 1)
            else {
                for (int i = 0; i < wordsize; i++)
                    for (int j = 0; j < abcSize; j++) if (word[index][i] == abc[j]) xword[i] = abc[j]; // посимвольное сравнение 
                p += abcSize;
            }


            if (p == 10)break;

        } while (xword != word[index]);



        system("cls");
        cout << "\n\n\t" << question[index];
        if ((xword == word[index]) || abc == word[index])
        {
            cout << "\n\n\tВаш ответ: " << word[index] << "\n\n\tКоличество попыток : " << p << ". Вы выиграли : " << bettingAmount * 10 << ". Теперь сумма на вашем счету составляет : " << amount + bettingAmount * 10 << endl;
            amount = amount + bettingAmount * 10;
        }
        else
        {
            cout << "\n\n\tПравильный ответ: " << word[index] <<
                "\n\n\tПопытки закончились!" << " Вы проиграли: " << bettingAmount << ". Теперь сумма на вашем счету составляет : " << amount - bettingAmount << endl;
            amount = amount - bettingAmount;
        }
        if (amount == 0)
        {
            cout << "\n\tУ вас закончились средства!";
            break;
        }

        cout << "\n\n\tХотите продолжить игру? ( да - 1 / нет - 0 )? ";
        cin >> choice;

    } while (choice == '1');

    cout << "\n\n\n";
    drawLine(80, '=');
    cout << "\n\n\tСпасибо за игру. Ваш баланс составляет $ " << amount << "\n\n";
    drawLine(80, '=');
}

