#include <iostream>
#include<vector>
using namespace std;

class T{};

class MasinaSport
{
    int an_fabricatie;
    string culoare;
    int cai_putere;
    string tip_combustibil;

public:
    MasinaSport(){};
    MasinaSport(int, string, int, string);
    friend istream& operator>>(istream&, MasinaSport&);
    friend ostream& operator<<(ostream&, MasinaSport&);
    MasinaSport(const MasinaSport&);
    MasinaSport& operator=(MasinaSport&);
    virtual void citire(){
   cout<<"Furnizati anul fabricatiei: ";
   cin>>an_fabricatie;
   cout<<endl<<"Furnizati culoarea: ";
   cin>>culoare;
   cout<<endl<<"Furnizati numarul de cai putere: ";
   cin>>cai_putere;
   cout<<endl<<"Furnizati tipul de combustibil: ";
   cin>>tip_combustibil;
   cout<<endl;
};
    virtual void afisare(){
    cout<<"An fabricatie: "<<an_fabricatie<<endl<<"Culoare: "<<culoare<<endl<<"Cai putere: "
    <<cai_putere<<endl<<"Tip combustibil: "<<tip_combustibil<<endl;
}
;
    int get_an(){return an_fabricatie;}
    string get_culoare(){return culoare;}
    int get_cp(){return cai_putere;}
    string get_tip(){return tip_combustibil;}
    static MasinaSport* creare(int op);
    virtual ~MasinaSport();
};

MasinaSport::~MasinaSport(){};

class kilometraj:public MasinaSport
{
    MasinaSport* M;
    int km;
public:
    kilometraj(MasinaSport *m, int km):M(m)
    {
        this->km=km;
    }
    void afisare(){MasinaSport::afisare();
                   cout<<endl<<"Kilometraj: "<<km;}
    ~kilometraj();

};

kilometraj::~kilometraj(){};


MasinaSport& MasinaSport::operator=(MasinaSport& m)
{
    if(this!=&m)
    {
        an_fabricatie=m.an_fabricatie;
        culoare=m.culoare;
        cai_putere=m.cai_putere;
        tip_combustibil=m.tip_combustibil;

    }
    return *this;
}

MasinaSport::MasinaSport(int an=0, string c="", int cp=0, string tip="")
{
    an_fabricatie=an;
    culoare=c;
    cai_putere=cp;
    tip_combustibil=tip;
}

MasinaSport::MasinaSport(const MasinaSport& m)
{
    an_fabricatie=m.an_fabricatie;
    culoare=m.culoare;
    cai_putere=m.cai_putere;
    tip_combustibil=m.tip_combustibil;
}


istream& operator>>(istream& is, MasinaSport& m)
{
   cout<<"Furnizati anul fabricatiei: ";
   cin>>m.an_fabricatie;
   cout<<endl<<"Furnizati culoarea: ";
   cin>>m.culoare;
   cout<<endl<<"Furnizati numarul de cai putere: ";
   cin>>m.cai_putere;
   cout<<endl<<"Furnizati tipul de combustibil: ";
   cin>>m.tip_combustibil;
   cout<<endl;
   return is;

}


ostream& operator<<(ostream& o, MasinaSport& m)
{
    cout<<"An fabricatie: "<<m.an_fabricatie<<endl<<"Culoare: "<<m.culoare<<endl<<"Cai putere: "
    <<m.cai_putere<<endl<<"Tip combustibil: "<<m.tip_combustibil<<endl;
    return o;
}


class HotHatch: public MasinaSport
{
    string clasa;
public:
    HotHatch(int an=0, string c="",int cai=0, string tip="", string cls="");
    friend istream& operator>>(istream&, HotHatch&);
    friend ostream& operator<<(ostream&, HotHatch&);
    HotHatch(const HotHatch&);
    HotHatch& operator=(HotHatch&);
    void citire(){MasinaSport::citire();
                  cout<<"Furnizati clasa: ";
                  cin>>clasa;
                  cout<<endl;}
    void afisare(){MasinaSport::afisare();
                   cout<<"Clasa: "<<clasa<<endl;}
    ~HotHatch();
};

