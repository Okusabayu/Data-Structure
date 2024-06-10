/*  Create by Oksa Bayu Widrian
    23343080 Padang State University*/
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// Struktur untuk merepresentasikan stack
struct Stack {
    int atas; // Menunjukkan indeks atas stack
    unsigned kapasitas; // Menyimpan kapasitas maksimum stack
    int* array; // Array untuk menyimpan elemen stack
};

// Fungsi untuk membuat stack dengan kapasitas yang diberikan
struct Stack* buatStack(unsigned kapasitas)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack)); // Alokasi memori untuk stack
    stack->kapasitas = kapasitas; // Set kapasitas stack
    stack->atas = -1; // Atas stack diinisialisasi dengan -1 karena stack kosong
    stack->array = (int*)malloc(stack->kapasitas * sizeof(int)); // Alokasi memori untuk array penyimpan elemen stack
    return stack;
}

// Fungsi untuk mengecek apakah stack penuh
int isFull(struct Stack* stack)
{
    return stack->atas == stack->kapasitas - 1; // Stack penuh jika indeks atas sama dengan kapasitas - 1
}

// Fungsi untuk mengecek apakah stack kosong
int isEmpty(struct Stack* stack)
{
    return stack->atas == -1; // Stack kosong jika indeks atas sama dengan -1
}

// Fungsi push untuk menambahkan elemen ke stack
void push(struct Stack* stack, int item)
{
    if (isFull(stack)) // Cek jika stack penuh
        return;
    stack->array[++stack->atas] = item; // Tambahkan elemen dan naikkan indeks atas
    printf("%d ditambahkan ke stack\n", item);
}

// Fungsi pop untuk menghapus elemen dari stack
int pop(struct Stack* stack)
{
    if (isEmpty(stack)) // Cek jika stack kosong
        return INT_MIN;
    return stack->array[stack->atas--]; // Kurangi indeks atas dan kembalikan elemen pada indeks sebelumnya
}

// Fungsi peek untuk mendapatkan elemen teratas dari stack tanpa menghapusnya
int peek(struct Stack* stack)
{
    if (isEmpty(stack)) // Cek jika stack kosong
        return INT_MIN;
    return stack->array[stack->atas]; // Kembalikan elemen teratas stack
}

// Fungsi main untuk mengetes fungsi-fungsi di atas
int main()
{
    struct Stack* stack = buatStack(100); // Buat stack dengan kapasitas 100
    push(stack, 10); // Tambahkan elemen 10 ke stack
    push(stack, 20); // Tambahkan elemen 20 ke stack
    push(stack, 30); // Tambahkan elemen 30 ke stack
    printf("%d dihapus dari stack\n", pop(stack)); // Hapus dan cetak elemen teratas dari stack
    return 0;
}

