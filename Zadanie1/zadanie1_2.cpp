// Karwalski Jakub
//Zadanie 1.2
#include <iostream>

using namespace std;

int main()
{
    int pierwsza_liczba,druga_liczba,trzecia_liczba;
        cout << "Program wczytujacy trzy liczby calkowite oraz obliczajacy ich sume, srednia arytmetyczna i srednia harmoniczna z liczb calkowitych" << endl;
        cout << "Podaj pierwsza liczbe: ";
        cin >> pierwsza_liczba;
        cout << "Podaj druga liczbe: ";
        cin >> druga_liczba;
        cout << "Podaj trzecia liczbe: ";
        cin >> trzecia_liczba;
    int suma {pierwsza_liczba+druga_liczba+trzecia_liczba};
    float L1,L2,L3; // Zadeklarowanie zmiennych ktore pomoga przekonwertowac wpisane przez uzytkownika 3 liczby calkowite na liczby zmiennoprzecinkowe L1 - liczba pierwsza, L2- liczba druga, L3- liczba trzecia
    L1 = pierwsza_liczba; L2= druga_liczba; L3= trzecia_liczba; // konwersja typu zmiennych staloprzecinkowych na zmiennoprzecinkowe
    float srednia_arytm {(L1+L2+L3)/3}; // srednia arytmetyczna
    float srednia_harm {3/(1/L1+1/L2+1/L3)}; // wzor na srednia harmoniczna
        cout << "Suma wynosi: " << suma << endl;
        cout << "Srednia arytmetyczna wynosi: " << srednia_arytm << endl;
        cout << "Srednia harmoniczna wynosi: " << srednia_harm << endl;
    return 0;
}
