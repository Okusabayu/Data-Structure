/*  Create by Oksa Bayu Widrian
    23343080 Padang State University*/
#include<stdio.h>
#define ukuran 5 // Ukuran maksimum antrian

void enQueue(int);
void deQueue();
void tampilkan();

int items[ukuran], depan = -1, belakang = -1; // Variabel global untuk mewakili antrian

int main() {
    // Menghapus elemen dari antrian kosong
    deQueue();
    // Menambahkan elemen ke antrian
    enQueue(7);
    enQueue(8);
    enQueue(3);
    enQueue(4);
    enQueue(9);
    enQueue(6);
    // Menampilkan elemen dalam antrian
    tampilkan();
    // Menghapus elemen dari antrian
    deQueue();
    // Menampilkan elemen dalam antrian setelah penghapusan
    tampilkan();
    return 0;
}

// Fungsi untuk menambahkan elemen ke antrian
void enQueue(int value) {
    if (belakang == ukuran - 1)
        printf("\nQueue telah penuh!");
    else {
        if (depan == -1)
            depan = 0;
        belakang++;
        items[belakang] = value;
        printf("\nNilai ditambahkan -> %d", value);
    }
}

// Fungsi untuk menghapus elemen dari antrian
void deQueue() {
    if (depan == -1)
        printf("\nQueue kosong!!");
    else {
        printf("\nNilai dihapus adalah : %d", items[depan]);
        depan++;
        if (depan > belakang)
            depan = belakang = -1;
    }
}

// Fungsi untuk menampilkan elemen dalam antrian
void tampilkan() {
    if (belakang == -1)
        printf("\nQueue kosong!!!");
    else {
        int i;
        printf("\nElemen pada Queue adalah:\n");
        for (i = depan; i <= belakang; i++)
            printf("%d\t", items[i]);
    }
}

