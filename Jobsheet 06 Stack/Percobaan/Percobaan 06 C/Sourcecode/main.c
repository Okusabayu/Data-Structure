/*  Create by Oksa Bayu Widrian
    23343080 Padang State University*/
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// Struktur untuk merepresentasikan node pada stack
struct StackNode {
    int data; // Data yang disimpan pada node
    struct StackNode* next; // Pointer ke node selanjutnya
};

// Fungsi untuk membuat node baru pada stack dengan data yang diberikan
struct StackNode* newNode(int data) {
    struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode)); // Alokasi memori untuk node baru
    stackNode->data = data; // Set data pada node baru
    stackNode->next = NULL; // Atur pointer next menjadi NULL karena node baru akan menjadi paling atas pada stack
    return stackNode; // Kembalikan node baru
}

// Fungsi untuk mengecek apakah stack kosong
int isEmpty(struct StackNode* root) {
    return !root; // Stack kosong jika root adalah NULL
}

// Fungsi untuk menambahkan elemen ke atas stack
void push(struct StackNode** root, int data) {
    struct StackNode* stackNode = newNode(data); // Buat node baru dengan data yang diberikan
    stackNode->next = *root; // Atur pointer next dari node baru ke root
    *root = stackNode; // Atur root agar menunjuk ke node baru
    printf("%d ditambahkan ke stack\n", data);
}

// Fungsi untuk menghapus elemen dari atas stack
int pop(struct StackNode** root) {
    if (isEmpty(*root)) // Jika stack kosong
        return INT_MIN; // Kembalikan nilai INT_MIN yang menunjukkan bahwa operasi pop gagal
    struct StackNode* temp = *root; // Simpan root sementara
    *root = (*root)->next; // Pindahkan root ke node berikutnya
    int popped = temp->data; // Simpan data yang akan dihapus
    free(temp); // Bebaskan memori yang dialokasikan untuk node yang akan dihapus
    return popped; // Kembalikan data yang dihapus
}

// Fungsi untuk melihat elemen teratas stack tanpa menghapusnya
int peek(struct StackNode* root) {
    if (isEmpty(root)) // Jika stack kosong
        return INT_MIN; // Kembalikan nilai INT_MIN yang menunjukkan bahwa operasi peek gagal
    return root->data; // Kembalikan data dari node teratas stack
}

// Fungsi main untuk mengetes fungsi-fungsi di atas
int main() {
    struct StackNode* root = NULL; // Inisialisasi stack kosong

    // Menambahkan elemen ke stack
    push(&root, 10);
    push(&root, 20);
    push(&root, 30);

    // Menghapus dan menampilkan elemen teratas stack
    printf("%d dihapus dari stack\n", pop(&root));

    // Menampilkan elemen teratas stack tanpa menghapusnya
    printf("Elemen teratas (Top) adalah %d\n", peek(root));

    return 0;
}

