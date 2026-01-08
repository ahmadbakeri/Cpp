#include <iostream>
#include <iomanip>  // Buat ngerapiin tabel (setw)
#include <cstring>  // Buat ngukur panjang string (strlen)
#include <cctype>   // Buat fungsi tolower (biar huruf besar/kecil dianggap sama)

using namespace std;

// Struktur barang
struct Barang {
    char nama[30];
    int stok;
    float harga;
};

const int MAX_BARANG = 100;

// Fungsi"
// Fungsi buat ngecek persamaan kata
bool cekStringSama(char a[], char b[]) {
    // mencek total huruf a=b
    if (strlen(a) != strlen(b)) return false; 
    
    // Cek huruf satu per satu
    for (int i = 0; i < strlen(a); i++) {
        if (tolower(a[i]) != tolower(b[i])) return false;
    }
    return true;
}

// --- MODUL INPUT ---
void inputData(Barang daftar[], int &jumlah) {
    cout << "=== Input Data Barang ===" << endl;
    cout << "Mau input berapa barang? (Maks " << MAX_BARANG << "): ";
    cin >> jumlah;

    // Validasi buat input tidak lebih dari kapasitas array
    if (jumlah > MAX_BARANG) jumlah = MAX_BARANG;

    for (int i = 0; i < jumlah; i++) {
        cout << "\nData ke-" << (i + 1) << endl;
        
        // Wajib: Bersihin sisa 'Enter' di keyboard biar input nama gak ke-skip
        cin.ignore(); 
        
        cout << "Nama Barang : ";
        cin.getline(daftar[i].nama, 30);
        
        cout << "Stok        : ";
        cin >> daftar[i].stok;
        
        cout << "Harga       : ";
        cin >> daftar[i].harga;
    }
}

// --- MODUL OUTPUT (TABEL) ---
void tampilkanData(Barang daftar[], int jumlah) {
    cout << "\n" << string(60, '=') << endl;
    cout << left << setw(5) << "No" 
         << setw(25) << "Nama Barang" 
         << setw(10) << "Stok" 
         << setw(10) << "Harga" 
         << setw(10) << "Total Aset" << endl;
    cout << string(60, '=') << endl;

    for (int i = 0; i < jumlah; i++) {
        float total = daftar[i].stok * daftar[i].harga;
        
        cout << left << setw(5) << (i + 1)
             << setw(25) << daftar[i].nama
             << setw(10) << daftar[i].stok
             << setw(10) << daftar[i].harga
             << setw(10) << total << endl;
    }
    cout << string(60, '-') << endl;
}

// --- MODUL PENCARIAN (LINEAR SEARCH) ---
void cariBarang(Barang daftar[], int jumlah) {
    char keyword[30];
    bool ketemu = false;

    cout << "\n=== Cari Barang ===" << endl;
    cout << "Ketik nama barang yang dicari: ";
    cin.ignore(); // Bersihin buffer lagi karena sebelumnya abis input angka
    cin.getline(keyword, 30);

    cout << "\nHasil Pencarian:" << endl;
    
    // Loop nyari satu-satu dari atas ke bawah
    for (int i = 0; i < jumlah; i++) {
        // Pakai fungsi bantuan kita tadi buat ngebandingin
        if (cekStringSama(daftar[i].nama, keyword)) {
            cout << "[DITEMUKAN] Data ke-" << (i + 1) << endl;
            cout << "Nama  : " << daftar[i].nama << endl;
            cout << "Stok  : " << daftar[i].stok << endl;
            cout << "Harga : " << daftar[i].harga << endl;
            cout << "Total : " << (daftar[i].stok * daftar[i].harga) << endl;
            ketemu = true;
            break; // Ngeberhentiin Looping
        }
    }

    if (!ketemu) {
        cout << "Maaf, barang '" << keyword << "' gak ada di data." << endl;
    }
}

// --- PROGRAM UTAMA ---
int main() {
    Barang toko[MAX_BARANG];
    int jumlahBarang = 0;

    // Panggil fungsi-fungsi di atas secara berurutan
    inputData(toko, jumlahBarang);
    tampilkanData(toko, jumlahBarang);
    cariBarang(toko, jumlahBarang);

    return 0;
}
