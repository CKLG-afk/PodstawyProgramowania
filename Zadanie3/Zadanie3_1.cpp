//Jakub Karwalski
//Zadanie 3.1

#include <iostream>
#define PI 3.141592653589

using namespace std;

void p_prostokat(float a,float b);
void p_trojkat(float a, float h);
void p_kolo(float r);

int main()
{
    char litera;
    float a,b,h,r;
    cout << "Program obliczajacy jedno z trzech pol: prostokata, trojkata lub kola w zaleznosci od wyboru uzytkownika! " << endl;
    cout << "Jesli chcesz aby program obliczyl pole prostokata podaj litere p lub P" << endl;
    cout << "Jesli chcesz aby program obliczyl pole trojkata podaj litere t lub T" << endl;
    cout << "Jesli chcesz aby program obliczyl pole kola podaj litere k lub K" << endl;
    cout << "Podaj litere: ";
    cin >> litera;
    switch (litera) //case'y puste aby odpalala sie wielka i mala litera
    {
    case 'p':

    case 'P':
        cout<<"Podaj dlugosc 1 boku prostokata: ";
        cin >> a;
        cout<<"Podaj dlugosc 2 boku prostokata: ";
        cin >> b;
        cout << endl;
        p_prostokat(a,b);
        break;
    case 't':

    case 'T':
        cout<<"Podaj dlugosc podstawy trojkata: ";
        cin >> a;
        cout<<"Podaj dlugosc wysokosci trojkata: ";
        cin >> h;
        p_trojkat(a,h);
        break;
    case 'k':

    case 'K':
        cout<<"Podaj dlugosc promienia kola: ";
        cin >> r;
        p_kolo(r);
        break;
    default:
        cout << "Nastepnym razem podaj poprawna wartosc! ";
    }
    return 0;
}
void p_prostokat (float a,float b)//funkcja liczaca pole prostokata
{
    if (a<=0 || b<=0)
    {
        cout <<"Wartosci musza byc dodatnie!" << endl;
    }
    else
    {
        cout << "Pole prostokata wynosi: " << a*b << endl;
    }
}
void p_trojkat (float a,float h)//funkcja liczaca pole trojkata
{
    if (a<=0 || h<=0)
    {
        cout <<"Wartosci musza byc dodatnie!" << endl;
    }
    else
    {
        cout << "Pole trojkata wynosi: " << a*h/2 << endl;
    }
}
void p_kolo (float r)//funkcja liczaca pole kola
{
    if (r<=0)
    {
        cout <<"Wartosc musi byc dodatnia!" << endl;
    }
    else
    {
        cout << "Pole kola wynosi: " << r*r*PI << endl;
    }
}

