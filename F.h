
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
#include <list>
#include <algorithm>    // std::remove

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
double vidurkis(double visindrez, int m); // vidurkio funkcija
double median(vaikas SK, int n); // medianos funkcija
double galutinis(double a, double b);
void failo_generavimas(vector<vaikas>& SK, int tempvaik);
void skaitymas_is_failo_list (list<vaikas>& sk, int* kieknd, int tempvaik);
void delete_line(const char *file_name, int n);
void isvedimas_i_faila_list (list<vaikas> SK, int kieknd, int tempvaik);
void skaitymas_is_failo (vector<vaikas>& SK, int* kieknd, int tempvaik);
void isvedimas_i_faila (vector<vaikas> SK, int kieknd);
