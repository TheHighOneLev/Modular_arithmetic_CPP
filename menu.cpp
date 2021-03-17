#include "menu.h"
using namespace std;

int
printMenu()
{   

    cout << "0. Exit" << endl;
    cout << "1. Fill an array with the elements of the ring" << endl;
    cout << "2. Sum of two elements of the ring" << endl;
    cout << "3. Substract the values of two elements of the ring" << endl;
    cout << "4. Multiply the values of two elements of the ring" << endl;
    cout << "5. Fill a 2D array with the reciprocal of the elements in the ring" << endl;
    cout << "6. Find the reciprocal of a specific element in the ring" << endl;
    cout << "7. -------------------------------------------------------------" << endl;
    cout << "8. Divide the values of two numbers in the ring" << endl;
    cout << "9. (METHOD 1) Calculate the power of an element from the residual ring using the lowest natural number" << endl;
    cout << "10. (METHOD 2) Calculate the power of an element from the residual ring using binary system" << endl;
    cout << "11. -------------------------------------------------------------" << endl;
    cout << "12. -------------------------------------------------------------" << endl;
    cout << "13. -------------------------------------------------------------" << endl;
    cout << "14. Check if the ring is a residual field" << endl;

    cout << endl;

    return 0;
}

bool
menu(int option, int**& arr, int& n) 
{
    system("cls"); 

    int a{}, b{}; 

    if (arr[0] == nullptr && option > 1)
    {
        cout << "Please initialize the array first by entering option 1 from the menu!" << endl; 
        return 1;                                       
    }

    switch (option) {
    case 1:
        zadacha1(arr[0], n);
        break;
    case 2:
        zadacha2(n, a, b);
        break;
    case 3:
        zadacha3(n, a, b);
        break;
    case 4:
        zadacha4(n, a, b);
        break;
    case 5:
        zadacha5_1(arr[1], n);   
        break;
    case 6:
        zadacha6(arr[1], n, a);
        break;
    case 8:
        zadacha8(arr[1], n, a, b);
        break;
    case 9:     
        zadacha9(n);
        break;
    case 10:       
        zadacha10(n);
        break;
    case 14:
        zadacha14(n);
        break;
    default:
        cout << "See you soon!" << endl;
        return 0;
    }
    cout << endl;
    return 1;
}