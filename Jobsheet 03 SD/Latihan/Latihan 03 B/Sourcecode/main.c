/* Create by Oksa Bayu Widrian
    23343080 Padang State University*/
#include <stdio.h>
#include <stdlib.h>

// Mendefinisikan struktur node untuk representasi simpul dalam linked list
struct node {
    int data;           // Data yang disimpan di dalam simpul
    struct node *next;  // Pointer ke simpul berikutnya dalam linked list
};

int main() {
    // Deklarasi tiga pointer untuk menyimpan alamat dari tiga simpul dalam linked list
    struct node* head = NULL;
    struct node* second = NULL;
    struct node* third = NULL;

    // Mengalokasikan memori untuk tiga simpul dalam linked list menggunakan fungsi malloc
    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));

    // Mengisi data dan pointer next dari setiap simpul
    head->data = 1;         // Data simpul pertama
    head->next = second;    // Pointer next dari simpul pertama menunjuk ke simpul kedua
    second->data = 2;       // Data simpul kedua
    second->next = third;   // Pointer next dari simpul kedua menunjuk ke simpul ketiga
    third->data = 3;        // Data simpul ketiga
    third->next = NULL;     // Pointer next dari simpul ketiga menunjuk ke NULL, menandakan akhir dari linked list

    return 0;
}

