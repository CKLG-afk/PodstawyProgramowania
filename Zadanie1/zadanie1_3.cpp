// Karwalski Jakub
//Zadanie 1.3
#include <iostream>
#include <math.h>
#define M_PI 3.14159265358979323846

using namespace std;

int main()
{
    float p_kuli,p_stozka,w_stozka; // zadelkarowanie zmiennych: promien kuli, promien stozka, wysokosc stozka
        cout << "Program obliczajacy objetosc kuli oraz stozka" << endl;
        cout << "Podaj promien kuli: ";
        cin >> p_kuli;
        cout << "Podaj promien stozka: ";
        cin >> p_stozka;
        cout << "Podaj wysokosc stozka: ";
        cin >> w_stozka;
    if (p_kuli <=0 || p_stozka <=0 || w_stozka <=0)// Warunek aby podane przez uzytkownika liczby byly dodatnie
    {
        cout << "Podane liczby musza byc dodatnie! ";
    }
    else
    {
        float obj_kuli {(4*M_PI*pow(p_kuli,3))/3}; // wzor na objetosc kuli
        float obj_stoz {(M_PI*pow(p_stozka,2)*w_stozka)/3}; // wzor na objetosc stozka
            cout << "Objetosc kuli wynosi: " << obj_kuli << endl;
            cout << "Objetosc stozka wynosi: " << obj_stoz;
    }
    return 0;
}
