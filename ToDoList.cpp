#include <iostream>
#include <string>
using namespace std;

// Struct To-Do list item (List nanti di dalem grupnya)
struct ToDoItem {
    string task;
    bool done;
    ToDoItem* next; // Linked List item dalam grup
};

// testing 
// Struct Grup To-Do lisnya 
struct ToDoGroup {
    string groupName;
    string groupDate;
    ToDoItem* headItem; // Pointer ke linked list item
    ToDoGroup* next;    // Linked List antar grup
};

// Head dari linked list grup
ToDoGroup* headGroup = nullptr;

// ===================== FUNGSI-FUNGSI ==========================

// Tambahkan grup baru ke daftar
void addGroup(string name, string date) {
    // Buat node grup baru
    // Tambahkan ke linked list grup
}

// Tambahkan to-do item ke grup tertentu
void addToDoItem(string groupName, string task) {
    // Cari grup dengan nama tertentu
    // Tambahkan item ke linked list item pada grup
}

// Hapus seluruh grup beserta semua list di dalamnya
void deleteGroup(string groupName) {
    // Cari grup
    // Hapus semua item dalam grup
    // Hapus grup dari linked list grup
}

// Hapus satu item dalam grup
void deleteItem(string groupName, string task) {
    // Cari grup
    // Cari item berdasarkan nama
    // Hapus item dari linked list
}

// Checklist tugas
void checkItem(string groupName, string task) {
    // Cari grup dan item
    // Ubah status 'done' jadi true
}

// Tampilkan seluruh grup dan to-do list-nya
void displayAll() {
    // Looping seluruh grup
    // Looping seluruh item dalam grup
    // Tampilkan status checklist
}

// Urutkan to-do list dalam grup berdasarkan abjad
void sortItems(string groupName) {
    // Gunakan bubble sort atau lainnya
    // Urutkan berdasarkan nama task
}

// Cari grup berdasarkan nama (menggunakan searching)
ToDoGroup* searchGroup(string name) {
    // Linear search dalam linked list grup
    return nullptr;
}

// =============================================================

int main() {
    // Menu utama akan dibuat di sini
    // Panggil fungsi-fungsi di atas sesuai pilihan user

    return 0;
}
