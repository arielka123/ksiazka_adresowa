#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

struct Uzytkownik
{
    int id_uzytkownika =0;
    string login ="", haslo ="";
};

struct Kontakt
{
    int id_adresata=0, id_uzytkownika =0;
    string imie="", nazwisko="", adres="",email="", nr_telefonu="";
};

int zamiana_string_na_int (string str)
{
    int s =0;
    s = atoi(str.c_str());

    return s;
}

string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst)
{
    if (!tekst.empty())
    {
        transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);
        tekst[0] = toupper(tekst[0]);
    }
    return tekst;
}

vector<string> podziel_string (string s, char delim)
{
    vector<string> result;
    stringstream ss (s);
    string item;

    while (getline (ss, item, delim))
    {
        result.push_back (item);
    }
    return result;
}

void zapisz_do_pliku_adresatow (Kontakt nowy_adresat)
{
    fstream plik;

    plik.open ("ksiazka_adresowa.txt",ios::out | ios::app);
    if (plik.good() == true)
    {
        plik<<nowy_adresat.id_adresata<<"|";
        plik<<nowy_adresat.id_uzytkownika<<"|";
        plik<<nowy_adresat.imie<<"|";
        plik<<nowy_adresat.nazwisko<<"|";
        plik<<nowy_adresat.adres<<"|";
        plik<<nowy_adresat.email<<"|";
        plik<<nowy_adresat.nr_telefonu<<"|"<<endl;
        plik.close();
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku i zapisac do niego danych." << endl;
        Sleep (1500);
    }
}

Kontakt utworz_kontakt (int max_id, int id_uzytkownika)
{
    string imie, nazwisko, adres, email, nr_telefonu;

    Kontakt nowy_adresat = Kontakt();

    cout << "Podaj imie: ";
    cin >>imie;
    cout << "Podaj Nazwisko: ";
    cin >>nazwisko;
    cout << "Podaj adres: ";
    cin.ignore();
    getline (cin,adres);
    cout << "Podaj nr telefonu: ";
    cin >>nr_telefonu;
    cout << "Podaj email: ";
    cin >>email;

    nowy_adresat.imie = zamienPierwszaLitereNaDuzaAPozostaleNaMale(imie);
    nowy_adresat.nazwisko = zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwisko);
    nowy_adresat.adres = zamienPierwszaLitereNaDuzaAPozostaleNaMale(adres);
    nowy_adresat.email = email;
    nowy_adresat.nr_telefonu = nr_telefonu;
    nowy_adresat.id_adresata = max_id+1;
    nowy_adresat.id_uzytkownika = id_uzytkownika;

    zapisz_do_pliku_adresatow (nowy_adresat);

    return nowy_adresat;
}

void wczytaj_adresatow_z_pliku_zalogowanego_u (vector <Kontakt> &adresaci, int id_zalogowanego)
{
    fstream plik;
    string id_adresata, id_uzytkownika, nazwisko, imie, adres, email, nr_telefonu;

    plik.open( "ksiazka_adresowa.txt", ios::in);

    if (plik.good()==true)
    {
        string linia;
        vector<string> v;

        while (getline(plik,linia))
        {
            v = podziel_string (linia, '|');

            Kontakt k1 = Kontakt ();

            for (int i=0; i< v.size (); i++)
            {
                if (i ==0)
                {
                    id_adresata = v[i];
                }
                if (i ==1)
                {
                    id_uzytkownika = v[i];
                }
                if (i ==2)
                {
                    imie = v[i];
                }
                if (i ==3)
                {
                    nazwisko = v[i];
                }
                if (i ==4)
                {
                    adres = v[i];
                }
                if (i ==5)
                {
                    nr_telefonu = v[i];
                }
                if (i ==6)
                {
                    email = v[i];
                }
            }

            if (zamiana_string_na_int (id_uzytkownika) == id_zalogowanego)
            {
                k1.imie = imie;
                k1.nazwisko = nazwisko;
                k1.adres = adres;
                k1.email = email;
                k1.nr_telefonu = nr_telefonu;
                k1.id_adresata = zamiana_string_na_int (id_adresata);
                k1.id_uzytkownika = zamiana_string_na_int (id_uzytkownika);
                adresaci.push_back(k1);
            }
        }
        plik.close();
    }
}

