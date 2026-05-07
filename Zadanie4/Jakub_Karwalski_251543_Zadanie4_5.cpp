//Jakub Karwalski
//Zadanie 4.5

#include <iostream>
#include <cmath>

int zamiana(int);

using namespace std;

int main()
{
    int liczba;
    cout << "Program wczytujacy liczbe z zakresu 0-100 000 i wypisuje ja w siodemkowym systemime liczbowym" << endl;
    cout << "Podaj liczbe:";
    cin >> liczba;
    if (liczba>=0 && liczba <=100000)
    {
        cout << endl << "Liczba po przeliczeniu na system siodemkowy wynosi: ";
        zamiana (liczba);
    }
    else
    {
        cout << "Nie podales poprawnej wartosci!";
    }
    return 0;
}

int zamiana (int liczba)
{
    if(liczba == 0)
    {
        return 0;
    }
    zamiana(liczba / 7);
    cout << liczba % 7;
}
