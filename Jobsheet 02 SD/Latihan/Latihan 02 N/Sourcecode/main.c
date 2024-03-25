/* Created by Oksa Bayu Widrian
   23343080 Padang State University */
#include<stdio.h>
#include<conio.h>

int main() {
    int usia1 = 50;
    int usia2 = 18;

    // Menciptakan sebuah pointer
    int *ptr;

    // Menugaskan pointer tersebut kepada usia1
    ptr = &usia1; // & adalah operator alamat

    printf("\nUsia saya (usia1): %d ", usia1); // Menampilkan 50
    printf("\nUsia saya (*ptr): %d", *ptr); // Menampilkan 50, *ptr merupakan nilai yang disimpan ptr, yaitu 50
    printf("\n(&usia1) %x (ptr) %x", &usia1, ptr);

    // Sekarang Anda akan menugaskannya kepada usia2
    ptr = &usia2;

    printf("\nUsia Anda (*ptr): %d", *ptr); // Menampilkan 18, *ptr merupakan nilai yang disimpan ptr, yaitu 18
    printf("\n(&usia2) %x (ptr) %x", &usia2, ptr);

    // Menampilkan alamat dari variabel ptr. Anda tidak memerlukan alamat ini.
    printf("\n(&ptr) %x", &ptr);

    getch();
    return 0;
}

