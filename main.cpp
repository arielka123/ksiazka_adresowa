#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

struct Kontakt
{
    int id=0;
    string imie="", nazwisko="", adres="",email="", nr_telefonu="";
};

string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst)
{
    if (!tekst.empty())
    {
        transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);
        tekst[0] = toupper(tekst[0]);
    }
    return tekst;
}

void zapisz_do_pliku (Kontakt nowy_adresat)
{
    fstream plik;

    plik.open ("ksiazka_adresowa.txt",ios::out | ios::app);
    if (plik.good() == true)
    {
        plik<<nowy_adresat.id<<"|";
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
        system("pause");
    }

}

Kontakt utworz_kontakt (int max_id)
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
    nowy_adresat.id = max_id+1;

    zapisz_do_pliku (nowy_adresat);

    return nowy_adresat;
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

vector <Kontakt> wczytaj_adresatow_z_pliku ()
{
    fstream plik;
    int id;
    string imie, nazwisko, adres;
    string email;
    string nr_telefonu;
    vector <Kontakt> adresaci;

    plik.open( "ksiazka_adresowa.txt", ios::in);

    if (plik.good()==true)
    {
        string linia;
        vector<string> v;

        while (getline(plik,linia))
        {
            string id, nazwisko, imie, adres, email, nr_telefonu;

            v = podziel_string (linia, '|');

            Kontakt k1 = Kontakt ();

            for (int i=0; i< v.size (); i++)
            {
                if (i ==0)
                {
                    id = v[i];
                }
                if (i ==1)
                {
                    imie = v[i];
                }
                if (i ==2)
                {
                    nazwisko = v[i];
                }
                if (i ==3)
                {
                    adres = v[i];
                }
                if (i ==4)
                {
                    nr_telefonu = v[i];
                }
                if (i ==5)
                {
                    email = v[i];
                }
            }
            k1.imie = imie;
            k1.nazwisko = nazwisko;
            k1.adres = adres;
            k1.email = email;
            k1.nr_telefonu = nr_telefonu;
            k1.id =  atoi(id.c_str());
            adresaci.push_back(k1);
        }
        plik.close();
    }

    return adresaci;
}

