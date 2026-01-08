#include <iostream>
#include <iomanip> 
#include <string> 

using namespace std;

// Sesuai soal, kita butuh data untuk 30 hari
const int JUMLAH_HARI = 30; 

// Fungsi Input
void inputSuhu(float data[]) {
    cout << "=== Input Data Suhu (" << JUMLAH_HARI << " Hari) ===" << endl;
    cout << "Tips: Masukkan angka lalu tekan spasi atau enter." << endl;
    
    for (int i = 0; i < JUMLAH_HARI; i++) {
        cout << "Hari ke-" << (i + 1) << ": ";
        cin >> data[i];
    }
}

// Fungsi nyari rata rata
float hitungRataRata(float data[]) {
    float total = 0;
    for (int i = 0; i < JUMLAH_HARI; i++) {
        total += data[i];
    }
    return total / JUMLAH_HARI;
}

// Fungsi nyari nilai min sama max
// Kita pakai "pass by reference" (&) biar fungsi ini bisa langsung
// mengubah nilai variabel maxVal, minVal, dll di main()
void cariMaxMin(float data[], float &maxVal, int &hariMax, float &minVal, int &hariMin) {
    // Inisialisasi: Anggap hari pertama adalah yang ter- segalanya
    maxVal = data[0];
    minVal = data[0];
    hariMax = 1;
    hariMin = 1;

    // Mulai cek dari hari kedua (index 1) sampai akhir
    for (int i = 1; i < JUMLAH_HARI; i++) {
        // Cek Nilai Tertinggi
        if (data[i] > maxVal) {
            maxVal = data[i];
            hariMax = i + 1; // Ditambah 1 karena index array mulai dari 0
        }
        
        // Cek Nilai Terendah
        if (data[i] < minVal) {
            minVal = data[i];
            hariMin = i + 1;
        }
    }
}

// Fungsi Kategori
string tentukanKategori(float rata) {
    if (rata >= 30) {
        return "Panas";
    } else if (rata >= 25) {
        return "Normal";
    } else {
        return "Sejuk";
    }
}

// Fungsi Utama / Program Utama
int main() {
    float suhuHarian[JUMLAH_HARI];
    
    // Variabel buat nampung hasil analisa
    float rataRata, suhuMax, suhuMin;
    int hariMax, hariMin;

    // 1. Panggil Fungsi Input
    // Tips: Kalau capek ngetik 30 angka pas testing, 
    // ubah angka di 'const int JUMLAH_HARI' jadi 3 atau 5 dulu.
    inputSuhu(suhuHarian);

    // 2. Proses Hitung Rata-rata
    rataRata = hitungRataRata(suhuHarian);

    // 3. Proses Cari Max & Min
    cariMaxMin(suhuHarian, suhuMax, hariMax, suhuMin, hariMin);

    // 4. Tampilkan Output Ringkas (Sesuai Contoh Soal)
    cout << "\n" << string(40, '=') << endl;
    cout << "HASIL ANALISIS SUHU" << endl;
    cout << string(40, '=') << endl;

    // setprecision(1) biar cuma ada 1 angka di belakang koma (misal: 27.5)
    cout << fixed << setprecision(1); 
    
    cout << "Rata-rata     : " << rataRata 
         << " (" << tentukanKategori(rataRata) << ")" << endl;
         
    cout << "Suhu Tertinggi: " << suhuMax 
         << " (hari ke-" << hariMax << ")" << endl;
         
    cout << "Suhu Terendah : " << suhuMin 
         << " (hari ke-" << hariMin << ")" << endl;
         
    cout << string(40, '-') << endl;

    return 0;
}
