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
void ivedimas(vaikas Masyvas[], int n)
{
    int nd; // konkretaus namu darbo rezultatas
    for(int i=0; i<n; i++){
        cout << "Iveskite vaiko varda: ";
        cin >> Masyvas[i].vard;
        cout << "Iveskite vaiko pavarde: ";
        cin >> Masyvas[i].pav;
        cout << "Iveskite vaiko egzamino rezultata: ";
        cin >> Masyvas[i].egz;
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
            Masyvas[i].ndrez.push_back(nd);
            }
            if(Masyvas[i].ndrez.size()<1)
            {
                cout << "Mokinys neturi nei vieno namu darbu pazymio" << endl;
            }
        }
        else
        {

            for(int z=0; z<(rand()%10+1); z++){
            Masyvas[i].ndrez.push_back(rand()%10+1);
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
double median(vaikas Masyvas, int n){ // medianos funkcija
    double mediana;
    if(Masyvas.ndrez.size()==0){
        mediana=0;
    }
    else{
        if(Masyvas.ndrez.size()%2==0)
        {
            int k = Masyvas.ndrez.size()/2;
            mediana=(Masyvas.ndrez[k]+Masyvas.ndrez[k-1])/2.0;
        }
        else
            mediana = Masyvas.ndrez[Masyvas.ndrez.size()/2];
    }
    return mediana;
}
double galutinis(double a, double b){
    double gpaz;
    gpaz = (0.4*a)+(0.6*b);
    return gpaz;
}
void isvedimas(vaikas Masyvas[], int n){
    cout << left << setw(15) << "Vardas" << left << setw(15) << "pavarde" << left << setw(15) <<"Galutinis (Vid.)" << " / " << setw(15) << "Galutinis (Med.)" << endl;
    for(int k=0; k<60; k++){
    cout << "_";
    }
    cout << endl;
    for(int i=0; i<n; i++){

        double suma; // vektoriaus elementu suma
        suma = accumulate(Masyvas[i].ndrez.begin(), Masyvas[i].ndrez.end(), 0);
        sort(Masyvas[i].ndrez.begin(), Masyvas[i].ndrez.end());
        cout << left << setw(15) << Masyvas[i].vard << left << setw(15) << Masyvas[i].pav << left << setw(15) << fixed << setprecision(2) << galutinis(vidurkis(suma, Masyvas[i].ndrez.size()), Masyvas[i].egz)<< left << setw(15) << galutinis(median(Masyvas[i], Masyvas[i].ndrez.size()), Masyvas[i].egz) << endl;
    }
}
int main()
{
    int n; // n - mokiniu skaicius, nd - namų darbų pažymys
    vaikas A[10];
    //vector<vaikas> A(10); // vektoriaus strukturos
    cout << "Iveskite vaiku kieki: ";
    cin >> n;
    ivedimas(A, n);
    isvedimas(A, n);
    return 0;
}
