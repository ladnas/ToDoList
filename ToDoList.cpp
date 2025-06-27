#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;


struct Tugas {
    string namaTugas;
    bool selesai;
    Tugas* next;
};

struct Grup {
    string namaGrup;
    string tanggal;
    Tugas* head;
    Grup* next;
};


Grup* headGroup = NULL;
Grup* queueArray[100];
int front = -1, back = -1;


bool isQueueEmpty() {
    return front == -1;
}

void enqueue(Grup* newGroup) {
    if (back == 99) return;
    if (isQueueEmpty()) front = 0;
    queueArray[++back] = newGroup;
}

Grup* dequeue() {
    if (isQueueEmpty()) return NULL;
    Grup* result = queueArray[front++];
    if (front > back) front = back = -1;
    return result;
}


bool isEmpty() {
    return headGroup == NULL;
}

Grup* cariGrup(string nama) {
    Grup* current = headGroup;
    while (current != NULL) {
        if (current->namaGrup == nama)
            return current;
        current = current->next;
    }
    return NULL;
}

void tampilkanDaftarGrup() {
    Grup* current = headGroup;
    cout << "\nDaftar Grup Yang Ada:\n";
    while (current != NULL) {
        cout << "- " << current->namaGrup << endl;
        current = current->next;
    }
    cout << endl;
}

void tampilkanDaftarTugasDalamGrup(string namaGrup) {
    Grup* grup = cariGrup(namaGrup);
    if (!grup) return;

    cout << "\nTugas di dalam grup '" << namaGrup << "':\n";
    Tugas* tugas = grup->head;
    while (tugas != NULL) {
        cout << (tugas->selesai ? "[v] " : "[ ] ") << tugas->namaTugas << endl;
        tugas = tugas->next;
    }
}

void hapusSemuaTugas(Tugas* head) {
    while (head != NULL) {
        Tugas* temp = head;
        head = head->next;
        delete temp;
    }
}

void hapusGrup(string namaGrup) {
    Grup* current = headGroup;
    Grup* previous = NULL;

    while (current != NULL && current->namaGrup != namaGrup) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        cout << "Grup tidak ditemukan.\n";
        return;
    }

    hapusSemuaTugas(current->head);

    if (previous == NULL) {
        headGroup = current->next;
    } else {
        previous->next = current->next;
    }

    delete current;
    cout << "Grup \"" << namaGrup << "\" berhasil dihapus.\n";
}

void hapusTugas(string namaGrup, string namaTugas) {
    Grup* grup = cariGrup(namaGrup);
    if (grup == NULL) {
        cout << "Grup tidak ditemukan.\n";
        return;
    }

    Tugas* current = grup->head;
    Tugas* previous = NULL;

    while (current != NULL && current->namaTugas != namaTugas) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        cout << "Tugas tidak ditemukan.\n";
        return;
    }

    if (previous == NULL) {
        grup->head = current->next;
    } else {
        previous->next = current->next;
    }

    delete current;
    cout << "Tugas \"" << namaTugas << "\" berhasil dihapus dari grup \"" << namaGrup << "\".\n";
}

void tambahGrup(string nama, string tanggal) {
    Grup* baru = new Grup;
    baru->namaGrup = nama;
    baru->tanggal = tanggal;
    baru->head = NULL;
    baru->next = NULL;

    if (isEmpty()) {
        headGroup = baru;
    } else {
        Grup* temp = headGroup;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = baru;
    }
    enqueue(baru);
    cout << "\nGrup berhasil ditambahkan.\n";
}

void tambahTugas(string namaGrup, string namaTugas) {
    Grup* grup = cariGrup(namaGrup);
    if (grup == NULL) {
        cout << "Grup tidak ditemukan.\n";
        return;
    }
    char tambahLagi;
    do {
        string namaTugas;
        cout <<"Masukan Nama Tugas: ";
        getline(cin, namaTugas);


    
    Tugas* tugasBaru = new Tugas{namaTugas, false, NULL};

    if (grup->head == NULL) {
        grup->head = tugasBaru;
    } else {
        Tugas* temp = grup->head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = tugasBaru;
    }
    cout << "Tugas berhasil ditambahkan ke grup \"" << namaGrup << "\".\n";
    cout << "Ingin tambah tugas lagi? (y/n): ";
    cin >> tambahLagi;
    cin.ignore();
    } while (tambahLagi == 'y' || tambahLagi == 'Y');
}

