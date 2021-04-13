#include <iostream>
#include "KsiazkaAdresowa.h"

using namespace std;

int _main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy2.txt", "Adresaci.txt");

    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    //ksiazkaAdresowa.rejestracjaUzytkownika();
    //ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    ksiazkaAdresowa.logowanieUzytkownika();
    //ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
    //ksiazkaAdresowa.wylogowanieUzytkownika();
    ksiazkaAdresowa.dodajAdresata();
    ksiazkaAdresowa.dodajAdresata();
        ksiazkaAdresowa.dodajAdresata();

            ksiazkaAdresowa.dodajAdresata();



    return 0;
}

//testy

#include "AdresatManager.h"

int main()
{
    AdresatManager adresatManager ("Adresaci.txt",3);
    adresatManager.dodajAdresata();


     return 0;
}
