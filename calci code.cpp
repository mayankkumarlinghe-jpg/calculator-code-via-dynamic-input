#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int choice;
    double a, b;

    cout << "_________SIMPLE C++ CALCULATOR________\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
    cout << "5. Floor Division\n";
    cout << "6. Square\n";
    cout << "7. Square Root\n";
    cout << "_______________________________________\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch(choice) {
        case 1:
            cout << "Enter two numbers: ";
            cin >> a >> b;
            cout << "Result = " << a + b;
            break;

        case 2:
            cout << "Enter two numbers: ";
            cin >> a >> b;
            cout << "Result = " << a - b;
            break;

        case 3:
            cout << "Enter two numbers: ";
            cin >> a >> b;
            cout << "Result = " << a * b;
            break;

        case 4:
            cout << "Enter two numbers: ";
            cin >> a >> b;
            if(b != 0)
                cout << "Result = " << a / b;
            else
                cout << "Error: Division by zero!";
            break;

        case 5:
            cout << "Enter two numbers: ";
            cin >> a >> b;
            if(b != 0)
                cout << "Result = " << floor(a / b);
            else
                cout << "Error: Division by zero!";
            break;

        case 6:
            cout << "Enter a number: ";
            cin >> a;
            cout << "Result = " << a * a;
            break;

        case 7:
            cout << "Enter a number: ";
            cin >> a;
            if(a >= 0)
                cout << "Result = " << sqrt(a);
            else
                cout << "Error: Negative number!";
            break;

        default:
            cout << "Invalid Choice!";
    }

    return 0;
}
