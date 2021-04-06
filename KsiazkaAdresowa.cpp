#include "KsiazkaAdresowa.h"

 void KsiazkaAdresowa::rejestracjaUzytkownika()
 {
     uzytkownikManager.rejestracjaUzytkownika();
 }

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
    uzytkownikManager.wypiszWszystkichUzytkownikow();
}

int KsiazkaAdresowa::logowanieUzytkownika()
    {
        uzytkownikManager.logowanieUzytkownika();
    }

int  KsiazkaAdresowa::pobierzidZalogowanegoUzytkownika()
{
    return uzytkownikManager.pobierzIdZalogowanegoUzytkownika();
}

void  KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika ()
{
    uzytkownikManager.zmianaHaslaZalogowanegoUzytkownika();
}

  void KsiazkaAdresowa::wylogowanieUzytkownika()
  {
      uzytkownikManager.wylogowanieUzytkownika();
  }

