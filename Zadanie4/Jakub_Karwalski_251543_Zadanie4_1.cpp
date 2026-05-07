//Jakub Karwalski 251543
//Zadanie 4.1

#include <iostream>

using namespace std;

int silnia_i (int); //Funkcja do obliczania silni w sposob iteracyjny
int silnia_r (int); //Funkcja do obliczania silni w sposob rekurencyjny
int newton (int,int); //Funkcja do obliczania symbolu newtona
void pascal_t (int); //Funkcja do wyswietlenia trojkatu pascala

int main()
{
    int n,k=1;
    int liczba_wierszy,liczba_kolumn;
    cout << "Program sprawdzajacy poprawnosc funkcji silni napisamych w sposob iteracyjny oraz rekurencyjny" << endl;
    cout << "Program oblicza rowniez wartosc symbolu Newtona, oraz wyswietla trojkat pascala w zaleznosci od podanej liczby wierszy " << endl;
    cout << "Podaj wartosc liczby naturalnej do silni, oznaczonej jako n: ";
    cin >> n;
    cout << "Podaj wartosc liczby naturalnej potrzebnej do obliczenia symbolu Newtona, onzaczonej jako k: ";
    cin >> k;
    cout << "Wynik silni iteracyjnej: " << silnia_i(n) << endl;
    cout << "Wynik silni rekurencyjnej: " << silnia_r(n) << endl;
    cout << "Wynik symbolu newtona: " << newton(n,k);
    cout << endl << "Wyswietlmy trojkat Pascala" << endl;
    cout << "Podaj liczbe wierszy: ";
    cin >> liczba_wierszy;
    pascal_t(liczba_wierszy);

    return 0;
}
int newton (int n,int k)
{
    return (silnia_i(n))/(silnia_i(k)*silnia_i(n-k));
}
int silnia_i (int n)
{
    int wynik=1;
    for(int i=2; i<=n; i++)
    {
        wynik=wynik*i;
    }
    return wynik;
}
int silnia_r (int n)
{
    if (n==0)
    {
        return 1;
    }
    else
    {
        return n*silnia_r(n-1);
    }

}
void pascal_t(int liczba_wierszy)
{
    int c=1; //wartosc liczby wyswietlanej w trojkacie pascala
    for (int i=0; i<liczba_wierszy;i++)
    {
        for (int j=1; j<=liczba_wierszy-i;j++)
        {
            cout << "  ";
        }
        for (int k=0; k<=i;k++)
        {
            if (k== 0 || i == 0)
            {
                c=1;
            }
            else
            {
                c=c*(i-k+1)/k;
            }
            cout << c << "   ";
        }
        cout << endl;
    }
}

//UWAGI DO ZADAN
//Przechodzimy na funkcyjnosc
//4.2 wskazniki, 1 jako wartosc, 2 jako wskaznik
//4.3 Potrzebna funkcja random
//4.5 tablice i operacja modulo
