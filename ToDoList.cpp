#include <iostream>
#include <string>
using namespace std;

// Struct tugas di dalem grup nanti 
struct ToDoItem {
    string task;
    bool done;
    ToDoItem* next; // Linked List item dalam grup
};

// Struct Grup To-Do listnya 
struct ToDoGroup {
    string groupName;
    string groupDate;
    ToDoItem* headItem; // Pointer ke linked list item
    ToDoGroup* next;    // Linked List antar grup
};

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

// Head dari linked list grup
ToDoGroup* headGroup = nullptr;

// ===================== FUNGSI-FUNGSI ==========================

// Tambahkan grup baru ke daftar
void addGroup(string name, string date) {
    // Buat node grup baru
    // Tambahkan ke linked list grup

    // cek kodingan kodingan kemaren, kodinganya pasti mirip, bedanya cuman di variabel sama pointernya
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
    // Menu utama akan dibuat di sini
    // Panggil fungsi-fungsi di atas sesuai pilihan user

    // ini paling gampang, cuman ngeoutputin doang

    return 0;
}
