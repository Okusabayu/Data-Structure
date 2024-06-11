/* Created by Oksa Bayu Widrian
   23343080 Padang State University */

#include <stdio.h>

// Mendefinisikan struktur complex untuk menyimpan bilangan kompleks
struct complex {
    int imag; // Bagian imajiner
    float real; // Bagian real
};

// Mendefinisikan struktur number yang berisi bilangan bulat dan bilangan kompleks
struct number {
    struct complex comp; // Menyimpan bilangan kompleks
    int integers; // Menyimpan bilangan bulat
} num1, num2;

// Nested struct level 1
struct level1 {
    struct number num; // Menyimpan sebuah number struct
};

// Nested struct level 2
struct level2 {
    struct level1 lvl1; // Menyimpan struct level1
};

// Nested struct level 3
struct level3 {
    struct level2 lvl2; // Menyimpan struct level2
};

// Nested struct level 4
struct level4 {
    struct level3 lvl3; // Menyimpan struct level3
};

// Nested struct level 5
struct level5 {
    struct level4 lvl4; // Menyimpan struct level4
};

int main() {
    // Deklarasi instance dari struct level5
    struct level5 lvl5_instance;

    return 0;
}
