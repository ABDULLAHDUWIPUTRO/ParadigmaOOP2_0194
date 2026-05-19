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

// ==========================================================
// 3. DERIVED CLASS - REKENING KONVENSIONAL
// ==========================================================
class RekeningKonvensional : public RekeningBank {
public:
    RekeningKonvensional(string nama, double saldoAwal) : RekeningBank(nama, saldoAwal) {}

    // Implementasi potongAdmin: Potongan flat Rp 15.000
    void potongAdmin() override {
        double biayaAdmin = 15000;
        saldo -= biayaAdmin;
        cout << "[Konvensional] " << namaNasabah << ": Dipotong biaya admin Rp 15.000. ";
    }
};

// ==========================================================
// 4. DERIVED CLASS BARU - REKENING PREMIUM (Fitur Baru)
// ==========================================================
class RekeningPremium : public RekeningBank {
public:
    RekeningPremium(string nama, double saldoAwal) : RekeningBank(nama, saldoAwal) {}

    // Implementasi potongAdmin: Potongan dinamis berdasarkan aturan saldo
    void potongAdmin() override {
        if (saldo > 10000000) {
            cout << "[Premium] " << namaNasabah << ": Saldo > 10JT, Bebas biaya admin! ";
        } else {
            double biayaAdmin = 50000;
            saldo -= biayaAdmin;
            cout << "[Premium] " << namaNasabah << ": Saldo <= 10JT, Dipotong Rp 50.000. ";
        }
    }
};

// ==========================================================
// MAIN PROGRAM - SIMULASI SERVER AKHIR BULAN BANK
// ==========================================================
int main() {
    cout << "=== PROSES OTOMATISASI AKHIR BULAN BANK GIBRAN JAYA ===" << endl << endl;

    // Server menampung semua jenis rekening menggunakan Vector bertipe Pointer Base Class
    vector<RekeningBank*> daftarRekening;

    // Registrasi nasabah ke dalam sistem server
    daftarRekening.push_back(new RekeningSyariah("Abdullah", 5000000));
    daftarRekening.push_back(new RekeningKonvensional("Zidan", 2000000));
    
    // Anggota baru: Rekening Premium dengan kondisi saldo berbeda
    daftarRekening.push_back(new RekeningPremium("Naufal (Premium Kaya)", 15000000)); // > 10 Juta
    daftarRekening.push_back(new RekeningPremium("Aqib (Premium Pas-pasan)", 7500000)); // <= 10 Juta

    cout << "--- Kondisi Sebelum Pemrosesan ---" << endl;
    for (const auto& rekening : daftarRekening) {
        rekening->tampilkanInfo();
    }
    cout << "----------------------------------" << endl << endl;

    cout << "--- Eksekusi Potong Admin Otomatis ---" << endl;
    // Server memproses semua rekening secara fleksibel berkat Polymorphism
    for (auto& rekening : daftarRekening) {
        rekening->potongAdmin();
        rekening->tampilkanInfo(); // Menampilkan saldo terbaru setelah dipotong
    }
    cout << "--------------------------------------" << endl << endl;

    // Membersihkan memory dari heap (Good practice)
    for (auto& rekening : daftarRekening) {
        delete rekening;
    }
    daftarRekening.clear();

    return 0;
}