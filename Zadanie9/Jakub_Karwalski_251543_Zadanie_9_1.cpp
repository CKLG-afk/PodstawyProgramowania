//Jakub Karwalski 251543
//Zadanie 9.1

//UWAGI
//funkcja fopen i fstream
//3. Get pisarz

#include <iostream>
#include <fstream>

using namespace std;

struct Osoba
{
    char imie[10];
    char nazwisko[20];
    int wiek;
};

struct Pies
{
    char imie[10];
    int wiek;
    double masa;
};

struct Pisarz
{
    int rok_urodzenia;
    char imie[12];
    char nazwisko[20];
};

struct Ksiazka
{
    char tytul[20];
    int rok_wydania;
    Pisarz* autor;
};

void funkcja_osoba (Osoba * osoba)
{
    cin.ignore();
    cout << "\nPodaj imie osoby(do 10 znakow): ";
    cin.getline(osoba->imie, sizeof(osoba->imie));
    cin.clear(); fflush(stdin);
    cout << "\nPodaj nazwisko osoby(do 20 znakow): ";
    cin.getline(osoba->nazwisko, sizeof(osoba->nazwisko));
    cin.clear(); fflush(stdin);
    cout << "\nPodaj wiek osoby: ";
    cin >> osoba->wiek;
    cin.clear(); fflush(stdin);
    while (osoba->wiek == 0)
    {
        cout << "\nPodaj wiek ponownie: ";
        cin >> osoba->wiek;
        cin.clear(); fflush(stdin);
    }
}

Pies set1()
{
    cin.ignore();
    char a[10];
    int b;
    double c;
    cout << "\nPodaj imie swojego psa: ";
    cin.getline(a, sizeof(a));
    cin.clear(); fflush(stdin);
    do
    {
        cout << "\nPodaj wiek psa: ";
        cin >> b;
        cin.clear(); fflush(stdin);
    } while (b == 0 || b < 0);

    do
    {
        cout << "\nPodaj mase psa: ";
        cin >> c;
        cin.clear(); fflush(stdin);
    } while (c == 0.0 || c < 0.0);
    Pies pies;
    for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++)
    {
        pies.imie[i] = a[i];
    }
    pies.wiek = b; pies.masa = c;
    return pies;
}

Pies set2(char imie[10], int wiek, double masa)
{
    struct Pies pies;
    for (int i = 0; i < sizeof(imie)/sizeof(char); i++)
    {
        pies.imie[i] = imie[i];
    }
    pies.wiek = wiek; pies.masa = masa;
    return pies;
}

void get1 (Pies* pies)
{
    cout << "\nPies " << pies->imie << " ma " << pies->wiek << " lat(a) i wazy " << pies->masa << "kg\n";
}

Pisarz wypelnij(Pisarz pisarz, int numer)
{
    pisarz.rok_urodzenia = 0;
    cout << "Podaj imie pisarza nr " << numer + 1 << " "; cin >> pisarz.imie; cout << endl;
    cout << "Podaj nazwisko pisarza nr " << numer + 1 << " "; cin >> pisarz.nazwisko; cout << endl;
    while (pisarz.rok_urodzenia == 0)
    {
        cout << "Podaj rok urodzenia pisarza nr " << numer + 1 << " "; cin >> pisarz.rok_urodzenia; cout << endl;
        cin.clear(); fflush(stdin);
    }
    return pisarz;
}

Ksiazka wypelniaj(Ksiazka ksiazka, int numer, Pisarz* autorzy, int rozmiar_autorow)
{
    ksiazka.rok_wydania = 0;
    int pomoc = 0;
    cin.clear(); fflush(stdin);
    cout << "Podaj tytul ksiazki nr " << numer + 1 << " ";
    cin.getline(ksiazka.tytul, sizeof(ksiazka.tytul)); cout << endl;
    while (ksiazka.rok_wydania == 0)
    {
        cout << "Podaj rok wydania ksiazki nr " << numer + 1 << " "; cin >> ksiazka.rok_wydania; cout << endl;
        cin.clear(); fflush(stdin);
    }
    cout << "Podaj ktorego autora jest ta ksiazka:" << endl;
    for (int i = 0; i < rozmiar_autorow; i++)
    {
        cout << "(" << i + 1 << ") " << autorzy[i].imie << " " << autorzy[i].nazwisko << endl;
    }
    while (pomoc != 1 && pomoc != 2 && pomoc != 3)
    {
        cout << "-> ";
        cin >> pomoc;
        if (pomoc == 1 || pomoc == 2 || pomoc == 3)
        {
            ksiazka.autor = &autorzy[pomoc - 1];
        }
    }
    cout << endl;
    return ksiazka;
}

void getPisarz (Pisarz pisarz)
{
    cout << pisarz.imie << " " << pisarz.nazwisko << " urodzony(/a) w " << pisarz.rok_urodzenia << " roku" << endl;
}

void getKsiazka (Ksiazka ksiazka)
{
    cout << "Tytul: " << ksiazka.tytul << " - rok wydania " << ksiazka.rok_wydania << ", autor: ";
    cout << ksiazka.autor->imie << " " << ksiazka.autor->nazwisko << " urodzony(/a) w " << ksiazka.autor->rok_urodzenia << " roku" << endl;
}

int main()
{
    char dzialanieProgramu = '1';
    char menu;
    while (dzialanieProgramu != '0')
    {
        cout << "\n--------------- MENU ------------------";
        cout << "\nPodaj ktora opcje ma wykonac program:";
        cout << "\n\n1. Struktura Osoba\n2. Struktura Pies\n3. Struktura Pisarz i Ksiazka\n4. Zakonczenie programu";
        cout << "\n---------------------------------------" << endl;
        cout << "-> "; cin >> menu;
        switch (menu)
        {
            case '1':
                Osoba o1;
                funkcja_osoba(&o1);
                cout << "\nImie: " << o1.imie << "\nNazwisko: " << o1.nazwisko << "\nWiek: " << o1.wiek << "\n";
                break;
            case '2':
                {
                   Pies pupile[3];
                    pupile[0] = set1();
                    pupile[1] = set2("Halt", 5, 2.0);
                    pupile[2] = set2("Hund", 120, 666.15);
                    cout << "-----------------------------";
                    for (int i = 0; i < (sizeof(pupile)/sizeof(pupile[0])); i++)
                        {
                            get1(&pupile[i]);
                        }
                        ofstream plik("imiona.txt");
                        for (int i = 0; i < (sizeof(pupile)/sizeof(pupile[0])); i++)
                        {
                            plik << pupile[i].imie << " " << pupile[i].wiek << " " << pupile[i].masa << endl;
                        }
                        plik.close();
                        break;
                }
             case '3':
                Pisarz Autorzy[3];
                Ksiazka Tomy[4];
                for (int i = 0; i < 3; i++)
                {
                    Autorzy[i] = wypelnij(Autorzy[i], i);
                }
                for (int i = 0; i < 4; i++)
                {
                    Tomy[i] = wypelniaj(Tomy[i], i, Autorzy, 3);
                }
                cout << "Zadeklarowani pisarze: " << endl << endl;
                for (int i = 0; i < 3; i++)
                {
                    getPisarz(Autorzy[i]);
                }
                cout << endl;
                cout << "Zadeklarowane ksiazki: " << endl << endl;
                for (int i = 0; i < 4; i++)
                {
                    getKsiazka(Tomy[i]);
                }
                break;

            case '4':
                cout << "\nWybrales zakonczenie programu\n";
                dzialanieProgramu = '0';
                break;

            default:
                cout << "\nNiepoprawna opcja!\n";
                break;

        }

    }
    return 0;
}
