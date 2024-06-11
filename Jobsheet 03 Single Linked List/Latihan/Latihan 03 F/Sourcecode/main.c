/* Create by Oksa Bayu Widrian
    23343080 Padang State University*/
#include <stdio.h>
#include <stdlib.h>

// Mendefinisikan struktur Node untuk merepresentasikan simpul dalam linked list
struct Node {
    int data;           // Menyimpan data dalam simpul
    struct Node* next;  // Menunjuk ke simpul berikutnya dalam linked list
};

// Fungsi untuk mencetak isi linked list
void printList(struct Node* n) {
    // Selama simpul yang ditunjuk tidak NULL, cetak data dan lanjutkan ke simpul berikutnya
    while (n != NULL) {
        printf(" %d ", n->data); // Cetak data dari simpul saat ini
        n = n->next; // Pindah ke simpul berikutnya
    }
}

int main() {
    // Deklarasi pointer untuk tiga simpul dalam linked list
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    // Mengalokasikan memori untuk tiga simpul menggunakan malloc
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    // Mengisi data dan pointer next dari masing-masing simpul
    head->data = 1;             // Data untuk simpul pertama
    head->next = second;        // Pointer next dari simpul pertama menunjuk ke simpul kedua
    second->data = 2;           // Data untuk simpul kedua
    second->next = third;       // Pointer next dari simpul kedua menunjuk ke simpul ketiga
    third->data = 3;            // Data untuk simpul ketiga
    third->next = NULL;         // Pointer next dari simpul ketiga menunjuk ke NULL, menandakan akhir dari linked list

    // Memanggil fungsi untuk mencetak isi linked list, dimulai dari simpul pertama
    printList(head);

    return 0;
}
