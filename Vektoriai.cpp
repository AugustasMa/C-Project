#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <cstdio>
#include <vector>
#include <cstdlib>
using namespace std;

struct vaikas{
    string vard;
    string pav;
    int egz; // egzamino rez.
    vector<int> ndrez;// namų darbų rez.
};
void skaitymas_is_failo (vector<vaikas>& SK,)
{
    int temp;
    int vaikusk = 0;
    ifstream r;
    r.open("kursiokai.txt");
    while(true)
    {
        r >> SK.at(vaikusk).vard;
        r >> SK.at(vaikusk).pav;
        for(i=0; i<)
    }
}


void ivedimas(vector<vaikas>& SK, int n)
{
    int nd; // konkretaus namu darbo rezultatas
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
            cin >> nd;
            if(nd == -1){
                break;
                }
            SK[i].ndrez.push_back(nd);
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
int main()
{
    int n; // n - mokiniu skaicius, nd - namų darbų pažymys
    vector<vaikas> A; // vektoriaus strukturos
    cout << "Iveskite vaiku kieki: ";
    cin >> n;
    ivedimas(A, n);
    isvedimas(A, n);
    return 0;
}
