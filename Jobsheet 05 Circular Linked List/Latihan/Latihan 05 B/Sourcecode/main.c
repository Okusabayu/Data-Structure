/*  Create by Oksa Bayu Widrian
    23343080 Padang State University*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definisi struktur gudang untuk menyimpan informasi barang
struct gudang {
    char nama_barang[50]; // Nama barang
    int harga; // Harga barang
    struct gudang *next; // Pointer ke gudang berikutnya
    struct gudang *prev; // Pointer ke gudang sebelumnya
};

// Fungsi untuk mencetak elemen-elemen dalam gudang
void cetak(struct gudang *head)
{
    struct gudang *temp = head;
    printf("\n\nList elements are - \n");
    while (temp != NULL)
    {
        printf("%s = %d --->", temp->nama_barang, temp->harga);
        temp = temp->next;
    }
}

int main()
{
    struct gudang *head;
    struct gudang *one = NULL; // Node pertama
    struct gudang *two = NULL; // Node kedua
    struct gudang *three = NULL; // Node ketiga

    /* Allocate memory */
    one = (struct gudang *)malloc(sizeof(struct gudang)); // Allokasi memori untuk node pertama
    two = (struct gudang *)malloc(sizeof(struct gudang)); // Allokasi memori untuk node kedua
    three = (struct gudang *)malloc(sizeof(struct gudang)); // Allokasi memori untuk node ketiga

    /* Assign data values */
    one->harga = 1000; // Mengisi harga barang pada node pertama
    strcpy(one->nama_barang, "obat nyamuk"); // Mengisi nama barang pada node pertama
    two->harga = 5000; // Mengisi harga barang pada node kedua
    strcpy(two->nama_barang, "Gula 1 kilo"); // Mengisi nama barang pada node kedua
    three->harga = 50000; // Mengisi harga barang pada node ketiga
    strcpy(three->nama_barang, "Minyak Goreng"); // Mengisi nama barang pada node ketiga

    /* Connect nodes */
    one->next = two; // Menghubungkan node pertama dengan node kedua
    one->prev = NULL; // Node pertama tidak memiliki node sebelumnya
    two->next = three; // Menghubungkan node kedua dengan node ketiga
    two->prev = one; // Menghubungkan node kedua dengan node pertama
    three->next = NULL; // Node ketiga tidak memiliki node berikutnya
    three->prev = two; // Menghubungkan node ketiga dengan node kedua

    /* Save address of first node in head */
    head = one; // Menyimpan alamat node pertama dalam variabel head
    cetak(head); // Memanggil fungsi untuk mencetak elemen-elemen dalam gudang

    return 0;
}
