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
        cout <<"Aby dodac adresata nalezy najpierw sie zalogowac"<<endl;
        system("pause");
    }
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow()
{
    adresatManager->wyswietlWszystkichAdresatow();
}

void KsiazkaAdresowa::wyszukajAdresatowPoImieniu()
{
    adresatManager->wyszukajAdresatowPoImieniu();
}

void KsiazkaAdresowa:: wyszukajAdresatowPoNazwisku()
{
    adresatManager->wyszukajAdresatowPoNazwisku();
}
void KsiazkaAdresowa:: edytujAdresata()
{
    adresatManager->edytujAdresata();
}

int KsiazkaAdresowa :: usunAdresata()
{
    adresatManager->usunAdresata();
}
