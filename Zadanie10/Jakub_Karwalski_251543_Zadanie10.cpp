//Jakub Karwalski 251543
//Zadanie 10

#include <iostream>
#include <fstream>
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
    ifstream plik("ksiazki.txt");

    if (!plik.is_open()) {
        cout << "Blad: Nie udalo sie otworzyc pliku 'ksiazki.txt'!" << endl;
        return 1;
    }

    int wczytane = 0;
    string temp;

    // Petla wczytuje dane dopóki plik się nie skończy LUB nie osiągniemy limitu tablicy
    while (wczytane < ILOSC_KSIAZEK && !plik.eof()) {

        // Próba wczytania pierwszej linii (tytułu)
        if (!plik.getline(ksiazki[wczytane].tytul, sizeof(ksiazki[wczytane].tytul))) {
            break; // Wyjdz, jeśli nie ma więcej danych
        }

        try {
            // Rok wydania
            getline(plik, temp);
            if (!temp.empty()) ksiazki[wczytane].rok_wydania = stoi(temp);

            // Rodzaj
            plik.getline(ksiazki[wczytane].rodzaj, sizeof(ksiazki[wczytane].rodzaj));

            // Nazwisko autora
            plik.getline(ksiazki[wczytane].autor.nazwisko, sizeof(ksiazki[wczytane].autor.nazwisko));

            // Rok urodzenia
            getline(plik, temp);
            if (!temp.empty()) ksiazki[wczytane].autor.rok_urodzenia = stoi(temp);

            // Pusta linia separatora
            getline(plik, temp);

            wczytane++;
        }
        catch (const exception& e) {
            cout << "Blad formatu danych w rekordzie nr " << wczytane + 1 << endl;
            break;
        }
    }

    plik.close();

    cout << "Pomyslnie wczytano " << wczytane << " ksiazek:" << endl;
    for (int i = 0; i < wczytane; i++) {
        cout << i + 1 << ". " << ksiazki[i].tytul << " (" << ksiazki[i].autor.nazwisko << ")" << endl;
    }

    return 0;
}
