//Jakub Karwalski 251543
//Zadanie 9.2

#include <iostream>

using namespace std;

struct pies
{
    char imie[10];
    int wiek;
    double masa;
};

pies set1()
{
    pies nowy_pies;
    cout << "Podaj imie psa: ";
    cin >> nowy_pies.imie;
    cout << "Podaj wiek psa: ";
    cin >> nowy_pies.wiek;
    cout << "Podaj mase psa: ";
    cin >> nowy_pies.masa;
    return nowy_pies;
}

pies set2(char imie[10], int wiek, double masa)
{
    pies nowy_pies2;
     for (int i = 0; i < 9 && imie[i] != '\0'; ++i) {
        nowy_pies2.imie[i] = imie[i];
    }
    nowy_pies2.imie[9] = '\0';
    nowy_pies2.wiek = wiek;
    nowy_pies2.masa = masa;
    return nowy_pies2;
}
void get1(pies nowy_pies)
{
    cout << "Pies " << nowy_pies.imie << " ma " << nowy_pies.wiek << " lat(a) i wazy " << nowy_pies.masa << " kg" << endl;
}

int main()
{
    char imie[10] = "";
    int wiek = 0;
    double masa = 0.0;
    pies nowy_pies1 = set1();
    cout << "Podaj imie psa 2. ";
    cin >> imie;
    cout << "Podaj wiek psa 2. ";
    cin >> wiek;
    cout << "Podaj mase psa 2. ";
    cin >> masa;
    pies nowy_pies2 = set2(imie,wiek,masa);
    get1(nowy_pies1);
    pies pupile[3];
    pupile[0] = set1();
    for (int i=1;i<3;i++)
    {
        cout << "Podaj imie psa " << i+2 << " ";
        cin >> imie;
        cout << "Podaj wiek psa "<< i+2 << " ";
        cin >> wiek;
        cout << "Podaj mase psa "<< i+2 << " ";
        cin >> masa;
        pupile[i] = set2(imie,wiek,masa);
    }
    for (int i=0;i<3;i++)
    {
        get1(pupile[i]);
    }
    return 0;
}

