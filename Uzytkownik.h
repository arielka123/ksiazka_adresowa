#ifndef UZYTKOWNIK_H
#define UZYTKOWNIK_H

#include <iostream>

using namespace std;

class Uzytkownik
{
    int id;
    string login, haslo;
public:
    void ustawId(int noweId); // settery
    void ustawLogin(string nowyLogin);
    void ustawHaslo(string noweHaslo);

    int pobierzId();            //gettery
    string pobierzLogin();
    string pobierzHaslo();

};

#endif // UZYTKOWNIK_H
