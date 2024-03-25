/* Create by Oksa Bayu Widrian
    23343080 Padang State University*/
#include <stdio.h>
#include <conio.h>

// Menggunakan typedef untuk memberikan alias pada tipe data int dan char
typedef int angka;
typedef char huruf;

int main() {
    // Mendeklarasikan variabel umur dengan tipe angka
    angka umur;

    // Mendeklarasikan variabel h dengan tipe huruf
    huruf h;

    // Mendeklarasikan array nama dengan tipe huruf dan panjang 10
    huruf nama[10];

    // Meminta pengguna untuk memasukkan umur
    printf("Masukkan umur anda: ");
    scanf("%d", &umur);

    // Menampilkan umur yang dimasukkan pengguna
    printf("Umur anda adalah %d\n", umur);

    // Meminta pengguna untuk memasukkan satu huruf
    printf("Masukkan huruf: ");
    h = getch();
    printf("\nHuruf yang anda masukkan: %c\n", h);

    // Meminta pengguna untuk memasukkan nama
    printf("Masukkan nama: ");
    scanf("%s", nama);

    // Menampilkan nama yang dimasukkan pengguna
    printf("Nama anda: %s\n", nama);

    // Menunggu agar program tidak langsung keluar setelah dijalankan
    getch();

    return 0;
}