HotHatch::~HotHatch(){};

HotHatch::HotHatch(int an, string c, int cp, string tip, string cls):MasinaSport(an,c,cp,tip)
{
    clasa=cls;
}

istream& operator>>(istream& is, HotHatch& h)
{
    is>>dynamic_cast<MasinaSport&>(h);
    cout<<"Furnizati clasa: "<<endl;
    is>>h.clasa;
    return is;
}

ostream& operator<<(ostream& o, HotHatch& h)
{
    o<<dynamic_cast<MasinaSport&>(h);
    o<<"Clasa: "<<h.clasa<<endl;
    return o;
}

HotHatch::HotHatch(const HotHatch& h):MasinaSport(h)
{
    clasa=h.clasa;
}

HotHatch& HotHatch::operator=(HotHatch& h)
{
    if(this!=&h)
    {
        this->MasinaSport::operator=(h);
        clasa=h.clasa;
    }
    return *this;
}

class Cabrio: public MasinaSport
{
    string acoperis;
    string material;
public:
    Cabrio(int a=0, string c="", int cp=0, string t="", string ac="", string m="");
    Cabrio(const Cabrio&);
    friend istream& operator>>(istream&, Cabrio&);
    friend ostream& operator<<(ostream&, Cabrio&);
    Cabrio& operator=(Cabrio&);
    void citire(){MasinaSport::citire();
                  cout<<"Furnizati tipul de acoperis: ";
                  cin>>acoperis;
                  cout<<endl<<"Furnizati tipul de material: ";
                  cin>>material;
                  cout<<endl;}
    void afisare(){MasinaSport::afisare();
                  cout<<"Acoperis: "<<acoperis<<endl<<"Material: "<<material<<endl;}

    ~Cabrio();
};

Cabrio::~Cabrio(){};

Cabrio::Cabrio(int a, string c, int cp, string t, string ac, string m):MasinaSport(a,c,cp,t)
{
    acoperis=ac;
    material=m;
}

Cabrio& Cabrio::operator=(Cabrio& c)
{
    if(this!=&c)
    {
        this->MasinaSport::operator=(c);
        acoperis=c.acoperis;
        material=c.material;
    }
    return *this;
}

Cabrio::Cabrio(const Cabrio& c):MasinaSport(c)
{
    acoperis=c.acoperis;
    material=c.material;
}

istream& operator>>(istream& is, Cabrio& c)
{
    is>>dynamic_cast<MasinaSport&>(c);
    cout<<"Furnizati tipul de acoperis: ";
    is>>c.acoperis;
    cout<<endl<<"Furnizati tipul de material: ";
    is>>c.material;
    cout<<endl;
    return is;
}

ostream& operator<<(ostream& o, Cabrio& c)
{
    o<<dynamic_cast<MasinaSport&>(c);
    o<<"Acoperis: "<<c.acoperis<<endl<<"Material: "<<c.material<<endl;
    return o;
}

class Supersport: public MasinaSport
{
    string model;
    float pret;
public:
    Supersport(int a=0, string c="", int cp=0, string t="", string m="", float p=0);
    Supersport(const Supersport&);
    Supersport& operator=(Supersport&);
    friend istream& operator>>(istream&, Supersport&);
    friend ostream& operator<<(ostream&, Supersport&);
    void citire(){MasinaSport::citire();
                  cout<<"Furnizati modelul masinii: ";
                  cin>>model;
                  cout<<"Furnizati pretul masinii: ";
                  cin>>pret;
                  cout<<endl;}
    void afisare(){MasinaSport::afisare();
                   cout<<"Model: "<<model<<endl;
                   cout<<"Pret: "<<pret<<endl;}

    string get_model(){return model;}
    float get_pret(){return pret;}

    ~Supersport();
};

Supersport::~Supersport(){};

Supersport::Supersport(int a, string c, int cp, string t, string m, float p):MasinaSport(a,c,cp,t)
{
    model=m;
    pret=p;
}