void wczytaj_adresatow_z_pliku_wszystkich_u (vector <Kontakt> &adresaci_wszystkich_u)
{
    fstream plik;
    string id_adresata, id_uzytkownika, nazwisko, imie, adres, email, nr_telefonu;

    plik.open( "ksiazka_adresowa.txt", ios::in);

    if (plik.good()==true)
    {
        string linia;
        vector<string> v;

        while (getline(plik,linia))
        {
            v = podziel_string (linia, '|');

            Kontakt k1 = Kontakt ();

            for (int i=0; i< v.size (); i++)
            {
                if (i ==0)
                {
                    id_adresata = v[i];
                }
                if (i ==1)
                {
                    id_uzytkownika = v[i];
                }
                if (i ==2)
                {
                    imie = v[i];
                }
                if (i ==3)
                {
                    nazwisko = v[i];
                }
                if (i ==4)
                {
                    adres = v[i];
                }
                if (i ==5)
                {
                    nr_telefonu = v[i];
                }
                if (i ==6)
                {
                    email = v[i];
                }
            }

            k1.imie = imie;
            k1.nazwisko = nazwisko;
            k1.adres = adres;
            k1.email = email;
            k1.nr_telefonu = nr_telefonu;
            k1.id_adresata = zamiana_string_na_int (id_adresata);
            k1.id_uzytkownika = zamiana_string_na_int (id_uzytkownika);
            adresaci_wszystkich_u.push_back(k1);
        }
        plik.close();
    }
}

void  wyswietl_adresatow (vector <Kontakt> adresaci)
{
    int liczba_kontaktow =adresaci.size();

    if (liczba_kontaktow>0)
    {
        for (int i=0; i<liczba_kontaktow; i++)
        {
            cout<<endl;
            cout <<adresaci[i].id_adresata<<". "<<adresaci[i].imie<<" "<< adresaci[i].nazwisko<<endl;
            cout <<adresaci[i].adres<<endl;
            cout <<"nr tel.: "<<adresaci[i].nr_telefonu<<endl;
            cout<<"e-mail: "<<adresaci[i].email<<endl;
        }
        getch();
    }
    else
    {
        cerr <<"Nie ma zapisanych zadnych kontaktow. Dodaj nowy kontakt"<<endl;
        Sleep(1500);
    }
}

void wyswietl_po_imieniu (vector <Kontakt> adresaci)
{
    string imie = "";
    int liczba_kontaktow=adresaci.size();
    bool czy_istnieje =false;

    cout <<"Podaj imie szukanego adresata: ";
    cin >> imie;
    imie =zamienPierwszaLitereNaDuzaAPozostaleNaMale(imie);

    for (int i=0; i<liczba_kontaktow; i++)
    {
        if (imie == adresaci[i].imie)
        {
            czy_istnieje =true;
            cout<<endl;
            cout <<adresaci[i].id_adresata<<". "<<adresaci[i].imie<<" "<< adresaci[i].nazwisko<<endl;
            cout <<adresaci[i].adres<<endl;
            cout <<"nr tel.: "<<adresaci[i].nr_telefonu<<endl;
            cout<<"e-mail: "<<adresaci[i].email<<endl;
        }
    }
    if (czy_istnieje ==false)
    {
        cerr <<"Nie ma takiego imienia w bazie kontaktow."<<endl;
    }
    getch ();
}

