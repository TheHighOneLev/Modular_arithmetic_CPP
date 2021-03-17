#include "com_functions.h"
using namespace std;

int print_array(int** arr, int n) 
{
    //Ако има въведен масив и n>0 и има елемент на нулева позиция от масива и има елемент на първа позиция от масива
    if (arr != nullptr && n > 0 && arr[0] != nullptr && arr[1] != nullptr) 
    {
        for (int i = 0; i < n; i++) 
        {
            if (arr[1][i] != -1) 
            {
                cout << "1/" << arr[0][i] << " = " << arr[1][i] << endl;
            }
            else 
            {
                cout << "1/" << arr[0][i] << " is not divisible" << endl;
            }
        }
    }
    cout << endl << endl;

    return 0;
}

int vkaranoChislo(int& num, int mini, int maxi) //Input number 
{
    char ch[50];
    bool correct = true;
    int i = 0;

    do 
    {                                                                                               
        do 
        {
            correct = true;
            cin.getline(ch, 50);    //Чете unformatted set of characters
            if (strlen(ch) == 0) 
            {
                correct = false;
                continue;                                               //Strlen дава дължината на горното
            }
            i = 0;  
            if (ch[0] == '-' && strlen(ch) > 1) i++;

            for (; i<int(strlen(ch)); i++) 
            {
                if (!(ch[i] >= '0' && ch[i] <= '9')) 
                {
                    correct = false;
                    break;
                }
            }

            if (!correct) cout << "Incorrect number!" << endl;

        } while (!correct);

        num = 0;
        i = 0;
        if (ch[0] == '-') i++;
        for (; i<int(strlen(ch)); i++) 
        {
            num = num * 10 + (ch[i] - '0');
        }
        if (ch[0] == '-') num *= -1;
        if (!(num >= mini && num <= maxi)) cout << "The value cannot be " << num << endl;

    } while (!(num >= mini && num <= maxi));

    return 0;
}

int greatest_common_divisor(int a, int b) //най-голям общ делител
{
    int tmp = a, tmp1 = a, tmp2 = b;

    while (tmp1 % tmp2 != 0) 
    {
        tmp = tmp1;
        tmp1 = tmp2;
        tmp2 = tmp % tmp1;
        if (tmp2 == 0) break;
    }

    return tmp2;
}

bool distinct_values(int* arr, int n)   //всички различни value-та
{

    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            if (arr[i] == arr[j]) return 0;
        }
    }

    return 1;
}

int cnt_s_numbers(int n) 
{
    int cnt = 0;
    for (int i = 2; i < n; i++) 
    {
        if (greatest_common_divisor(i, n) == 1) cnt++;
    }
    return cnt;
}