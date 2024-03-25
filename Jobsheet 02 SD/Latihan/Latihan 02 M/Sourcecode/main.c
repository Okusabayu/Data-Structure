/* Created by Oksa Bayu Widrian
   23343080 Padang State University */

#include <stdio.h>

// Mendefinisikan struktur person untuk menyimpan informasi tentang usia dan berat seseorang
struct person {
    int age; // Variabel untuk menyimpan usia
    float weight; // Variabel untuk menyimpan berat
};

int main() {
    struct person *personPtr, person1; // Deklarasi pointer ke struct person dan variabel person1

    personPtr = &person1; // Menginisialisasi pointer personPtr dengan alamat dari variabel person1

    // Meminta pengguna memasukkan usia
    printf("Enter age: ");
    scanf("%d", &personPtr->age);

    // Meminta pengguna memasukkan berat
    printf("Enter weight: ");
    scanf("%f", &personPtr->weight);

    // Menampilkan informasi yang dimasukkan oleh pengguna
    printf("Displaying:\n");
    printf("Age: %d\n", personPtr->age); // Menampilkan usia
    printf("Weight: %.2f\n", personPtr->weight); // Menampilkan berat, diformat menjadi dua angka desimal

    return 0;
}

