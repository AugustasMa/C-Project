#include "F.h"
#include <string>
using namespace std;

unsigned int Zodziai_eiluteje(std::string const& str)
{
    std::stringstream stream(str);
    return std::distance(std::istream_iterator<std::string>(stream), std::istream_iterator<std::string>());
}


int random_pazymys()
{
	return rand() % 10 + 1;
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
/*
double galutinis_su_vec(vector<int> balai) {
	vaikas eilute;
	eilute.gp = 0.4 * accumulate(balai.begin(), balai.end(), 0) / balai.size() + 0.6 * random_pazymys();
	return eilute.gp;
}
*/

void isvedimas(vector<vaikas> SK, int n){
    cout << left << setw(15) << "Vardas" << left << setw(15) << "pavarde" << left << setw(15) <<"Galutinis (Vid.)" << " / " << setw(15) << "Galutinis (Med.)" << endl;
    for(int k=0; k<60; k++){
    cout << "_";
    }
    for(int i=0; i<n; i++){

        double suma; // vektoriaus elementu suma
        suma = accumulate(SK[i].ndrez.begin(), SK[i].ndrez.end(), 0);
        sort(SK[i].ndrez.begin(), SK[i].ndrez.end());
        cout << left << setw(15) << SK[i].vard << left << setw(15) << SK[i].pav << left << setw(15) << fixed << setprecision(2) << galutinis(vidurkis(suma, SK[i].ndrez.size()), SK[i].egz)<< left << setw(15) << galutinis(median(SK[i], SK[i].ndrez.size()), SK[i].egz) << endl;
    }
}

void failo_generavimas(vector<vaikas>& SK, int tempvaik)
{
    auto start = std::chrono::high_resolution_clock::now();

    int randsk;
    randsk = rand()% 3 + 3;
    string filas = "Studentai" + to_string(tempvaik)+".txt";
    ofstream w1(filas);
    w1 << setw(16) << left << "Vardas"
		<< setw(16) << left << "Pavarde";
    for(int n=0; n<randsk; n++)
    {
        w1 << setw(5) << "ND" + to_string(n+1);
    }
    w1 << "Egz." << endl;
    for (int j=0; j<tempvaik; j++)
    {
        w1 << setw(16) << "Vardas" + to_string(j+1)
			<< setw(16) << "Pavarde" + to_string(j+1);
        for(int k=0; k<randsk; k++)
        {
            w1 << setw(5) << random_pazymys();
        }
        w1 << setw(5) << random_pazymys() << endl;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
	std::cout << "Failo su " + std::to_string(tempvaik) + " studentu/-ais kurimas uztruko: " << diff.count() << " s\n";
}

void skaitymas_is_failo (vector<vaikas>& SK, int* kieknd, int tempvaik)
{
    auto start = std::chrono::high_resolution_clock::now();

    int temp;
    int vaikusk = 0;
    string buff;
    ifstream r;
    string filas = "Studentai" + to_string(tempvaik)+".txt";
    try{
        r.open(filas);
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
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
	std::cout << "Duomenu nuskaitymas uztruko: " << diff.count() << " s\n";
}

void isvedimas_i_faila(vector<vaikas> SK, int kieknd)
{
    auto start1 = std::chrono::high_resolution_clock::now();
    ofstream w1, w2;
    w1.open("vargsiukai.txt");
    w2.open("kietiakai.txt");
    w1 << left << setw(17) << "Vardas" << left << setw(17) << "Pavarde"
        << left << setw(22) << "Galutinis(vid.)/" << left << setw(22)
        << "Galutinis(med.)\n";

    w2 << left << setw(17) << "Vardas" << left << setw(17) << "Pavarde"
        << left << setw(22) << "Galutinis(vid.)/" << left << setw(22)
        << "Galutinis(med.)\n";

    for(int k=0; k<70; k++)
    {
        w1 << "_" ;
        w2 << "_" ;
    }
    w1 << endl;
    w2 << endl;

    auto start = std::chrono::high_resolution_clock::now();

    for(int i=0; i<SK.size(); i++)
    {
        double suma; // vektoriaus elementu suma
        suma = accumulate(SK[i].ndrez.begin(), SK[i].ndrez.end(), 0);
        sort(SK[i].ndrez.begin(), SK[i].ndrez.end());

        if(galutinis(vidurkis(suma, SK[i].ndrez.size()),SK[i].egz)<5)
           {
                w1 << left << setw(17) << SK[i].vard << left << setw(17) << SK[i].pav
                    <<left << setw(22) << fixed << setprecision(2) << galutinis(vidurkis(suma, SK[i].ndrez.size()), SK[i].egz)
                    << left << setw(22) << fixed << setprecision(2) << galutinis(median(SK[i], SK[i].ndrez.size()), SK[i].egz) << endl;
           }
           else
            {
                w2 << left << setw(17) << SK[i].vard << left << setw(17) << SK[i].pav
                    <<left << setw(22) << fixed << setprecision(2) << galutinis(vidurkis(suma, SK[i].ndrez.size()), SK[i].egz)
                    << left << setw(22) << fixed << setprecision(2) << galutinis(median(SK[i], SK[i].ndrez.size()), SK[i].egz) << endl;
            }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Duomenu rusiavimas i dvi grupes uztruko: " << diff.count() << " s\n";

    w1.close();
    w2.close();
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff1 = end1 - start1;
    std::cout << "Isvedimas i du failus uztruko: " << diff1.count() << " s\n";
}
