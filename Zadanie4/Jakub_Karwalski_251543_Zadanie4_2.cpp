//Jakub Karwalski 251543
//Zadanie 4.2

#include <iostream>

using namespace std;

void zwrocenie_przez_wartosc(int,int);
void zwrocenie_przez_referencje(int &a,int &b)
{
    a = 0;
    b = 0;
    cout << "Wartosc a i b w funkcji zerujacej przez referencje: " << a << " " << b << endl;
}
int main()
{
    int a,b;
    cout << "Program zerujacy dwie zmienne! " << endl;
    cout << "Podaj wartosc zmiennej a: ";
    cin >> a;
    cout << "Podaj wartosc zmiennej b: ";
    cin >> b;
    cout << endl << "Wartosc zmiennych a i b przed wyswietleniem ich przez funkcje wynosi: " << a << " i " << b << endl;
    zwrocenie_przez_wartosc(a,b);
    cout << endl << "Wartosc a i b po przekazaniu ich funkcji zerujacej przez wartosc, a przed przekazaniem przez referencje wynosi: " << a << " i " << b << endl;
    zwrocenie_przez_referencje(a,b);
    cout << "Wartosc funkcji zerujacej po przekazaniu przez referencje wynosi: " << a << " i " << b << endl;

    return 0;
}

void zwrocenie_przez_wartosc(int a,int b)
{
    a = 0;
    b = 0;
    cout << "Wartosc a i b w funkcji zerujacej z przekazaniem przez wartosc: " << a << " " << b << endl;
}
/*void zwrocenie_przez_referencje(int &a, int b)
{

}
*/
