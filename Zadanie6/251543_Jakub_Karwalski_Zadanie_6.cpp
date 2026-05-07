//Zadanie 6

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

#define N 10 //rozmiar tablicy X i Y

using namespace std;

void wypelnianie_tablicy(int *,int,int);
void wypisanie_tablicy(int *);
int suma_kwadratow_liczb_nieparzystych(int *);
void element_maksymalny(int *,int&,int&);
double odchylenie_standardowe(int *);
int iloczyn_skalarny(int *,int *);
int Horner(int*);

int main()
{
    srand(time(NULL));
    int p,k,main_maks,main_indeks;
    int X[N]={0};
    int Y[N]={0};
    int a[5]={0};
    cout << "Wypelnijmy tablice liczbai z zakresu od p do k" << endl;
    cout << "Podaj p: ";
    cin >> p;
    cout << "Podaj k: ";
    cin >> k;
    cout << "Wypelnianie tablicy X" << endl;
    wypelnianie_tablicy(X,p,k);
    cout << "Wypelnianie tablicy Y" << endl;
    wypelnianie_tablicy(Y,p,k);
    cout << "tablice sa wypelnione" << endl;
    cout << "wypisanie tablicy X" << endl;
    wypisanie_tablicy(X);
    cout << "wypisanie tablicy Y" << endl;
    wypisanie_tablicy(Y);
    cout << "Teraz obliczymy sume kwadratow dla nieparzystych elementow"
    " tablicy X" << endl;
    cout << "Suma kwadratow dla liczb nieparzystych tablicy X wynosi: "
    << suma_kwadratow_liczb_nieparzystych(X) << endl;
    cout << "Obliczymy teraz element maksymalny tablicy Y, oraz jego indeks "
    "na ktorym sie znajduje" << endl;
    element_maksymalny(Y,main_maks,main_indeks);
    cout << "Elementem maksymalnym tablicy Y jest: "<< main_maks <<
    " a ostatnim indeksem maksymalnego elementu jest:" << main_indeks <<
    endl;
    cout << "Nastepnie obliczmy odchylenie standardowe dla tablicy X " <<
    endl;
    cout << "Odchylenie standardowe wynosi: " << odchylenie_standardowe(X) <<
    endl;
    cout << "Obliczmy iloczyn skalarany wektorow reprezentowanych "
    "przez tablice: " << endl;
    cout << "Iloczyn skalarny dwoch tablic wynosi: " << iloczyn_skalarny(X,Y)
    << endl;
    cout << Horner(a);
    return 0;
}
void wypelnianie_tablicy(int X[N],int p,int k)
{
    for (int i=0; i<N; i++)
    {
        X[i] = (rand()%(k-p+1)+p);
    }
}
void wypisanie_tablicy(int X[N])
{
    for (int i=0; i<N; i++)
    {
                cout << "element tablicy " << i+1 <<  " to: " << X[i] << endl;
    }
}
int suma_kwadratow_liczb_nieparzystych(int X[N])
{
    int suma_kwadratow=0;
    for (int i=0; i<N; i++)
    {
        if (X[i]%2!=0)
        {
            suma_kwadratow = suma_kwadratow + (X[i]*X[i]);
        }
    }
    return suma_kwadratow;
}
void element_maksymalny(int Y[N],int &maks,int &indeks)
{
    maks = Y[0];
    indeks = 0;
    for (int i=0; i<N;i++)
    {
        if (maks<=Y[i])
        {
            maks = Y[i];
            indeks = i+1;
        }
    }
}
double odchylenie_standardowe(int X[N])
{
    int suma = 0;
    double wariancja_nie_podzielona=0;
    //obliczanie sredniej arytmetycznej
    for (int i=0;i<N;i++)
    {
        suma = suma + X[i];
    }
    double srednia_ary = suma/N;
    // obliczanie wariancji
    for (int i=0;i<N;i++)
    {
        wariancja_nie_podzielona =wariancja_nie_podzielona +((X[i]-srednia_ary)*(X[i]-srednia_ary));
    }
    double wariancja_podzielona = wariancja_nie_podzielona/N;
    double odchylenie = sqrt(wariancja_podzielona);
    return odchylenie;
}
int iloczyn_skalarny(int X[N],int Y[N])
{
    int iloczyn=0;
    for (int i=0;i<N; i++)
    {
        iloczyn = iloczyn + (X[i]*Y[i]);
    }
    return iloczyn;
}
int Horner(int a[5])
{
    int punkt_x;
    cout << "Na koniec znajdzmy wartosc na osi X wielomianu maksymalnie 4 "
    "stopnia, okreslonego wzorem: y(x) = a[0] + a[1]*x + a[2]*x^2 +...+ a[n]x^n" << endl <<
    "Wartosci podane sa przez uzytkownika" << endl << "Podaj wartosc punktu x: ";
    cin >> punkt_x;
    for (int i=0; i<5;i++)
    {
        cout << "Podaj wartosc wspolczynnika " << i << " wielomianu: ";
        cin >> a[i];
    }
    int wynik = a[4];
    for (int i=4; i>=0;i--)
    {
        wynik = wynik * punkt_x + a[i];
    }
    cout << "Wartosc funkcji w punkcie " << punkt_x << " wynosi:";
    return wynik;
}
