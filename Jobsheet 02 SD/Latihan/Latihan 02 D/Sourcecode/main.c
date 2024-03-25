/* Create by Oksa Bayu Widrian
    23343080 Padang State University*/

#include <stdio.h>

int main() {
    // Mendeklarasikan array 2 dimensi dan variabel loop
    int a[5][2] = { {0, 0}, {1, 2}, {2, 4}, {3, 6}, {4, 8} };
    int i, j;

    // Loop untuk mengakses dan mencetak setiap elemen array
    for (i = 0; i < 5; i++) { // Loop untuk baris
        for (j = 0; j < 2; j++) { // Loop untuk kolom
            // Mencetak nilai setiap elemen array beserta indeksnya
            printf("a[%d][%d] = %d\n", i, j, a[i][j]);
        }
    }

    return 0;
}

