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
            cout <<"\t" << playerName << ", �������� ������: $ ";
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


void play_wheel_of_fortune()
{
    srand(time(0)); // "Seed" the random generator
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
            if (bettingAmount > amount or bettingAmount<=0)
                cout << "\t������������ ������ \n"
                << "\n\t���������� ��� ��� \n ";
        } while (bettingAmount > amount or bettingAmount<0);

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
            cout << "\n\n\t�����������! �� �������� $ " << bettingAmount * 10 <<"\n";
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


void krestiki_noliki()
{
    system("chcp 1251>nul");
    const int N = 3;
    int amount1, amount2, bettingAmount1, bettingAmount2, x, y, k, dgt;
    char A[N][N], c, z, element, choice;
    string s, a, b, name1, name2;

    drawLine(80, '_');
    cout << "\n\n\t\t����  ��������-������\n\n\n";
    drawLine(80, '_');

    cout << "\t\t������� ����\n";
    drawLine(80, '-');
    cout << "\t1. � ���� ��������� ������� ��� ������, ������� �� ������� ������ ��������/������ � ��������� �������.\n";
    cout << "\t2. ���������� ���, ��� ������ �������� � ��� ��� ����� �����.\n";
    cout << "\t3. ���� �� ���������, �� �������� � 10 ��� ������ �����, ��� ���������.\n";
    cout << "\t4. ���� �� ��� �������� �������� ���, �� �� ��������� ����� ����� ������.\n\n";
    drawLine(80, '-');;

    cout << "\n\t������� ��� ������� ������: ";
    cin.get();
    getline(cin, name1);
    
    cout << "\n\t������� ��� ������� ������: ";
    
    getline(cin, name2);
   
    while (true)
    {
        cout << "\n\n\t������� ����� �������� 1-�� ������, ����� ������ ����: $ ";
        cin >> amount1;
       cin.ignore();

        cout << "\n\n\t������� ����� �������� 2-�� ������, ����� ������ ����: $";
        cin >> amount2;
                    
        if (amount1 <= 0 || amount2 <= 0)
            cout << "\n\t�� ����� ����������� ������\n"
            << "\n\t��������� ���� ������\n ";
       else break;
    }
    do
    {


        while (true)
        {
            cout << "\n\t" << name1 << ", ������� ����� ����� ������: $ ";
            cin >> bettingAmount1;

            cout << "\n\t" << name2 << ", ������� ����� ����� ������: $ ";
            cin >> bettingAmount2;

            if (bettingAmount1 > amount1 || bettingAmount2 > amount2) cout << "\n\t���� ������ ������� �������" << "\n\t��������� ���� ������\n";
            else break;
        }

        system("cls");
        cout << "\n\t" << name1 <<", ��� ������ $ " << amount1 << ", � ������ $" << bettingAmount1 <<"\n";
        cout << "\n\t" << name2 << ", ��� ������ $ " << amount2 << ", � ������ $" << bettingAmount2 << "\n";
        
        a = "������";
        b = "��������";
        z = '0';
        c = 'X';
        while (true)
        {
            cout << "\n\t�� ���� ����� ������ �����?(������� 0 ��� X): ";

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
            else cout << "\n\t ���������� ��� ���.\n";
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
            cout << "\n\t�������� ��� ��� (" << s << ")" << endl;
            cout << "\n\t������: ";
            cin >> x;
            cout << "\t�������: ";
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
                cout << "\t������ ������� ������!" << endl;
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
                cout << "\t���� ���������! ";
                if ((A[x][y] == z) && (dgt == 1))
                {
                    cout <<"\n\t" << name1 << " �������(a)! �� ��������: " << bettingAmount1 * 10 << ". ������ ����� �� ����� ����� ����������: " << amount1 + bettingAmount1 * 10 << "\n "
                        << "\t" << name2 << " ��������(�)! �� ���������: " << bettingAmount2 << ". ������ ����� �� ����� ����� ����������: " << amount2 - bettingAmount2 << endl;
                    amount1 = amount1 + bettingAmount1 * 10;
                    amount2 = amount2 - bettingAmount2;
                }
                else if ((A[x][y] == c) && (dgt == 2))
                {
                    cout << "\n\t" << name1 << " �������(�)! �� ��������: " << bettingAmount1 * 10 << ". ������ ����� �� ����� ����� ����������: " << amount1 + bettingAmount1 * 10 << "\n "
                        << "\t" << name2 << " ��������(�)! �� ���������: " << bettingAmount2 << ". ������ ����� �� ����� ����� ����������: " << amount2 - bettingAmount2 << endl;
                    amount1 = amount1 + bettingAmount1 * 10;
                    amount2 = amount2 - bettingAmount2;
                }
                else if ((A[x][y] == c) && (dgt == 1))
                {
                    cout << "\n\t" << name2 << " �������(�)! �� ��������: " << bettingAmount2 * 10 << ". ������ ����� �� ����� ����� ����������: " << amount2 + bettingAmount2 * 10 << "\n"
                        << "\t" << name1 << " ��������(�)! �� ���������: " << bettingAmount1 << ". ������ ����� �� ����� ����� ����������: " << amount1 - bettingAmount1 << endl;
                    amount1 = amount1 - bettingAmount1;
                    amount2 = amount2 + bettingAmount2*10;
                }
                else if ((A[x][y] == z) && (dgt == 2))
                {
                    cout << "\n\t" << name2 << " �������(�)! �� ��������: " << bettingAmount2 * 10 << ". ������ ����� �� ����� ����� ����������: " << amount2 + bettingAmount2 * 10 << "\n"
                        << "\t" << name1 << " ��������(�)! �� ���������: " << bettingAmount1 << ". ������ ����� �� ����� ����� ����������: " << amount1 - bettingAmount2 << endl;
                    amount1 = amount1 - bettingAmount1;
                    amount2 = amount2 + bettingAmount2 * 10;
                }
                break;
            }
           
        }
        if (!(k)) cout << "\n\t���� ����������� ������!" << endl;
        cout << "\n\n\t������ ���������� ����? ( �� - 1 / ��� - 0 )? ";
        cin >> choice;
     
    }while (choice == '1');

    cout << "\n\n\n";
    drawLine(70, '=');
    cout << "\n\n\t������� �� ����. ��� ������ ����������: " <<name1 << " = "<<amount1<<", "<< name2 << " = "<< amount2 << "\n\n";
    drawLine(70, '=');
}


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
            cin >> abc; abcSize = abc.size();

            if (abcSize > wordsize) { cout << "\n\n\t������! ������������ �����!"; system("pause>nul"); continue; }


            if (abc == word[index]) { p++; break; } // ���� ����� ����� ����� 

            else if (abcSize > 1) {p++; cout << "\n\t������������ �����, ��������� ��� \n"; system("pause>nul"); continue; }//������� ������� ����� �������(����� 1)
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
            cout << "\n\n\t��� �����: " << word[index] << "\n\n\t\���������� ������� : "<< p <<". �� �������� : " << bettingAmount * 10 << ". ������ ����� �� ����� ����� ���������� : " << amount + bettingAmount * 10 << endl;
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


void drawLine(int n, char symbol)
{
    for (int i = 0; i < n; i++)
        cout << symbol;
    cout << "\n";
}

void start()
{
    cout << "\n\t������������, ������� ����! ����� ���������� � ���� ������� ����!" << endl;
    cout << "\t---------------------������ ������� ����------------------------" << endl;
    cout << "\t\t                    �����!!!\n" << endl;
}

int main()
{
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