void wyswietl_po_nazwisku(vector<Kontakt> adresaci)
{
    bool czy_istnieje =false;
    string nazwisko ="";

    int liczba_kontaktow=adresaci.size();

    cout <<"Podaj nazwisko szukanego adresata: ";
    cin >> nazwisko;
    nazwisko =zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwisko);

    for (int i=0; i<liczba_kontaktow; i++)
    {
        if (nazwisko == adresaci[i].nazwisko)
        {
            czy_istnieje =true;
            cout<<endl;
            cout <<adresaci[i].id_adresata<<". "<<adresaci[i].imie<<" "<< adresaci[i].nazwisko<<endl;
            cout <<adresaci[i].adres<<endl;
            cout <<"nr tel.: "<<adresaci[i].nr_telefonu<<endl;
            cout<<"e-mail: "<<adresaci[i].email<<endl;
        }
    }
    if (czy_istnieje ==false)
    {
        cerr <<"Nie ma takiego nazwiska w bazie kontaktow."<<endl;
    }

    getch();
}

vector <Kontakt> usywanie_adresata (vector <Kontakt>adresaci)
{
    int id_adresata;
    int pozycja =0;
    bool czy_istnieje = false;

    cout << "Podaj nr ID adresata ktorego chcesz skasowac: ";
    cin >>id_adresata;

    for(int i = 0; i<adresaci.size(); i++)
    {
        if (adresaci[i].id_adresata== id_adresata)
        {
            czy_istnieje =true;
            pozycja =i;
        }
    }
    if (czy_istnieje == false)
    {
        cerr <<"Nie ma takiego nr id w bazie kontaktow !";
        Sleep (1500);
        return adresaci;
    }
    cout <<"Jesli chcesz usunac adreasata o nr ID "<<id_adresata<<" wcisnij klawisz 't'. Jesli sie rozmysliles wcisnij klawisz";

    char wybor;
    wybor = getch ();

    switch (wybor)
    {
    case 't':
    {
        adresaci.erase(adresaci.begin()+ pozycja);
        cout <<"Adresat zostal usuniety";
    }
    break;
    }
    return adresaci;
}

vector <Kontakt > edycja_adresata(vector <Kontakt> adresaci)
{
    int id_adresata=0;
    int pozycja=0;
    bool czy_istnieje =false;
    fstream plik;
    string nazwisko, adres, email, nr_telefonu, imie;

    cout <<"Podaj nr ID adresata ktorego chcesz edytowac: ";
    cin >>id_adresata;
    plik.open( "ksiazka_adresowa.txt", ios::in);
    for(int i = 0; i<adresaci.size(); i++)
    {
        if (id_adresata==adresaci[i].id_adresata)
        {

            if (plik.good() == true)
            {
                czy_istnieje =true;
                pozycja = i;

            }
            else  if (czy_istnieje == false)
            {
                cerr <<"Nie ma takiego nr id w bazie kontaktow !";
                Sleep (1500);
            }
        }
    }
    system ("cls");

    cout <<"----EDYCJA----"<<endl;
    cout <<"1. imie"<<endl;
    cout <<"2. nazwisko"<<endl;
    cout <<"3. numer telefonu"<<endl;
    cout <<"4. email"<<endl;
    cout <<"5. adres"<<endl;
    cout <<"6. powrot do menu"<<endl;

    char wybor;
    wybor = getch();

    switch (wybor)
    {
    case '1':
    {
        cout <<"Podaj poprawne imie: ";
        cin>> imie;
        imie =zamienPierwszaLitereNaDuzaAPozostaleNaMale(imie);
        adresaci[pozycja].imie=imie;
    } break;

    case '2':
    {
        cout <<"Podaj poprawne nazwisko: ";
        cin>> nazwisko;
        nazwisko =zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwisko);
        adresaci[pozycja].nazwisko=nazwisko;
    }
    break;
    case '3':
    {
        cout <<"Podaj poprawny nr telefonu: ";
        cin>> nr_telefonu;
        adresaci[pozycja].nr_telefonu=nr_telefonu;
    }
    break;
    case '4':
    {
        cout <<"Podaj poprawny email: ";
        cin>> email;
        adresaci[pozycja].email=email;
    }
    break;

    case '5':
    {
        cout <<"Podaj poprawny adres: ";
        cin.ignore();
        getline (cin,adres);
        adres =zamienPierwszaLitereNaDuzaAPozostaleNaMale(adres);
        adresaci[pozycja].adres=adres;
    }
    break;

    case '6':
    {
        return adresaci;
    }
    break;
    }

    plik.close();

    return adresaci;
}

