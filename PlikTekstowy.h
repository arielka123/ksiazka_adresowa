#ifndef PLIKTEKSTOWY_H
#define PLIKTEKSTOWY_H

#include <iostream>
#include <fstream>

#include "MetodyPomocnicze.h"

using namespace std;

class PlikTekstowy
{
        protected:
        const string NAZWA_PLIKU;

        bool czyPlikJestPusty(fstream &plikTekstowy);

       PlikTekstowy (string nazwaPliku): NAZWA_PLIKU (nazwaPliku){};


};

#endif
