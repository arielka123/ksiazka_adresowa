#include <iostream>
#include "KsiazkaAdresowa.h"
#include "Adresat.h"

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

    return 0;
}
