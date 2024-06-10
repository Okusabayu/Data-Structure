/* Create by Oksa Bayu Widrian
    23343080 Padang State University */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node untuk stack
struct Simpul {
    char data;
    struct Simpul* berikutnya;
};

// Inisialisasi stack kosong
struct Simpul* atas = NULL;

// Fungsi untuk menambahkan karakter ke dalam stack
void tambah(char data) {
    struct Simpul* simpulBaru = (struct Simpul*)malloc(sizeof(struct Simpul));
    simpulBaru->data = data;
    simpulBaru->berikutnya = atas;
    atas = simpulBaru;
}

// Fungsi untuk menghapus karakter dari stack (pop)
void hapus() {
    if (atas == NULL) {
        printf("Stack kosong.\n");
        return;
    }
    struct Simpul* temp = atas;
    atas = atas->berikutnya;
    free(temp);
}

// Fungsi untuk membaca input kata dari pengguna
void inputKata() {
    char kata[100];
    printf("Masukkan kata: ");
    scanf("%s", kata);
    int i = 0;
    while (kata[i] != '\0') {
        tambah(kata[i]);
        i++;
    }
}

// Fungsi untuk membalik kata menggunakan stack
void balikKata() {
    if (atas == NULL) {
        printf("Stack kosong.\n");
        return;
    }
    printf("Kata terbalik: ");
    while (atas != NULL) {
        printf("%c", atas->data);
        hapus();
    }
    printf("\n");
}

int main() {
    int pilihan;

    printf("Program Pembalik Kata Sederhana\n");
    printf("========================================\n");
    do {
        printf("\nMenu:\n");
        printf("1. Input Kata\n");
        printf("2. Balik Kata\n");
        printf("3. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                inputKata();
                break;
            case 2:
                balikKata();
                break;
            case 3:
                printf("Program selesai.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 3);

    return 0;
}
