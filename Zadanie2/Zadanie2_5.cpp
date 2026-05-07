//Jakub Karwalski
//Zadanie 2.5

#include <iostream>
#include <math.h>

using namespace std;



int main()
{
    char warunek;
    bool powtorz_program;
    bool powtorz_czy_chcesz_kontynuowac;
    cout << "Program pobierajacy od uzytkownika liczbe calkowita, wypisujacy jej wszystkie podzielniki" << endl;
    do
    {
        cout << "Podaj liczbe calkowita: ";
        int liczba_Z=0;
        int wynik = 0;
        cin >> liczba_Z;

        for (int i=1; i<=liczba_Z; i++ )
        {
            if(liczba_Z%i==0)//warunek ze liczba jest dzielnikiem
            {
                cout << i << " ";
                wynik++;
            }

        }
        if(wynik==2)
                {
                    cout << "Podana liczba jest liczba pierwsza";
                }
                else
                {
                    cout << "Podana liczba nie jest liczba pierwsza";
                }
            cout << endl << "czy chcesz kontynuowac?[t/n] " <<endl;
            cin >> warunek;
            switch(warunek)
            {
                case 't':
                    powtorz_program=true;
                    break;
                case 'n':
                    powtorz_program=false;
                    break;
            }

    }while (powtorz_program);

    return 0;
}
