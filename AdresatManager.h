#ifndef ADRESATMANAGER_H
#define ADRESATMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <sstream>

#include "Adresat.h"
#include "MetodyPomocnicze.h"
#include "PlikZAdresatami.h"

using namespace std;

class AdresatManager
{
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
    vector <Adresat> adresaci;

    PlikZAdresatami plikZAdresatami;

    Adresat podajDaneNowegoAdresata();
    void wyswietlDaneAdresata(Adresat adresat);
    void wyswietlIloscWyszukanychAdresatow(int iloscAdresatow);
    int podajIdWybranegoAdresata();
    char wybierzOpcjeZMenuEdycja();
    void zaktualizujDaneWybranegoAdresata(Adresat adresat);


public:
    AdresatManager (string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika)
    : plikZAdresatami (nazwaPlikuZAdresatami), ID_ZALOGOWANEGO_UZYTKOWNIKA (idZalogowanegoUzytkownika)
    {
        adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    };

    void dodajAdresata();
    void wyswietlWszystkichAdresatow ();
    void wyszukajAdresatowPoImieniu();
    void wyszukajAdresatowPoNazwisku();
    void edytujAdresata();
    int usunAdresata();

};

#endif

