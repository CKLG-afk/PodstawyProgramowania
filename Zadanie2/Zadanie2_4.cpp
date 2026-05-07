//Jakub Karwalski
//Zadanie 2.4

#include <iostream>

using namespace std;

int main()
{
    int N; //liczba iteracji
    float x, wynik, skladowa={1}; //x- wartosc sumy potegi, wynik- zbieranie oblizonej sumy, skladowa- obliczanie kolejnych skladnikow sumy
    cout << "Program wyswietlajacy wartosc funkcji sumy potegi x przez silnie i" << endl;
    cout << "Podaj wartosc N:";
    cin >> N;
    cout << "Podaj wartosc x:";
    cin >> x;
    for (int i=1; i<=N; i++)
    {
        skladowa=skladowa*x/i;
        wynik=wynik+skladowa;
    }
    cout << "wartosc funkcji sumy potegi x przez silnie i: " << wynik << endl;
    return 0;
}
