#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

class ucenik{
    string ime;
    string prezime;
    string razred;
    string brtel;

public:

    //setters
    void staviIme(string ime){this->ime=ime;}
    void staviPrezime(string prezime){this->prezime=prezime;}
    void staviRazred(string razred){this->razred=razred;}
    void staviBrtel(string brtel){this->brtel=brtel;}
    //getters
    string dajIme(){return ime;}
    string dajPrezime(){return prezime;}
    string dajRazred(){return razred;}
    string dajBrtel(){return brtel;}

    void knjige_na_raspolaganju();///Funckija za izbor knjiga.
    void pregled_knjiga_za_racun(); ///pregled knjiga za prijavljen racun
    void korisnik_mogucnosti();  ///fuckcija za korisnika i mogucnosti njegove

};

class date{
public:
    int d,m,g;

const int maxgod = 2500; ///za datum funkciju
const int mingod = 2000;  ///Za datum funkciju bitno

    bool prestupna(int g);///Funckija za datum.
    bool datum(int d, int m, int g);///Funckija za datum.
    void unosdatum(int &d,int&m,int&g);///Funckija za datum.

};
class admin
{
    string ime;
    string prezime;
    int password;

public:
    void admin_mogucnosti();///ispis mogucnosti admina
    void pozoviAdmina();  ///Funckija za admina.
    void ispis_racuna(); ///ispis svih racuna iz datoteke;
    void ispis_knjiga();///isšis knjiga iz datoteke.
    void ispis_zadanih_knjiga();///ispis izdanih knjiga iz datoteke.
    void brisi_izdane_knjige();
    void brisi_racune();///funkcija koja brise sve racuna iz datoteke

}a1,a2;

char * crt = "=============================================";    ///Ovo je samo da izgleda pristojno
char * tack = "*********************************************";  ///isto

class menu{
    public:
void prijava(); ///Prijava nakon kreiranja racuna.
void kreiraj_racun(); ///Kreiranje racuna
void pozovi_menu(); ///pocetak

};

class trenutniUcenik:public ucenik  ///klasa ucenika koji je prijavljen trenutno;
{
    string ime;
    string prezime;

public:


    void staviIme(string ime){this->ime=ime;}
    void staviPrezime(string prezime){this->prezime=prezime;}
    string dajIme(){return ime;}
    string dajPrezime(){return prezime;}

}u1;


int main()
{
    menu x;

    x.pozovi_menu();

 //   pozovi_menu(); ///glavni int main ovo je jedina funkcija prizvana

    return 0;
}

void ucenik::korisnik_mogucnosti()  {
       menu x;
       int odg;
    do{
    cout<<"Dobro dosli korisnik"<<endl;
    cout<<"Izaberite opciju:"<<endl;
    cout<<"1.Podigni knjigu"<<endl;
    cout<<"2.Pregled podignutih knjiga na vasem racunu"<<endl;
    cout<<"3.Odjava od korisnika"<<endl;

      do
    {  cout<<"Unesite vas izbor:"<<endl;
       cin>>odg;
       if(!cin){cin.clear();cin.ignore(1000,'\n');}

    }while(odg!=1&&odg!=2&&odg!=3);
    switch(odg)
    {
        case 1: knjige_na_raspolaganju(); break;
        case 2: pregled_knjiga_za_racun(); break;
        case 3: x.pozovi_menu(); return;
    }
    } while(odg!=3);
cout<<"GRESKA GRESKA GREKSA"<<odg<<endl;
    return;
}

