#include <iostream>
#include <string>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

// Struct tugas di dalem grup nanti 
struct ToDoItem {
    string task;
    bool done;
    ToDoItem* next; // Linked List item dalam grup
};

// tes

// Struct Grup To-Do listnya 
struct ToDoGroup {
    string groupName;
    string groupDate;
    ToDoItem* headItem; // Pointer ke linked list item
    ToDoGroup* next;    // Linked List antar grup
};

// ======================= CEK BENTUK OUTPUT DI PALING BAWAH ===========================


// Head dari linked list grup
ToDoGroup* headGroup = nullptr;
ToDoGroup* currentNode = nullptr;

// ===================== FUNGSI-FUNGSI ==========================
bool isEmpty() {
    return (headGroup == NULL);
}
// Tambahkan grup baru ke daftar
void addGroup(string name, string date) {
    ToDoGroup *newNode = new ToDoGroup;
    newNode->groupName = name;
    newNode->groupDate = date;
    newNode->next = NULL;

    if (isEmpty()) {
        headGroup = newNode;
    } else {
        currentNode->next = newNode;
    }
    currentNode = newNode;

    cout << "Nama group berhasil ditambahkan\n\n";
}

// Tambahkan to-do item ke grup tertentu
void addToDoItem(string groupName, string task) {
    // Cari grup dengan nama tertentu
    // Tambahkan item ke linked list item pada grup

    // cek kodingan kodingan kemaren, kodinganya pasti mirip, bedanya cuman di variabel sama pointernya
}

// Hapus seluruh grup beserta semua list di dalamnya
void deleteGroup(string groupName) {
    // Cari grup
    // Hapus semua item dalam grup
    // Hapus grup dari linked list grup

    // cek kodingan kodingan kemaren, kodinganya pasti mirip, bedanya cuman di variabel sama pointernya
}

// Hapus satu item dalam grup
void deleteItem(string groupName, string task) {
    // Cari grup
    // Cari item berdasarkan nama
    // Hapus item dari linked list

    // cek kodingan kodingan kemaren, kodinganya pasti mirip, bedanya cuman di variabel sama pointernya
    ToDoGroup* group = headGroup;

    // Cari grup
    while (group != NULL && group->groupName != groupName) {
        group = group->next;
    }

    if (group == NULL) {
        cout << "Grup tidak ditemukan.\n";
        return;
    }

    ToDoItem* current = group->headItem;
    ToDoItem* previous = NULL;

    // Cari item
    while (current != NULL && current->task != task) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        cout << "Item tidak ditemukan dalam grup.\n";
        return;
    }

    // Hapus item
    if (previous == NULL) {
        // Item pertama
        group->headItem = current->next;
    } else {
        previous->next = current->next;
    }

    delete current;
    cout << "Item \"" << task << "\" berhasil dihapus dari grup \"" << groupName << "\".\n";


}

// Checklist tugas
void checkItem(string groupName, string task) {
    // Cari grup dan item
    // Ubah status 'done' jadi true

    // cek kodingan kodingan kemaren, kodinganya pasti mirip, bedanya cuman di variabel sama pointernya
}

// Tampilkan seluruh grup dan to-do list-nya
void displayAll() {
    // Looping seluruh grup
    // Looping seluruh item dalam grup
    // Tampilkan status checklist

    // cek kodingan kodingan kemaren, kodinganya pasti mirip, bedanya cuman di variabel sama pointernya
}

// Urutkan to-do list dalam grup berdasarkan abjad
void sortItems(string groupName) {
    // Gunakan bubble sort atau lainnya
    // Urutkan berdasarkan nama task

    // cek kodingan kodingan kemaren, kodinganya pasti mirip, bedanya cuman di variabel sama pointernya
}

// Cari grup berdasarkan nama (menggunakan searching)
ToDoGroup* searchGroup(string name) {
    // Linear search dalam linked list grup

    // cek kodingan kodingan kemaren, kodinganya pasti mirip, bedanya cuman di variabel sama pointernya
    return nullptr;
}

// =============================================================

int main() {
    int pilihanMenu;
    string Name, date;

    do {
        system("cls");
        cout << "==============================================\n";
        cout << "Menu To do list anda\n";
        cout << "==============================================\n";
        cout << "1. Menambah To Do List baru\n";
        cout << "==============================================";
        cout << "\nMasukkan pilihan anda : ";
        cin >> pilihanMenu;
        cout << endl;

        switch (pilihanMenu) {
            case 1:
                cout << "Masukkan Judul to do list anda : "; cin >> Name;
                cout << "Masukkan Hari dan tanggal pada to do list anda : "; cin >> date;
                addGroup(Name, date);
                break;
            case 2:
                break;

            default:
                cout << "Menu yang dipilih tidak terdaftar\n\n";
                break;
        }

        system("pause"); 
    } while (pilihanMenu != 2);
    return 0;
}


// Intinya, 2 struct diatas nanti hasil outputnya bakal keliatan kayak gini:

/* List hari ini: tgl 17 juli 2025: <-- ini string di dalem grup ToDoGroup "List hari ini" groupName. "tgl 17 juli 2025" groupDate
    [ ] Ngasih makan ikan 
    [ ] Belajar
    [ ] Ngerjain tugas
    [ ] Tidur

    [ ] <-- kotak ini pake bool done (bool done di dalem struct ToDoItem) atau artinya pake true false buat nanti user bisa ngechecklist kalo tugas ini kelar
            klo semisal user nge-done tugas ini, nanti ouputnya [v] Ngasih makan ikan

    Ngasih makan ikan <-- ini string task di dalem struct ToDoItem

    Jadi disini ada 2 linked list, linked list buat grup dan nanti di dalem grup dikasih linked list tugas. Mangkanya ada 2 struct, 
*/