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
    return uzytkownikManager.logowanieUzytkownika();
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

void KsiazkaAdresowa:: dodajAdresata()
{
    //adresatManager.dodajAdresata();
}

