#include "zadachi.h"
using namespace std;


int zadacha1(int*& arr, int& n) {     
    cout << "Enter n: ";             
    vkaranoChislo(n, 1, INT32_MAX); 
    arr = new int[n];     
    if (arr != nullptr) {                             
        for (int i = 0; i < n; i++) {   
            arr[i] = i;
        }
    }                 
    cout << endl;
    return 0;
}


int zadacha2(int n, int& a, int& b) {
    
    cout << "Enter the first number: ";
    vkaranoChislo(a, 0, n - 1);
    cout << "Enter the second number: ";
    vkaranoChislo(b, 0, n - 1);

    cout << a << " + " << b << " = " << (a + b) % n << endl;
    return 0;
}


int zadacha3(int n, int& a, int& b) {
    
    cout << "Enter the first number: ";
    vkaranoChislo(a, 0, n - 1);
    cout << "Enter the second number: ";
    vkaranoChislo(b, 0, n - 1);

    int result = (a - b) % n;

    if (result < 0) {
        result += n;
    }
    cout << a << " - " << b << " = " << result << endl;
    return 0;
}


int zadacha4(int n, int& a, int& b) {

    cout << "Enter the first number: ";
    vkaranoChislo(a, 0, n - 1);
    cout << "Enter the second number: ";
    vkaranoChislo(b, 0, n - 1);

    cout << a << " * " << b << " = " << (a * b) % n << endl;
    return 0;
}


int zadacha5_0(int*& arr, int n) { 

    if (arr == nullptr) {
        delete[] arr;   
        arr = nullptr;
    }

    arr = new int[n];

    if (arr != nullptr) {
        for (int i = 0; i < n; i++) {
            arr[i] = -1;
        }           
        for (int i = 1; i < n; i++) {
            if (arr[i] != -1) continue;
            for (int j = 0; j < n; j++) {
                if ((i * j) % n == 1) {
                    arr[i] = j;
                    arr[j] = i;
                }
            }           
        }
    }
    return 0;
}


int zadacha5_1(int*& arr, int n) {

    if (arr == nullptr) {
        zadacha5_0(arr, n);
    }    
    if (arr != nullptr) {
        for (int i = 0; i < n; i++) {
            if (arr[i] != -1) {
                cout << 1 << "/" << i << " = " << arr[i] << endl;
            }
            else {
                cout << "1/" << i << " isn't divisible" << endl;
            }
        }
    }
    return 0;
}


int zadacha6(int* arr, int n, int a) {
    cout << "Enter a number: ";
    vkaranoChislo(a, 0, n - 1);

    if (arr == nullptr) {
        zadacha5_0(arr, n);
    }
    if (arr != nullptr) {
        cout << "1/" << a << " = " << arr[a] << endl;
    }
    return 0;
}



int zadacha8(int*& arr, int n, int a, int b) {
    
    cout << "Enter the first number: ";
    vkaranoChislo(a, 0, n - 1);
    cout << "Enter the second number: ";
    vkaranoChislo(b, 0, n - 1);
                                                                                             
    if (arr == nullptr) {                                                                   
        zadacha5_0(arr, n);                                                                                                             
    }                                                                                                                              
    if (arr != nullptr) {       
        cout << a << "/" << b << " = " << (a * arr[b]) % n << endl;
    }                                                                                    //Checking results for Z(7):
    else {                                                                              //2 : 3 ≡ 2 × (1/3) ≡ 2 × 5 ≡ 3
        cout << "-1" << endl;                                                          //5 : 6 ≡ 5 × (1/6) ≡ 5 × 6 ≡ 2
    }                                                                                 //3 : 4 ≡ 3 × (1/4) ≡ 3 × 2 ≡ 6
    return 0;
}


int zadacha9(int n) {
    
    int base, exp, k = 1, res = 0;
    cout << "Enter the base: "; 
    vkaranoChislo(base, 0, n - 1); 
    cout << "Enter the exponent: ";
    vkaranoChislo(exp, INT32_MIN, INT32_MAX); 
    
    res = base;

    while (res != 1 && exp != k) {
        k++;
        res = base * res % n;
    }
    if (k != exp) {
        cout << base << " to the power of " << exp << " is " << (int)pow(base, exp % k) % n << endl;
    }
    else {
        cout << base << " to the power of " << exp << " is " << res << endl;
    }
    return 0;

}


int zadacha10(int n)
{
    int binaryNum[1024];
    int base, exp, i = 0, temp, z = 0, q = 0;
    long long unsigned int y = 1;
    cout << "Enter the base: ";
    vkaranoChislo(base, 0, n - 1); 
    cout << "Enter the exponent: ";
    vkaranoChislo(exp, INT32_MIN, INT32_MAX); 

    temp = exp;

    while (temp > 0) {
        binaryNum[i] = temp % 2;
        temp = temp / 2;
        i++;
    }
    for (int k = 0; k < i; k++) {
        if (binaryNum[k] == 1) {
            q++;
        }
    }

    int* numbers = new int[q];

    for (int j = 0; j < i; j++) {
        if (binaryNum[j] == 1) {
            numbers[z] = (int)pow(base, j) % n ;
            z++;
        }
    }
    for (int x = 0; x < z; x++) {
        y = y * (int)(numbers[x]);
    }
    cout << base << " to the power of " << exp << " is " << y % n << endl;

    delete[] numbers;
    return 0;
}

int zadacha14(int n) {

    int cnt = 0;
    for (int i = 2; i < n; i++)
    {
        if ((n % i) != 0)
        {
            cnt++;
        }
    }
    if (cnt == (n - 2) || n == 1)
    {
        cout << "The residual ring of " << n << " is a residual field" << endl;
    }
    else
    {
        cout << "The residual ring of " << n << " is not a residual field" << endl;
    }
    return 0;
}