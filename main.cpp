#include <iostream>
#include "KsiazkaAdresowa.h"
#include "Adresat.h"
#include "UzytkownikManager.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy2.txt");

    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    // ksiazkaAdresowa.rejestracjaUzytkownika();
    // ksiazkaAdresowa.rejestracjaUzytkownika();
    // ksiazkaAdresowa.wypiszWszystkichUzytkownikow();

    // ksiazkaAdresowa.logowanieUzytkownika();
    ksiazkaAdresowa.logowanieUzytkownika();

    ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();



    return 0;
}
