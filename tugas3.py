# ===============================
# SINGLE LINKED LIST (Mahasiswa)
# ===============================

class NodeSingle:
    def __init__(self, nama, nim):
        self.nama = nama
        self.nim = nim
        self.next = None


class SingleLinkedList:
    def __init__(self):
        self.head = None

    def tambah_mahasiswa(self, nama, nim):
        baru = NodeSingle(nama, nim)
        baru.next = self.head
        self.head = baru

    def tampil_mahasiswa(self):
        if self.head is None:
            print("\nData kosong.")
            return
        
        temp = self.head
        print("\nDaftar Mahasiswa:")
        while temp:
            print(f"Nama: {temp.nama}, NIM: {temp.nim}")
            temp = temp.next

    def hapus_mahasiswa(self, nim):
        temp = self.head
        prev = None

        while temp and temp.nim != nim:
            prev = temp
            temp = temp.next

        if temp is None:
            print("Data tidak ditemukan.")
            return False

        if prev is None:
            self.head = temp.next
        else:
            prev.next = temp.next

        print("Data berhasil dihapus.")
        return True


# ===============================
# DOUBLE LINKED LIST (Riwayat)
# ===============================

class NodeDouble:
    def __init__(self, aktivitas):
        self.aktivitas = aktivitas
        self.prev = None
        self.next = None


class DoubleLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def tambah_riwayat(self, aktivitas):
        baru = NodeDouble(aktivitas)

        if self.head is None:
            self.head = self.tail = baru
        else:
            self.tail.next = baru
            baru.prev = self.tail
            self.tail = baru

    def tampil_maju(self):
        if self.head is None:
            print("\nRiwayat kosong.")
            return
        
        temp = self.head
        print("\nRiwayat (Maju):")
        while temp:
            print(temp.aktivitas)
            temp = temp.next

    def tampil_mundur(self):
        if self.tail is None:
            print("\nRiwayat kosong.")
            return
        
        temp = self.tail
        print("\nRiwayat (Mundur):")
        while temp:
            print(temp.aktivitas)
            temp = temp.prev


# ===============================
# PROGRAM UTAMA
# ===============================

def main():
    data_mahasiswa = SingleLinkedList()
    riwayat = DoubleLinkedList()

    while True:
        print("\n=== MENU ===")
        print("1. Tambah Mahasiswa")
        print("2. Hapus Mahasiswa")
        print("3. Tampilkan Mahasiswa")
        print("4. Tampilkan Riwayat (Maju)")
        print("5. Tampilkan Riwayat (Mundur)")
        print("0. Keluar")

        pilih = input("Pilih menu: ")

        if pilih == "1":
            nama = input("Masukkan Nama: ")
            nim = input("Masukkan NIM: ")
            data_mahasiswa.tambah_mahasiswa(nama, nim)
            riwayat.tambah_riwayat(f"Tambah Mahasiswa: {nama}")
            print("Data berhasil ditambahkan.")

        elif pilih == "2":
            nim = input("Masukkan NIM yang akan dihapus: ")
            berhasil = data_mahasiswa.hapus_mahasiswa(nim)
            if berhasil:
                riwayat.tambah_riwayat(f"Hapus Mahasiswa NIM: {nim}")

        elif pilih == "3":
            data_mahasiswa.tampil_mahasiswa()

        elif pilih == "4":
            riwayat.tampil_maju()

        elif pilih == "5":
            riwayat.tampil_mundur()

        elif pilih == "0":
            print("Program selesai.")
            break

        else:
            print("Pilihan tidak valid.")


if __name__ == "__main__":
    main()