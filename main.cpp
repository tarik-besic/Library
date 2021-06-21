#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

void prijava(); ///Prijava nakon kreiranja racuna.
void kreiraj_racun(); ///Kreiranje racuna
void knjige_na_raspolaganju();///Funckija za izbor knjiga.
void unosdatum(int &d,int&m,int&g);///Funckija za datum.
void pozoviAdmina();///Funckija za admina.
bool datum(int d, int m, int g);///Funckija za datum.
bool prestupna(int g);///Funckija za datum.
void admin_mogucnosti();///ispis mogucnosti admina
void ispis_racuna(); ///ispis svih racuna iz datoteke;
void ispis_knjiga();///isšis knjiga iz datoteke.
void ispis_zadanih_knjiga();///ispis izdanih knjiga iz datoteke.
void pozovi_menu(); ///pocetak
void brisi_racune();///funkcija koja brise sve racuna iz datoteke
void brisi_izdane_knjige();
void korisnik_mogucnosti(); ///fuckcija za korisnika i mogucnosti njegove
void pregled_knjiga_za_racun(); ///pregled knjiga za prijavljen racun

char * crt = "=============================================";    ///Ovo je samo da izgleda pristojno
char * tack = "*********************************************";  ///isto
const int maxgod = 2500; ///za datum funkciju
const int mingod = 2000;  ///Za datum funkciju bitno

struct ucenik      ///Struktura koju sam koristio da upisujem u datoteku prilikom upisa ili kreiranja racuna
{
    char ime[25];
    char prezime[25];
    char razred[15];
    char brtel[20];
};

struct ucenik1  ///Struktura ucenika koji je prijavljen trenutno;
{
    string ime;
    string prezime;
}u1;

struct admin  ///struktura admina
{
   string ime;
   string prezime;
   int password;
}a1;

int main()
{
    pozovi_menu(); ///glavni int main ovo je jedina funkcija prizvana

    return 0;
}

void korisnik_mogucnosti()
{   int odg;
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
        case 3: pozovi_menu(); return;
    }
    } while(odg!=3);
cout<<"GRESKA GRESKA GREKSA"<<odg<<endl;
    return;
}


void pozovi_menu()  ///pocetak
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
        case 1: pozoviAdmina(); return;
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
void pozoviAdmina()
{
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
            pozovi_menu();
            return;
        }}


       if(prisutan) admin_mogucnosti();

  }


void kreiraj_racun()

{   ucenik neki;
    ofstream dat;
    dat.open("racuni.txt",ios::app);

    cout<<"Unesite vase podatke:"<<endl;
    cout<<"Kako se zovete"<<endl;
    cin>>neki.ime;
    cout<<"Kako se prezivate"<<endl;
    cin>>neki.prezime;
    cout<<"Koji ste razred"<<endl;
    cin>>neki.razred;
    cout<<"Broj telefona"<<endl;
    cin>>neki.brtel;

    dat<<endl<<neki.ime<<endl;dat<<neki.prezime<<endl;dat<<neki.razred<<endl;dat<<neki.brtel;
    dat.close();

    cout<<"Sad se prijavite sa vasim racunom"<<endl;
    prijava();


}
void prijava()
{   bool uspjesno=false;



    string ime,prezime,razred;
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
    {   dat>>neki.ime>>neki.prezime>>neki.razred>>neki.brtel;
        if(ime==neki.ime&& prezime==neki.prezime && razred==neki.razred)
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
    u1.ime=ime;
    u1.prezime=prezime;
    ///knjige_na_raspolaganju();
    korisnik_mogucnosti();
    return;}

    if(odg=="da")
        {cout<<"Onda molimo vas da kreirate novi racun jer vam nema accounta"<<endl;
        kreiraj_racun(); return;
        }
       if(odg=="ne") prijava();
        ///ovdje sam pozivao knjige na rapslo i bio bug
}
void knjige_na_raspolaganju()
{
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
            unosdatum(d,m,g);
                if(!datum(d,m,g))cout<<"Unesite ispravan datum molim vas!!!!!!"<<endl;
} while(!datum(d,m,g));
            ofstream datoteka;
            datoteka.open("izdano.txt",ios::app);
            datoteka<<"Uceniku: "<<u1.ime<<" "<<u1.prezime<<" je izdana knjiga: "<<knjiga
                <<"  datuma:"<<d<<"."<<m<<"."<<g<<endl;
                dat.close();
            cout<<"Uspjesno ste podigli knjigu i upisani ste u fajl"<<endl;


        break; }
    }
    korisnik_mogucnosti();

}
bool prestupna(int g)
{

return (((g% 4 == 0) && (g% 100 != 0)) ||(g% 400 == 0));
}

bool datum(int d, int m, int g)
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
void unosdatum(int &d,int&m,int&g)
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
void admin_mogucnosti()
{   int odg;
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
pozovi_menu();


}
void ispis_knjiga()
{
    ifstream dat;
    dat.open("knjige.txt");
    string unos;
    while(dat){getline(dat,unos);
    cout<<unos<<endl;}
    dat.close();
}
void ispis_racuna()
{
    ucenik s;
    ifstream dat;
    dat.open("racuni.txt");
    string unos;
    while(dat.good()){
            dat>>s.ime>>s.prezime>>s.razred>>s.brtel;
            cout<<"Ime: "<<s.ime<<endl;
            cout<<"Prezime: "<<s.prezime<<endl;
            cout<<"Razred: "<<s.razred<<endl;
            cout<<"Broj telefona: "<<s.brtel<<endl;
            cout<<endl;

   }
    dat.close();
}

void ispis_zadanih_knjiga()
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
void brisi_racune()
{   string s;
    ofstream dat;
    dat.open("racuni.txt",ios::out|ios::trunc);
    cout<<"Upozorenje,Obrisani su vam svi racuni molimo vas kreirajte nove prije nego"<<endl;
    cout<<" prije nego sto pokrenete opciju prikazi racune"<<endl;
    dat.close();

}
void pregled_knjiga_za_racun()
{
    ifstream dat;
    dat.open("izdano.txt");
    string unos,ime,prezime,t;

    while(!dat.eof())
    {
        dat>>unos>>ime>>prezime;
        getline(dat,t);
        if(dat.good()) ///ubacio sam ovo jer mi je na kraju ispisivalo 2 puta zadnju liniju
        if(u1.ime==ime&&u1.prezime==prezime)
            cout<<unos<<ime<<" "<<prezime<<" "<<t<<endl;
    }
    dat.close();
}
void brisi_izdane_knjige()
{
    ofstream dat;
    dat.open("izdano.txt",ios::out|ios::trunc);
    if(!dat)cout<<"Nece"<<endl;
    cout<<"Obrisani su podatci o izdanim knjigama"<<endl;
    dat.close();

}