Supersport::Supersport(const Supersport& s):MasinaSport(s)
{
    model=s.model;
    pret=s.pret;
}

Supersport& Supersport::operator=(Supersport& s)
{
    if(this!=&s)
    {
        this->MasinaSport::operator=(s);
        model=s.model;
        pret=s.pret;
    }
    return *this;
}

istream& operator>>(istream& is, Supersport& s)
{
    is>>dynamic_cast<MasinaSport&>(s);
    cout<<"Furnizati modelul masinii: ";
    is>>s.model;
    cout<<endl;
    return is;
}

ostream& operator<<(ostream& o, Supersport& s)
{
    o<<dynamic_cast<MasinaSport&>(s);
    o<<"Model: "<<s.model<<endl<<"Pret: "<<s.pret<<endl;
    return o;
}


template<class T>
class Expozitie
{
    static int nr;
    vector<T*> v;
public:
    Expozitie(vector<T*> v={});
    Expozitie(const Expozitie&);
    Expozitie& operator=(Expozitie&);
    void creare_expo();
    void afisare_expo();

};


template<class T>
Expozitie<T>::Expozitie(vector<T*> vec)
{
    v=vec;
}


template<class T>
int Expozitie<T>::nr=0;

template<class T>
void Expozitie<T>::creare_expo()
{
    cout<<"Furnizati numarul de masini din expozitie: "<<endl;
    int nrm;
    cin>>nrm;
    for(int i=1;i<=nrm;i++)
    {
      T* t=new T();
      t->citire();
      v.push_back(t);
      nr++;
    }

    cout<<endl;

}

template<class T>
void Expozitie<T>::afisare_expo()
{
    //vector<T*>::iterator p;
    for(auto p=v.begin();p!=v.end();p++)
        (**p).afisare();
}

template<>
class Expozitie<Supersport>
{
    static int nr;
    vector<pair<Supersport*,float>> expuse;
    static int nrv;
    vector<pair<Supersport*,float>> vandute;
public:
    Expozitie<Supersport>(vector<pair<Supersport*,float>> e={}, vector<pair<Supersport*,float>> v={});
    Expozitie(const Expozitie&);
    Expozitie<Supersport>& operator=(Expozitie<Supersport>&);
    void creare_expo();
    void afisare_expo();
    void afisare_vanzare();
    Expozitie<Supersport>& operator-=(Supersport&);
    void destruct();

};

void Expozitie<Supersport>::destruct()
{
    if(expuse.empty()!=0)
    {
        for(auto p:expuse)
            {delete p.first;}
    }

    if(vandute.empty()!=0)
    {
        for(auto p:vandute)
            {delete p.first;}
    }
}

Expozitie<Supersport>& Expozitie<Supersport>::operator-=(Supersport& s)
{
    nrv++;
    int i;
    for(i=0;i<nr;i++)
        {if((expuse[i].first->get_model()==s.get_model())&& (expuse[i].first->get_an()==s.get_an()) &&
            (expuse[i].first->get_cp()==s.get_cp()) && (expuse[i].first->get_an()==s.get_cp()))

        {
            vandute.push_back(make_pair(expuse[i].first,expuse[i].first->get_pret()));
            expuse.erase(expuse.begin()+i);
            break;
        }
           }
    nr--;
    return *this;
}


Expozitie<Supersport>& Expozitie<Supersport>::operator=(Expozitie<Supersport> & e)
{
    if(this!=&e)
    {
        expuse=e.expuse;
        vandute=e.vandute;
    }
    return *this;
}

Expozitie<Supersport>::Expozitie(vector<pair<Supersport*,float>> exp, vector<pair<Supersport*,float>> van)
{
    expuse=exp;
    vandute=van;
}

int Expozitie<Supersport>::nr=0;
int Expozitie<Supersport>::nrv=0;

