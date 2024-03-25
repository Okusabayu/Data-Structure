/* Create by Oksa bayu Widrian
    23343080 Padang state University*/
#include <stdio.h>

int main() {
    int n[10];
    int i, j;

    // Inisialisasi array n dengan nilai i + 100
    for (i = 0; i < 10; i++) {
        n[i] = i + 100;
    }

    // Mencetak elemen-elemen array n
    for (j = 0; j < 10; j++) {
        printf("Element[%d] = %d\n", j, n[j]);
    }

    return 0;
}