void zakonczProgram()
{
    cout << endl << "Koniec programu." << endl;
    exit(0);
}

void zapisz_do_pliku_uzytkownika (Uzytkownik nowy_uzytkownik)
{
    fstream plik;

    plik.open ("uzytkownicy.txt",ios::out | ios::app);
    if (plik.good() == true)
    {
        plik<<nowy_uzytkownik.id_uzytkownika<<"|";
        plik<<nowy_uzytkownik.login<<"|";
        plik<<nowy_uzytkownik.haslo<<"|"<<endl;
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku i zapisac do niego danych." << endl;
        Sleep (1500);
    }
    plik.close ();
}

void zapisz_uzytkownikow (vector <Uzytkownik> &uzytkownicy)
{
    fstream plik;

    plik.open ("uzytkownicy.txt",ios::out);

    for(int i = 0; i<uzytkownicy.size(); i++)
    {
        if (plik.good() == true)
        {
            plik<<uzytkownicy[i].id_uzytkownika<<"|";
            plik<<uzytkownicy[i].login<<"|";
            plik<<uzytkownicy[i].haslo<<"|"<<endl;
        }
    }

    if (plik.good() == false)
    {
        cout << "Nie udalo sie otworzyc pliku i zapisac do niego danych." << endl;
        Sleep (1500);
    }
    plik.close();
}

void wczytaj_uzytkownikow_z_pliku (vector <Uzytkownik> &uzytkownicy)
{
    fstream plik;
    string id_uzytkownika;
    string haslo, login;

    plik.open( "uzytkownicy.txt", ios::in);

    if (plik.good()==true)
    {
        string linia;
        vector<string> wczytane_dane;

        while (getline(plik,linia))
        {
            wczytane_dane = podziel_string (linia, '|');

            Uzytkownik k1 = Uzytkownik ();

            for (int i=0; i< wczytane_dane.size (); i++)
            {
                if (i ==0)
                {
                    id_uzytkownika = wczytane_dane[i];
                }
                if (i ==1)
                {
                    login= wczytane_dane[i];
                }
                if (i ==2)
                {
                    haslo = wczytane_dane[i];
                }
            }
            k1.haslo = haslo;
            k1.login = login;
            k1.id_uzytkownika =  zamiana_string_na_int (id_uzytkownika);

            uzytkownicy.push_back(k1);
        }
    }
    plik.close();
}

int rejestracja (vector <Uzytkownik> &uzytkownicy, int najwyzsze_znane_id_uzytkownika)
{
    Uzytkownik nowy_uzytkownik = Uzytkownik();

    int ilosc_uzytkownikow = uzytkownicy.size();
    string login, haslo;
    cout << "Podaj login: ";
    cin >>login;

    int  pozycja =0;

    while (pozycja<ilosc_uzytkownikow)
    {
        if (uzytkownicy[pozycja].login == login)
        {
            cerr <<"Taki uzytkownik juz istnieje. Wpisz inny login: ";
            cin >> login;
            pozycja= 0;
        }
        else
        {
            pozycja ++;
        }
    }
    cout <<"Podaj haslo :";
    cin >> haslo;

    nowy_uzytkownik.haslo = haslo;
    nowy_uzytkownik.login = login;
    nowy_uzytkownik.id_uzytkownika = najwyzsze_znane_id_uzytkownika+1;

    uzytkownicy.push_back (nowy_uzytkownik);

    cout <<"Uzytkownik zostal zalogowany" <<endl;
    Sleep(1000);

    zapisz_do_pliku_uzytkownika (nowy_uzytkownik);

    return najwyzsze_znane_id_uzytkownika+1;
}

