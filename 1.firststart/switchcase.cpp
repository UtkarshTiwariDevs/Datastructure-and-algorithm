#include<iostream>
using namespace std;

int main(){
    char button;
    cout<<"Enter a character\n";
    cin>>button;

    switch (button)
    {
    case 'a':
    cout<<"hello";
        break;
    case 'b':
    cout<<"Namaste";
        break;
    case 'c':
    cout<<"Hola";
        break;
    case 'd':
    cout<<"Cios";
        break;
    
    default:
    cout<<"Still learning";
        break;
    }
}