//Jakub Karwalski 251543
//Zadanie 10

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>

#define ILOSC_KSIAZEK 10

using namespace std;

struct Pisarz
{
    int rok_urodzenia;
    char nazwisko[20];
};

struct Ksiazka
{
    char tytul[50];
    int rok_wydania;
    char rodzaj[20];
    Pisarz autor;
};

int main()
{
    Ksiazka ksiazki[10];
    fstream plik;
    while(true)
    {
        plik.open("ksiazki.txt", ios::in);
        if(plik.good() == true)
        {
            for(int i = 0; i < ILOSC_KSIAZEK; i++)
            {
                string temp;

                //Tytul
                plik.getline(ksiazki[i].tytul, sizeof(ksiazki[i].tytul));

                //Rok wydania
                getline(plik, temp);
                ksiazki[i].rok_wydania = stoi(temp);

                //Rodzaj
                plik.getline(ksiazki[i].rodzaj, sizeof(ksiazki[i].rodzaj));

                //Nazwisko autora
                plik.getline(ksiazki[i].autor.nazwisko, sizeof(ksiazki[i].autor.nazwisko));

                //Rok urodzenia
                getline(plik, temp);
                ksiazki[i].autor.rok_urodzenia = stoi(temp);

                //Pusta linia
                getline(plik, temp);


            }

            plik.close();
        }


        else
        {
            cout << endl << "Nie udalo sie wczytac pliku.";
            return 0;
        }
    }
    return 0;
}
