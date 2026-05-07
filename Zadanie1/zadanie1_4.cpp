// Karwalski Jakub
//Zadanie 1.4
#include <iostream>

using namespace std;

int main()
{
    int rok;
        cout << "Program obliczajacy czy rok jest przestepny " << endl;
        cout << "Podaj rok ktory chcesz sprawdzic: ";
        cin >> rok;
    if (rok <=1582) // co jesli uzytkownik poda rok mniejszy niz 1582
    {
        cout << "Podany rok musi byc wiekszy od roku 1582, poniewaz wtedy zostal wprowadzony kalendarz gregorianski, " << endl << "a wraz z nim zostaly okreslone obecne zasady co do roku przestepnego";
    }
    else
    {
        if ((rok % 4 == 0 && rok % 100 != 0) || (rok % 400 == 0)) //warunki na rok przestepny
        {
            cout << "Rok jest przestepny";
        }
        else
        {
            cout << "Rok nie jest przestepny";
        }

    }
    return 0;
}
