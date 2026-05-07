//Jakub Karwalski
//Zadanie 3.2

#include <iostream>
#include <cmath>
#define PI 3.141592653589

using namespace std;

double zamiana_stopni_na_radiany(double);//funkcja zmienia stopnie na radiany

int main()
{
    double miara_kata;
    char stopnie_lub_radiany;
    cout << "Program obliczajacy sinus kata w zaleznosci od wartosci podanej przez uzytkownika! " << endl;
    cout << "Jesli uzytkownika poda litere r/R to zakladam za miarara kata podna jest w radianach." << endl;
    cout << "Jesli uzytkownika poda litere s/S to zakladam za miarara kata podna jest w stopniach." << endl;
    cout << "Czy bedziesz podawac wartosc kata w stopniach czy radianach? ";
    cin >> stopnie_lub_radiany;
    cout << endl << "Podaj wartosc miary kata: ";
    cin >> miara_kata;

    switch (stopnie_lub_radiany)//nie ma break poniewaz ze stopni bedzie zmieniac na radiany
    {
        case 's':

        case 'S':
        miara_kata = zamiana_stopni_na_radiany(miara_kata); //przypisujemy nowa wartosc dla miary kata przeksztalcona ze stopni na radiany
        case 'r':

        case 'R':
        cout << "sinus tego kata wynosi: " << sin(miara_kata);//funkcja przyjmuje wartosc w radianach
            break;
        default:
        cout << "Podaj poprawna litere w jakiej jednostce mam to obliczyc";
        break;
    }
    return 0;
}
double zamiana_stopni_na_radiany(double miara_kata)
{
    miara_kata= (miara_kata*PI)/180;
    return miara_kata;
}
