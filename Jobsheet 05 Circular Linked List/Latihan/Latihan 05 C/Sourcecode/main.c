/*  Create by Oksa Bayu Widrian
    23343080 Padang State University*/
#include <stdio.h>
#include <stdlib.h>

// Struktur dari sebuah node
struct Node
{
    int data;
    struct Node *next; // Pointer ke node selanjutnya
    struct Node *prev; // Pointer ke node sebelumnya
};

// Fungsi untuk menyisipkan node baru di akhir dari circular doubly linked list
void insertEnd(struct Node** start, int value)
{
    // Jika list kosong, buat satu node tunggal yang berbentuk circular dan doubly linked
    if (*start == NULL)
    {
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); // Alokasikan memori untuk node baru
        new_node->data = value; // Set data untuk node baru
        new_node->next = new_node->prev = new_node; // Buat node tersebut menunjuk ke dirinya sendiri
        *start = new_node; // Perbarui pointer start
        return;
    }

    // Jika list tidak kosong
    /* Temukan node terakhir */
    struct Node *last = (*start)->prev;

    // Buat node baru secara dinamis
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); // Alokasikan memori untuk node baru
    new_node->data = value; // Set data untuk node baru

    // Node baru akan menjadi next dari start
    new_node->next = *start;

    // Buat node baru menjadi previous dari start
    (*start)->prev = new_node;

    // Buat node baru menjadi previous dari yang terakhir
    new_node->prev = last;

    // Buat node baru menjadi next dari yang terakhir
    last->next = new_node;
}

// Fungsi untuk menampilkan circular doubly linked list
void display(struct Node* start)
{
    struct Node *temp = start;

    printf("\nTraversal in forward direction \n");
    while (temp->next != start)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d ", temp->data);

    printf("\nTraversal in reverse direction \n");
    struct Node *last = start->prev;
    temp = last;
    while (temp->prev != last)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("%d ", temp->data);
}

int main()
{
    /* Mulai dengan list yang kosong */
    struct Node* start = NULL;

    // Menyisipkan elemen ke dalam circular doubly linked list
    insertEnd(&start, 5);
    insertEnd(&start, 8);
    insertEnd(&start, 9);
    insertEnd(&start, 3);

    printf("Circular doubly linked list yang dibuat adalah: ");
    display(start); // Menampilkan circular doubly linked list

    return 0;
}

