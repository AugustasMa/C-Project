#include "F.h"

using namespace std;


int main()
{
    int n, kieknd, tempvaik; // n - mokiniu skaicius, nd - namų darbų pažymys
    vector<vaikas> A; // vektoriaus strukturos
    string pasirinkti;
    cout << "Jei norite, kad duomenys butu skaityti is filo, parasykite 'f', norint sugeneruoti fila: 'g', norint ranka irasyti duomenis: bet kokia kita raide: ";
    cin >> pasirinkti;
    cout << endl;
    if(pasirinkti=="f")
    {
        skaitymas_is_failo(A, &kieknd, tempvaik);
        isvedimas_i_faila(A, kieknd);
    }
    else if(pasirinkti=="g")
    {
        cout << "Iveskite vaiku skaiciu: ";
        cin >> tempvaik;
        failo_generavimas(A, tempvaik);
        skaitymas_is_failo(A, &kieknd, tempvaik);
        isvedimas_i_faila(A, kieknd);
    }
    else
    {
        cout << "Iveskite vaiku kieki: ";
        cin >> n;
        ivedimas(A, n);
        isvedimas(A, n);
    }
    return 0;
}
