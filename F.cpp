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

void failo_generavimas(vector<vaikas>& SK, int tempvaik)
{
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
    w1.close();
}


void skaitymas_is_failo_list (list<vaikas>& sk, int* kieknd, int tempvaik)
{
    auto start = std::chrono::high_resolution_clock::now();
    string buff, eilute;
    int temp;
    int vaikusk = 0;
    string filas = "Studentai" + to_string(tempvaik)+".txt";
    ifstream r;
    try{
        r.open(filas);
        if(!r)
            throw std::runtime_error("Nepavyko rasti failo");

        getline(r >> ws, buff);
        *kieknd = Zodziai_eiluteje(buff) - 3;

        while(true)
        {
            if(r.eof())
            {
                sk.pop_back();
                break;
            }
            vaikas studentas;
            r >> studentas.vard >> studentas.pav;

            for(int i=0; i<*kieknd; i++)
            {
                r >> temp;
                studentas.ndrez.push_back(temp);
            }
            r >> studentas.egz;

            sk.push_back(studentas);
            vaikusk +=1;
        }
    }
    catch(int e){}
     auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
	std::cout << "Duomenu nuskaitymas su listu uztruko: " << diff.count() << " s\n";
}



void isvedimas_i_faila_list (list<vaikas> SK, int kieknd, int tempvaik)
{
    auto start1 = std::chrono::high_resolution_clock::now();
    ifstream r;
    ofstream w1;
    string filas = "Studentai" + to_string(tempvaik)+".txt";
    ofstream w2(filas);
    w1.open("vargsiukaiL.txt");
    w1 << left << setw(17) << "Vardas" << left << setw(17) << "Pavarde"
        << left << setw(22) << "Galutinis(vid.)/" << left << setw(22)
        << "Galutinis(med.)\n";


    for(int k=0; k<70; k++)
    {
        w1 << "_" ;
    }
    w1 << endl;


    double suma;
    vector<int> temp1;
    for(std::list<vaikas>::iterator it = SK.begin(); it != SK.end(); ++it){
        temp1 = it->ndrez;

        suma = accumulate(temp1.begin(), temp1.end(), 0);
        sort(temp1.begin(), temp1.end());

        if(galutinis(vidurkis(suma, temp1.size()),it->egz)<5)
           {
                w1 << left << setw(17) << it->vard << left << setw(17) << it->pav
                    << left << setw(22) << fixed << setprecision(2) << galutinis(vidurkis(suma, it->ndrez.size()), it->egz)
                    << left << setw(22) << fixed << setprecision(2) << galutinis(median(*it, it->ndrez.size()), it->egz) << endl;

                SK.erase(it);

           }
    }
    for(std::list<vaikas>::iterator it = SK.begin(); it != SK.end(); ++it){
        temp1 = it->ndrez;
        w2 << left << setw(17) << it->vard << left << setw(17) << it->pav
            << left << setw(22) << fixed << setprecision(2) << galutinis(vidurkis(suma, it->ndrez.size()), it->egz)
            << left << setw(22) << fixed << setprecision(2) << galutinis(median(*it, it->ndrez.size()), it->egz) << endl;
    }
    w1.close();
    w2.close();
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff1 = end1 - start1;
    std::cout << "Duomenu isvedimas i du failus su listu uztruko: " << diff1.count() << " s\n";

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
            throw std::runtime_error("Nepavyko rasti failo");

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
	std::cout << "Duomenu nuskaitymas su vektorium uztruko: " << diff.count() << " s\n";
}

/*
void remove_if_skirstymas(vector<vaikas>& v, vector<vaikas>& SK) {
    auto start = std::chrono::high_resolution_clock::now();
    double suma;
    for(int i=0; i<SK.size(); i++)
    {
        vector<vaikas>::iterator it;

        v.erase(remove_if(v.begin(), v.end(), [&SK](vaikas naujas) {


            suma = accumulate(naujas[i].ndrez.begin(), naujas[i].ndrez.end(), 0);
            sort(naujas[i].ndrez.begin(), naujas[i].ndrez.end());

            if (galutinis(vidurkis(suma, naujas[i].ndrez.size()), naujas[i].egz)) < 5) {
                SK.push_back(naujas);
                return true;
            }
            else { return false; }
            }), v.end());
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration < double>diff = end - start;
    cout << "(VEKTORIUS REMOVE_IF) Skirstymas i kietus ir minkstus uztruko: " << diff.count() << "s\n";

}
*/


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



           /*
           else
            {
                w2 << left << setw(17) << SK[i].vard << left << setw(17) << SK[i].pav
                    <<left << setw(22) << fixed << setprecision(2) << galutinis(vidurkis(suma, SK[i].ndrez.size()), SK[i].egz)
                    << left << setw(22) << fixed << setprecision(2) << galutinis(median(SK[i], SK[i].ndrez.size()), SK[i].egz) << endl;
            }
            */
    }

    w1.close();
    w2.close();
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff1 = end1 - start1;
    std::cout << "Duomenu isvedimas i du failus su vektorium uztruko: " << diff1.count() << " s\n";
}

