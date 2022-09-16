#include <iostream>
#include <bits/stdc++.h>

using namespace std;
struct vaikas{
string vard; // vardas
string pav; // pavarde
int egz; // egzamino rez.
int ndkiekis = 0; //namu darbu pazymiu kiekis
int *ndrez; // namu darbu rezultatu masyvas
};


void ivedimas(vaikas Masyvas[], int n) // skaitymo funkcija
{
    int nd; // konkretaus namu darbo rezultatas
    int *ndrez2; // laikinas masyvas talpos padidinimui
    for(int i=0; i<n; i++){
        cout << "Iveskite vaiko varda: ";
        cin >> Masyvas[i].vard;
        cout << "Iveskite vaiko pavarde: ";
        cin >> Masyvas[i].pav;
        cout << "Iveskite vaiko egzamino rezultata: ";
        cin >> Masyvas[i].egz;
        while(true) // ciklas, kurio metu duomenys yra saugomi vienam dinaminiam masyve ir perduodami kitam.
        {
        cout << "Iveskite namu darbo pazymi, jeigu daugiau pazymiu nera, iveskite -1: " << endl;
        cin >> nd;
        if(nd == -1){
            break;
            }
        Masyvas[i].ndkiekis += 1;
        ndrez2 = new int(Masyvas[i].ndkiekis);
        if(Masyvas[i].ndkiekis != 1){
            for(int j=0; j<Masyvas[i].ndkiekis-1; j++)
            {
                ndrez2[j+1] = Masyvas[i].ndrez[j];
            }
            delete[] Masyvas[i].ndrez;
        }
        ndrez2[0] = nd;
        Masyvas[i].ndrez = ndrez2;
        }
        if(Masyvas[i].ndkiekis==0) // bug'o tikrinimas
        {
            cout << "Mokinys neturi nei vieno namu darbu pazymio" << endl;
        }
    }
}
int sum(int labas[], int n){ // funkcija skaiciuojanti visu namu darbu suma
    int visindrez = 0;
    for(int i=0; i<n; i++){
        visindrez += labas[i];
    }
    return visindrez;
}
double vidurkis(double visindrez, int m)
{
    double vid;
    vid = visindrez/m;
    if(m==0)
        vid = 0;
    return vid;
}
double median(vaikas Masyvas, int n){ // funkcija medianos radimui
    double mediana;
    if(Masyvas.ndkiekis==0){
        mediana=0;
    }
    else{
        if(Masyvas.ndkiekis%2==0)
        {
            int k = Masyvas.ndkiekis/2;
            mediana=(Masyvas.ndrez[k]+Masyvas.ndrez[k-1])/2.0;
        }
        else
            mediana = Masyvas.ndrez[Masyvas.ndkiekis/2];
    }
    return mediana;
}

void rusiavimas(vaikas Masyvas){ // ciklo cikle pagalba atliekama rusiavimo funkcija, kurios metu mazesne,
                                //is dvieju lyginamu reiksmiu, yra perkeliama i kairesne pozicija.
    for(int i=0; i<Masyvas.ndkiekis-1; i++){
        for(int j=i;j<Masyvas.ndkiekis; j++){
            if(Masyvas.ndrez[i]>Masyvas.ndrez[j])
                swap(Masyvas.ndrez[i], Masyvas.ndrez[j]);
        }
    }
}
void isvedimas(vaikas Masyvas[], int n){
    cout << left << setw(15) << "Vardas" << left << setw(15) << "pavarde" << left << setw(15) <<"Galutinis (Vid.)" << " / " << setw(15) << "Galutinis (Med.)" << endl;
    for(int k=0; k<60; k++){
    cout << "_";
    }
    cout << endl;
    for(int i=0; i<n; i++){

        rusiavimas(Masyvas[i]);
        cout << left << setw(15) << Masyvas[i].vard << left << setw(15) << Masyvas[i].pav << left << setw(15) << fixed << setprecision(2) << vidurkis(sum(Masyvas[i].ndrez, Masyvas[i].ndkiekis), Masyvas[i].ndkiekis)<< left << setw(15) << median(Masyvas[i], Masyvas[i].ndkiekis) << endl;
    }
}
int main()
{
    int n; // n - mokiniu skaicius, nd - namų darbų pažymys
    vaikas A[10];
    cout << "Iveskite vaiku kieki: ";
    cin >> n;
    ivedimas(A, n);
    isvedimas(A, n);
    for(int i=0; i<n; i++){ //atlaisvinama atmintis
        delete[] A[i].ndrez;
    }
    return 0;
}
