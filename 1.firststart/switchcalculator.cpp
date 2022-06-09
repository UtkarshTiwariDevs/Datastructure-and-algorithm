#include <iostream>
using namespace std;

int main()
{  
    int again;
    while (true)
    {
        float a, b, ans;
        int choice;
        cout << "Enter Your choice:\n1 for addition\n2 for substraction\n3 for multiplication\n4 for division\n";
        cin >> choice;
        cout << "Now enter two numbers \n";
        cin >> a >> b;

        switch (choice)
        {
        case 1:
            cout << a << " + " << b << " = ";
            ans = a + b;
            cout << ans << endl;
            break;
        case 2:
            cout << a << " - " << b << " = ";
            ans = a - b;
            cout << ans << endl;
            break;
        case 3:
            cout << a << " * " << b << " = ";
            ans = a * b;
            cout << ans << endl;
            break;
        case 4:
            cout << a << " / " << b << " = ";
            ans = a / b;
            cout << ans << endl;
            break;
        default:
            cout << "Wrong choice entered" << endl;
            break;
        }
        cout << "Want to use calculator again then press 1 or else 2" << endl;
        cin >> again;
        if (again == 1)
        {
            continue;
        }
        else
        {
            break;
        }
    }
}