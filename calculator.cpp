#include <iostream>
#include <limits>
using namespace std;

int main()
{   
    char choice;
    do
    {
        cout << "Enter two numbers and the operation you want to perform (+, -, *, /): " << endl;
        float num1, num2;
        char ch;

        if (!(cin >> num1 >> ch >> num2))
        {
            cout << "Invalid input. Please enter numeric values for the numbers and a valid operator (+, -, *, /)." << endl;
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            
            cout << "Do you want to perform another calculation? (y/n): ";
            cin >> choice;
            continue; 
        }

        switch(ch)
        {
            case '+':
                cout << "The addition of the two numbers is: " << num1 + num2 << endl;
                break;
            
            case '-':
                cout << "The subtraction of the two numbers is: " << num1 - num2 << endl;
                break;

            case '*':
                cout << "The multiplication of the two numbers is: " << num1 * num2 << endl;
                break;

            case '/':
                if (num2 != 0)
                    cout << "The division of the two numbers is: " << num1 / num2 << endl;
                else
                    cout << "Error: Division by zero is not allowed." << endl;
                break;

            default:
                cout << "Invalid operation. Please enter a valid operator (+, -, *, /)." << endl;
        }

        cout << "Do you want to perform another calculation? (y/n): ";
        cin >> choice;

    } while(choice == 'y' || choice == 'Y');

    return 0;
}
