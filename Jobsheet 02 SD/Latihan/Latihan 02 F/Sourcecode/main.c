/* Create by Oksa Bayu Widrian
    23343080 Padang State University*/
#include <stdio.h>
#include <string.h>

// Mendefinisikan struktur Mahasiswa
struct Mahasiswa {
    char nama[50];
    char jurusan[50];
    int nilai;
};

// Menggunakan typedef untuk memberi alias pada struct Mahasiswa menjadi 'data'
typedef struct Mahasiswa data;

int main(void) {
    // Mendeklarasikan variabel mhs01 sebagai instance dari struct Mahasiswa (atau 'data')
    data mhs01;

    // Menginisialisasi atribut-atribut mhs01
    strcpy(mhs01.nama, "Oksa Bayu"); // Mengisi nama mahasiswa
    strcpy(mhs01.jurusan, "Teknik Informatika"); // Mengisi jurusan mahasiswa
    mhs01.nilai = 100; // Mengisi nilai mahasiswa

    // Mencetak informasi mahasiswa
    printf("%s adalah mahasiswa jurusan %s\n", mhs01.nama, mhs01.jurusan); // Mencetak nama dan jurusan
    printf("Memperoleh nilai UAS %d\n", mhs01.nilai); // Mencetak nilai UAS

    return 0;
}
