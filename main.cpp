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
    cin.ignore();
    //ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
    //ksiazkaAdresowa.wylogowanieUzytkownika();
    ksiazkaAdresowa.dodajAdresata();
    ksiazkaAdresowa.wyswietlWszystkichAdresatow();
    //ksiazkaAdresowa.wyszukajAdresatowPoImieniu();
    //ksiazkaAdresowa.wyszukajAdresatowPoNazwisku();
    //ksiazkaAdresowa.edytujAdresata();
    ksiazkaAdresowa.usunAdresata();

    ksiazkaAdresowa.wyswietlWszystkichAdresatow();


    return 0;
}

//testy

#include "AdresatManager.h"

int _main()
{
    AdresatManager adresatManager ("Adresaci.txt",3);
  adresatManager.wyswietlWszystkichAdresatow();
 //  adresatManager.dodajAdresata();
    adresatManager.dodajAdresata();
    adresatManager.dodajAdresata();
  //  adresatManager.wyswietlWszystkichAdresatow();

    adresatManager.usunAdresata();
    adresatManager.wyswietlWszystkichAdresatow();


     return 0;
}
