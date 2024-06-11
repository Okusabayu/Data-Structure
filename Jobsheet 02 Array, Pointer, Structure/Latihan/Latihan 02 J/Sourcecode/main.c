/* Create by Oksa Bayu Widrian
    23343080 Padang State University*/
#include <stdio.h>

// Mendefinisikan struktur jam
typedef struct {
    int HH, MM, SS; // Variabel untuk menyimpan jam, menit, dan detik
} jam;

// Fungsi untuk menampilkan jam
void tampil(jam j) {
    printf("JAM %02d:%02d:%02d\n", j.HH, j.MM, j.SS); // Menggunakan format %02d untuk memastikan format dua digit dengan leading zero
}

// Fungsi untuk memeriksa validitas jam
int valid(jam j) {
    return j.HH >= 0 && j.HH <= 23 // Memeriksa jam (0-23)
        && j.MM >= 0 && j.MM <= 59 // Memeriksa menit (0-59)
        && j.SS >= 0 && j.SS <= 59; // Memeriksa detik (0-59)
}

// Fungsi untuk input jam dari pengguna
jam input() {
    jam j;
    do {
        printf("Masukkan Jam (0-23): ");
        scanf("%d", &j.HH);
        printf("Masukkan Menit (0-59): ");
        scanf("%d", &j.MM);
        printf("Masukkan Detik (0-59): ");
        scanf("%d", &j.SS);
    } while (!valid(j)); // Mengulangi input jika jam tidak valid
    return j;
}

int main() {
    jam j;
    j = input(); // Memanggil fungsi input untuk mendapatkan jam dari pengguna
    tampil(j); // Menampilkan jam yang dimasukkan oleh pengguna
    return 0;
}

