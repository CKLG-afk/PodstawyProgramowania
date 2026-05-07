//Jakub Karwalski 251543
//Zadanie 4.4

#include <iostream>

using namespace std;

void przelicz(int*,int*,bool);

int main()
{
    char wybor;
    int rokG = 0, rokM = 0, wynik = 0;
    int *wskG = &rokG;
    int *wskM = &rokM;
    cout << "Przelicznik roku gregorianskiego na muzulmanski i odwrotnie!" << endl;
    cout << "Czy chcesz przeliczac date z kalendarza gregorianskiego na muzulmanski (wcisnij g/G), czy odwrotnie (wcisnij M/m)" << endl;
    cin >> wybor;
    switch (wybor)
    {
        case 'm':


        case 'M':
            cout << "Podaj rok w formie muzulmanskiej: ";
            cin >> rokM;
            przelicz(&rokG, &rokM, true);
            cout << endl <<"Rok w formie gregorianskiej: " << rokG << endl;
            break;
        case 'g':

        case 'G':
            cout << "Podaj rok w formie gregorianskiej: ";
            cin >> rokG;
            przelicz(&rokG, &rokM, false);
            cout << endl << "Rok w formie muzulmanskiej: " << rokM << endl;
            break;
    }
    return 0;
}
void przelicz(int* wskG, int* wskM, bool MtoG)
{
    if(MtoG == false)
    {
    *wskM = *wskG - 621 + (*wskG - 621) / 32;
    }
    else if(MtoG == true)
    {
    *wskG = *wskM - (*wskM/33) + 621;
    }
}
