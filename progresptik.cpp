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

// Fungsi utama program
int main() {
    std::cout << "=====================================\n";
    std::cout << "   Pengembangan Aplikasi CRUD Dosen  \n";
    std::cout << "=====================================\n";

    // Membuat objek database untuk menyimpan data dosen
    DatabaseDosen database;
    
    char pilihan;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Tambah Data Dosen\n";
        std::cout << "2. Lihat Data Dosen\n";
        std::cout << "3. Update Data Dosen\n";
        std::cout << "4. Hapus Data Dosen\n";
        std::cout << "5. Keluar\n";
        std::cout << "Masukkan Pilihan : ";
        std::cin >> pilihan;
        
        // Memproses pilihan menu
        switch (pilihan) {
            case '1': {
                // Input data dosen baru
                Dosen dosen;
                std::cin.ignore(); // membersihkan newline dari buffer

                // Validasi Nama
                do {
                    std::cout << "Masukkan Nama Dosen: ";
                    std::getline(std::cin, dosen.nama);
                    
                    if (dosen.nama.empty()){
                    	std::cout << "Error: Nama dosen tidak boleh kosong. \n";
                    	continue; //melanjutkan loop tanpa menambah data dosen
					}
					if (!database.isAlpha(dosen.nama)){
						std::cout << "Error: Nama dosen hanya berisi huruf.\n";
						continue; //Melanjutkan loop tanpa menambah data dosen
					}
                } while (dosen.nama.empty() || !database.isAlpha(dosen.nama));

                // Validasi NIP
                do {
                    std::cout << "Masukkan NIP Dosen: ";
                    std::getline(std::cin, dosen.nip);
                    
                     if (dosen.nip.empty()){
                    	std::cout << "Error: Nip dosen tidak boleh kosong. \n";
                    	continue; //melanjutkan loop tanpa menambah data dosen
					}
					if (!database.isNumeric(dosen.nip)){
						std::cout << "Error: Nip dosen hanya berisi angka.\n";
						continue; //Melanjutkan loop tanpa menambah data dosen
					}
                } while (dosen.nip.empty() || !database.isNumeric(dosen.nip));

                // Validasi Alamat
                std::cout << "Masukkan Alamat Dosen: ";
                std::getline(std::cin, dosen.alamat);

                // Validasi Email
                std::cout << "Masukkan Email Dosen: ";
                std::getline(std::cin, dosen.email);

                // Validasi Nomor Telepon
                do {
                    std::cout << "Masukkan Nomor Telepon Dosen: ";
                    std::getline(std::cin, dosen.nomorTelepon);
                    
                    if (dosen.nomorTelepon.empty()){
                    	std::cout << "Error: Nomor Telepon dosen tidak boleh kosong. \n";
                    	continue; //melanjutkan loop tanpa menambah data dosen
					}
					if (!database.isNumeric(dosen.nomorTelepon)){
						std::cout << "Error: Nomor Telepon dosen hanya berisi angka.\n";
						continue; //Melanjutkan loop tanpa menambah data dosen
					}
                } while (dosen.nomorTelepon.empty() || !database.isNumeric(dosen.nomorTelepon) || dosen.nomorTelepon.length() > 13);

                // Validasi Mata Kuliah
                do {
                    std::cout << "Masukkan Mata Kuliah: ";
                    std::getline(std::cin, dosen.mataKuliah);
                    
                    if (dosen.mataKuliah.empty()){
                    	std::cout << "Error: Mata Kuliah dosen tidak boleh kosong. \n";
                    	continue; //melanjutkan loop tanpa menambah data dosen
					}
					if (!database.isAlpha(dosen.mataKuliah)){
						std::cout << "Error: Mata Kuliah dosen hanya berisi huruf.\n";
						continue; //Melanjutkan loop tanpa menambah data dosen
					}
                } while (dosen.mataKuliah.empty() || !database.isAlpha(dosen.mataKuliah));

                // Validasi Hari Mengajar
                do {
                    std::cout << "Masukkan Hari Mengajar (Senin, Selasa, Rabu, Kamis, Jumat): ";
                    std::getline(std::cin, dosen.hariMengajar);
                    
                    //Ubah input menjadi huruf besar
                    std::transform(dosen.hariMengajar.begin(), dosen.hariMengajar.end(), dosen.hariMengajar.begin(), ::toupper);
                                        
                } while (!database.isValidHari(dosen.hariMengajar));
                
                // Validasi Umur
                do {
                    std::cout << "Masukkan Umur Dosen: ";
                    std::string umurStr;
                    std::cin>> umurStr;
                    
                    try{
                    	//mengonversi string ke integer
                    	dosen.umur = std::stoi (umurStr);
                    	
                    	if (dosen.umur < 0){
                    		throw std::out_of_range("umur tidak boleh negatif");
						}
					} catch (const std::invalid_argument& e){
						std::cout << "Error: input tidak valid. Masukkan Angka.\n";
						std::cin.clear(); //membersihkan status error
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //membersihkan buffer input
						dosen.umur = -1; //nilai negatif untuk mengulangi loop
					} catch(const std::out_of_range& e) {
						std::cout <<"Error: " <<e.what() << "\n";
						dosen.umur = -1; //Nilai negatif untuk mengulangi loop
					}
                } while (dosen.umur < 0);

                // Menambahkan data dosen baru ke dalam database
                database.tambahDataDosen(dosen);
                std::cout << "Data dosen berhasil ditambahkan.\n";
                break;
            }
            case '2':
                // Menampilkan semua data dosen
                database.lihatDataDosen();
                break;
                
            case '3': {
                // Mengupdate data dosen
                std::string namaDosen;
                std::cin.ignore();
                std::cout << "Masukkan Nama Dosen yang akan diupdate: ";
                std::getline(std::cin, namaDosen);

                if (database.isDosenExist(namaDosen)) {
                    Dosen newData;
                    //Validasi Nama baru dosen
                    do {
    					std::cout << "Masukkan Nama Baru Dosen: ";
   						std::getline(std::cin, newData.nama);
    					if (newData.nama.empty() || !database.isAlpha(newData.nama)) {
        					std::cout << "Error: Nama dosen baru tidak valid. Harus berupa huruf.\n";
    					}
					} while (newData.nama.empty() || !database.isAlpha(newData.nama));
					//Validasi NIP  baru Dosen
                    do {
    					std::cout << "Masukkan NIP Baru Dosen: ";
    					std::getline(std::cin, newData.nip);
    					if (newData.nip.empty() || !database.isNumeric(newData.nip)) {
        					std::cout << "Error: NIP dosen baru tidak valid. Harus berupa angka.\n";
    					}
					} while (newData.nip.empty() || !database.isNumeric(newData.nip));

                    
                    //Validasi Alamat Baru
                    	std::cout << "Masukkan Alamat Baru Dosen: ";
                    	std::getline(std::cin, newData.alamat);
                    	
                    //Validasi Email Baru
                    	std::cout << "Masukkan Email Baru Dosen: ";
                    	std::getline(std::cin, newData.email);

                    //Validasi Nomor Telepon Baru Dosen
                    do {
    					std::cout << "Masukkan Nomor Telepon Baru Dosen: ";
    					std::getline(std::cin, newData.nomorTelepon);
    					if (newData.nomorTelepon.empty() || !database.isNumeric(newData.nomorTelepon) || newData.nomorTelepon.length() > 13) {
        					std::cout << "Error: Nomor Telepon dosen baru tidak valid. Harus berupa angka dan tidak lebih dari 13 digit.\n";
    					}
					} while (newData.nomorTelepon.empty() || !database.isNumeric(newData.nomorTelepon) || newData.nomorTelepon.length() > 13);

					//Validasi Mata kuliah Baru
                    do {
    					std::cout << "Masukkan Mata Kuliah Baru: ";
    					std::getline(std::cin, newData.mataKuliah);
    					if (newData.mataKuliah.empty() || !database.isAlpha(newData.mataKuliah)) {
        					std::cout << "Error: Mata Kuliah dosen baru tidak valid. Harus diisi huruf dan tidak boleh kosong.\n";
    					}
					} while (newData.mataKuliah.empty() || !database.isAlpha(newData.mataKuliah));

                    // Validasi Hari Mengajar Baru
                    do {
                        std::cout << "Masukkan Hari Mengajar Baru (Senin, Selasa, Rabu, Kamis, Jumat): ";
                        std::getline(std::cin, newData.hariMengajar);
                    } while (!database.isValidHari(newData.hariMengajar));

					//Validasi Umur Baru Dosen
                   do {
    					std::cout << "Masukkan Umur Baru Dosen: ";
    					std::string umurStr;
    					std::cin >> umurStr;
    				try {
        				newData.umur = std::stoi(umurStr);
        				if (newData.umur < 0) {
            				throw std::out_of_range("umur tidak boleh negatif");
        			}
    			} catch (const std::invalid_argument& e) {
        			std::cout << "Error: Input tidak valid. Masukkan angka.\n";
        			std::cin.clear();
        			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        			newData.umur = -1;
    			} catch (const std::out_of_range& e) {
        			std::cout << "Error: " << e.what() << "\n";
        			newData.umur = -1;
	    		}
			} while (newData.umur < 0);