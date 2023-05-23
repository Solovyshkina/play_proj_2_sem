#include <iostream>
#include <string> // Needed to use strings
#include <cstdlib> // Needed to use random numbers
#include <ctime>
#include <array>
using namespace std;

void drawLine(int n, char symbol);


void play_guess_the_number()
{
    system("chcp 1251>nul");
    string playerName;
    int amount; // hold player's balance amount
    int bettingAmount;
    int guess;
    int dice; // hold computer generated number
    char choice;

    srand(time(0)); // "Seed" the random generator

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
            cout <<"\t" << playerName << ", Сделайте ставку: $ ";
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


void play_wheel_of_fortune()
{
    srand(time(0)); // "Seed" the random generator
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
            if (bettingAmount > amount or bettingAmount<=0)
                cout << "\tНекорректные данные \n"
                << "\n\tПопробуйте еще раз \n ";
        } while (bettingAmount > amount or bettingAmount<0);

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
            cout << "\n\n\tПоздравляем! Вы выиграли $ " << bettingAmount * 10 <<"\n";
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
        cout << "\n\t" << name1 <<", ваш баланс $ " << amount1 << ", а ставка $" << bettingAmount1 <<"\n";
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
                    cout <<"\n\t" << name1 << " победил(a)! Вы выиграли: " << bettingAmount1 * 10 << ". Теперь сумма на вашем счету составляет: " << amount1 + bettingAmount1 * 10 << "\n "
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
                    amount2 = amount2 + bettingAmount2*10;
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
     
    }while (choice == '1');

    cout << "\n\n\n";
    drawLine(70, '=');
    cout << "\n\n\tСпасибо за игру. Ваш баланс составляет: " <<name1 << " = "<<amount1<<", "<< name2 << " = "<< amount2 << "\n\n";
    drawLine(70, '=');
}


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
            cin >> abc; abcSize = abc.size();

            if (abcSize > wordsize) { cout << "\n\n\tОшибка! Переполнение ввода!"; system("pause>nul"); continue; }


            if (abc == word[index]) { p++; break; } // если ввели целое слово 

            else if (abcSize > 1) {p++; cout << "\n\tНеправильное слово, подумайте еще \n"; system("pause>nul"); continue; }//попытка угадать слово целиком(штраф 1)
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
            cout << "\n\n\tВаш ответ: " << word[index] << "\n\n\t\Количество попыток : "<< p <<". Вы выиграли : " << bettingAmount * 10 << ". Теперь сумма на вашем счету составляет : " << amount + bettingAmount * 10 << endl;
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


void drawLine(int n, char symbol)
{
    for (int i = 0; i < n; i++)
        cout << symbol;
    cout << "\n";
}

void start()
{
    cout << "\n\tПРИВЕТСТВУЕМ, ДОРОГОЙ ДРУГ! ДОБРО ПОЖАЛОВАТЬ В НАШУ ЧЕСТНУЮ ИГРУ!" << endl;
    cout << "\t---------------------МОЖЕШЬ ВЫБРАТЬ ИГРУ------------------------" << endl;
    cout << "\t\t                    УДАЧИ!!!\n" << endl;
}

int main()
{
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