void menu::pozovi_menu()  ///pocetak
{   string odg;
    int odg1;
    cout<<crt<<endl;
    cout<<"Dobro Dosli u biblioteku"<<endl<<crt<<endl;
    cout<<endl;
    cout<<"Izaberite opciju:"<<endl;
    cout<<"1.Admin"<<endl;
    cout<<"2.Korisnik"<<endl;
    cout<<"3.Ugasi program"<<endl;
    do{
            cin>>odg1;
            if(!cin){cin.clear();
            cin.ignore(1000,'\n');odg1=0;}
    }
    while(odg1!=1&&odg1!=2&&odg1!=3);


    switch(odg1)
    {
        case 1: a2.pozoviAdmina(); return;
        case 2:
            do{
            cout<<"Da li imate racun kreiran kod nas(da/ne)?"<<endl;
            cin>>odg;}
                    while(odg!="da"&&odg!="ne");

    if(odg=="da")
        {prijava();
        return;}
        else
            if(odg=="ne")
                {kreiraj_racun();
                return;}
        case 3:
            exit(0);
    }

    ///ovo dole radi kao ovo gore samo je bolje napisano ovo gore!
  /*  if(odg1==1)
    {
        pozoviAdmina(); return;
    }
    else if (odg1==2)
    {
        do{
            cout<<"Da li imate racun kreiran kod nas(da/ne)?"<<endl;
            cin>>odg;
    }
    while(odg!="da"&&odg!="ne");


    if(odg=="da") prijava();
        else
            kreiraj_racun();}
    else

        return;*/
}

void menu::kreiraj_racun()

{   ucenik neki;
    ofstream dat;
    dat.open("racuni.txt",ios::app);
    string ime,prezime,razred,brtel;
    cout<<"Unesite vase podatke:"<<endl;
    cout<<"Kako se zovete"<<endl;
    cin>>ime;
    neki.staviIme(ime);
    cout<<"Kako se prezivate"<<endl;
    cin>>prezime;
    neki.staviPrezime(prezime);
    cout<<"Koji ste razred"<<endl;
    cin>>razred;
    neki.staviRazred(razred);
    cout<<"Broj telefona"<<endl;
    cin>>brtel;
    neki.staviBrtel(brtel);

    dat<<endl<<neki.dajIme()<<endl;dat<<neki.dajPrezime()<<endl;dat<<neki.dajRazred()<<endl;dat<<neki.dajBrtel();
    dat.close();

    cout<<"Sad se prijavite sa vasim racunom"<<endl;
    prijava();


}
void menu::prijava()
{   bool uspjesno=false;
    ucenik x;


    string ime,prezime,razred;
    string ime2,prezime2,razred2,brtel2;
    cout<<tack<<endl;
    cout<<"Prijavi se"<<endl;
    cout<<tack<<endl;
    ifstream dat;
    dat.open("racuni.txt");

    ucenik neki;

    cout<<"Unesite vase ime"<<endl; cin>>ime;
    cout<<"unesite vase prezime"<<endl;cin>>prezime;
    cout<<"Koji ste razred unesite"<<endl;cin>>razred;
    cout<<tack<<endl;
    cout<<tack<<endl;
    cout<<"Prolazimo kroz bazu podataka da nadem vas acount"<<endl;
    cout<<tack<<endl;
    cout<<tack<<endl;
    while(dat)
    {   dat>>ime2>>prezime2>>razred2>>brtel2;
        if(ime==ime2&& prezime==prezime2 && razred==razred2)
        uspjesno=true;
        else
            uspjesno=false;

        if(uspjesno) break; ///izlazim iz while petlje cim nadem acc
    }

    dat.close();
    string odg;

    if(!uspjesno) do{
    cout<<"Da li ste unijeli tacne podatke(da/ne)?"<<endl;
    cin>>odg;
    }
    while(odg!="da"&&odg!="ne");

    else {cout<<"Uspjesno ste prijavljeni!!!!!!!"<<endl<<endl;
    u1.staviIme(ime);
    u1.staviPrezime(prezime);
    ///knjige_na_raspolaganju();
    u1.korisnik_mogucnosti();
    return;}

    if(odg=="da")
        {cout<<"Onda molimo vas da kreirate novi racun jer vam nema accounta"<<endl;
        kreiraj_racun(); return;
        }
       if(odg=="ne") prijava();
        ///ovdje sam pozivao knjige na rapslo i bio bug
}
void admin::pozoviAdmina()
{      menu x;
      bool prisutan=false;
      ifstream dat;
      int password;
      dat.open("admin.txt");
      string odg,ime,prezime;

    cout<<"Unesite admin ime:"<<endl;
    cin>>ime;
    cout<<"Unesite admin prezime"<<endl;
    cin>>prezime;
    cout<<"Unesite admin password"<<endl;
    cin>>password;
    if(!cin){cin.clear();
    cin.ignore(1000,'\n');}

  while(dat)
  {
      dat>>a1.ime;dat>>a1.prezime;dat>>a1.password;
  if(ime==a1.ime &&prezime==a1.prezime&& password==a1.password)
    prisutan=true;
  else prisutan =false;
  }
  if(!prisutan)
  {
      do{
      cout<<"Nisu vam tacni podatci o adminu..."<<endl;
      cout<<"Ako ste haker molimo vas da udarite sakom u racunar"<<endl;
      cout<<endl;
      cout<<"Da li ste unijeli tacne podatke o adminu(da/ne)?"<<endl;
      cin>>odg;
    }
        while(odg!="da"&&odg!="ne");
    if(odg=="ne")
    {
        pozoviAdmina();
    }else
        if(odg=="da")
        {
            cout<<"Onda ne znate ko je admin."<<endl;
            x.pozovi_menu();
            return;
        }}


       if(prisutan) admin_mogucnosti();

  }

