
#include "AdresatManager.h"

int AdresatManager:: dodajAdresata()
{
    Adresat adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);

    PlikZAdresatami plikZAdresatami;

    plikZAdresatami.dopiszAdresataDoPliku(adresat);

    return ++idOstatniegoAdresata;
}

Adresat AdresatManager::podajDaneNowegoAdresata()
{
    string imie, nazwisko, telefon, email, adres;

    Adresat adresat;

    adresat.ustawIdAdresata(++idOstatniegoAdresata);
    adresat.ustawIdUzytkownika (uzytkownikManager.pobierzIdZalogowanegoUzytkownika());

    cout << "Podaj imie: ";
    cin >> imie;

    adresat.ustawImie(zamienPierwszaLitereNaDuzaAPozostaleNaMale(imie));

    cout << "Podaj nazwisko: ";
    cin >> nazwisko;
    adresat.ustawNazwisko(zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwisko));

    cout << "Podaj numer telefonu: ";

    cin.ignore();
    getline (cin,telefon);
    adresat.ustawNumerTelefonu(telefon);

    cout << "Podaj email: ";
    cin >> email;

    adresat.ustawEmail(email);

    cout << "Podaj adres: ";
    cin.ignore();
    getline(cin,adres);
    adresat.ustawAdres(adres);

    return adresat;
}

string AdresatManager:: zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst)
{
    if (!tekst.empty())
    {
        transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);
        tekst[0] = toupper(tekst[0]);
    }
    return tekst;
}

void AdresatManager::wczytajAdresatowZalogowanegoUzytkownikaZPliku()
{
    PlikZAdresatami plikZAdresatami;
    plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku();
}
