#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikManager.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
    uzytkownikManager.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::logowanieUzytkownika()
{
    uzytkownikManager.logowanieUzytkownika();
    if(uzytkownikManager.czyJestZalogowany())
    {
        adresatManager = new AdresatManager (NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikManager.pobierzIdZalogowanegoUzytkownika());
    }
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
    delete adresatManager;
    adresatManager = NULL;
}

void KsiazkaAdresowa:: dodajAdresata()
{
     if(uzytkownikManager.czyJestZalogowany())
    {
        adresatManager -> dodajAdresata();
    }
    else
    {
        cout <<"Aby dodac adresata nalezy najpierw siê zalogowac"<<endl;
        system("pause");
    }
}

