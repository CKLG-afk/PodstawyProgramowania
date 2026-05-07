//Jakub Karwalski
//Zadanie 3.5

#include <iostream>

using namespace std;

int NWD(int, int);

int main()
{
    int pierwsza_liczba, druga_liczba;
    cout << "Funkcja zwracajaca najwiekszy wspolny dzielnik dwoch liczb naturalnych" << endl;
    cout << "Podaj pierwsza liczbe: ";
    cin >> pierwsza_liczba;
    cout << "Podaj druga liczbe: ";
    cin >> druga_liczba;
    cout << "Najwiekszym wspolnym dzielnikiem jest: " << NWD(pierwsza_liczba,druga_liczba) << endl;
    return 0;
}
int NWD(int pierwsza_liczba, int druga_liczba)//funkcja nawiekszego wspolnego dzielnika
{
    if (pierwsza_liczba>0 && druga_liczba>0) //warunek ze uzytkownik podal liczbe naturalna
    {
        while(pierwsza_liczba!=druga_liczba) //algorytm euklidesa
        {
            if(pierwsza_liczba>druga_liczba)
            {
                pierwsza_liczba=pierwsza_liczba-druga_liczba;
            }
            else
            {
                druga_liczba=druga_liczba-pierwsza_liczba;
            }
        }
        return pierwsza_liczba;
    }
    else
    {
        cout << "Podaj wartosc dodatnia i calkowita!";
    }
}
