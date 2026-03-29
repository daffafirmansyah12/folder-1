#include <iostream>
using namespace std;

struct Node{
    string kereta;
    string tujuan;
    string jam;
    Node *next;
};

Node *top = NULL;

void push(){
    Node *baru = new Node();

    cin.ignore();

    cout << "Nama Kereta  : ";
    getline(cin, baru->kereta);

    cout << "Tujuan       : ";
    getline(cin, baru->tujuan);

    cout << "Jam Berangkat: ";
    getline(cin, baru->jam);

    baru->next = top;
    top = baru;

    cout << "Data perjalanan berhasil ditambahkan\n";
}

void pop(){
    if(top == NULL){
        cout << "Data perjalanan kosong\n";
        return;
    }

    Node *hapus = top;

    cout << "\nData perjalanan terakhir:\n";
    cout << "Kereta : " << hapus->kereta << endl;
    cout << "Tujuan : " << hapus->tujuan << endl;
    cout << "Jam    : " << hapus->jam << endl;

    top = top->next;

    delete hapus;
}

void lihat(){
    if(top == NULL){
        cout << "Belum ada data perjalanan\n";
        return;
    }

    Node *bantu = top;

    cout << "\nRiwayat Perjalanan Kereta\n";
    cout << "-------------------------\n";

    while(bantu != NULL){
        cout << "Kereta : " << bantu->kereta << endl;
        cout << "Tujuan : " << bantu->tujuan << endl;
        cout << "Jam    : " << bantu->jam << endl;
        cout << "-------------------------\n";

        bantu = bantu->next;
    }
}

int main(){

    int pilih;

    do{
        cout << "\n=== SISTEM RIWAYAT PERJALANAN KERETA API ===\n";
        cout << "1. Tambah Perjalanan\n";
        cout << "2. Hapus Perjalanan Terakhir\n";
        cout << "3. Lihat Riwayat\n";
        cout << "4. Keluar\n";
        cout << "Pilih : ";
        cin >> pilih;

        if(pilih == 1){
            push();
        }
        else if(pilih == 2){
            pop();
        }
        else if(pilih == 3){
            lihat();
        }
        else if(pilih == 4){
            cout << "Program selesai\n";
        }
        else{
            cout << "Pilihan tidak tersedia\n";
        }

    }while(pilih != 4);

    return 0;
}