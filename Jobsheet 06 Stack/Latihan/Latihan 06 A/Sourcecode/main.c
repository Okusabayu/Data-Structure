/*  Create by Oksa Bayu Widrian
    23343080 Padang State University*/
#include <stdio.h>

#define MAXSIZE 8

int stack[MAXSIZE];
int top = -1;

// Fungsi untuk memeriksa apakah stack kosong
int isempty() {
    if (top == -1)
        return 1;
    else
        return 0;
}

// Fungsi untuk memeriksa apakah stack penuh
int isfull() {
    if (top == MAXSIZE - 1)
        return 1;
    else
        return 0;
}

// Fungsi untuk melihat elemen teratas dari stack
int peek() {
    return stack[top];
}

// Fungsi untuk menghapus elemen teratas dari stack
int pop() {
    int data;
    if (!isempty()) {
        data = stack[top];
        top = top - 1;
        return data;
    } else {
        printf("Tidak dapat mengambil data, Stack kosong.\n");
        return -1; // Menambahkan nilai default untuk menandai kegagalan
    }
}

// Fungsi untuk menambahkan elemen ke stack
void push(int data) {
    if (!isfull()) {
        top = top + 1;
        stack[top] = data;
    } else {
        printf("Tidak dapat menambahkan data. Stack penuh\n");
    }
}

int main() {
    // Menambahkan elemen ke dalam stack
    push(3);
    push(5);
    push(9);
    push(1);
    push(12);
    push(15);

    // Menampilkan elemen teratas pada stack
    printf("Elemen teratas pada Stack adalah: %d\n", peek());
    printf("Semua elemennya adalah: \n");

    // Mencetak semua elemen dalam stack dan memeriksa apakah stack kosong atau penuh
    while (!isempty()) {
        int data = pop();
        printf("%d\n", data);
        printf("Stack full: %s\n", isfull() ? "true" : "false");
        printf("Stack empty: %s\n", isempty() ? "true" : "false");
    }

    return 0;
}


