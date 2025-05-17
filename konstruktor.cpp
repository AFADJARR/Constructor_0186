#include <iostream>
#include <string>
using namespace std;

class mahasiswa {
private:
    int nim;
    string nama;

public:
    mahasiswa();                            // Konstruktor default
    mahasiswa(int);                         // Konstruktor dengan nim
    mahasiswa(string);                      // Konstruktor dengan nama
    mahasiswa(int iNim, string iNama);      // Konstruktor dengan nim dan nama
    void cetak();
};