void Expozitie<Supersport>::creare_expo()
{
    cout<<"Furnizati numarul de masini din expozitie: "<<endl;
    int nrm;
    cin>>nrm;
    for(int i=1;i<=nrm;i++)
    {
      Supersport* s=new Supersport();
      s->citire();
      expuse.push_back(make_pair(s,-1));
      nr++;
    }

    cout<<endl;

}


void Expozitie<Supersport>::afisare_expo()
{
    for(auto p: expuse)
    {
        cout<<*p.first<<endl;
    }
}

void Expozitie<Supersport>::afisare_vanzare()
{
    for(auto p: vandute)
    {
        cout<<*p.first<<endl<<p.second<<endl;
    }
}


MasinaSport* MasinaSport::creare(int op)
{
    if(op==1) return new HotHatch;
    if(op==2) return new Cabrio;
    else return new Supersport;
}

class Meniu
{
public:
    static Meniu* getInstanta(){
        if(instanta == nullptr)
        {
            instanta = new Meniu();
        }
        return instanta;
    }
    static void deleteInstanta(){
        if(instanta != nullptr)
            delete instanta;
        instanta = nullptr;
    }
    ~Meniu(){};
    void adaugaInExpozitie();
    void afiseazaExpozitia();
    void vindeMasina();
    void afisVandute();
    void done();
private:
    static Meniu* instanta;
    Expozitie<HotHatch> h;
    Expozitie<Cabrio> c;
    Expozitie<Supersport> s;

};

void Meniu::done()
{
    s.destruct();
}

Meniu* Meniu::instanta=nullptr;
void Meniu::adaugaInExpozitie()
{
    cout<<"Alegeti tipul de masina de adaugat"<<endl<<"1-Hot-Hatch 2-Cabrio 3-Supersport"<<endl;
    int op;
    cin>>op;
    if(op==1)
    {
        h.creare_expo();

    }

    if(op==2)
    {
        c.creare_expo();
    }

    if(op==3)
    {
        s.creare_expo();
    }

}

void Meniu::afiseazaExpozitia()
{
    h.afisare_expo();
    c.afisare_expo();
    s.afisare_expo();
}

void Meniu::vindeMasina()
{
    cout<<"Furnizati detaliile masinii dorite"<<endl;
    Supersport s1;
    cin>>s1;
    s.operator-=(s1);
}

void Meniu::afisVandute()
{
    s.afisare_vanzare();
}


int main()
{
    /*MasinaSport M;
    M.citire();
    M.afisare();
    HotHatch h;
    cin>>h;
    cout<<h;
    Cabrio c;
    cin>>c;
    cout<<c;
    Cabrio c1=c;
    cout<<c1;
    Cabrio c2(c1);
    cout<<c2;
    Supersport s;
    cin>>s;
    cout<<s;
    Supersport s1=s;
    cout<<s1;
    Supersport s2(s1);
    cout<<s2;
    Expozitie<HotHatch> E1;
    E1.creare_expo();
    E1.afisare_expo();
    Expozitie<Cabrio> E;
    E.creare_expo();
    E.afisare_expo();
    Expozitie<Supersport> e;
    e.creare_expo();
    Supersport s1;
    cin>>s1;
    e.operator-=(s1);
    e.afisare_vanzare();
    e.afisare_expo();*/

    int optiune;
    Meniu* m=m->getInstanta();
    optiune=0;
    while(optiune!=5)
    {   cout<<"Alegeti optiunea dorita!"<<endl;
        cout<<"1-Adaugare masina la expozitie"<<endl;
        cout<<"2-Afisare expozitie"<<endl;
        cout<<"3-Cumpara masina"<<endl;
        cout<<"4-Afisare masini vandute"<<endl;
        cout<<"5-Iesire program"<<endl;
        cin>>optiune;
        if(optiune==1)
        {
             m->adaugaInExpozitie();
        }
        if(optiune==2)
        {
             m->afiseazaExpozitia();}

        if(optiune==3)
        {
             m->vindeMasina();
        }

        if(optiune==4)
        {
             m->afisVandute();
        }
    }
    m->deleteInstanta();
    m->done();
    return 0;

}
