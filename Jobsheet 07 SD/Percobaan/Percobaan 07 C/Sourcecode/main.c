/*  Create by Oksa Bayu Widrian
    23343080 Padang State University*/
#include <stdio.h>
#define ukuran 6

int queue[ukuran]; // Deklarasi array untuk circular queue
int front = -1;
int rear = -1;

// Fungsi untuk menambahkan elemen pada circular queue
void enqueue(int element) {
    if (front == -1 && rear == -1) { // Cek apakah queue kosong
        front = 0;
        rear = 0;
        queue[rear] = element;
    } else if ((rear + 1) % ukuran == front) { // Cek apakah queue penuh
        printf("Antrian telah penuh..\n");
    } else {
        rear = (rear + 1) % ukuran; // Perbarui rear
        queue[rear] = element; // Tambahkan elemen pada posisi rear
    }
}

// Fungsi untuk menghapus elemen dari queue
void dequeue() {
    if (front == -1 && rear == -1) { // Cek apakah queue kosong
        printf("\nQueue belum penuh..\n");
    } else if (front == rear) { // Hanya satu elemen di queue
        printf("\nElemen yang di-dequeue adalah %d\n", queue[front]);
        front = -1;
        rear = -1;
    } else {
        printf("\nElemen yang di-dequeue adalah %d\n", queue[front]);
        front = (front + 1) % ukuran; // Perbarui front
    }
}

// Fungsi untuk menampilkan elemen queue
void display() {
    int i = front;
    if (front == -1 && rear == -1) {
        printf("\nQueue kosong!!\n");
    } else {
        printf("\nElemen pada queue adalah : ");
        while (i <= rear) {
            printf("%d, ", queue[i]);
            i = (i + 1) % ukuran;
        }
        //printf("%d\n", queue[rear]); // Print elemen terakhir
    }
}

int main() {
    int menu = 1, x; // Deklarasi variabel
    while (menu < 4 && menu != 0) { // Looping menggunakan while
        printf("\n****************Circular Queue********************\n");
        printf("\n==================================================\n");
        printf("\n1: Tambah sebuah elemen");
        printf("\n2: Hapus sebuah elemen");
        printf("\n3: Tampilkan sebuah elemen");
        printf("\nMasukkan pilihanmu! ");
        scanf("%d", &menu);
        switch (menu) {
            case 1:
                printf("Silakan masukkan elemen yang ingin kamu tambahkan: ");
                scanf("%d", &x);
                enqueue(x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
        }
    }
    return 0;
}

