//Jakub Karwalski 251543
//Kolokwium II

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <limits>

using namespace std;
//Podpunkt 1
struct Gwiazda
{
    char typ[50];
    int temperatura;
    float masa;
};
//Podpunkt 2
Gwiazda ** tworzenie_tablicy(int w,int k)
{
    Gwiazda ** tablica = new Gwiazda*[w];
    for (int i=0;i<w;i++)
    {
        tablica [i] = new Gwiazda [k];
    }
    return tablica;
}
void usuwanie_tablicy(Gwiazda ** tablica, int w)
{
    for (int i = 0; i < w; ++i) {
        delete[] tablica[i];
    }
    delete[] tablica;
}
//Podpunkt 3
void pobieranie_danych_gwiazda(Gwiazda * gwiazdka)
{
    cin.clear(); fflush(stdin);
    cout << "Podaj typ, maksymalnie 49 znakow " << endl;
    cin.getline(gwiazdka->typ, sizeof(gwiazdka->typ));
    cout << endl;
    // Pobieranie temperatury gwiazdy
    cout << "Podaj temperature gwiazdy: ";
    while (!(cin >> gwiazdka->temperatura))
    {
        cin.clear(); // Reset flag bledow
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Wyczysc bufor
        cout << "Bledna temperatura. Podaj ponownie: ";
    }
    // Pobieranie masy gwiazdy
    cout << "Podaj mase gwiazdy: ";
    while (!(cin >> gwiazdka->masa))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Bledna masa. Podaj ponownie: ";
    }
    cout << endl;
    cin.clear(); fflush(stdin);
}
//Podpunkt 4
bool Zapis_do_pliku_gwiazda(Gwiazda *gwiazdka, string sciezka, int liczba)
{
    ofstream plik(sciezka);
    if (plik.is_open())
    {
        for (int i = 0; i < liczba; i++)
        {
            plik << "Typ gwiazdy: " << gwiazdka[i].typ << endl;
            plik << "Temperatura gwiazdy: " << gwiazdka[i].temperatura << endl;
            plik << "Masa gwiazdy: " << gwiazdka[i].masa << endl;
            plik << endl;
        }
        plik.close();
        return true;
    }
    else
    {
        return false;
    }
}
//Podpunkt 5
void liczenie_bitow(int liczba, int& ilosc_jedynek, int& ilosc_zer) {
    ilosc_jedynek = ilosc_zer = 0;
    for (int i = 0; i < sizeof(int) * 8; ++i) {
        if (liczba & (1 << i)) {
            ilosc_jedynek++;
        }
    }
    ilosc_zer = sizeof(int) * 8 - ilosc_jedynek;
}

int main()
{
    int w, k; //wiersze kolumny
    int ilosc_jedynek, ilosc_zer;
    int liczba = 10;
    const int rozmiar = 2; // rozmiar tablicy
    Gwiazda tablica1[rozmiar];
    cout << "Podaj ilosc wierszy: " << endl;
    cin >> w;
    cout << "Podaj ilosc kolumn: " << endl;
    cin >> k;

    // Podpunkt 2
    Gwiazda **moja_tablica = tworzenie_tablicy(w, k);
    // Wyswietlenie dzialania tablicy dynamicznej nie wiem czy o to chodzi z demonstracja dzialania stworzonych funkcji w main, polecam dac jakas mala wartosc wierszy i kolumn
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < k; j++)
        {
            pobieranie_danych_gwiazda(&moja_tablica[i][j]);
        }
    }
    cout << "Zawartosc tablicy:" << endl;
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cout << "Typ: " << moja_tablica[i][j].typ << ", Temperatura: " << moja_tablica[i][j].temperatura << ", Masa: " << moja_tablica[i][j].masa << endl;
        }
    }
    usuwanie_tablicy(moja_tablica, w);
    // Podpunkt 3
    for (int i = 0; i < rozmiar; i++)
    {
        pobieranie_danych_gwiazda(&tablica1[i]);
    }

    // Podpunkt 4
    string sciezka;
    cout << "Podaj nazwe pliku do ktorego chcesz to wrzucic: ";
    cin >> sciezka; // Ja podaje sciezke o nazwie - "gwiazdy.txt"
    cout << endl;

    if (Zapis_do_pliku_gwiazda(tablica1, sciezka, rozmiar) == true)
    {
        cout << "Zapis do pliku udany" << endl;
    }
    else
    {
        cout << "Zapis do pliku nieudany" << endl;
    }

    // Podpunkt 5
    liczenie_bitow(liczba, ilosc_jedynek, ilosc_zer);
    cout << "Liczba bitow ustawionych na 1: " << ilosc_jedynek << std::endl;
    cout << "Liczba bitow ustawionych na 0: " << ilosc_zer << std::endl;

    return 0;
}

