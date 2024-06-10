/* Create By Oksa Bayu Widrian
    23343080 Padang state University */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Struktur untuk mendefinisikan simpul dalam daftar berantai ganda
struct doublelinkedlist {
    int data;                    // Data yang disimpan dalam simpul
    struct doublelinkedlist *next, *prev;  // Pointer ke simpul berikutnya dan sebelumnya
} *head, *tail, *current;       // Pointer ke kepala, ekor, dan simpul saat ini dalam daftar

// Fungsi untuk menyisipkan data di akhir daftar
void insertlast(int data) {
    current = (struct doublelinkedlist *) malloc(sizeof(struct doublelinkedlist)); // Alokasi memori untuk simpul baru
    current->data = data;              // Menginisialisasi data simpul
    current->prev = current->next = NULL; // Menetapkan pointer sebelumnya dan berikutnya sebagai NULL karena ini adalah simpul terakhir
    if (head == NULL) {                // Jika daftar kosong
        head = tail = current;         // Kepala dan ekor menunjuk ke simpul pertama
    } else {
        current->prev = tail;          // Menetapkan simpul sebelumnya ke ekor
        tail->next = current;          // Menghubungkan simpul terakhir dengan simpul baru
        tail = current;                // Menetapkan ekor ke simpul baru
    }
}

// Fungsi untuk menyisipkan data di awal daftar
void insertfirst(int data) {
    current = (struct doublelinkedlist *) malloc(sizeof(struct doublelinkedlist)); // Alokasi memori untuk simpul baru
    current->data = data;              // Menginisialisasi data simpul
    current->next = current->prev = NULL; // Menetapkan pointer sebelumnya dan berikutnya sebagai NULL karena ini adalah simpul pertama
    if (head == NULL) {                // Jika daftar kosong
        head = tail = current;         // Kepala dan ekor menunjuk ke simpul pertama
    } else {
        head->prev = current;          // Menetapkan simpul pertama sebelumnya ke simpul baru
        current->next = head;          // Menghubungkan simpul baru dengan simpul pertama
        head = current;                // Menetapkan kepala ke simpul baru
    }
}

// Fungsi untuk menyisipkan data di tengah daftar
void insertmid(int data) {
    if (head == NULL) {                // Jika daftar kosong
        insertfirst(data);             // Panggil fungsi untuk menyisipkan data di awal
    } else if (data < head->data) {    // Jika data baru lebih kecil dari data di kepala
        insertfirst(data);             // Panggil fungsi untuk menyisipkan data di awal
    } else if (data > tail->data) {    // Jika data baru lebih besar dari data di ekor
        insertlast(data);              // Panggil fungsi untuk menyisipkan data di akhir
    } else {
        current = (struct doublelinkedlist *) malloc(sizeof(struct doublelinkedlist)); // Alokasi memori untuk simpul baru
        current->data = data;          // Menginisialisasi data simpul
        current->next = current->prev = NULL; // Menetapkan pointer sebelumnya dan berikutnya sebagai NULL karena ini adalah simpul baru
        struct doublelinkedlist *temp = head; // Pointer sementara untuk traversing daftar
        while (temp != NULL && temp->data < current->data) { // Mencari tempat yang sesuai untuk menyisipkan data baru
            temp = temp->next;
        }
        current->prev = temp->prev;     // Menetapkan simpul sebelumnya untuk simpul baru
        current->next = temp;           // Menetapkan simpul berikutnya untuk simpul baru
        temp->prev->next = current;     // Menghubungkan simpul sebelumnya dengan simpul baru
        temp->prev = current;           // Menghubungkan simpul berikutnya dengan simpul baru
    }
}

// Fungsi untuk menghapus data dari awal daftar
void deletefirst() {
    if (head == NULL) {                // Jika daftar kosong
        printf("No Data\n");           // Tampilkan pesan kesalahan
    } else if (head == tail) {         // Jika hanya ada satu simpul dalam daftar
        current = head;                // Simpan alamat simpul pertama dalam current
        head = tail = NULL;            // Atur kepala dan ekor menjadi NULL karena daftar kosong
        free(current);                 // Bebaskan memori yang dialokasikan untuk simpul pertama
    } else {
        current = head;                // Simpan alamat simpul pertama dalam current
        head = head->next;             // Pindahkan kepala ke simpul berikutnya
        head->prev = NULL;             // Atur pointer sebelumnya kepala menjadi NULL karena ini adalah simpul pertama baru
        free(current);                 // Bebaskan memori yang dialokasikan untuk simpul pertama
    }
}