void ucenik::knjige_na_raspolaganju()
{
    date x;
    int d,m,g;
    cout<<"Knjige koje mozete podici su:"<<endl;
    ifstream dat;
    dat.open("knjige.txt");
    string books;
    while(dat.good())
    {
    getline(dat,books);
    cout<<books<<endl;}

    dat.close();

    int br;
    cout<<endl;
    cout<<"Unesi broj knjige koju zelite podici"<<endl;

     do{
            cin>>br;
        if(!cin){
            cin.clear();
            cin.ignore(1000,'\n');
            br=0;
            cout<<"Unesi dobar broj..."<<endl;
    }}while(br<1||br>8);

    dat.close();

    int broj1,dan,mjesec,godina;
    char c;
    string knjiga;
    dat.open("knjige.txt");
    while(dat)
    {
        dat>>broj1>>c>>knjiga;
        if(broj1==br) {
                cout<<"Vasa knjiga je:"<<knjiga<<endl<<endl<<endl;
                cout<<"Unesite danasnji datum molim vas!!"<<endl;
        do
            {
            x.unosdatum(d,m,g);
                if(!x.datum(d,m,g))cout<<"Unesite ispravan datum molim vas!!!!!!"<<endl;
} while(!x.datum(d,m,g));
            ofstream datoteka;
            datoteka.open("izdano.txt",ios::app);
            datoteka<<"Uceniku: "<<u1.dajIme()<<" "<<u1.dajPrezime()<<" je izdana knjiga: "<<knjiga
                <<"  datuma:"<<d<<"."<<m<<"."<<g<<endl;
                dat.close();
            cout<<"Uspjesno ste podigli knjigu i upisani ste u fajl"<<endl;


        break; }
    }
    korisnik_mogucnosti();

}
bool date::prestupna(int g)
{

return (((g% 4 == 0) && (g% 100 != 0)) ||(g% 400 == 0));
}

