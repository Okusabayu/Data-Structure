/* Create by Oksa Bayu Widrian
    23343080 Padang State University */
#include <stdio.h>
#include <stdlib.h>

// Struktur Node untuk Doubly Linked List
struct Node {
    int data;
    struct Node *next; // Pointer ke node berikutnya
    struct Node *prev; // Pointer ke node sebelumnya
};

// Fungsi untuk menambahkan node baru di depan daftar (push)
void push(struct Node** head_ref, int new_data) {
    // 1. Mengalokasikan memori untuk node baru
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    // 2. Memasukkan data ke dalam node baru
    new_node->data = new_data;
    // 3. Mengatur pointer next dari node baru ke head lama
    new_node->next = (*head_ref);
    // 4. Mengatur pointer prev dari node baru menjadi NULL
    new_node->prev = NULL;
    // 5. Jika head lama tidak kosong, mengatur pointer prev dari head lama ke node baru
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
    // 6. Memindahkan head ke node baru
    (*head_ref) = new_node;
}

// Fungsi untuk menambahkan node baru di akhir daftar (append)
void append(struct Node** head_ref, int new_data) {
    // 1. Mengalokasikan memori untuk node baru
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    // 2. Menginisialisasi pointer last untuk menemukan node terakhir
    struct Node* last = *head_ref;
    // 3. Memasukkan data ke dalam node baru
    new_node->data = new_data;
    // 4. Mengatur pointer next dari node baru menjadi NULL karena ini akan menjadi node terakhir
    new_node->next = NULL;
    // 5. Jika daftar kosong, mengatur node baru sebagai head
    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }
    // 6. Menemukan node terakhir dan mengatur pointer nextnya ke node baru
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    // 7. Mengatur pointer prev dari node baru ke node terakhir
    new_node->prev = last;
}

// Fungsi untuk mencetak isi Doubly Linked List
void printList(struct Node* node) {
    // Pointer last digunakan untuk menyimpan alamat node terakhir
    struct Node* last;
    // Traversal maju
    printf("\nTraversal in forward direction: ");
    while (node != NULL) {
        printf("%d ", node->data);
        last = node;
        node = node->next;
    }
    // Traversal mundur
    printf("\nTraversal in reverse direction: ");
    while (last != NULL) {
        printf("%d ", last->data);
        last = last->prev;
    }
}

// Fungsi utama
int main() {
    struct Node* head = NULL;

    // Menambahkan beberapa elemen ke Doubly Linked List
    append(&head, 6);
    push(&head, 7);
    push(&head, 1);
    append(&head, 4);

    // Mencetak Doubly Linked List
    printf("Created Doubly Linked List: ");
    printList(head);

    return 0;
}

