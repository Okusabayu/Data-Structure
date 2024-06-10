/*  Create by Oksa Bayu Widrian
    23343080 Padang State University*/
#include <stdio.h>
#include <stdlib.h>

// Mendefinisikan struktur node untuk daftar berantai
struct node
{
    int no_pol; // Nomor polisi
    struct node *next; // Pointer ke node berikutnya
};

// Fungsi untuk menampilkan isi daftar berantai
void display(struct node *head)
{
    struct node *temp = head;
    printf("\n\nUrutan parkiran: \n");
    while (temp != NULL)
    {
        printf("%d --->", temp->no_pol);
        temp = temp->next;
    }
}

// Fungsi untuk menyisipkan node baru di depan daftar
void insertAtFront(struct node **headRef, int value)
{
    struct node *head = *headRef;
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->no_pol = value;
    newNode->next = head;
    head = newNode;
    *headRef = head;
}

int main()
{
    struct node *head;
    struct node *avanza = NULL; // Node untuk Avanza
    struct node *hilux = NULL;  // Node untuk Hilux
    struct node *kijangF1 = NULL; // Node untuk Kijang F1

    // Allokasi memori untuk setiap node
    avanza = (struct node *)malloc(sizeof(struct node));
    hilux = (struct node *)malloc(sizeof(struct node));
    kijangF1 = (struct node *)malloc(sizeof(struct node));

    // Mengisi nomor polisi untuk setiap mobil
    avanza->no_pol = 1234;
    hilux->no_pol = 2345;
    kijangF1->no_pol = 3456;

    // Menghubungkan node-node untuk membentuk daftar berantai
    avanza->next = hilux;
    hilux->next = kijangF1;
    kijangF1->next = NULL;

    // Menyimpan alamat node pertama dalam variabel head
    head = avanza;

    // Menyisipkan nomor polisi baru di depan daftar
    insertAtFront(&head, 46543);

    // Menampilkan daftar parkir
    display(head);

    return 0;
}

