#include <iostream>
using namespace std;

class mahasiswa{
    private:
        static int jmlMhs;
    public:
        string status;
        string nama;
        int nim;
        mahasiswa(string pnama, int pnim){
            status = "Mahasiswa Baru ";
            nama = pnama;
            nim = pnim;
            cout << "Mahasiswa Dibuat " << nama  << endl;
            cout << "Status = " << status << endl;
            ++jmlMhs;
        };
        mahasiswa(){
            cout << "Mahasiswa dengan nama " << nama << "Dihancurkan "  <<  endl;
            --jmlMhs;
        };
        static int gettotalmhs(){
            return jmlMhs;
        };
};

int mahasiswa ::jmlMhs = 0;


int main(){
    cout << "Jumlah Mahasiswa = " << mahasiswa::gettotalmhs() << endl;
    mahasiswa mhs1("Rudi", 28);
    mahasiswa mhs2("joko", 23); 
    mhs2.status = "Mahasiswa Uzur ";
    cout << mhs2.status << endl;
    mahasiswa mhs3("wobo", 69);
    cout << "Jumlah mahasiswa = " << mahasiswa::gettotalmhs() << endl;
    {
        mahasiswa mhs4("dewo", 98);
        cout << "Jumlah Mahasiswa dalam bracket= " << mahasiswa::gettotalmhs() << endl;
    }
        cout << "Jumlah mahasiswa = " << mahasiswa::gettotalmhs() << endl;
        return 0;
        
    
}