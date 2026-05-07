// Karwalski Jakub
//Zadanie 1.1
#include <iostream>
#define M_PI 3.14159265358979323846

using namespace std;

int main()
{
    float stopnie,radiany;
        cout << "Program przeliczajacy wielkosc kata wyrazona w stopniach na radiany i wyswietlajacy ja na ekranie" << endl;
        cout << "Podaj wielkosc kata wyrazona w stopniach: ";
        cin >> stopnie;
    radiany = (stopnie* M_PI)/180; // wzor na zamiane stopni na radiany
        cout << "Wielkosc kata w radianach wynosi: " << radiany << " radianow";
        return 0;
}
