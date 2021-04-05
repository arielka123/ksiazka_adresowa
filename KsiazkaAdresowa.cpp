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
/*
int  KsiazkaAdresowa::pobierzidZalogowanego()
{
    return uzytkownikManager.ustawIdZalogowanegouzytkownika();
}*/
void  KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika ()
{
    uzytkownikManager.zmianaHaslaZalogowanegoUzytkownika();
}
