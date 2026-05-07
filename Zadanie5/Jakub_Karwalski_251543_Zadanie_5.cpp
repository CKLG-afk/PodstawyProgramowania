//Jakub Karwalski
//Zadanie 5

#include <iostream>
#include <cstdlib>
#include <ctime>

#define rozmiar_student 100 //rozmiar tablicy student
#define rozmiar_ilosc_ocen 11 // rozmiar tablicy ilosc ocen

using namespace std;

void losowanie_liczb(int *); //losuje i wyswietla tablice
float srednia(int *); //obliczanie sredniej
void sortowanie(int *); //sortowanie tablicy
float mediana (int *); //obliczanie mediany
void obliczanie_ilosci_ocen_studentow(int *, int *); // wyliczenie kazdej ilosci ocen
void najw_ilosc_ocen(int *); // pokazanie liczby najwiekszej ilosci wybranych ocen
void histogram(int *);

int main()
{
    srand(time(NULL));
    int student[rozmiar_student] = {0};
    int ilosc_ocen[rozmiar_ilosc_ocen] = {0};
    cout << "Opinie studentow wyrazone w ocenach wypisane sa w tablicy: " << endl;
    losowanie_liczb(student);
    cout << "Srednia ocen wynosi: " << srednia(student) << endl;
    sortowanie(student);
    cout << "Mediana ocen wynosi: " << mediana(student) << endl;
    obliczanie_ilosci_ocen_studentow(student, ilosc_ocen);
    najw_ilosc_ocen(ilosc_ocen);
    histogram(ilosc_ocen);
    return 0;
}
void losowanie_liczb(int student[rozmiar_student])
{
    int kolumna=1; //zmienna do przeskakiwania do nowych linii
    for (int i=0;i<100;i++,kolumna++)
    {
        student[i] = (rand()%11); //losowanie liczb z zakresu 0-10
        cout << student[i] << " ";
        if (kolumna==10) // wyswietlanie sie tablicy w formacie dwuwymiarowym
        {
            kolumna=0;
            cout << endl;
        }

    }
}
float srednia(int student[rozmiar_student])
{
    float suma;
    for (int i=0; i<100; i++)
    {
        suma = suma + student[i];// suma wszystkich elementow tablicy
    }
    return suma/rozmiar_student; //wzor na srednia
}
float mediana(int student[rozmiar_student])
{
    float mediana = (student[(rozmiar_student/2)] + student[(rozmiar_student/2)+1])/2; //srednia dwoch srodkowych elementow tablicy
    return mediana;
}
void sortowanie(int student[rozmiar_student])
{
    for (int i=0; i<rozmiar_student-1;i++)
    {
        int min = i;
        for (int j=i+1; j<rozmiar_student;j++) //sortowanie przez wybor
        {
            if (student[min]>student[j])
            {
                min=j;
            }
            if (min != i)
            {
                swap(student[min],student[i]);
            }
        }
    }
    //Wyswietlenie posortowanej tablicy do zobaczenia czy sortowanie dziala
    /*cout << endl;
    int kolumna=1;
    for (int i=0;i<100;i++,kolumna++)
    {
        cout << student[i] << " ";
        if (kolumna==10)
        {
            kolumna=0;
            cout << endl;
        }

    }*/
}
void obliczanie_ilosci_ocen_studentow(int student[rozmiar_student], int ilosc_ocen[rozmiar_ilosc_ocen])
{
    for (int i=0; i<100; i++)
    {
        switch (student[i]) // naliczanie wartosci kazdego elementu tablicy
        {
            case 0:
                ilosc_ocen[0]++;
                break;
            case 1:
                ilosc_ocen[1]++;
                break;
            case 2:
                ilosc_ocen[2]++;
                break;
            case 3:
                ilosc_ocen[3]++;
                break;
            case 4:
                ilosc_ocen[4]++;
                break;
            case 5:
                ilosc_ocen[5]++;
                break;
            case 6:
                ilosc_ocen[6]++;
                break;
            case 7:
                ilosc_ocen[7]++;
                break;
            case 8:
                ilosc_ocen[8]++;
                break;
            case 9:
                ilosc_ocen[9]++;
                break;
            case 10:
                ilosc_ocen[10]++;
                break;
        }
    }
    for (int i=0; i<rozmiar_ilosc_ocen; i++)
    {
        cout << "Ilosc ocen " << i << " wynosi: " << ilosc_ocen[i] << endl;
    }
}
void najw_ilosc_ocen(int ilosc_ocen[rozmiar_ilosc_ocen])
{

    int najwieksza_ilosc_ocen = ilosc_ocen[0];
    int najwieksza_ocena = 0;
    int ilosc_liczb_maks=0;
    for (int i=1; i<rozmiar_ilosc_ocen; i++) //znalezie najwiekszej ilosci ocen
    {
        if (najwieksza_ilosc_ocen<ilosc_ocen[i])
        {
            najwieksza_ilosc_ocen = ilosc_ocen[i];
            najwieksza_ocena = i;
        }
    }
    for (int i=0; i<rozmiar_ilosc_ocen; i++) //sprawdzanie ile jest najwiekszych ilosci ocen
    {
        if (najwieksza_ilosc_ocen==ilosc_ocen[i])
        {
            ilosc_liczb_maks++;
        }
    }
    if (ilosc_liczb_maks>1) // jesli ilosci ocen najwiekszych jest wiecej niz 1
    {
        int * tab_ilosc_liczb_maks = new int[ilosc_liczb_maks]; //tablica zawierajaca tyle elementow ile jest najwiekszych ilosci ocen
        int index=0;
        for (int i=0; i<rozmiar_ilosc_ocen; i++) // Kolejne przeszukiwanie tablicy ilosc ocen aby do tablicy dynamicznej przypisywac wartosci
        {
            if (najwieksza_ilosc_ocen==ilosc_ocen[i])
            {
                tab_ilosc_liczb_maks[index] = i;
                index++;
            }
        }
        cout << "Ocen wystawianych najczeszciej jest: " << ilosc_liczb_maks << endl
        << "Jej ilosc wybran to: " << najwieksza_ilosc_ocen << " Sa to oceny: ";
        for (int i=0; i<ilosc_liczb_maks; i++)
        {
            cout << tab_ilosc_liczb_maks[i] << ",";
        }
        cout << endl;
        delete [] tab_ilosc_liczb_maks;
    }
    else // Jesli jest tylko 1 najwieksza ilosc
    {
        cout << najwieksza_ocena << " To ocena wystawiana najczesciej" << endl
        << "Jej ilosc wybran wynosi: " << najwieksza_ilosc_ocen << endl;
    }

}
void histogram (int ilosc_ocen[rozmiar_ilosc_ocen])
{
    cout << "Wyswietlenie histogramu:" << endl << endl;
    int max_ilosc = ilosc_ocen[0];
    for (int i = 1; i < rozmiar_ilosc_ocen; i++) {
        if (ilosc_ocen[i] > max_ilosc) {
            max_ilosc = ilosc_ocen[i];
        }
    }

    for (int i = max_ilosc; i >= 1; i--) {
        for (int j = 0; j < rozmiar_ilosc_ocen; j++) {
            if (ilosc_ocen[j] >= i) {
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }

    for (int i = 0; i < rozmiar_ilosc_ocen; i++) {
        cout << i << " ";
    }
    cout << endl;
}
