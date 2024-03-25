/* Create by Oksa Bayu Widrian
    23343080 Padang State University*/
#include <stdio.h>
#include <stdlib.h>

// Mendefinisikan struktur node untuk merepresentasikan simpul dalam linked list
struct node {
    int data;            // Menyimpan data dalam simpul
    struct node *next;   // Menunjuk ke simpul berikutnya dalam linked list
};

// Fungsi untuk mencetak isi linked list
void print(struct node *node) {
    while (node != NULL) {
        printf(" %d ", node->data); // Cetak data dari simpul saat ini
        node = node->next;          // Pindah ke simpul berikutnya
    }
}

int main() {
    struct node *head = NULL;    // Deklarasi pointer untuk simpul pertama dalam linked list
    struct node *second = NULL;  // Deklarasi pointer untuk simpul kedua dalam linked list
    struct node *third = NULL;   // Deklarasi pointer untuk simpul ketiga dalam linked list
    struct node *new_node = NULL; // Deklarasi pointer untuk simpul baru yang akan ditambahkan

    // Mengalokasikan memori untuk empat simpul dalam linked list menggunakan malloc
    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));
    new_node = (struct node*)malloc(sizeof(struct node));

    // Mengisi data dan pointer next pada masing-masing simpul
    head->data = 1;          // Data untuk simpul pertama
    head->next = second;     // Pointer next dari simpul pertama menunjuk ke simpul kedua
    second->data = 2;        // Data untuk simpul kedua
    second->next = third;    // Pointer next dari simpul kedua menunjuk ke simpul ketiga
    third->data = 3;         // Data untuk simpul ketiga
    third->next = NULL;      // Pointer next dari simpul ketiga menunjuk ke NULL, menandakan akhir dari linked list

    // Menambahkan simpul baru di awal linked list
    new_node->data = 4;      // Data untuk simpul baru
    new_node->next = head;   // Pointer next dari simpul baru menunjuk ke simpul pertama
    head = new_node;         // Simpul baru ditetapkan sebagai simpul pertama

    // Memanggil fungsi print untuk mencetak isi linked list
    print(head);

    return 0;
}
