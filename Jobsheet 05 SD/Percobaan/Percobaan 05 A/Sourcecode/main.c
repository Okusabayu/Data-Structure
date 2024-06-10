/* Create By Oksa Bayu Widrian
    23343080 Padang state University */
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;           // Data yang disimpan dalam simpul
    struct node *next;  // Pointer ke simpul berikutnya
    struct node *back;  // Pointer ke simpul sebelumnya
};

struct node *head = NULL;   // Pointer ke simpul pertama dalam daftar
struct node *tail = NULL;   // Pointer ke simpul terakhir dalam daftar
struct node *current;       // Pointer sementara untuk penanganan saat ini

int main() {
    // Membuat simpul baru
    current = (struct node *) malloc(sizeof(struct node));
    current->data = 1;      // Menginisialisasi data simpul
    current->next = NULL;   // Pointer berikutnya ditetapkan sebagai NULL karena ini adalah simpul terakhir
    current->back = NULL;   // Pointer sebelumnya ditetapkan sebagai NULL karena ini adalah simpul pertama

    // Menetapkan kepala dan ekor ke simpul pertama
    head = tail = current;

    return 0;
}