bool date::datum(int d, int m, int g)
{

    if (g > maxgod ||g < mingod)
    return false;
    if (m < 1 || m > 12)
    return false;
    if (d < 1 || d > 31)
    return false;
    if (m == 2) ///ovo mi je za februar odma da rjesim
    {
        if (prestupna(g))
        return (d <= 29);  ///brza metoda vracanja ako je tacno vrati da ili ne tj ako je prestupna godina i ima ispod ili 29 vraca tacno
        else
        return (d <= 28); ///ako je datum manji ili 28 onda vraca tacno ako je preko onda vraca 0
    }

    if (m == 4 || m == 6 ||m == 9 || m == 11)
        return (d <= 30);

    return true;
}
void date::unosdatum(int &d,int&m,int&g)
{


            do{cout<<"Unesite dan:"<<endl;cin>>d;
            if(!cin){
            cin.clear();
            cin.ignore(1000,'\n');
            d=0;}
            } while(!d);
            do{cout<<"Unesite mjesec:"<<endl;cin>>m;
            if(!cin){
            cin.clear();
            cin.ignore(1000,'\n');
            m=0;}
            } while(!m);
            do{cout<<"Unesite godinu:"<<endl;cin>>g;
            if(!cin){
            cin.clear();
            cin.ignore(1000,'\n');
            g=0;}
            } while(!g);

}
void admin::admin_mogucnosti()
{   int odg;
    menu x;
    cout<<crt<<endl;
    cout<<"Zdravo vi ste admin ove nase divne biblioteke!!!"<<endl;
  do{  cout<<"Izaberite mogucnosti:"<<endl;
    cout<<crt<<endl;
        cout<<"1.Ispis racuna"<<endl;
        cout<<"2.Ispis knjiga na raspolaganju"<<endl;
        cout<<"3.Ispis izdanih knjiga"<<endl;
        cout<<"4.Brisanje svih kreiranih racuna"<<endl;
        cout<<"5.Brisanje svih izdanih knjiga"<<endl;
        cout<<"6.Odjavite se"<<endl;

    do
    {   cout<<"Unesite vas izbor!:"<<endl;
       cin>>odg;
       if(!cin){cin.clear();cin.ignore(1000,'\n');}

    }while(odg!=1&&odg!=2&&odg!=3&&odg!=4&&odg!=5&&odg!=6);

    cout<<endl<<endl;

    switch(odg)
    {
        case 1: ispis_racuna();         break;
        case 2: ispis_knjiga();         break;
        case 3: ispis_zadanih_knjiga(); break;
        case 4: brisi_racune();         break;
        case 5: brisi_izdane_knjige();    break;
        case 6:          break;
    }
}while(odg!=6);
x.pozovi_menu();


}
void admin::ispis_knjiga()
{
    ifstream dat;
    dat.open("knjige.txt");
    string unos;
    while(dat){getline(dat,unos);
    cout<<unos<<endl;}
    dat.close();
}
void admin::ispis_racuna()
{
    ucenik s; //ucenik za ispis racuna sa
    string ime,prezime,razred,brtel;
    ifstream dat;
    dat.open("racuni.txt");
    string unos;
    while(dat.good()){
            dat>>ime>>prezime>>razred>>brtel;
            cout<<"Ime: "<<ime<<endl;
            cout<<"Prezime: "<<prezime<<endl;
            cout<<"Razred: "<<razred<<endl;
            cout<<"Broj telefona: "<<brtel<<endl;
            cout<<endl;

   }
    dat.close();
}

void admin::ispis_zadanih_knjiga()
{
    ifstream dat;
    dat.open("izdano.txt");
    string unos;
    while(dat.good())
    {
        getline(dat,unos);
        cout<<unos<<endl;
    }
dat.close();
}
void admin::brisi_racune()
{   string s;
    ofstream dat;
    dat.open("racuni.txt",ios::out|ios::trunc);
    cout<<"Upozorenje,Obrisani su vam svi racuni molimo vas kreirajte nove prije nego"<<endl;
    cout<<" prije nego sto pokrenete opciju prikazi racune"<<endl;
    dat.close();

}
void ucenik::pregled_knjiga_za_racun()
{
    ifstream dat;
    trenutniUcenik tryStudent;
    dat.open("izdano.txt");
    string unos,ime,prezime,t;

    while(!dat.eof())
    {
        dat>>unos>>ime>>prezime;
        getline(dat,t);
        if(dat.good()) ///ubacio sam ovo jer mi je na kraju ispisivalo 2 puta zadnju liniju
        if(u1.dajIme()==ime&&u1.dajPrezime()==prezime)
            cout<<unos<<ime<<" "<<prezime<<" "<<t<<endl;
    }
    dat.close();
}
void admin::brisi_izdane_knjige()
{
    ofstream dat;
    dat.open("izdano.txt",ios::out|ios::trunc);
    if(!dat)cout<<"Ne moze da se otvori datoteka"<<endl;
    cout<<"Obrisani su podatci o izdanim knjigama"<<endl;
    dat.close();

}
