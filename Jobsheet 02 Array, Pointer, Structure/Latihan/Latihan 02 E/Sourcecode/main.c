/* Create by Oksa Bayu Widrian
    23343080 Padang State University*/
#include <stdio.h>
#include <string.h> // Menyertakan header file string.h untuk menggunakan fungsi strcpy()

// Mendefinisikan struktur Mahasiswa
struct Mahasiswa {
    char nama[50];
    char jurusan[50];
    int nilai;
};

int main(void) {
    // Mendefinisikan variabel mhs01 sebagai instance dari struktur Mahasiswa
    struct Mahasiswa mhs01;

    // Menginisialisasi atribut-atribut mhs01 menggunakan fungsi strcpy() dan operator assignment
    strcpy(mhs01.nama, "Oksa Bayu");
    strcpy(mhs01.jurusan, "Teknik Informatika");
    mhs01.nilai = 100;

    // Mencetak informasi mahasiswa menggunakan printf()
    printf("%s adalah mahasiswa jurusan %s\n", mhs01.nama, mhs01.jurusan);
    printf("Memperoleh nilai UAS %d\n", mhs01.nilai);

    return 0;
}
