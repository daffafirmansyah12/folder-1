#include <iostream>
using namespace std;

struct Node{
    string kereta;
    string tujuan;
    string jam;
    Node *next;
};

Node *front = NULL;
Node *rear = NULL;

void tambah(){
    Node *baru = new Node();

    cout << "Nama Kereta  : ";
    getline(cin, baru->kereta);

    cout << "Tujuan       : ";
    getline(cin, baru->tujuan);

    cout << "Jam Berangkat: ";
    getline(cin, baru->jam);

    baru->next = NULL;

    if(front == NULL){
        front = baru;
        rear = baru;
    }else{
        rear->next = baru;
        rear = baru;
    }

    cout << "Jadwal berhasil ditambahkan\n";
}

void proses(){
    if(front == NULL){
        cout << "Jadwal masih kosong\n";
        return;
    }

    Node *hapus = front;

    cout << "\nKereta yang akan berangkat:\n";
    cout << "Kereta : " << hapus->kereta << endl;
    cout << "Tujuan : " << hapus->tujuan << endl;
    cout << "Jam    : " << hapus->jam << endl;

    front = front->next;

    if(front == NULL){
        rear = NULL;
    }

    delete hapus;
}

void lihat(){
    if(front == NULL){
        cout << "Belum ada jadwal kereta\n";
        return;
    }

    Node *bantu = front;

    cout << "\nDaftar Jadwal Kereta\n";
    while(bantu != NULL){
        cout << "Kereta : " << bantu->kereta << endl;
        cout << "Tujuan : " << bantu->tujuan << endl;
        cout << "Jam    : " << bantu->jam << endl;
        cout << "---------------------\n";
        bantu = bantu->next;
    }
}

int main(){

    int pilih;

    do{
        cout << "\n=== SISTEM JADWAL KERETA API ===\n";
        cout << "1. Tambah Jadwal\n";
        cout << "2. Proses Kereta\n";
        cout << "3. Lihat Jadwal\n";
        cout << "4. Keluar\n";
        cout << "Pilih : ";
        cin >> pilih;
        cin.ignore();

        if(pilih == 1){
            tambah();
        }
        else if(pilih == 2){
            proses();
        }
        else if(pilih == 3){
            lihat();
        }
        else if(pilih == 4){
            cout << "Program selesai\n";
        }
        else{
            cout << "Pilihan tidak ada\n";
        }

    }while(pilih != 4);

    return 0;
}