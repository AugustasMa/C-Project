#ifndef F_H_INCLUDED
#define F_H_INCLUDED
#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <iterator>
#include <string>
#include <chrono>

using namespace std;

struct vaikas{
    string vard;
    string pav;
    int egz; // egzamino rez.
    vector<int> ndrez;// namų darbų rez.
    double gp;
};
unsigned int Zodziai_eiluteje(std::string const& str);
int random_pazymys();
void ivedimas(vector<vaikas>& SK, int n);
double vidurkis(double visindrez, int m); // vidurkio funkcija
double median(vaikas SK, int n); // medianos funkcija
double galutinis(double a, double b);
void isvedimas(vector<vaikas> SK, int n);
void failo_generavimas(vector<vaikas>& SK, int tempvaik);
void skaitymas_is_failo (vector<vaikas>& SK, int* kieknd, int tempvaik);
void isvedimas_i_faila(vector<vaikas> SK, int kieknd);



#endif // F_H_INCLUDED
