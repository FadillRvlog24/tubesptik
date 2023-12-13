#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>

const int MAX_DOSEN = 100; // Ukuran maksimum array

// Struktur untuk menyimpan informasi dosen
struct Dosen {
    std::string nama;
    std::string nip;
    std::string alamat;
    std::string email;
    std::string nomorTelepon;
    std::string mataKuliah;
    std::string hariMengajar;
    int umur;
};

// Kelas untuk menyimpan data dosen dan operasinya
class DatabaseDosen {
private:
    Dosen dataDosen[MAX_DOSEN];
    int jumlahDosen; // Menyimpan jumlah dosen yang telah dimasukkan

public:
    // Konstruktor
    DatabaseDosen() : jumlahDosen(0) {}

    // Menambahkan data dosen ke dalam array
    void tambahDataDosen(const Dosen& dosen);

    // Menampilkan semua data dosen
    void lihatDataDosen() const;

    // Mengupdate data dosen berdasarkan nama
    void updateDataDosen(const std::string& namaDosen, const Dosen& newData);

    // Menghapus data dosen berdasarkan nama
    void hapusDataDosen(const std::string& namaDosen);

    // Validasi input hari
    bool isValidHari(const std::string& hari) const;

    // Validasi apakah string hanya berisi huruf
    bool isAlpha(const std::string& str) const;

    // Validasi apakah string hanya berisi angka
    bool isNumeric(const std::string& str) const;

    // Validasi apakah nama dosen sudah ada dalam database
    bool isDosenExist(const std::string& namaDosen) const;
};

// Implementasi fungsi untuk menambahkan data dosen
void DatabaseDosen::tambahDataDosen(const Dosen& dosen) {
    if (jumlahDosen < MAX_DOSEN) {
        dataDosen[jumlahDosen++] = dosen;
    } else {
        std::cout << "Database penuh. Tidak dapat menambahkan lebih banyak data dosen.\n";
    }
}

// Implementasi fungsi untuk menampilkan semua data dosen
void DatabaseDosen::lihatDataDosen() const {
	if (jumlahDosen > 0){
    std::cout << "\nData Dosen:\n";
    for (int i = 0; i < jumlahDosen; ++i) {
        std::cout << "Nama: " << dataDosen[i].nama << "\n";
        std::cout << "NIP: " << dataDosen[i].nip << "\n";
        std::cout << "Alamat: " << dataDosen[i].alamat << "\n";
        std::cout << "Email: " << dataDosen[i].email << "\n";
        std::cout << "Nomor Telepon: " << dataDosen[i].nomorTelepon << "\n";
        std::cout << "Mata Kuliah: " << dataDosen[i].mataKuliah << "\n";
		std::cout << "Hari Mengajar: " << dataDosen[i].hariMengajar << "\n";
        std::cout << "Umur: " << dataDosen[i].umur << " tahun\n\n";
       
        
    }
}	else {
		std::cout<<"Belum ada data dosen. \";
		}	std::cout<<"----------------------------------------------\n";
}   
     
// Implementasi fungsi untuk mengupdate data dosen berdasarkan nama
void DatabaseDosen::updateDataDosen(const std::string& namaDosen, const Dosen& newData) {
    int index = -1;
    for (int i = 0; i < jumlahDosen; ++i) {
        if (dataDosen[i].nama == namaDosen) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        dataDosen[index] = newData;
        std::cout << "Data dosen berhasil diupdate.\n";
    } else {
        std::cout << "Dosen dengan nama '" << namaDosen << "' tidak ditemukan. Apakah Anda ingin menambahkannya? (Y/N): ";
        char tambahData;
        std::cin >> tambahData;

        if (std::toupper(tambahData) == 'Y') {
            tambahDataDosen(newData);
            std::cout << "Data dosen berhasil ditambahkan.\n";
        } else {
            std::cout << "Update dibatalkan.\n";
        }
    }
}

// Implementasi fungsi untuk menghapus data dosen berdasarkan nama
void DatabaseDosen::hapusDataDosen(const std::string& namaDosen) {
    int index = -1;
    for (int i = 0; i < jumlahDosen; ++i) {
        if (dataDosen[i].nama == namaDosen) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        for (int i = index; i < jumlahDosen - 1; ++i) {
            dataDosen[i] = dataDosen[i + 1];
        }
        --jumlahDosen;
        std::cout << "Data dosen berhasil dihapus.\n";
    } else {
        std::cout << "Dosen dengan nama '" << namaDosen << "' tidak ditemukan. Hapus dibatalkan.\n";
    }
}

// Implementasi fungsi untuk validasi input hari
bool DatabaseDosen::isValidHari(const std::string& hari) const {
    std::string hariUpper;
    std::transform(hari.begin(), hari.end(), std::back_inserter(hariUpper), ::toupper);
    
    std::vector<std::string>daftarHari = {"SENIN", "SELASA", "RABU", "KAMIS", "JUMAT"};
    	return std::find(daftarHari.begin(), daftarHari.end(), hariUpper) != daftarHari.end();
}

// Implementasi fungsi untuk validasi apakah string hanya berisi huruf
bool DatabaseDosen::isAlpha(const std::string& str) const {
    return std::all_of(str.begin(), str.end(), ::isalpha);
}

// Implementasi fungsi untuk validasi apakah string hanya berisi angka
bool DatabaseDosen::isNumeric(const std::string& str) const {
    return std::all_of(str.begin(), str.end(), ::isdigit);
}

// Implementasi fungsi untuk validasi apakah nama dosen sudah ada dalam database
bool DatabaseDosen::isDosenExist(const std::string& namaDosen) const {
    for (int i = 0; i < jumlahDosen; ++i) {
        if (dataDosen[i].nama == namaDosen) {
            return true; // Nama dosen ditemukan
        }
    }
    return false; // Nama dosen tidak ditemukan
}