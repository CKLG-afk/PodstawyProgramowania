//Jakub Karwalski
//Zadanie 3.4

#include <iostream>

using namespace std;

int liczby_pit(int,int,int);

int main()
{
    int a,b,c;
    cout << "Program pobierajacy trzy liczby calkowite i jesli liczby sa pitagorejskie to wyswietli sie wartosc 1" << endl;
    cout << "Liczby pitagorejskie to takie liczby spelniajace wzor: pierwsza liczba^2+druga liczba^2=trzecia liczba^2" << endl;
    cout << "W danym programie kolejnosc ma znaczenie! " << endl;
    cout << "Podaj pierwsza liczbe: ";
    cin >> a;
    cout << "Podaj druga liczbe: ";
    cin >> b;
    cout << "Podaj trzecia liczbe: ";
    cin >> c;
    liczby_pit(a,b,c);

}
int liczby_pit(int a,int b,int c) //funkcja obliczajaca czy liczy sa pitagorejskie spelniajace warunek a^2+b^2=c^2
{
        if (a*a+b*b==c*c)
    {
        cout << "Liczby sa pitagorejskie ";
        return 1;
    }
    else
    {
        cout << "Liczby nie sa pitagorejskie ";
        return 0;
    }
}
