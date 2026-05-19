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
