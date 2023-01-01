#include "F.h"

using namespace std;


int main()
{
    int n, kieknd, tempvaik; // n - mokiniu skaicius, nd - namų darbų pažymys
    vector<vaikas> A; // vektoriaus strukturos
    list<vaikas> B;

    cout << "Iveskite vaiku skaiciu: ";
    cin >> tempvaik;
    failo_generavimas(A, tempvaik);
    //skaitymas_is_failo(A, &kieknd, tempvaik);
    skaitymas_is_failo_list(B, &kieknd, tempvaik);
    //isvedimas_i_faila(A, kieknd);
    isvedimas_i_faila_list(B, kieknd, tempvaik);

    return 0;
}
