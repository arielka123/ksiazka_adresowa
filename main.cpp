#include <iostream>
#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy2.txt", "Adresaci.txt");
    char wybor;
    int idZalogowanegoUzytkownika=0;

while (true)
    {
        if (idZalogowanegoUzytkownika == 0)
        {
            wybor = ksiazkaAdresowa.wybierzOpcjeZMenuGlownego();

            switch (wybor)
            {
            case '1':
            ksiazkaAdresowa.rejestracjaUzytkownika();
            idZalogowanegoUzytkownika = ksiazkaAdresowa.pobierzidZalogowanegoUzytkownika();

            break;
            case '2':
                ksiazkaAdresowa.logowanieUzytkownika();
               idZalogowanegoUzytkownika = ksiazkaAdresowa.pobierzidZalogowanegoUzytkownika();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }

        else
        {
            wybor = ksiazkaAdresowa.wybierzOpcjeZMenuUzytkownika();

            switch (wybor)
            {
            case '1':
                ksiazkaAdresowa.dodajAdresata();
                break;
            case '2':
                ksiazkaAdresowa.wyszukajAdresatowPoImieniu();
                break;
            case '3':
                ksiazkaAdresowa.wyszukajAdresatowPoNazwisku();
                break;
            case '4':
                ksiazkaAdresowa.wyswietlWszystkichAdresatow();
                break;
            case '5':
                ksiazkaAdresowa.usunAdresata();
                break;
            case '6':
                ksiazkaAdresowa.edytujAdresata();
                break;
            case '7':
                ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '8':
               idZalogowanegoUzytkownika = 0;
                break;
            }
        }
    }

    return 0;
}

//testy

#include "AdresatManager.h"

int _main()
{
    AdresatManager adresatManager ("Adresaci_test.txt",9);
    adresatManager.wyswietlWszystkichAdresatow();
    adresatManager.dodajAdresata();
    adresatManager.wyswietlWszystkichAdresatow();

//  //  adresatManager.wyswietlWszystkichAdresatow();
    adresatManager.edytujAdresata();
    //adresatManager.usunAdresata();
    adresatManager.wyswietlWszystkichAdresatow();


    return 0;
}
