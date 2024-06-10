/* Create by Oksa Bayu Widrian
    23343080 Padang State University */
#include <stdio.h>
#include <stdlib.h>

// Fungsi untuk menampilkan bilangan Fibonacci
void tampilkanFibonacci(int n) {
    int *fibonacci = (int*)malloc(n * sizeof(int));

    if (fibonacci == NULL) {
        printf("Pengalokasian memori gagal!");
        return;
    }

    fibonacci[0] = 0;
    fibonacci[1] = 1;

    printf("\nBilangan Fibonacci pertama %d:\n", n);
    printf("%d ", fibonacci[0]);
    printf("%d ", fibonacci[1]);

    for (int i = 2; i < n; i++) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
        printf("%d ", fibonacci[i]);
    }

    free(fibonacci);
}

// Fungsi untuk memeriksa apakah sebuah bilangan prima
int isPrima(int num) {
    if (num <= 1) return 0; // 0 dan 1 bukan bilangan prima

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0; // Bukan bilangan prima
    }

    return 1; // Bilangan prima
}

// Fungsi untuk menampilkan bilangan prima
void tampilkanPrima(int n) {
    int *prima = (int*)malloc(n * sizeof(int));

    if (prima == NULL) {
        printf("Pengalokasian memori gagal!");
        return;
    }

    int count = 0;
    int num = 2;

    while (count < n) {
        if (isPrima(num)) {
            prima[count] = num;
            count++;
        }
        num++;
    }

    printf("\nBilangan Prima pertama %d:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", prima[i]);
    }

    free(prima);
}

int main() {
    int pilihan;
    int n;

    printf("Tugas 03 Struktur Data\n");
    printf("=======================================");

    do {
        printf("\n\nMenu:\n");
        printf("1. Tampilkan bilangan Fibonacci\n");
        printf("2. Tampilkan bilangan Prima\n");
        printf("3. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("Masukkan jumlah bilangan Fibonacci yang ingin ditampilkan: ");
                scanf("%d", &n);
                tampilkanFibonacci(n);
                break;
            case 2:
                printf("Masukkan jumlah bilangan Prima yang ingin ditampilkan: ");
                scanf("%d", &n);
                tampilkanPrima(n);
                break;
            case 3:
                printf("Terima kasih!\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 3);

    return 0;
}

