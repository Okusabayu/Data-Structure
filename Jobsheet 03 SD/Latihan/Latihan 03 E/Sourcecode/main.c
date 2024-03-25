/* Create by Oksa Bayu Widrian
    23343080 Padang State University*/
#include <stdio.h>
#include <stdlib.h>

// Mendefinisikan struktur LinkedList untuk merepresentasikan simpul dalam linked list
typedef struct LinkedList {
    int data;                // Menyimpan data dalam simpul
    struct LinkedList* next; // Menunjuk ke simpul berikutnya dalam linked list
} node;

int main() {
    // Deklarasi dan inisialisasi pointer ke tiga simpul dalam linked list
    node* head = NULL;
    node* second = NULL;
    node* third = NULL;

    // Mengalokasikan memori untuk tiga simpul dalam linked list menggunakan malloc
    head = (node*)malloc(sizeof(node));
    second = (node*)malloc(sizeof(node));
    third = (node*)malloc(sizeof(node));

    // Mengisi data dan pointer next dari masing-masing simpul
    head->data = 1;          // Data untuk simpul pertama
    head->next = second;     // Pointer next dari simpul pertama menunjuk ke simpul kedua
    second->data = 2;        // Data untuk simpul kedua
    second->next = third;    // Pointer next dari simpul kedua menunjuk ke simpul ketiga
    third->data = 3;         // Data untuk simpul ketiga
    third->next = NULL;      // Pointer next dari simpul ketiga menunjuk ke NULL, menandakan akhir dari linked list

    // Menampilkan data dari simpul pertama
    printf("%d", head->data);

    return 0;
}
