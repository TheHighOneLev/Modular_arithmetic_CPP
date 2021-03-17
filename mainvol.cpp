#include <iostream>
#include "menu.h"
#include "com_functions.h"
using namespace std;

int main()
{
    int opt, n = 0;
    int** arr = new int* [3];
    arr[0] = arr[1] = nullptr;

    if (arr != nullptr) {                           
        do {
            printMenu();
            cout << "Enter your choice: ";      
            vkaranoChislo(opt);                 
        } while (menu(opt, arr, n));
                                                
        if (arr[0] != nullptr) {                     
            delete[] arr[0];
            arr[0] = nullptr;
        }
        if (arr[1] != nullptr) {
            delete[] arr[1];
            arr[1] = nullptr;
        }
        if (arr[2] != nullptr) {
            delete[] arr[2];
            arr[2] = nullptr;
        }
        delete[] arr;
        arr = nullptr;
    }
    return 0;
}

