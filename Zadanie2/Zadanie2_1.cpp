//Jakub Karwalski
//Zadanie 2.1

#include <iostream>

using namespace std;

void petla_dla_liczba_nieparzystych ();
int N;
int z;

int main()
{
    cout << "Program wyswietlajacy liczby od 1 do N, od N do 1, liczby nieparzyste mniejsze od n, " << endl <<  "liczby parzyste mniejsze od N dajace przy dzieleniu przez 3 reszte 2, " << endl << "wieloktotnosci 5 mniejsze od N,gdzie N to liczba podana przez uzytkownika, " << endl << "oraz wyswietlajacy male litery alfabetu od a do z" << endl;
    cout << "Podaj wartosc N: ";
    cin >> N;
    cout << "Wyswietlenie liczb od 1 do N" << endl;
    for (int i = 1; i<=N; i++ )//petla sluzaca do wyswietlania liczba calkowitych od 1 do N
    {
        cout << i << " ";
    }
    cout << endl << "wyswieltenie liczb od N do 1" << endl; ////petla sluzaca do wyswietlania liczba calkowitych od N do 1
    for (int j=N; j>0; j--)
    {
        cout << j << " ";
    }
    cout << endl << "Wyswietlenie liczb nieparzystych mniejszych od n" << endl;
        if (N%2==0) //Warunek jesli liczba jest parzysta
        {
            z=N-1;//Zmiana wartosci na nieprzysta
            petla_dla_liczba_nieparzystych();
        }
        else //Warunek jesli nieparzysta
        {
            z=N-2;//obnizenie wartosci do kolejnej, mniejszej, nieparzystej  liczby
            petla_dla_liczba_nieparzystych();
        }
    cout << endl << "Wyswietlenie liczb parzystych mniejszych od N dajacych przy dzieleniu przez 3 reszte 2" << endl;
        for(int l=N; l>0; l--) //Wyswietlenie wszystkich liczb
        {
              if (l%2==0)//warunek parzystosci
            {
                if(l%3==2)//warunek ze parzysta liczba daje reszte 2 przy dzieleniu przez 3
                {
                    cout << l << " ";
                }
            }
        }
    cout << endl << "Wyswietlenie wielokrotnosci liczby 5 mniejszych od N" << endl;
    for(int m=N; m>0; m--)
    {
        if(m%5==0)//warunek dla podzielnosci przez 5
        {
            cout << m << " ";
        }
    }
    cout << endl << "Wyswietlenie malych liter alfabetu od a do z " << endl;
    for (int o=97; o<123; o++)
    {
        cout << (char)o << " ";//Wartosc liczbowa na kod ascii
    }
    return 0;
}
void petla_dla_liczba_nieparzystych ()
{
     for (int k=z; k>0; k=k-2)
            {
                cout << k << " ";
            }
}
