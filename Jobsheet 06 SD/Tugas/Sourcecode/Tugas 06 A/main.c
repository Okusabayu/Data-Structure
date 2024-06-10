/* Create by Oksa Bayu Widrian
    23343080 Padang State University */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur untuk menyimpan data mahasiswa
struct Mahasiswa {
    char nim[15];
    char nama[100];
    float nilai;
};

// Node untuk stack
struct Simpul {
    struct Mahasiswa data;
    struct Simpul* berikutnya;
};

// Inisialisasi stack kosong
struct Simpul* atas = NULL;

// Fungsi untuk menambahkan data ke dalam stack
void tambah(struct Mahasiswa data) {
    struct Simpul* simpulBaru = (struct Simpul*)malloc(sizeof(struct Simpul));
    simpulBaru->data = data;
    simpulBaru->berikutnya = atas;
    atas = simpulBaru;
}

// Fungsi untuk menghapus data dari stack (pop)
void hapus() {
    if (atas == NULL) {
        printf("Stack kosong.\n");
        return;
    }
    struct Simpul* temp = atas;
    atas = atas->berikutnya;
    free(temp);
}

// Fungsi untuk menampilkan data dalam stack
void tampilkan() {
    if (atas == NULL) {
        printf("Stack kosong.\n");
        return;
    }
    printf("Data Nilai Mahasiswa:\n");
    struct Simpul* saatIni = atas;
    while (saatIni != NULL) {
        printf("NIM: %s, Nama: %s, Nilai: %.2f\n", saatIni->data.nim, saatIni->data.nama, saatIni->data.nilai);
        saatIni = saatIni->berikutnya;
    }
}

// Fungsi untuk membandingkan dua nilai float (digunakan dalam sorting)
int bandingkan(const void *a, const void *b) {
    return (*(float*)a - *(float*)b);
}

// Fungsi untuk melakukan sorting pada nilai mahasiswa dalam stack
void urutkan() {
    if (atas == NULL) {
        printf("Stack kosong.\n");
        return;
    }
    int jumlah = 0;
    struct Simpul* saatIni = atas;
    while (saatIni != NULL) {
        jumlah++;
        saatIni = saatIni->berikutnya;
    }
    float* nilaiArray = (float*)malloc(jumlah * sizeof(float));
    saatIni = atas;
    int i = 0;
    while (saatIni != NULL) {
        nilaiArray[i++] = saatIni->data.nilai;
        saatIni = saatIni->berikutnya;
    }
    qsort(nilaiArray, jumlah, sizeof(float), bandingkan);
    saatIni = atas;
    i = 0;
    while (saatIni != NULL) {
        saatIni->data.nilai = nilaiArray[i++];
        saatIni = saatIni->berikutnya;
    }
    free(nilaiArray);
}

// Fungsi untuk membersihkan seluruh stack
void bersihkanStack() {
    while (atas != NULL) {
        hapus();
    }
}

int main() {
    int pilihan;
    printf("Program Data Nilai Mahasiswa\n");
    printf("============================================\n");
    do {
        printf("\nMenu:\n");
        printf("1. Tambah Data Nilai Mahasiswa\n");
        printf("2. Hapus Data Teratas\n");
        printf("3. Tampilkan Data Nilai Mahasiswa\n");
        printf("4. Urutkan Data Nilai Mahasiswa\n");
        printf("5. Hapus Semua Data\n");
        printf("6. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1: {
                struct Mahasiswa mahasiswaBaru;
                printf("Masukkan NIM: ");
                scanf("%s", mahasiswaBaru.nim);
                printf("Masukkan Nama: ");
                scanf("%s", mahasiswaBaru.nama);
                printf("Masukkan Nilai: ");
                scanf("%f", &mahasiswaBaru.nilai);
                tambah(mahasiswaBaru);
                break;
            }
            case 2:
                hapus();
                break;
            case 3:
                tampilkan();
                break;
            case 4:
                urutkan();
                printf("Data Nilai Mahasiswa telah diurutkan.\n");
                break;
            case 5:
                bersihkanStack();
                printf("Semua Data Nilai Mahasiswa telah dihapus.\n");
                break;
            case 6:
                printf("Program selesai.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 6);

    return 0;
}

