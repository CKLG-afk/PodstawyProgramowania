// Karwalski Jakub
//Zadanie 1.5
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    double a,b,c;
        cout << "Program obliczajacy rozwiazania rownania kwadratowego i liniowego" << endl;
        cout << "Podaj wspolczynnik a: ";
        cin >> a;
        cout << "Podaj wspolczynnik b: ";
        cin >> b;
        cout << "Podaj wspolczynnik c: ";
        cin >> c;
    if (a==0) // przypadek kiedy rownanie nie bedzie kwadratowe
    {
        if (b==0) // przypadek kiedy nie ma wspolczynnika b- rownanie sprzeczne
        {
                cout << "Rownanie jest sprzeczne i nie ma rozwiazan";
        }
        else // przypadek rownania liniowego
        {
            float rozw{(-c)/b}; // wzor na jedyne rozwiazanie rownania liniowego
                cout << "Rownanie jest liniowe i jego rozwiazaniem jest: " << rozw;
        }

    }
    else // przypadek rownania kwadratowego
    {
        double delta {pow(b,2)-(4*a*c)}; // wzor na delte
        double rozw1 {(-b+sqrt(delta))/(2*a)}; // wzor na pierwsze rozwiazanie z delty
        double rozw2 {(-b-sqrt(delta))/(2*a)}; // wzor na drugie rozwiazanie z delty
        if (delta < 0) //delta ujemna- brak rozwiazan
        {
            cout << "Rownanie jest kwadratowe i nie ma rozwiazan";
        }
        else // delta dodatnia lub rowna 0
        {
            if (rozw1==rozw2) //przypadek rownania kwadratowego z jednym rozwiazaniem
            {
                cout << "Rownanie jest kwadratowe i ma jedno roziwazanie, a roziwazaniem jest: " << rozw1;
            }
            else //przypadek rownania kwadratowego z dwoma rozwiazaniami
            {
                cout << "Rownanie jest kwadratowe i ma dwa rozwiazania, a roziwazaniami sa: " << rozw1 << " i " << rozw2 ;
            }
        }


    }
    return 0;
}
