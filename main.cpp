#include "F.h"

using namespace std;


int main()
{
    int n, kieknd; // n - mokiniu skaicius, nd - namų darbų pažymys
    vector<vaikas> A; // vektoriaus strukturos
    string pasirinkti;
    cout << "Jei norite, kad duomenys butu skaityti is filo, parasykite 'f', norint duomenis ivesti ranka, iveskite, bet kokia raide:";
    cin >> pasirinkti;
    cout << endl;
    if(pasirinkti=="f")
    {
        skaitymas_is_failo(A, &kieknd);
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
