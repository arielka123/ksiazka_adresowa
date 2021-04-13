#include "AdresatManager.h"

void AdresatManager:: dodajAdresata()
{
    Adresat adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);

    if (plikZAdresatami.dopiszAdresataDoPliku(adresat))
        cout <<"Nowy adresat zostal dodany";
    else
        cout <<"Blad. bie udalo sie dodac nowego adresata"<<endl; // dlatego moze byc boool
    system("pause");
}

Adresat AdresatManager::podajDaneNowegoAdresata()
{
    string imie, nazwisko, telefon, email, adres;

    Adresat adresat;

    adresat.ustawIdAdresata(plikZAdresatami.pobierzIdOstatniegoAdresata(adresaci)+1);
    adresat.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);

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