int logowanie(vector <Uzytkownik> &uzytkownicy)
{
    string login, haslo;
    cout << "Podaj login: ";
    cin >> login;
    int i =0;
    while (i<uzytkownicy.size())
    {
        if (uzytkownicy[i].login == login)
        {
            for (int proby=0; proby<3; proby++)
            {
                cout <<"Podaj haslo. Pozostalo prob " << 3-proby<<" :";
                cin >> haslo;
                if (uzytkownicy[i].haslo == haslo)
                {
                    cout <<"Uzytkownik zostal zalogowany";
                    Sleep(1000);
                    return uzytkownicy[i].id_uzytkownika;
                }
            }
            cout << "Podales 3 razy bledne haslo. Poczekaj 3 sekundy przed kolejna proba"<<endl;
            Sleep (3000);
            return 0;
        }
        i++;
    }
    cout << "Nie ma uzytkownika z takim loginem. Zarejestruj sie."<<endl;
    Sleep(1000);
    return 0;
}

menu_logowania (vector <Uzytkownik> &uzytkownicy, int id_uzytkownika)
{
    int max_id_uzytkownika;
    char wybor;

    while (id_uzytkownika ==0)
    {
        system ("cls");
        cout <<"---KSIAZKA ADRESOWA---" <<endl;
        cout <<"1. Rejestracja"<<endl;
        cout <<"2. Logowanie"<<endl;
        cout <<"9. Zakoncz program"<<endl;
        cin >>wybor;

        if (wybor =='1')
        {
            int liczba_uzytkownikow =uzytkownicy.size();
            if (liczba_uzytkownikow >0)
            {
                max_id_uzytkownika = uzytkownicy[liczba_uzytkownikow-1].id_uzytkownika;

                id_uzytkownika=rejestracja(uzytkownicy, max_id_uzytkownika);
            }
            else  id_uzytkownika=rejestracja(uzytkownicy, 0);
        }
        else if (wybor =='2')
        {
            id_uzytkownika =logowanie(uzytkownicy);
        }
        else if (wybor =='9')
        {
            zakonczProgram ();
        }
        else
        {
            cerr << "Nie ma takiej opcji do wyboru. Wybierz jeszcze raz";
            Sleep(1000);
            id_uzytkownika =0;
        }
    }
    return id_uzytkownika;
}

void zmianaHasla (vector <Uzytkownik> &uzytkownicy,int idZalogowanego)
{
    string haslo;
    int  iloscUzytkownikow = uzytkownicy.size();
    bool czy_zmienione =false;

    for (int i=0; i<iloscUzytkownikow; i++)
    {
        if ( uzytkownicy[i].id_uzytkownika==idZalogowanego)
        {
            cout <<"Podaj nowe haslo: "<<endl;
            cin >> haslo;
            uzytkownicy[i].haslo=haslo;
            czy_zmienione =true;
        }
    }

    if (czy_zmienione == true)
    {
        cout << "Haslo zostalo zmienione"<<endl;
        Sleep (1000);
    }
    else
    {
        cout << "Cos poszlo nie tak... sprobuj jeszcze raz"<<endl;
        Sleep (1000);
        exit (0);
    }
    zapisz_uzytkownikow (uzytkownicy);
}

void zapisz_zmiany_uzytkownika ( vector <Kontakt> &adresaci, vector <Kontakt> &adresaci_wszystkich_u, int id_zalogowanego)
{
    fstream plik;

    wczytaj_adresatow_z_pliku_wszystkich_u (adresaci_wszystkich_u);

    plik.open ("tymczasowy.txt",ios::out);
    if (plik.good() == true)
    {
        for(int j = 0; j<adresaci_wszystkich_u.size(); j++)
        {
            if (adresaci_wszystkich_u[j].id_uzytkownika != adresaci[0].id_uzytkownika)
            {
                plik<<adresaci_wszystkich_u[j].id_adresata<<"|";
                plik<<adresaci_wszystkich_u[j].id_uzytkownika<<"|";
                plik<<adresaci_wszystkich_u[j].imie<<"|";
                plik<<adresaci_wszystkich_u[j].nazwisko<<"|";
                plik<<adresaci_wszystkich_u[j].adres<<"|";
                plik<<adresaci_wszystkich_u[j].email<<"|";
                plik<<adresaci_wszystkich_u[j].nr_telefonu<<"|"<<endl;
            }
        }
        for (int i = 0; i<adresaci.size(); i++)
        {
            plik<<adresaci[i].id_adresata<<"|";
            plik<<adresaci[i].id_uzytkownika<<"|";
            plik<<adresaci[i].imie<<"|";
            plik<<adresaci[i].nazwisko<<"|";
            plik<<adresaci[i].adres<<"|";
            plik<<adresaci[i].email<<"|";
            plik<<adresaci[i].nr_telefonu<<"|"<<endl;
        }
    }
    plik.close();

    remove ("ksiazka_adresowa.txt")==0;
    rename("tymczasowy.txt", "ksiazka_adresowa.txt");
    adresaci_wszystkich_u.clear();
}


