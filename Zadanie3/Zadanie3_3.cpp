//Jakub Karwalski
//Zadanie 3.3

#include <iostream>
#include <cmath>
#define PI 3.1415926

using namespace std;

void wysw_fun_trygonometrycznych (double);

int main()
{
    double zmiana_stopni;
    char wybor;
    cout << "Program wyswietlajacy na konsoli wartosci funkcji trugonometrycznych od 0 do 90 stopni, " << endl << "zmiana stopni zalezy od uzytkownika" << endl;
    cout << "Czy chcesz zmienic wartosc inkrementacji stopni? (Domyslna wartosc 15) [t/n]: ";
    cin >> wybor;
    switch (wybor) //wybor dla uzytkownika czy chce zmienic ustawienia domyslne, case'y puste ze wzgledu na to aby program akcjeptowal podawanie wielkich i malych liter
    {
    case 't': //wypadek ze uzytkownik podaje wlasna wartosc

    case 'T':
        cout << "Podaj jaka ma byc wartosc inkrementacji stopni: ";
        cin >> zmiana_stopni;
        wysw_fun_trygonometrycznych(zmiana_stopni);
        break;
    case 'n': //warunek ze program ma przypisana domyslna wartosc

    case 'N':
        zmiana_stopni=15;
        wysw_fun_trygonometrycznych(zmiana_stopni);
        break;
    }

    return 0;
}
void wysw_fun_trygonometrycznych (double zmiana_stopni) //funckja wyswiuelajaca funkcje sin, cos, tg, ctg, jesli wartosc jest ujemna program sie konczy
{
        if (zmiana_stopni<=0)//warunek na to aby nie byly podane wartosci ujemne
    {
        cout << "Podaj prawidlowa wartosc! ";
    }
    else
    {
        for(int i=0;i<=90; i=i+zmiana_stopni) // jesli wartosc jest dodatnia to inkrementacja jest stosowana a nastepnie zamieniana na radiany aby program obliczal poprawne wartosci
        {
            float zmiana_stopni_na_radiany= (i*PI)/180;
            cout << "Wartosc dla " << i << " stopni" << endl;
            cout << "-----------------------------" << endl;
            cout << "Sinus wynosi: " << sin(zmiana_stopni_na_radiany) << endl;
            cout << "Cosinus wynosi: " << floor(cos(zmiana_stopni_na_radiany)) << endl;
            cout << "Tangens wynosi: " << tan(zmiana_stopni_na_radiany) << endl;
            cout << "Cotangens wynosi: " << (cos(zmiana_stopni_na_radiany)/sin(zmiana_stopni_na_radiany)) << endl;
            cout << "-----------------------------" << endl;
        }
    }
}
