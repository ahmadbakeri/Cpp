#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

// Struktur Data
struct Mahasiswa {
    string nama;
    int nilaiTugas, nilaiUTS, nilaiUAS;
    float nilaiAkhir;                   
    char grade;
};

// Nilai Tetap
const int MAX_MAHASISWA = 50;

// Fungsi"

// Fungsi membersihkan buffer input agar tidak terjadi error/skip
void bersihkanBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Fungsi validasi input angka 0-100 
int ambilInputNilai(string label) {
    int n;
    while (true) {
        cout << label << " (0-100): ";
        if (cin >> n && n >= 0 && n <= 100) {
            return n;
        }
        cout << "Gagal! Masukkan angka bulat 0-100 saja.\n";
        bersihkanBuffer();
    }
}

// Fungsi hitung nilai akhir
float hitungNilaiAkhir(int tugas, int uts, int uas) {
    return (0.3 * tugas) + (0.3 * uts) + (0.4 * uas);
}

// Fungsi konversi angka ke huruf (Grade)
char tentukanGrade(float na) {
    if (na >= 85) {
        return 'A';
    } 
    else if (na >= 70) {
        return 'B';
    } 
    else if (na >= 60) {
        return 'C';
    } 
    else if (na >= 50) {
        return 'D';
    } 
    else {
        return 'E';
    }
}
// --- PROGRAM UTAMA ---

int main() {
    Mahasiswa daftarMhs[MAX_MAHASISWA];
    int jumlahData;
	//
    cout << "======================================" << endl;
    cout << "   SISTEM PENILAIAN MAHASISWA C++" << endl;
    cout << "======================================" << endl;

    // 1. Input Jumlah Mahasiswa
    while (true) {
        cout << "Masukkan jumlah mahasiswa (1-" << MAX_MAHASISWA << "): ";
        if (cin >> jumlahData && jumlahData >= 1 && jumlahData <= MAX_MAHASISWA) {
            break;
        }
        cout << "Input tidak valid! Masukkan angka antara 1 sampai " << MAX_MAHASISWA << endl;
        bersihkanBuffer();
    }

    // 2. Loop Input Data Mahasiswa
    for (int i = 0; i < jumlahData; i++) {
        cout << "\n>>> Data Mahasiswa ke-" << (i + 1) << endl;
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Nama Lengkap       : ";
        getline(cin, daftarMhs[i].nama);

        // Memanggil fungsi pembantu untuk input nilai int
        daftarMhs[i].nilaiTugas = ambilInputNilai("Nilai Tugas       ");
        daftarMhs[i].nilaiUTS   = ambilInputNilai("Nilai UTS         ");
        daftarMhs[i].nilaiUAS   = ambilInputNilai("Nilai UAS         ");

        // Proses Hitung
        daftarMhs[i].nilaiAkhir = hitungNilaiAkhir(daftarMhs[i].nilaiTugas, 
                                                   daftarMhs[i].nilaiUTS, 
                                                   daftarMhs[i].nilaiUAS);
        daftarMhs[i].grade = tentukanGrade(daftarMhs[i].nilaiAkhir);
    }

    // 3. Tampilkan Hasil (Output)
    cout << "\n" << string(70, '=') << endl;
    cout << left << setw(25) << "NAMA"
		 << setw(8)  << "TUGAS"
         << setw(8)  << "UTS"
         << setw(8)  << "UAS"
         << setw(8)  << "NA"
         << setw(8)  << "GRADE" << endl;
    cout << string(70, '-') << endl;

    cout << fixed << setprecision(1);
    for (int i = 0; i < jumlahData; i++) {
        cout << left << setw(25) << daftarMhs[i].nama
             << setw(8)  << daftarMhs[i].nilaiTugas
             << setw(8)  << daftarMhs[i].nilaiUTS
             << setw(8)  << daftarMhs[i].nilaiUAS
             << setw(8)  << daftarMhs[i].nilaiAkhir
             << "  " << daftarMhs[i].grade << endl;
    }
    cout << string(70, '=') << endl;

    return 0;
}
