/* Create by Oksa Bayu Widrian
    23343080 Padang State University */
#include <stdio.h>
#include <stdlib.h>

// Maksimal jumlah simpul (node) dalam graf
#define MAX_SIMPUL 100

// Definisi struktur untuk simpul dalam graf
struct Simpul {
    int nomor;
    int terhubung[MAX_SIMPUL];
    int terhubung_count;
    int sudah_dikunjungi;
};

// Fungsi untuk menambahkan koneksi antara dua simpul dalam graf
void tambahKoneksi(struct Simpul graf[], int simpul1, int simpul2) {
    graf[simpul1].terhubung[graf[simpul1].terhubung_count++] = simpul2;
    graf[simpul2].terhubung[graf[simpul2].terhubung_count++] = simpul1;
}

// Fungsi untuk BFS
void BFS(struct Simpul graf[], int jumlah_simpul, int simpul_awal) {
    // Inisialisasi queue untuk menyimpan simpul yang akan dikunjungi
    int queue[MAX_SIMPUL];
    int depan = 0, belakang = 0;

    // Tambahkan simpul awal ke dalam queue dan tandai sebagai sudah dikunjungi
    queue[belakang++] = simpul_awal;
    graf[simpul_awal].sudah_dikunjungi = 1;

    // Selama queue tidak kosong
    while (depan != belakang) {
        // Ambil simpul dari depan queue
        int simpul_sekarang = queue[depan++];
        printf("%d ", simpul_sekarang);

        // Periksa semua simpul yang terhubung dengan simpul sekarang
        for (int i = 0; i < graf[simpul_sekarang].terhubung_count; i++) {
            int terhubung = graf[simpul_sekarang].terhubung[i];
            // Jika simpul belum pernah dikunjungi, tambahkan ke queue dan tandai sebagai sudah dikunjungi
            if (!graf[terhubung].sudah_dikunjungi) {
                queue[belakang++] = terhubung;
                graf[terhubung].sudah_dikunjungi = 1;
            }
        }
    }
}

int main() {
    // Inisialisasi graf
    struct Simpul graf[MAX_SIMPUL];
    for (int i = 0; i < MAX_SIMPUL; i++) {
        graf[i].nomor = i;
        graf[i].terhubung_count = 0;
        graf[i].sudah_dikunjungi = 0;
    }

    // Tambahkan koneksi antar simpul (contoh)
    tambahKoneksi(graf, 0, 1);
    tambahKoneksi(graf, 0, 2);
    tambahKoneksi(graf, 1, 3);
    tambahKoneksi(graf, 1, 4);
    tambahKoneksi(graf, 2, 5);
    tambahKoneksi(graf, 2, 6);

    // Lakukan BFS dari simpul 0
    printf("Hasil BFS: ");
    BFS(graf, 7, 0);
    printf("\n");

    return 0;
}
