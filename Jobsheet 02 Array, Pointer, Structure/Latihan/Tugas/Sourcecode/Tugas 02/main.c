/* Create by Oksa Bayu Widrian
    23343080 Padang State University */

#include <stdio.h>

// Definisi struct untuk data mahasiswa
struct Mahasiswa {
    int NIM;
    char Nama[50];
    char TanggalLahir[20];
    float IPK;
};

// Fungsi untuk menginput data mahasiswa
void inputMahasiswa(struct Mahasiswa *mhs) {
    printf("Input Data Mahasiswa\n");
    printf("Masukkan NIM               : ");
    scanf("%d", &mhs->NIM);

    printf("Masukkan Nama              : ");
    scanf(" %[^\n]s", mhs->Nama);

    printf("Tanggal Lahir (DD/MM/YYYY) : ");
    scanf(" %[^\n]s", mhs->TanggalLahir);

    printf("Masukkan IPK               : ");
    scanf("%f", &mhs->IPK);
}

// Fungsi untuk menampilkan data mahasiswa
void tampilkanMahasiswa(struct Mahasiswa mhs) {
    printf("\n=======================================\n");
    printf("\nData Mahasiswa\n");
    printf("NIM             : %d\n", mhs.NIM);
    printf("Nama            : %s\n", mhs.Nama);
    printf("Tanggal Lahir   : %s\n", mhs.TanggalLahir);
    printf("IPK             : %.2f\n", mhs.IPK);
}

int main() {
    struct Mahasiswa mhs;

    // Input data mahasiswa
    inputMahasiswa(&mhs);

    // Tampilkan data mahasiswa
    tampilkanMahasiswa(mhs);

    return 0;
}

