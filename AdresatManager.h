#ifndef ADRESATMANAGER_H
#define ADRESATMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <sstream>
#include <algorithm>

#include "UzytkownikManager.h"
#include "Adresat.h"
#include "MetodyPomocnicze.h"
#include "PlikZAdresatami.h"

using namespace std;

class AdresatManager
{
    int idOstatniegoAdresata;
    int idUsunietegoAdresata;
    vector <Adresat> adresaci;

    UzytkownikManager uzytkownikManager;

    Adresat podajDaneNowegoAdresata();
    void dopiszAdresataDoPliku(Adresat adresat);
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);

public:
    AdresatManager ();

    void wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    int dodajAdresata();

};

#endif

