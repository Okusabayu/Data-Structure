/* Create by Oksa Bayu Widrian
    23343080 Padang State University*/
#include <stdio.h>
#include <stdlib.h>

// Mendefinisikan struktur ktp
typedef struct {
    char nama[25];
    int nik;
    char alamat[30];
    char status[25];
} ktp;

int main() {
    ktp myktp;

    // Meminta pengguna untuk memasukkan data
    printf("Nama\t: ");
    fgets(myktp.nama, sizeof(myktp.nama), stdin); // Menggunakan fgets untuk membaca string dari input, termasuk spasi
    fflush(stdin); // Membersihkan buffer stdin

    printf("NIK \t: ");
    scanf("%i", &myktp.nik);
    fflush(stdin); // Membersihkan buffer stdin

    printf("Alamat\t: ");
    fgets(myktp.alamat, sizeof(myktp.alamat), stdin); // Menggunakan fgets untuk membaca string dari input, termasuk spasi

    printf("Kewarganegaraan\t: ");
    fgets(myktp.status, sizeof(myktp.status), stdin); // Menggunakan fgets untuk membaca string dari input, termasuk spasi

    return 0;
}

