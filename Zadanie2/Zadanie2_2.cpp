//Jakub Karwalski
//Zadanie 2.2

#include <iostream>

using namespace std;

int main()
{
    int ilosc_gwiazdek;
    cout << "Program rozmieszczajacy wzory w zaleznosci od ilosci gwiazdekProgram rozmieszczajacy wzory w zaleznosci od ilosci gwiazdek " << endl;
    cout << "Podaj ilosc gwiazdek: ";
    cin >> ilosc_gwiazdek;
    if (ilosc_gwiazdek <= 0) {
        cout << "Podaj ilosc gwiazdek wieksza od zera." << endl;
        return 1;
    }
    //trojkat 1
    for (int i = 1; i <= ilosc_gwiazdek; i++) {
        for (int j = 0; j < i; j++) {
            cout << "*";
        }
        cout << endl;
    }
    cout << endl << endl;
    //trojkat 2
    for (int i = ilosc_gwiazdek; i >= 1; i--) {
        for (int j = 0; j < i; j++) {
            cout << "*";
        }
        cout << endl;
    }
    cout << endl;
    //trojkat 3
    for (int i = ilosc_gwiazdek; i >= 1; i--) {
        for (int j = 0; j < ilosc_gwiazdek - i; j++) {
            cout << " ";
        }
        for (int j = 0; j < i; j++) {
            cout << "*";
        }
        cout << endl;
    }
    //trojkat 4
    cout << endl << endl;
    for (int i = 1; i <= ilosc_gwiazdek; i++) {
        for (int j = 0; j < ilosc_gwiazdek - i; j++) {
            cout << " ";
        }
        for (int j = 0; j < i; j++) {
            cout << "*";
        }
        cout << endl;
    }

    cout << endl;
    //trojkat 5
    for (int i = 1; i <= ilosc_gwiazdek; i++) {
        for (int j = 0; j < ilosc_gwiazdek - i; j++) {
            cout << " ";
        }
        for (int j = 0; j < 2 * i - 1; j++) {
            cout << "*";
        }

        cout << endl;
    }
    cout << endl;

    //trojkat 6
    for (int i = ilosc_gwiazdek; i >= 1; i--) {
        for (int j = 0; j < ilosc_gwiazdek - i; j++) {
            cout << " ";
        }

        for (int j = 0; j < 2 * i - 1; j++) {
            cout << "*";
        }

        cout << endl;
    }
    cout << endl;
    return 0;
    //testy
}