int main()
{
    vector <Uzytkownik> uzytkownicy;
    vector <Kontakt> adresaci;
    vector <Kontakt> adresaci_wszystkich_u;
    char wybor;
    int id_zalogowanego =0;
    int max_id_adresata = 0;

    wczytaj_uzytkownikow_z_pliku (uzytkownicy);

    id_zalogowanego = menu_logowania (uzytkownicy, id_zalogowanego);

    wczytaj_adresatow_z_pliku_zalogowanego_u (adresaci, id_zalogowanego);

    while (true)
    {
        system ("cls");
        cout <<"---KSIAZKA ADRESOWA---" <<endl;
        cout <<"1. Dodaj adresata"<<endl;
        cout <<"2. Wyszukaj po imieniu"<<endl;
        cout <<"3. Wyszukaj po nazwisku"<<endl;
        cout <<"4. Wyswietl wszystkich adresatow"<<endl;
        cout <<"5. Usun adresata"<<endl;
        cout <<"6. Edytuj adresata"<<endl;
        cout <<"7. Zmien haslo"<<endl;
        cout <<"8. Wyloguj"<<endl;
        cout <<"9. Zamknij Program"<<endl;
        cout <<"Twoj wybor: "<<endl;

        wybor=getch();

        switch (wybor)
        {
        case '1':
        {
            int liczba_kontaktow=adresaci.size();
            if (liczba_kontaktow >0)
            {
                max_id_adresata = adresaci[liczba_kontaktow-1].id_adresata;

                adresaci.push_back(utworz_kontakt(max_id_adresata, id_zalogowanego));
            }
            else  adresaci.push_back(utworz_kontakt(0, id_zalogowanego));
        }
        break;

        case '2':
        {
            wyswietl_po_imieniu (adresaci);
        }
        break;

        case '3':
        {
            wyswietl_po_nazwisku(adresaci);
        }
        break;
        case '4':
        {
            wyswietl_adresatow (adresaci);
        }
        break;
        case '5':
        {
            adresaci = usywanie_adresata (adresaci);
            zapisz_zmiany_uzytkownika (adresaci,adresaci_wszystkich_u, id_zalogowanego);
        }
        break;

        case '6':
        {
            adresaci = edycja_adresata(adresaci);
            zapisz_zmiany_uzytkownika (adresaci,adresaci_wszystkich_u, id_zalogowanego);
        }
        break;

        case '7':
        {
            system ("cls");
            cout <<"1. Zmiana hasla"<<endl;
            cout <<"2. Wyloguj"<<endl;
            cout <<"3. Wroc do menu glownego"<<endl;
            cin >>wybor;

            wybor=getch();

            if (wybor =='1')
            {
                zmianaHasla (uzytkownicy, id_zalogowanego);
            }
            else if (wybor =='2')
            {
                id_zalogowanego =0;
                id_zalogowanego = menu_logowania (uzytkownicy, id_zalogowanego);
            }
            else if (wybor =='3')
            {
                system ("cls");
                continue;
            }
        }
        break;

        case '8':
        {
            id_zalogowanego =0;
            id_zalogowanego = menu_logowania (uzytkownicy, id_zalogowanego);
        }
        break;

        case '9':
        {
            zakonczProgram ();
        }
        break;

        default:
        {
            cerr << "Nie ma takiej opcji do wyboru. Wybierz jeszcze raz";
            Sleep(1000);
        }
        }
    }
    return 0;
}
