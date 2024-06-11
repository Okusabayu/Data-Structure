/* Create by Oksa Bayu Widrian
    23343080 Padang State University*/
#include <stdio.h>
#include <stdlib.h>

// Mendefinisikan struktur Node untuk merepresentasikan simpul dalam linked list
struct Node {
    int data;           // Menyimpan data dalam simpul
    struct Node *next;  // Menunjuk ke simpul berikutnya dalam linked list
};

// Fungsi untuk menambahkan simpul baru di awal linked list
void push(struct Node** head_ref, int new_data) {
    // Mengalokasikan memori untuk simpul baru
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    // Memeriksa apakah alokasi memori berhasil
    if (new_node == NULL) {
        printf("Memory allocation failed");
        return;
    }

    // Mengisi data dan pointer next pada simpul baru
    new_node->data = new_data;
    new_node->next = (*head_ref);

    // Mengubah pointer head menjadi simpul baru
    (*head_ref) = new_node;
}

// Fungsi untuk mencetak isi linked list
void printList(struct Node *node) {
    // Selama simpul yang ditunjuk tidak NULL, cetak data dan lanjutkan ke simpul berikutnya
    while (node != NULL) {
        printf(" %d ", node->data); // Cetak data dari simpul saat ini
        node = node->next; // Pindah ke simpul berikutnya
    }
}

int main() {
    // Deklarasi pointer untuk simpul pertama dalam linked list
    struct Node* head = NULL;

    // Memanggil fungsi push untuk menambahkan simpul baru di awal linked list
    push(&head, 7);
    push(&head, 1);

    // Mencetak isi linked list
    printf("\nCreated Linked list is: ");
    printList(head);

    return 0;
}

