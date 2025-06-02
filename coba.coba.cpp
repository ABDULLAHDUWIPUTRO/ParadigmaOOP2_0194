#include <iostream>
using namespace std;

class mahasiswa {
    //Syarat untuk Encapsulasi
    // 1. Atriubute harus private atau protected
    protected:
        string nama;
        string nim;
    private:
        string umur;

    public:
    mahasiswa (string pNama, string pNim, string pUmur) : nama(pNama), nim(pNim), umur(pUmur) {
        // Constructor untuk inisialisasi nama, nim, dan umur
    }
    // menandakan bahwa ini abstrak class
    // sebagai syarat untuk polimorfi
    virtual void infoMhs() = 0;

    // abstraksi hanya dapat mengakses melalui method
    void setNama(string pNama) {
        nama = pNama;
    }
    string getNama() {
        return nama;
    }

    void setUmur(string pUmur) {
        umur = pUmur;
    }

    string getUmur() {
        return umur;
    }
};

class mhsBaru : public mahasiswa{
    public:
    mhsBaru(string pNama, string pNim, string pUmur) : mahasiswa(pNama, pNim, pUmur) {}
    
        virtual void infoMhs() override {               // overide method untuk mendukung polimorfi
            cout << "Nama Mhs: " << nama << endl;
            cout << "Nim Mhs: " << nim << endl;
            cout << "Umur Mhs: " << getUmur() << endl;
        };
};

class mhsLama : public mahasiswa {
    public:
    mhsLama(string pNama, string pNim, string pUmur) : mahasiswa(pNama, pNim, pUmur) {}
    
        virtual void infoMhs() override {               // overide method infoMhs untuk mendukung polimorfi
            cout << "Nama Mhs: " << nama << endl;
            cout << "Nim Mhs: " << nim << endl;
            cout << "Umur Mhs: " << getUmur() << endl;
        };
};

int main(){
    mahasiswa *mhs;
    mhsBaru mhsb("Joko", "2023", "45");
    mhsLama mhsL("Lia", "2023", "22");

    mhs = &mhsb;  // Memberi nilai objek dengan alamat objek dari class mhsBaru
    mhs->infoMhs(); // Memanggil fungsi infoMhs() dari class mhsBaru
    mhs = &mhsL;  // Memberi nilai objek dengan alamat objek dari class mhsLama
    mhs->infoMhs(); // Memanggil fungsi infoMhs() dari class mhsLama
}