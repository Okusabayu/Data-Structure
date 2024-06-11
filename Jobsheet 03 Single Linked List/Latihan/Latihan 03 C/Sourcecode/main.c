/* Create by Oksa Bayu Widrian
    23343080 Padang State University*/
#include <stdio.h>
#include <stdlib.h>

// Mendefinisikan struktur LinkedList untuk merepresentasikan simpul dalam linked list
struct LinkedList {
    int data;                // Menyimpan data dalam simpul
    struct LinkedList *next; // Menunjuk ke simpul berikutnya dalam linked list
};

// Memberikan alias "node" untuk "struct LinkedList"
typedef struct LinkedList node;

// Mendeklarasikan tiga pointer untuk menyimpan alamat tiga simpul dalam linked list
node *head = NULL;
node *second = NULL;
node *third = NULL;

int main() {
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

    return 0;
}

