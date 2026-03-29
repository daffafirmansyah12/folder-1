#include <iostream>
#include <limits>
using namespace std;

struct NodeS {
    string nama;
    string nim;
    NodeS* next;
};

NodeS* headS = nullptr;

void tambahMahasiswa(string nama, string nim) {
    NodeS* baru = new NodeS{nama, nim, headS};
    headS = baru;
}

void tampilMahasiswa() {
    if (!headS) {
        cout << "\nData kosong.\n";
        return;
    }

    cout << "\nDaftar Mahasiswa:\n";
    for (NodeS* temp = headS; temp; temp = temp->next)
        cout << "Nama: " << temp->nama
             << " | NIM: " << temp->nim << endl;
}

bool hapusMahasiswa(string nim) {
    NodeS *temp = headS, *prev = nullptr;

    while (temp && temp->nim != nim) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) {
        cout << "Data tidak ditemukan.\n";
        return false;
    }

    if (!prev)
        headS = temp->next;
    else
        prev->next = temp->next;

    delete temp;
    cout << "Data berhasil dihapus.\n";
    return true;
}

struct NodeD {
    string aktivitas;
    NodeD* prev;
    NodeD* next;
};

NodeD *headD = nullptr, *tailD = nullptr;

void tambahRiwayat(string aktivitas) {
    NodeD* baru = new NodeD{aktivitas, nullptr, nullptr};

    if (!headD)
        headD = tailD = baru;
    else {
        tailD->next = baru;
        baru->prev = tailD;
        tailD = baru;
    }
}

void tampilRiwayat(bool maju) {
    if (!headD) {
        cout << "\nRiwayat kosong.\n";
        return;
    }

    cout << "\nRiwayat (" << (maju ? "Maju" : "Mundur") << "):\n";
    NodeD* temp = maju ? headD : tailD;

    while (temp) {
        cout << "- " << temp->aktivitas << endl;
        temp = maju ? temp->next : temp->prev;
    }
}

int main() {
    int pilih;
    string nama, nim;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Tambah Mahasiswa\n";
        cout << "2. Hapus Mahasiswa\n";
        cout << "3. Tampilkan Mahasiswa\n";
        cout << "4. Tampilkan Riwayat (Maju)\n";
        cout << "5. Tampilkan Riwayat (Mundur)\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (pilih) {

        case 1:
            cout << "Nama: ";
            getline(cin, nama);
            cout << "NIM: ";
            getline(cin, nim);
            tambahMahasiswa(nama, nim);
            tambahRiwayat("Tambah Mahasiswa: " + nama);
            cout << "Data berhasil ditambahkan.\n";
            break;

        case 2:
            cout << "Masukkan NIM: ";
            getline(cin, nim);
            if (hapusMahasiswa(nim))
                tambahRiwayat("Mahasiswa NIM: " + nim);
            break;

        case 3:
            tampilMahasiswa();
            break;

        case 4:
            tampilRiwayat(true);
            break;

        case 5:
            tampilRiwayat(false);
            break;

        case 0:
            cout << "Program selesai.\n";
            break;

        default:
            cout << "Pilihan tidak valid.\n";
        }

    } while (pilih != 0);

    return 0;
}