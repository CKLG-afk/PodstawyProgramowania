//Jakub Karwalski
//Zadanie 2.3

#include <iostream>
#include <math.h>

using namespace std;

float epsilon(float,float); //funkcja predefiniowana

int main()
{
    float x,eps;// x-podstawa potegi, eps-dokladnosc
    cout << "Program obliczajacy wartosc e^x z dokladnoscia do epsilon" << endl;
    cout << "Podaj x: ";
    cin >> x;
    cout << "Podaj wartosc epsilon: ";
    cin >> eps;


    cout <<"wartosc e^" << x << "obliczona z przyblizeniem: " << epsilon(x,eps) << endl;
}

float epsilon(float x, float eps) //funkcja odpowiadajaca z obliczanie wartosci funkcji wykladniczej z dokladnoscia do epsilon
{
    float wynik=0;
    float element=1; //aktualny skladnik szeregu
    int i=1; //numer iteracji
    while(abs(element)>eps)
    {
        element=element*x/i;
        wynik=wynik+element;
        i++;
    }
    return wynik;
}
