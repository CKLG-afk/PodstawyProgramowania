//Jakub Karwalski 251543
//Zadanie 4.3

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int zwroc_sume();
void kasyno(int);

int main()
{
    srand(time(0));
    int pieniadze=100;
    cout << "Kasyno, gracz rzuca dwoma koscmi i jesli suma wynosi 7 lub 11 gracz wygrywa." << endl << "Jesli suma oczek przy pierwszym rzucie wynosi 2,3 lub 12 gracz przegrywa" << endl;
    cout << "Jesli suma oczek wynosi od 4 do 10, suma staje sie punktami, " <<endl << "wtedy gracz musi wyrzucic taka sama liczbe oczek jak poprzednio" << endl;
    cout << "Na poczatek gracz otrzymuje 100 zlotych, za kazda wygrana 30 zl, a za przegrana traci 20 zl, gra trwa 10 rund" << endl;
    system("pause");
    kasyno(pieniadze);
    cout << "Koniec gry! Twoj stan konta to: " << pieniadze;
    return 0;
}
int zwroc_sume ()
{
    int wartosc_k1 =0;
    int wartosc_k2 =0;
    wartosc_k1=rand()%6+1; //liczby od 1 do 6
    wartosc_k2=rand()%6+1;
    return wartosc_k1+wartosc_k2; //suma rzutow dwoch kosci
}
void kasyno(int pieniadze)
{
    for (int i =1; i<11; i++) //10 rund
    {
        int punkty = zwroc_sume(); //przypisanie zwrocenej wartosci funkcji do zmiennej
        cout << "Runda nr " << i << endl;
        cout << "-----------------------" << endl;
        cout << "Wyrzucona przez ciebie ilosc oczek wynosi " << punkty << endl;
        if (punkty==7 ||punkty==11) //warunek zwyciestwa
        {
            cout << "Wygrales runde! " << endl << "Dostajesz 30 zl" << endl;
            pieniadze = pieniadze+30;
        }
        else if (punkty==2,punkty==3,punkty==12)//warunek przegranej
        {
            cout << "Przegrales runde... " << endl << "Tracisz 20 zl" << endl;
            pieniadze = pieniadze-20;
        }
        else //dodatkowe rzuty
        {
            int aktywator=0;
            cout << "Musisz losowac jeszcze raz" << endl;
            cout << "Twoja suma staje sie punktami, wyrzucenie 7 to przegrana"<< endl;
            system("pause");
            while (aktywator==0) //rzuty do spelnienia warunku wyrzucenia takiej samej liczby oczek
            {
                int punkty_zapas = zwroc_sume();
                cout << "Teraz wyrzuciles " << punkty_zapas << endl;
                if (punkty_zapas==punkty) //warunek wygranej
                {
                    cout << "Wygrales runde! Zdobywasz 30 zl" << endl;
                    pieniadze = pieniadze+30;
                    aktywator=1;
                }
                else if (punkty_zapas==7) //warunek przegranej
                {
                    cout << "Przegrales runde... tracisz 20 zl" << endl;
                    pieniadze = pieniadze-20;
                    aktywator=1;
                }
                else//powtorzenie rzutu
                {
                    cout <<"Musisz rzucac jeszcze raz!" << endl;
                    system("pause");
                }
            }
        }
        cout << "-----------------------" << endl;
        cout << "Przejdz do nastepnej rundy (ENTER)" << endl << "-----------------------" << endl << endl << endl;
        system("pause");
    }
}