void  wyswietl_adresatow (vector <Kontakt>adresaci)
{
    int liczba_kontaktow =adresaci.size();

    if (liczba_kontaktow>0)
    {
        for (int i=0; i<liczba_kontaktow; i++)
        {
            cout<<endl;
            cout <<adresaci[i].id<<". "<<adresaci[i].imie<<" "<< adresaci[i].nazwisko<<endl;
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
    int ilosc_adresatow =0;

    cout <<"Podaj imie szukanego adresata: ";
    cin >> imie;
    imie =zamienPierwszaLitereNaDuzaAPozostaleNaMale(imie);

    for (int i=0; i<liczba_kontaktow; i++)
    {
        if (imie == adresaci[i].imie)
        {
            cout<<endl;
            cout <<adresaci[i].id<<". "<<adresaci[i].imie<<" "<< adresaci[i].nazwisko<<endl;
            cout <<adresaci[i].adres<<endl;
            cout <<"nr tel.: "<<adresaci[i].nr_telefonu<<endl;
            cout<<"e-mail: "<<adresaci[i].email<<endl;

            ilosc_adresatow++;
        }

    }
    if (ilosc_adresatow ==0)
    {
        cerr <<"Nie ma takiego imienia w bazie kontaktow."<<endl;
    }
    getch ();
}

void wyswietl_po_nazwisku(vector<Kontakt> adresaci)
{
    int ilosc_adresatow = 0;
    string nazwisko ="";

    int liczba_kontaktow=adresaci.size();

    cout <<"Podaj nazwisko szukanego adresata: ";
    cin >> nazwisko;
    nazwisko =zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwisko);

    for (int i=0; i<liczba_kontaktow; i++)
    {
        if (nazwisko == adresaci[i].nazwisko)
        {
            cout<<endl;
            cout <<adresaci[i].id<<". "<<adresaci[i].imie<<" "<< adresaci[i].nazwisko<<endl;
            cout <<adresaci[i].adres<<endl;
            cout <<"nr tel.: "<<adresaci[i].nr_telefonu<<endl;
            cout<<"e-mail: "<<adresaci[i].email<<endl;
        }

    }
    if (ilosc_adresatow ==0)
    {
        cerr <<"Nie ma takiego nazwiska w bazie kontaktow."<<endl;
    }

    getch();
}

vector <Kontakt> usywanie_adresata (vector <Kontakt>adresaci)
{
    int nr_id;
    int pozycja =0;
    int czy_istnieje = 0;

    cout << "Podaj nr ID adresata ktorego chcesz skasowac: ";
    cin >>nr_id;

    for(int i = 0; i<adresaci.size(); i++)
    {
        if (adresaci[i].id== nr_id)
        {
            pozycja =i;
            czy_istnieje++;
        }
    }

    if (czy_istnieje == 0)
    {
        cerr <<"Nie ma takiego nr id w bazie kontaktow !";
        Sleep (1500);
        return adresaci;
    }

    cout <<"Jesli chcesz usunac adreasata o nr ID "<<nr_id<<" wcisnij klawisz 't' lub inny jesli jednak nie";

    char wybor;
    wybor = getch ();

    switch (wybor)
    {
    case 't':
    {
        adresaci.erase(adresaci.begin()+ pozycja);
    }
    break;
    }
    return adresaci;
}

vector <Kontakt > edycja_adresata(vector <Kontakt>adresaci)
{
    int nr_id=0;

    int pozycja=0;
    int czy_istnieje =0;
    fstream plik;
    string nazwisko, adres, email, nr_telefonu, imie;

    cout <<"Podaj nr ID adresata ktorego chcesz edytowac: ";
    cin >>nr_id;

    for(int i = 0; i<adresaci.size(); i++)
    {
        if (nr_id==adresaci[i].id)
        {
            plik.open( "ksiazka_adresowa.txt", ios::in);

            if (plik.good() == true)

            {
                pozycja = i;

                system ("cls");

                cout <<"Edytuj: "<<endl;
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
                    plik<<adresaci[pozycja].imie;
                }
                break;

                case '2':
                {
                    cout <<"Podaj poprawne nazwisko: ";
                    cin>> nazwisko;
                    nazwisko =zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwisko);
                    adresaci[pozycja].nazwisko=nazwisko;
                    plik<<adresaci[pozycja].nazwisko;
                }
                break;
                case '3':
                {
                    cout <<"Podaj poprawny nr telefonu: ";
                    cin>> nr_telefonu;
                    adresaci[pozycja].nr_telefonu=nr_telefonu;
                    plik<<adresaci[pozycja].nr_telefonu;
                }
                break;
                case '4':
                {
                    cout <<"Podaj poprawny email: ";
                    cin>> email;
                    adresaci[pozycja].email=email;
                    plik<<adresaci[pozycja].email;
                }
                break;

                case '5':
                {
                    cout <<"Podaj poprawny adres: ";
                    cin.ignore();
                    getline (cin,adres);
                    adres =zamienPierwszaLitereNaDuzaAPozostaleNaMale(adres);
                    adresaci[pozycja].adres=adres;
                    plik<<adresaci[pozycja].adres;
                }
                break;

                case '6':
                {
                    return adresaci;
                }
                break;
                }

                czy_istnieje++;
            }
            plik.close();
        }
    }

    if (czy_istnieje == 0)
    {
        cerr <<"Nie ma takiego nr id w bazie kontaktow !";
        Sleep (1500);
    }

    return adresaci;
}

void zakonczProgram()
{
    cout << endl << "Koniec programu." << endl;
    exit(0);
}

void zapisz (vector <Kontakt>adresaci)
{
    remove ("ksiazka_adresowa.txt") == 0;
    for(int i = 0; i<adresaci.size(); i++)
    {
        zapisz_do_pliku (adresaci[i]);
    }
}

int main()
{
    vector <Kontakt> adresaci;
    char wybor;

    adresaci = wczytaj_adresatow_z_pliku ();

    int max_id=0;

    while (true)
    {
        system ("cls");
        cout <<"KSIAZKA ADRESOWA" <<endl;
        cout <<"1. Dodaj adresata"<<endl;
        cout <<"2. Wyszukaj po imieniu"<<endl;
        cout <<"3. Wyszukaj po nazwisku"<<endl;
        cout <<"4. Wyswietl wszystkich adresatow"<<endl;
        cout <<"5. Usun adresata"<<endl;
        cout <<"6. Edytuj adresata"<<endl;
        cout <<"9. Zakoncz program"<<endl;
        cout <<"Twoj wybor: "<<endl;

        wybor=getch();

        switch (wybor)
        {
        case '1':
        {
            int liczba_kontaktow=adresaci.size();
            if (liczba_kontaktow >0)
            {
                max_id = adresaci[liczba_kontaktow-1].id;

                adresaci.push_back(utworz_kontakt(max_id));
            }
            else  adresaci.push_back(utworz_kontakt(0));
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

        case '5':
        {
            adresaci = usywanie_adresata (adresaci);
            zapisz (adresaci);
        }
        break;

        case '4':
        {
            wyswietl_adresatow (adresaci);
        }
        break;

        case '6':
        {
            adresaci = edycja_adresata(adresaci);
            zapisz (adresaci);
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
