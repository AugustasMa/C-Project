#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <iterator>
using namespace std;

struct vaikas{
    string vard;
    string pav;
    int egz; // egzamino rez.
    vector<int> ndrez;// namų darbų rez.
};

unsigned int Zodziai_eiluteje(std::string const& str)
{
    std::stringstream stream(str);
    return std::distance(std::istream_iterator<std::string>(stream), std::istream_iterator<std::string>());
}

void skaitymas_is_failo (vector<vaikas>& SK, int* kieknd)
{

    int temp;
    int vaikusk = 0;
    string buff;
    ifstream r;
    try{
        r.open("kursiokai.txt");
        if(!r)
            throw std::runtime_error("Nepavyko rasti filo");

            getline(r >> std::ws, buff);
            *kieknd = Zodziai_eiluteje(buff) - 3;
            while(true)
            {
                SK.resize(SK.size()+1);
                r >> SK.at(vaikusk).vard;
                if(r.eof())
                {
                    SK.pop_back();
                    break;
                }
                r >> SK.at(vaikusk).pav;
                for(int i=0; i<*kieknd; i++)
                {
                    r >> temp;
                    SK.at(vaikusk).ndrez.push_back(temp);
                }
                r >> SK.at(vaikusk).egz;
                vaikusk += 1;
            }
            r.close();
    }
    catch(int e){}
}

void ivedimas(vector<vaikas>& SK, int n)
{
    int temp; // konkretaus namu darbo rezultatas
    for(int i=0; i<n; i++){
        SK.resize(SK.size()+1);
        cout << "Iveskite vaiko varda: ";
        cin >> SK[i].vard;
        cout << "Iveskite vaiko pavarde: ";
        cin >> SK[i].pav;
        cout << "Iveskite vaiko egzamino rezultata: ";
        cin >> SK[i].egz;
        string pasirinkti;
        cout << "Pasirinkite ar nau darbu rezultatus ivedinesite ranka, ar juos sugeneruos kompiuteris? Jeigu ivedinesite ranka rasykite: t, jei tai atliks kompiuteris, rasykite: n" << endl;
        cin >> pasirinkti;
        if(pasirinkti == "t"){
            while(true) // ivesti arba randominiai skaiciai sukeliami i vektoriaus pabaiga
            {
            cout << "Iveskite namu darbo pazymi, jeigu daugiau pazymiu nera, iveskite -1: " << endl;
            cin >> temp;
            if(temp == -1){
                break;
                }
            SK[i].ndrez.push_back(temp);
            }
            if(SK[i].ndrez.size()<1)
            {
                cout << "Mokinys neturi nei vieno namu darbu pazymio" << endl;
            }
        }
        else
        {

            for(int z=0; z<(rand()%10+1); z++){
            SK[i].ndrez.push_back(rand()%10+1);
            }
            }
        }
}
double vidurkis(double visindrez, int m) // vidurkio funkcija
{
    double vid;
    vid = visindrez/m;
    if(m==0)
        vid = 0;
    return vid;
}
double median(vaikas SK, int n){ // medianos funkcija
    double mediana;
    if(SK.ndrez.size()==0){
        mediana=0;
    }
    else{
        if(SK.ndrez.size()%2==0)
        {
            int k = SK.ndrez.size()/2;
            mediana=(SK.ndrez[k]+SK.ndrez[k-1])/2.0;
        }
        else
            mediana = SK.ndrez[SK.ndrez.size()/2];
    }
    return mediana;
}
double galutinis(double a, double b){
    double gpaz;
    gpaz = (0.4*a)+(0.6*b);
    return gpaz;
}
void isvedimas(vector<vaikas> SK, int n){
    cout << left << setw(15) << "Vardas" << left << setw(15) << "pavarde" << left << setw(15) <<"Galutinis (Vid.)" << " / " << setw(15) << "Galutinis (Med.)" << endl;
    for(int k=0; k<60; k++){
    cout << "_";
    }
    cout << endl;
    for(int i=0; i<n; i++){

        double suma; // vektoriaus elementu suma
        suma = accumulate(SK[i].ndrez.begin(), SK[i].ndrez.end(), 0);
        sort(SK[i].ndrez.begin(), SK[i].ndrez.end());
        cout << left << setw(15) << SK[i].vard << left << setw(15) << SK[i].pav << left << setw(15) << fixed << setprecision(2) << galutinis(vidurkis(suma, SK[i].ndrez.size()), SK[i].egz)<< left << setw(15) << galutinis(median(SK[i], SK[i].ndrez.size()), SK[i].egz) << endl;
    }
}
void isvedimas_i_faila(vector<vaikas> SK, int kieknd)
{
    ofstream w;
    w.open("rezultatai.txt");
    w << left << setw(17) << "Vardas" << left << setw(17) << "Pavarde"
        << left << setw(22) << "Galutinis(vid.)/" << left << setw(22)
        << "Galutinis(med.)\n" << endl;
    for(int k=0; k<70; k++)
    {
        w << "_" ;
    }
    w << endl;
    for(int i=0; i<SK.size(); i++)
    {
        double suma; // vektoriaus elementu suma
        suma = accumulate(SK[i].ndrez.begin(), SK[i].ndrez.end(), 0);
        sort(SK[i].ndrez.begin(), SK[i].ndrez.end());
        w << left << setw(17) << SK[i].vard << left << setw(17) << SK[i].pav
            <<left << setw(22) << fixed << setprecision(2) << galutinis(vidurkis(suma, SK[i].ndrez.size()), SK[i].egz)
            << left << setw(22) << fixed << setprecision(2) << galutinis(median(SK[i], SK[i].ndrez.size()), SK[i].egz) << endl;
    }
    w.close();
}
int main()
{
    int temp;
    int n, kieknd; // n - mokiniu skaicius, nd - namų darbų pažymys
    vector<vaikas> A; // vektoriaus strukturos
    //cout << "Iveskite vaiku kieki: ";
    //cin >> n;
    //ivedimas(A, n);
    //isvedimas(A, n);
    skaitymas_is_failo(A, &kieknd);
    isvedimas_i_faila(A, kieknd);
    return 0;
}