void tampilkanSemua() {
    Grup* grup = headGroup;
    while (grup != NULL) {
        cout << "\n" << grup->namaGrup << " - " << grup->tanggal << ":\n";
        Tugas* tugas = grup->head;
        while (tugas != NULL) {
            cout << (tugas->selesai ? "[v] " : "[ ] ") << tugas->namaTugas << endl;
            tugas = tugas->next;
        }
        grup = grup->next;
    }
    cout << endl;
}

void checklistTugas(string namaGrup, string namaTugas) {
    Grup* grup = cariGrup(namaGrup);
    if (grup == NULL) return;

    Tugas* tugas = grup->head;
    while (tugas != NULL) {
        if (tugas->namaTugas == namaTugas) {
            tugas->selesai = true;
            cout << "Tugas " << namaTugas << " selesai!\n";
            return;
        }
        tugas = tugas->next;
    }
    cout << "Tugas tidak ditemukan.\n";
}

void urutkanTugas(string namaGrup) {
    Grup* grup = cariGrup(namaGrup);
    if (!grup || !grup->head) return;

    bool tukar;
    do {
        tukar = false;
        Tugas* sekarang = grup->head;
        Tugas* sebelumnya = NULL;

        while (sekarang->next != NULL) {
            if (sekarang->namaTugas > sekarang->next->namaTugas) {
                Tugas* tmp = sekarang->next;
                sekarang->next = tmp->next;
                tmp->next = sekarang;
                if (sebelumnya == NULL)
                    grup->head = tmp;
                else
                    sebelumnya->next = tmp;
                tukar = true;
                sebelumnya = tmp;
            } else {
                sebelumnya = sekarang;
                sekarang = sekarang->next;
            }
        }
    } while (tukar);
    cout << "Tugas dalam grup \"" << namaGrup << "\" telah diurutkan.\n";
}

// ===== MENU UTAMA =====
int main() {
    int pilihan;
    string namaGrup, tanggal, namaTugas;

    do {

        system("cls");
        
        cout << "\n========= MENU TO DO LIST =========\n";
        cout << "1. Tambah Grup\n";
        cout << "2. Tambah Tugas ke Grup\n";
        cout << "3. Checklist Tugas\n";
        cout << "4. Tampilkan Semua\n";
        cout << "5. Urutkan Tugas dalam Grup\n";
        cout << "6. Hapus Tugas dari Grup\n";
        cout << "7. Hapus Grup\n";
        cout << "0. Keluar\n";
        cout << "\n====================================\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama grup: "; getline(cin, namaGrup);
                cout << "Masukkan tanggal: "; getline(cin, tanggal);
                tambahGrup(namaGrup, tanggal);
                break;
            case 2:
                tampilkanDaftarGrup();
                cout <<"Masukan Nama Grup: "; getline(cin, namaGrup);
                tambahTugas(namaGrup, namaTugas);
                break;
            case 3:
                #ifdef _WIN32
                system("cls");
                #else
                system("clear");
                #endif
                tampilkanSemua();
                cout << "Nama grup: "; getline(cin, namaGrup);
                cout << "Nama tugas yang selesai: "; getline(cin, namaTugas);
                checklistTugas(namaGrup, namaTugas);
                break;
            case 4:
                tampilkanSemua();
                break;
            case 5:
                tampilkanDaftarGrup();
                cout << "Nama grup: "; getline(cin, namaGrup);
                urutkanTugas(namaGrup);
                break;
            case 6:
                tampilkanDaftarGrup();
                cout << "Nama grup: "; getline(cin, namaGrup);
                tampilkanDaftarTugasDalamGrup(namaGrup);
                cout << "Nama tugas yang ingin dihapus: "; getline(cin, namaTugas);
                hapusTugas(namaGrup, namaTugas);
                break;
            case 7:
                tampilkanDaftarGrup();
                cout << "Nama grup yang ingin dihapus: "; getline(cin, namaGrup);
                hapusGrup(namaGrup);
                break;
            case 0:
                cout << "Keluar...\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
                break;
        }

        cout << "\nTekan Enter untuk melanjutkan...";
        cin.get();

    } while (pilihan != 0);

    return 0;
}
