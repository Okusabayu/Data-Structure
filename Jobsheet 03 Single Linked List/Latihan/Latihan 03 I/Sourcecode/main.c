/* Create by Oksa Bayu Widrian
    23343080 Padang State University*/
#include <stdio.h>
#include <stdlib.h>

// Mendefinisikan struktur Node untuk merepresentasikan simpul dalam linked list
struct Node {
    int data;            // Menyimpan data dalam simpul
    struct Node *next;   // Menunjuk ke simpul berikutnya dalam linked list
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

// Fungsi untuk menambahkan simpul baru setelah simpul tertentu dalam linked list
void insertAfter(struct Node* prev_node, int new_data) {
    // Memeriksa apakah simpul sebelumnya yang diberikan tidak NULL
    if (prev_node == NULL) {
        printf("The given previous node cannot be NULL");
        return;
    }
    // Mengalokasikan memori untuk simpul baru
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    // Memeriksa apakah alokasi memori berhasil
    if (new_node == NULL) {
        printf("Memory allocation failed");
        return;
    }
    // Mengisi data dan pointer next pada simpul baru
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Fungsi untuk menambahkan simpul baru di akhir linked list
void append(struct Node** head_ref, int new_data) {
    // Mengalokasikan memori untuk simpul baru
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    // Memeriksa apakah alokasi memori berhasil
    if (new_node == NULL) {
        printf("Memory allocation failed");
        return;
    }
    struct Node *last = *head_ref;
    // Mengisi data dan pointer next pada simpul baru
    new_node->data = new_data;
    new_node->next = NULL;
    // Jika linked list kosong, simpul baru akan menjadi simpul pertama
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    // Menemukan simpul terakhir dalam linked list
    while (last->next != NULL)
        last = last->next;
    // Menyambungkan simpul baru ke simpul terakhir
    last->next = new_node;
}

// Fungsi untuk mencetak isi linked list
void printList(struct Node *node) {
    // Selama simpul yang ditunjuk tidak NULL, cetak data dan lanjutkan ke simpul berikutnya
    while (node != NULL) {
        printf(" %d ", node->data); // Cetak data dari simpul saat ini
        node = node->next;          // Pindah ke simpul berikutnya
    }
}

int main() {
    struct Node* head = NULL; // Deklarasi pointer untuk simpul pertama dalam linked list
    // Menambahkan simpul baru dengan nilai 6 di akhir linked list
    append(&head, 6);
    // Menambahkan simpul baru dengan nilai 7 di awal linked list
    push(&head, 7);
    // Menambahkan simpul baru dengan nilai 1 di awal linked list
    push(&head, 1);
    // Menambahkan simpul baru dengan nilai 4 di akhir linked list
    append(&head, 4);
    // Menambahkan simpul baru dengan nilai 8 setelah simpul kedua
    insertAfter(head->next, 8);
    // Mencetak isi linked list
    printf("\nCreated Linked list is: ");
    printList(head);
    return 0;
}

