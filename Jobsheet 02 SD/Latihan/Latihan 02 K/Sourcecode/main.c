/* Create by Oksa Bayu Widrian
    23343080 Padang State University*/
#include <stdio.h>

// Mendefinisikan struktur Distance untuk menyimpan jarak dalam kaki dan inci
struct Distance {
    int feet;
    float inch;
} dist1, dist2, sum; // Deklarasi variabel dist1, dist2, dan sum

int main() {
    // Meminta pengguna untuk memasukkan jarak pertama
    printf("1st distance\n");
    printf("Enter feet: ");
    scanf("%d", &dist1.feet);
    printf("Enter inch: ");
    scanf("%f", &dist1.inch);

    // Meminta pengguna untuk memasukkan jarak kedua
    printf("2nd distance\n");
    printf("Enter feet: ");
    scanf("%d", &dist2.feet);
    printf("Enter inch: ");
    scanf("%f", &dist2.inch);

    // Menambahkan kaki dari kedua jarak
    sum.feet = dist1.feet + dist2.feet;

    // Menambahkan inci dari kedua jarak
    sum.inch = dist1.inch + dist2.inch;

    // Mengonversi ke kaki jika inci lebih dari atau sama dengan 12
    while (sum.inch >= 12) {
        ++sum.feet; // Menambahkan satu kaki
        sum.inch -= 12; // Mengurangi 12 inci
    }

    // Menampilkan hasil penambahan jarak
    printf("Sum of distances = %d\'-%.1f\"\n", sum.feet, sum.inch);

    return 0;
}

