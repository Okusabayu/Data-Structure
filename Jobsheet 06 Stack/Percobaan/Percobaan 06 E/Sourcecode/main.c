/*  Create by Oksa Bayu Widrian
    23343080 Padang State University*/
#include<stdio.h>
#define MAX 5

// Deklarasi Double Stack
typedef struct
{
    int atas1; // Indeks atas Stack1
    int atas2; // Indeks atas Stack2
    int ele[MAX]; // Array untuk menyimpan elemen-elemen stack
} DoubleStack;

// Menginisialisasi Double Stack
void init(DoubleStack *s)
{
    s->atas1 = -1; // Inisialisasi atas1 ke nilai -1 menunjukkan Stack1 kosong
    s->atas2 = MAX; // Inisialisasi atas2 ke nilai MAX menunjukkan Stack2 kosong
}

// Fungsi Push pada Stack1
void pushA(DoubleStack *s, int item)
{
    if (s->atas2 == s->atas1 + 1)
    {
        printf("\nStack Overflow Stack1"); // Jika indeks atas Stack1 bersentuhan dengan indeks atas Stack2, maka Stack1 penuh
        return;
    }
    s->atas1++; // Naikkan indeks atas Stack1
    s->ele[s->atas1] = item; // Simpan item pada indeks atas Stack1
    printf("\nItem ditambah pada Stack1: %d", item);
}

// Fungsi Push pada Stack2
void pushB(DoubleStack *s, int item)
{
    if (s->atas2 == s->atas1 + 1)
    {
        printf("\nStack Overflow Stack2"); // Jika indeks atas Stack2 bersentuhan dengan indeks atas Stack1, maka Stack2 penuh
        return;
    }
    s->atas2--; // Turunkan indeks atas Stack2
    s->ele[s->atas2] = item; // Simpan item pada indeks atas Stack2
    printf("\nItem ditambah pada Stack2: %d", item);
}

// Fungsi Pop pada Stack1
int popA(DoubleStack *s, int *item)
{
    if (s->atas1 == -1)
    {
        printf("\nStack Underflow Stack1"); // Jika indeks atas Stack1 bernilai -1, maka Stack1 kosong
        return -1;
    }
    *item = s->ele[s->atas1--]; // Ambil item dari indeks atas Stack1 dan turunkan indeks atas Stack1
    return 0;
}

// Fungsi Pop pada Stack2
int popB(DoubleStack *s, int *item)
{
    if (s->atas2 == MAX)
    {
        printf("\nStack Underflow Stack2"); // Jika indeks atas Stack2 bernilai MAX, maka Stack2 kosong
        return -1;
    }
    *item = s->ele[s->atas2++]; // Ambil item dari indeks atas Stack2 dan naikkan indeks atas Stack2
    return 0;
}

int main()
{
    int item = 0;
    DoubleStack s;
    init(&s); // Inisialisasi Double Stack

    // Menambahkan beberapa elemen ke Stack1 dan Stack2
    pushB(&s, 10);
    pushA(&s, 20);
    pushA(&s, 30);
    pushB(&s, 40);
    pushB(&s, 50);
    pushB(&s, 60);

    // Menghapus dan menampilkan beberapa elemen dari Stack1 dan Stack2
    if (popA(&s, &item) == 0)
        printf("\nItem dihapus dari Stack1: %d", item);
    if (popA(&s, &item) == 0)
        printf("\nItem dihapus dari Stack1: %d", item);
    if (popA(&s, &item) == 0)
        printf("\nItem dihapus dari Stack1: %d", item);
    if (popB(&s, &item) == 0)
        printf("\nItem dihapus dari Stack2: %d", item);
    if (popB(&s, &item) == 0)
        printf("\nItem dihapus dari Stack2: %d", item);
    if (popB(&s, &item) == 0)
        printf("\nItem dihapus dari Stack2: %d", item);

    printf("\n");
    return 0;
}

