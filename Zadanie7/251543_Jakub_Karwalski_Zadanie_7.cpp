#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>

#define N 7

using namespace std;

void wypelnianie_A(int [][N],int,int);
void wyswietlenie(int [][N]);
void najw_suma_wiersz(int [][N]);
void transpozycja(int [][N]);
void sortowanie(int [][N]);
bool symetryczna(int [][N],int);
void dynamiczna();

int main()
{
    srand(time(NULL));
    bool czy_ustawiona=false;
    int p,k,rozmiar,opcja;
    int A[N][N]={0};
        cout << "MENU GLOWNE" << endl;
        cout << "-------------------------------------------------------" << endl;
        cout << "1. Losowanie macierzy" << endl;
        cout << "2. Wyswietlenie macierzy" << endl;
        cout << "3. Wyswietlenie wierszow o najwiekszej sumie elementow" << endl;
        cout << "4. Sortowanie macierzy kolumnami" << endl;
        cout << "5. Transpozycja macierzy" << endl;
        cout << "6. Sprawdzenie czy macierz jest symetryczna" << endl;
        cout << "7. Tworzenie tablicy dynamiczej"<< endl;
        cout << "8. Wyjscie z programu " << endl;
        cout << "-------------------------------------------------------" << endl << endl;

    for(;;)
    {
        cout << "Podaj nr opcji: " << endl;
        cin >> opcja;

        switch (opcja)
        {
            case 1:
            {
                    cout << "wybierz zakres liczb losowych od p do k: ";
                    cin >> p >> k;
                    wypelnianie_A(A,p,k);
                    czy_ustawiona = true;
                    break;
            }
            case 2:
            {
                if (czy_ustawiona==false)
                    {
                        cout << "Najpierw stworz macierz" << endl;
                    }
                else
                {
                    cout <<  endl << "Wyswietlenie macierzy: " << endl;
                    wyswietlenie(A);
                }
                break;
            }
            case 3:
            {
                if (czy_ustawiona==false)
                    {
                        cout << "Najpierw stworz macierz" << endl;
                    }
                else
                {
                    najw_suma_wiersz(A);
                }
                break;
            }
            case 4:
            {
                if (czy_ustawiona==false)
                    {
                        cout << "Najpierw stworz macierz"<< endl;
                    }
                else
                {
                    sortowanie(A);
                }
                break;
            }
            case 5:
            {
                if (czy_ustawiona==false)
                    {
                        cout << "Najpierw stworz macierz" << endl;
                    }
                else
                {
                    transpozycja(A);
                }
                break;
            }
            case 6:
            {
                if (czy_ustawiona==false)
                    {
                        cout << "Najpierw stworz macierz" << endl;
                    }
                else
                {
                    cout << "Sprawdzenie czy tablica jest symetryczna: "<< endl;
                    if (symetryczna(A,N)==false) //Zamiast A dac nazwe tablicy innej, zamiast N dac rozmiar nowej tablicy
                        {
                            cout << "tablica nie jest symetryczna" << endl;
                        }
                    else
                        {
                            cout << "tablica jest symetryczna" << endl;
                        }
                }
                break;

            }
            case 7:
            {
                dynamiczna();
                break;
            }
            case 8:
            {
                cout << "Do widzenia! ";
                exit(0);
            }
        }
    }

    return 0;
}
void wypelnianie_A(int A[N][N],int p, int k)
{
    for (int i=0;i<N;i++)
    {
        for (int j=0; j<N;j++)
        {
            if (j>=i)
            {
                A[i][j] = rand()%(k-p+1)+p;
            }
            else
            {
                A[i][j] = A[j][i];
            }
        }
    }
}
void wyswietlenie(int A[N][N])
{
    for (int i=0;i<N;i++)
        {
            for (int j=0; j<N;j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
}
void najw_suma_wiersz(int A[N][N])
{
    int maks_wiersz=0; //maksymalna wartosc wiersza
    int liczba_wierszy=1;
    for (int i=0;i<N;i++) //znalezienie maksymalnej wartosci wiersza matrycy
        {
            int suma_elementow = 0;
            for (int j=0; j<N;j++)
            {
                suma_elementow += A[i][j];
            }
            if (suma_elementow>maks_wiersz)
            {
                maks_wiersz = suma_elementow;
            }
        }
        //Kolejna petla jest potrzebna gdyz nie wiadomo czy nastepny wiersz nie okaze sie wiekszy od poprzedniego
    for (int i=0;i<N;i++)//Przyrownanie najw wartosci wiersza i wyswietlenie go
    {
        int suma_elementow = 0;
        for (int j=0; j<N;j++)
            {
                suma_elementow += A[i][j];
            }
        if (suma_elementow==maks_wiersz)
        {
            cout << "oto " << liczba_wierszy << " wiersz ktory ma najwieksza wartosc: " << endl;
            for (int j=0;j<N;j++)
            {
                cout << A[i][j] << " ";
            }
            liczba_wierszy++;
            cout << endl;
        }
    }
}
void transpozycja(int A[N][N])
{
    int tymczasowy;
    for (int i=0;i<N;i++)
    {
        for (int j=i+1;j<N;j++)
        {
            tymczasowy=A[i][j];
            A[i][j]=A[j][i];
            A[j][i]=tymczasowy;
        }
    }
}
void sortowanie(int A[N][N])
{
    int wybor;
    int i, j, k, temp;
    cout << "Sortowanie malejace, wybierz 0, sortowanie rosnace, wybierz 1 " << endl;
    cin >> wybor;
    if (wybor==0)
    {
        for (j = 0; j<N; j++)
        {
            for (k = 0; k<N-1; k++)
            {

                for (i = 0; i<N-1; i++)
                {
                    if (A[i][j]<A[i + 1][j])
                    {
                        temp = A[i][j];
                        A[i][j] = A[i + 1][j];
                        A[i + 1][j] = temp;
                    }
                }
            }
        }
    }
    else if (wybor==1)
    {
        for (j = 0; j<N; j++)
        {
            for (k = 0; k<N-1; k++)
            {

                for (i = 0; i<N-1; i++)
                {
                    if (A[i][j]>A[i + 1][j])
                    {
                        temp = A[i][j];
                        A[i][j] = A[i + 1][j];
                        A[i + 1][j] = temp;
                    }
                }
            }
        }
    }
    else
    {
        cout << "Podano zla wartosc!";
        exit(0);
    }
}
bool symetryczna(int A[N][N], int rozmiar)
{
    for (int i=0;i<N;i++)
    {
        for (int j=0;j<N;j++)
        {
            if(A[i][j]!=A[j][i])
            {
                return false;
            }
        }
    }
    return true;
}
void dynamiczna()
{
    int M,n,p,k;
    cout << "Podaj liczbe wierzszy: ";
    cin >>M;
    cout << "Podaj liczbe kolumn: ";
    cin >>n;
    cout << "Podaj zakres liczb losowych od p do k" << endl;
    cin >> p >> k;
    int ** tab = new int *[M];

    for (int i=0;i<M;i++)// tworzenie tablicy
    {
        tab[i] = new int [n];
    }
    for (int i=0;i<M;i++) //losowanie liczb i wyswietlenie w tablicy
    {
        for (int j=0;j<n;j++)
        {
            tab[i][j] = rand()%(k-p+1)+p;
            cout << tab[i][j] << " ";
        }
        cout << endl;
    }
    for (int i =0; i<M;i++) //uwolnienie pamieci
    {
        delete [] tab[i];
    }
    delete [] tab;
    tab = NULL;
}