// Fungsi untuk menghapus data dari akhir daftar
void deletelast() {
    if (head == NULL) {                // Jika daftar kosong
        printf("No Data\n");           // Tampilkan pesan kesalahan
    } else if (head == tail) {         // Jika hanya ada satu simpul dalam daftar
        current = tail;                // Simpan alamat simpul terakhir dalam current
        head = tail = NULL;            // Atur kepala dan ekor menjadi NULL karena daftar kosong
        free(current);                 // Bebaskan memori yang dialokasikan untuk simpul terakhir
    } else {
        current = tail;                // Simpan alamat simpul terakhir dalam current
        tail = tail->prev;             // Pindahkan ekor ke simpul sebelumnya
        tail->next = NULL;             // Atur pointer berikutnya ekor menjadi NULL karena ini adalah simpul terakhir baru
        free(current);                 // Bebaskan memori yang dialokasikan untuk simpul terakhir
    }
}

// Fungsi untuk menghapus data dari tengah daftar
void deletemid(int data) {
    int temu = 0;                     // Variabel untuk menandai apakah data yang akan dihapus ditemukan
    if (head == NULL) {                // Jika daftar kosong
        printf("No Data\n");           // Tampilkan pesan kesalahan
    } else {
        current = head;                // Mulai pencarian dari simpul pertama
        while (current != NULL) {       // Loop melalui daftar
            if (current->data == data) { //
                temu = 1;              // Tandai bahwa data ditemukan
                break;                  // Keluar dari loop
            }
            current = current->next;    // Pindah ke simpul berikutnya
        }
        if (temu == 1) {               // Jika data ditemukan
            if (current == head) {      // Jika data berada di simpul pertama
                deletefirst();         // Panggil fungsi untuk menghapus data dari awal
            } else if (current == tail) { // Jika data berada di simpul terakhir
                deletelast();          // Panggil fungsi untuk menghapus data dari akhir
            } else {
                current->prev->next = current->next; // Hubungkan simpul sebelumnya dengan simpul berikutnya
                current->next->prev = current->prev; // Hubungkan simpul berikutnya dengan simpul sebelumnya
                free(current);         // Bebaskan memori yang dialokasikan untuk simpul yang dihapus
            }
        } else {
            printf("Data Not Found\n"); // Tampilkan pesan kesalahan jika data tidak ditemukan
        }
    }
}

// Fungsi untuk menghapus semua data dari daftar
void deleteall() {
    while (head != NULL) {              // Selama daftar belum kosong
        deletefirst();                 // Panggil fungsi untuk menghapus data dari awal
    }
}

// Fungsi untuk mencetak semua data dalam daftar
void print() {
    current = head;                    // Mulai dari kepala
    if (current != NULL) {              // Jika daftar tidak kosong
        while (current != NULL) {       // Loop melalui daftar
            printf("Data %d\n", current->data); // Cetak data dari setiap simpul
            current = current->next;    // Pindah ke simpul berikutnya
        }
    } else {
        printf("No Data\n");           // Jika daftar kosong, tampilkan pesan ini
    }
}

// Fungsi utama program
int main() {
    // Contoh penggunaan fungsi-fungsi yang telah didefinisikan
    insertfirst(2);
    insertfirst(3);
    insertfirst(4);
    insertfirst(5);
    insertlast(6);
    insertmid(7);
    deletemid(7);
    //popMid(6);
    //popAll();
    print();                          // Cetak isi dari daftar
    getchar();                       // Menunggu masukan sebelum keluar dari program
    return 0;                        // Kembalikan nilai 0 untuk menandakan keluar dari program
}
// terjadi error karna tidak adanya struct pada baris 15, 29, 50. Pada penggunaan size of
