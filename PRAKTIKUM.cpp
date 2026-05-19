#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ==========================================================
// 1. ABSTRACT BASE CLASS (Pondasi Utama Sistem Bank)
// ==========================================================
class RekeningBank {
protected:
    string namaNasabah;
    double saldo;

public:
    RekeningBank(string nama, double saldoAwal) : namaNasabah(nama), saldo(saldoAwal) {}

    // Pure Virtual Function - Membuat class ini menjadi Abstract Class
    virtual void potongAdmin() = 0; 

    // Helper function untuk menampilkan informasi rekening
    void tampilkanInfo() const {
        cout << "Nasabah: " << namaNasabah 
             << " | Saldo Akhir: Rp " << saldo << endl;
    }

    // Virtual destructor untuk mencegah memory leak saat menggunakan polymorphism
    virtual ~RekeningBank() {}
};

// ==========================================================
// 2. DERIVED CLASS - REKENING SYARIAH
// ==========================================================
class RekeningSyariah : public RekeningBank {
public:
    RekeningSyariah(string nama, double saldoAwal) : RekeningBank(nama, saldoAwal) {}

    // Implementasi potongAdmin: Bebas biaya admin (saldo utuh)
    void potongAdmin() override {
        cout << "[Syariah] " << namaNasabah << ": Bebas biaya admin bersih. ";
        // Tidak ada pengurangan saldo
    }
};
