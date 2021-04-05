#include "UzytkownikManager.h"

void UzytkownikManager::rejestracjaUzytkownika()
{
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);

    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

Uzytkownik UzytkownikManager::podajDaneNowegoUzytkownika()
{
    Uzytkownik uzytkownik;

uzytkownik.ustawId(pobierzIdNowegoUzytkownika());
string login;

    do
    {
        cout << "Podaj login: ";
        cin>>login;
        uzytkownik.ustawLogin(login);

    } while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    string haslo;

    cout << "Podaj haslo: ";
    cin>> haslo;
    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}

int UzytkownikManager::pobierzIdNowegoUzytkownika()
{
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}

bool UzytkownikManager::czyIstniejeLogin(string login)
{
    for (int i; i<uzytkownicy.size();i++)
    {
        if (uzytkownicy[i].pobierzLogin()==login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;

             return true;
        }
        return false;
    }
}

void UzytkownikManager::wypiszWszystkichUzytkownikow()
{
        for (int i=0; i<uzytkownicy.size();i++)
    {
        cout << uzytkownicy[i].pobierzId() << endl;
        cout << uzytkownicy[i].pobierzLogin() << endl;
        cout << uzytkownicy[i].pobierzHaslo() << endl;
    }
}


void UzytkownikManager::wczytajUzytkownikowZPliku()
{
   uzytkownicy= plikZUzytkownikami.wczytajUzytkownikowZPliku();
}

int UzytkownikManager::logowanieUzytkownika()
{
    Uzytkownik uzytkownik;
    string LOGIN = "", HASLO = "";

    cout << endl << "Podaj login: ";
    cin>>LOGIN;


    for (int i=0; i< uzytkownicy.size();i++)
    {
        if (uzytkownicy[i].pobierzLogin() == LOGIN)
        {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
               cin>> HASLO;

                if (uzytkownicy[i].pobierzHaslo() ==HASLO)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    return uzytkownicy[i].pobierzId();
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return 0;
        }
    }

    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return 0;
}

