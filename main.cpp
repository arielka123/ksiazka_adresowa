#include <iostream>
#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy2.txt", "Adresaci.txt");

    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    //ksiazkaAdresowa.rejestracjaUzytkownika();
    //ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    ksiazkaAdresowa.logowanieUzytkownika();
    //ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
    //ksiazkaAdresowa.wylogowanieUzytkownika();
   // ksiazkaAdresowa.dodajAdresata();
    ksiazkaAdresowa.wyswietlWszystkichAdresatow();
    ksiazkaAdresowa.wyszukajAdresatowPoImieniu();

    return 0;
}

//testy

#include "AdresatManager.h"

int _main()
{
    AdresatManager adresatManager ("Adresaci.txt",3);
    adresatManager.dodajAdresata();
    adresatManager.dodajAdresata();
    adresatManager.dodajAdresata();


     return 0;
}
