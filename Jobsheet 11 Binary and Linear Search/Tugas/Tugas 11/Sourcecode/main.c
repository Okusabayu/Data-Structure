/* Created by Oksa Bayu Widrian
    23343080 Padang State Univerity */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int NIM;
    char Nama[50];
    char TTL[50];
    float IPK;
} Mahasiswa;

void tambahData(Mahasiswa mahasiswa[], int *count) {
    printf("Masukkan NIM: ");
    scanf("%d", &mahasiswa[*count].NIM);
    getchar();  // Menghapus newline setelah input NIM
    printf("Masukkan Nama: ");
    fgets(mahasiswa[*count].Nama, sizeof(mahasiswa[*count].Nama), stdin);
    mahasiswa[*count].Nama[strcspn(mahasiswa[*count].Nama, "\n")] = '\0'; // Menghapus karakter newline
    printf("Masukkan TTL: ");
    fgets(mahasiswa[*count].TTL, sizeof(mahasiswa[*count].TTL), stdin);
    mahasiswa[*count].TTL[strcspn(mahasiswa[*count].TTL, "\n")] = '\0'; // Menghapus karakter newline
    printf("Masukkan IPK: ");
    scanf("%f", &mahasiswa[*count].IPK);
    (*count)++;
}

void tampilkanData(Mahasiswa mahasiswa[], int count) {
    if (count == 0) {
        printf("Tidak ada data yang tersedia.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("\nNIM: %d", mahasiswa[i].NIM);
        printf("\nNama: %s", mahasiswa[i].Nama);
        printf("\nTTL: %s", mahasiswa[i].TTL);
        printf("\nIPK: %.2f\n", mahasiswa[i].IPK);
    }
}

void sequentialSearch(Mahasiswa mahasiswa[], int count, int NIM) {
    for (int i = 0; i < count; i++) {
        if (mahasiswa[i].NIM == NIM) {
            printf("\nData ditemukan:\n");
            printf("NIM: %d\nNama: %s\nTTL: %s\nIPK: %.2f\n", mahasiswa[i].NIM, mahasiswa[i].Nama, mahasiswa[i].TTL, mahasiswa[i].IPK);
            return;
        }
    }
    printf("Data dengan NIM %d tidak ditemukan.\n", NIM);
}

int compare(const void *a, const void *b) {
    Mahasiswa *mahasiswaA = (Mahasiswa *)a;
    Mahasiswa *mahasiswaB = (Mahasiswa *)b;
    return (mahasiswaA->NIM - mahasiswaB->NIM);
}

void binarySearch(Mahasiswa mahasiswa[], int count, int NIM) {
    int left = 0, right = count - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (mahasiswa[mid].NIM == NIM) {
            printf("\nData ditemukan:\n");
            printf("NIM: %d\nNama: %s\nTTL: %s\nIPK: %.2f\n", mahasiswa[mid].NIM, mahasiswa[mid].Nama, mahasiswa[mid].TTL, mahasiswa[mid].IPK);
            return;
        }
        if (mahasiswa[mid].NIM < NIM)
            left = mid + 1;
        else
            right = mid - 1;
    }
    printf("Data dengan NIM %d tidak ditemukan.\n", NIM);
}

int main() {
    Mahasiswa mahasiswa[100];
    int count = 0;
    int pilihan, NIM;

    printf("\n  Selamat Datang didalam Aplikasi");

    while (1) {
        printf("\n=====================================");
        printf("\nMenu:\n");
        printf("1. Tambah Data\n");
        printf("2. Tampilkan Data\n");
        printf("3. Pencarian Sequential\n");
        printf("4. Pencarian Binary\n");
        printf("5. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);
        getchar(); // Membuang karakter newline setelah input pilihan

        switch (pilihan) {
            case 1:
                tambahData(mahasiswa, &count);
                break;
            case 2:
                tampilkanData(mahasiswa, count);
                break;
            case 3:
                printf("Masukkan NIM yang ingin dicari: ");
                scanf("%d", &NIM);
                sequentialSearch(mahasiswa, count, NIM);
                break;
            case 4:
                qsort(mahasiswa, count, sizeof(Mahasiswa), compare);
                printf("Masukkan NIM yang ingin dicari: ");
                scanf("%d", &NIM);
                binarySearch(mahasiswa, count, NIM);
                break;
            case 5:
                exit(0);
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    }
    return 0;
}
