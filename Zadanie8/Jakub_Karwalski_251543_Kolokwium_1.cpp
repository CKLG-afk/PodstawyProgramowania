//Jakub Karwalski 251543 Kolokwiumm 1

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

void losowanie(int *,const int,int);
void wyswietl(int *,const int);
int suma_elementow(int *,const int,int);
void zmiana_wartosci(int &, int &);
double pierwiastek_kwadratowy(int, float);

int main()
{
    int n;
    float a0;
    int k;
    const int N = 20; //przykladowy rozmiar
    srand(time(NULL));
    int tab[N];
    cout << "1. Przyblizenie pierwiastka kwadratowego" << endl;
    cout << "Podaj wartosc a0: " <<endl;
    cin >> a0;
    cout << "Podaj wartosc n: " <<endl;
    cin >> n;
    cout << "Przyblizenie pierwsiastka kwadratowego wynosi: " << pierwiastek_kwadratowy(n,a0);
    cout << endl << "2. Zwracanie wartosci w przypadku gdy drugi argument ma mniejsza wartosc niz pierwszy" << endl;
    int a=3; int b=5;
    cout << "wartosc pocz a: " << a << " wartosc pocz b: "<<b << endl;
    zmiana_wartosci(a,b);
    cout << "Wartosc a wynosi teraz: " << a << " Wartosc b wynosi teraz: " << b << endl;
    a=5;    b=3;
    cout << "wartosc pocz a: " << a << " wartosc pocz b: "<<b << endl;
    zmiana_wartosci(a,b);
    cout << "Wartosc a wynosi teraz: " << a << " Wartosc b wynosi teraz: " << b << endl;
    cout << endl << "3. losujemy wartosci tablicy:" << endl << "Podaj koniec zakresu przedzialu liczbowego (k): ";
    cin >> k;
    losowanie(tab,N,k);
    cout << endl << "4. Wyswietlamy tablice: " << endl;
    wyswietl(tab,N);
    cout << endl << "5. Suma elementow ktore sa mniejsze od k." << endl << "Podaj k: " << endl;
    cout << "k = ";
    cin >> k;
    cout << "Suma elementow mniejszy od: " << k << " wynosi: " << suma_elementow(tab,N,k) << endl;
    return 0;
}

void losowanie(int tab[],const int N,int k)
{
    for (int i=0;i<N;i++)
    {
        tab[i] = rand()%k+1;
    }
}
void wyswietl(int tab[],const int N)
{
    int nowa_linia=0;
    cout << "{" << endl;
    for (int i=0;i<N-1;i++)
    {
        cout << setw(7) << tab[i] << ",";

        nowa_linia++;
        if(nowa_linia==4)
        {
            cout << endl;
            nowa_linia=0;
        }

    }
        cout << setw(7) << tab[N-1];
    cout << endl << "}";
}
int suma_elementow (int tab[],const int N,int k)
{
    int suma=0;
    for (int i=0;i<N;i++)
    {
        if (tab[i]<k)
        {
            suma+=tab[i];
        }
    }
    return suma;
}
void zmiana_wartosci(int &a,int &b)
{
    int temp=0;
    if (a>b)
    {
        temp = b;
        b=a;
        a=temp;
    }

}
double pierwiastek_kwadratowy(int iteracje,float S)
{
    if (S <= 0) return 0;
    double xn = S / 2.0; // Pierwsze przybliżenie

    for (int i = 0; i < iteracje; i++) {
        xn = 0.5 * (xn + (S / xn));
    }
    return xn;
}

