#include <iostream>
#include <string>
using namespace std;

class Petugas; 
class Admin;   

class Buku {
private:
    string judul;
    string penulis;
    bool dipinjam;

public:
    Buku(string j, string p) : judul(j), penulis(p), dipinjam(false) {}

    void tampilkanStatus() {
        cout << "Judul: " << judul << ", Penulis: " << penulis
             << ", Status: " << (dipinjam ? "Dipinjam" : "Tersedia") << endl;
    }

    friend class Petugas; 
    friend void lihatDataBuku(const Buku* b); 
};

class Peminjam {
private:
    string nama;
    int id;
    int totalPinjaman;

public:
    Peminjam(string n, int i) : nama(n), id(i), totalPinjaman(0) {}

    friend class Petugas; 
    friend void lihatDataPeminjam(const Peminjam* p); 
};

class Petugas {
private:
    string nama;
    int idPetugas;
    string levelAkses;

public:
    Petugas(string n, int id, string lvl) : nama(n), idPetugas(id), levelAkses(lvl) {}

    void prosesPinjam(Buku* b, Peminjam* p) {
        if (!b->dipinjam) {
            b->dipinjam = true;
            p->totalPinjaman++;
            cout << "Buku berhasil dipinjam.\n";
        } else {
            cout << "Buku sedang dipinjam orang lain.\n";
        }
    }

    void prosesKembali(Buku* b, Peminjam* p) {
        if (b->dipinjam) {
            b->dipinjam = false;
            p->totalPinjaman--;
            cout << "Buku berhasil dikembalikan.\n";
        } else {
            cout << "Buku sudah tersedia.\n";
        }
    }

    friend class Admin;
};

class Admin {
public:
    void lihatStatistik(Buku* b, Peminjam* p) {
        lihatDataBuku(b);
        lihatDataPeminjam(p);
    }
};

// Friend functions untuk akses terbatas Admin
void lihatDataBuku(const Buku* b) {
    cout << "[Admin] Akses Buku: " << b->judul << " - Status: " << (b->dipinjam ? "Dipinjam" : "Tersedia") << endl;
}

void lihatDataPeminjam(const Peminjam* p) {
    cout << "[Admin] Akses Peminjam: Total Pinjaman = " << p->totalPinjaman << endl;
}

int main() {
    Buku b1("Dilan 1991", "Pidi Baiq");
    Peminjam p1("Farhan", 1001);
    Petugas petugas1("Ambon", 2001, "normal");
    Admin admin1;

    b1.tampilkanStatus();
    petugas1.prosesPinjam(&b1, &p1);
    b1.tampilkanStatus();

    admin1.lihatStatistik(&b1, &p1);
    petugas1.prosesKembali(&b1, &p1);
    b1.tampilkanStatus();

    return 0;
}