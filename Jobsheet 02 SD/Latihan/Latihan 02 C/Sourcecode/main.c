/* Create by Oksa Bayu Widrian
    23343080 Padang State University*/
#include <stdio.h>

int main() {
    int n;

    int angka[100]; //ukuran array bisa disesuaikan sesuai kebutuhan, misalnya 100

    printf("Masukkan banyaknya bilangan: ");  // Meminta pengguna untuk memasukkan banyaknya bilangan
    scanf("%d", &n);

    // Meminta pengguna untuk memasukkan setiap bilangan dan menyimpannya ke dalam array angka
    for(int i = 0; i < n; i++) {
        printf("Masukkan angka ke %d: ", i + 1);
        scanf("%d", &angka[i]);
    }

    printf("Bilangan yang dimasukkan:\n"); // Mencetak setiap bilangan yang telah dimasukkan pengguna
    for(int i = 0; i < n; i++) {
        printf("Angka ke %d: %d\n", i + 1, angka[i]);
    }

    getchar(); // Menunggu input dari pengguna agar program tidak langsung keluar

    return 0;
}



