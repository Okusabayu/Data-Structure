/* Create by Oksa Bayu Widrian
    23343080 Padang State University */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur untuk menyimpan data buku
struct Buku {
    char judul[100];
    char pengarang[100];
    int tahun;
};

// Struktur untuk menyimpan data mobil
struct Mobil {
    char noPlat[20];
    char merk[50];
    char pemilik[100];
};

// Node untuk Double Linked List
struct Node {
    void *data;
    struct Node *prev;
    struct Node *next;
};

// Fungsi untuk menambahkan node baru ke dalam linked list
void tambahNode(struct Node **head, void *data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
    } else {
        struct Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Fungsi untuk menghapus node berdasarkan judul buku
void hapusBuku(struct Node **head, char *judul) {
    struct Node *current = *head;
    while (current != NULL) {
        struct Buku *buku = (struct Buku*)current->data;
        if (strcmp(buku->judul, judul) == 0) {
            if (current->prev == NULL) {
                *head = current->next;
            } else {
                current->prev->next = current->next;
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            free(buku);
            free(current);
            return;
        }
        current = current->next;
    }
    printf("Buku dengan judul '%s' tidak ditemukan.\n", judul);
}

// Fungsi untuk menghapus node berdasarkan nomor plat mobil
void hapusMobil(struct Node **head, char *noPlat) {
    struct Node *current = *head;
    while (current != NULL) {
        struct Mobil *mobil = (struct Mobil*)current->data;
        if (strcmp(mobil->noPlat, noPlat) == 0) {
            if (current->prev == NULL) {
                *head = current->next;
            } else {
                current->prev->next = current->next;
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            free(mobil);
            free(current);
            return;
        }
        current = current->next;
    }
    printf("Mobil dengan nomor plat '%s' tidak ditemukan.\n", noPlat);
}

// Fungsi untuk mencetak daftar buku
void cetakBuku(struct Node *head) {
    printf("Daftar Buku:\n");
    struct Node *current = head;
    while (current != NULL) {
        struct Buku *buku = (struct Buku*)current->data;
        printf("Judul: %s,  Pengarang: %s,  Tahun: %d\n", buku->judul, buku->pengarang, buku->tahun);
        current = current->next;
    }
    printf("\n");
}

// Fungsi untuk mencetak daftar mobil
void cetakMobil(struct Node *head) {
    printf("Daftar Mobil:\n");
    struct Node *current = head;
    while (current != NULL) {
        struct Mobil *mobil = (struct Mobil*)current->data;
        printf("No Plat: %s,    Merk: %s, Pemilik: %s\n", mobil->noPlat, mobil->merk, mobil->pemilik);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node *daftarBuku = NULL;
    struct Node *daftarMobil = NULL;

    // Menambahkan data buku
    struct Buku *buku1 = (struct Buku*)malloc(sizeof(struct Buku));
    strcpy(buku1->judul, "Digital Design");
    strcpy(buku1->pengarang, "M.Morris Mano");
    buku1->tahun = 1997;
    tambahNode(&daftarBuku, buku1);

    struct Buku *buku2 = (struct Buku*)malloc(sizeof(struct Buku));
    strcpy(buku2->judul, "One Piece");
    strcpy(buku2->pengarang, "Eiichiro Oda");
    buku2->tahun = 1954;
    tambahNode(&daftarBuku, buku2);

    cetakBuku(daftarBuku);

    // Menambahkan data mobil
    struct Mobil *mobil1 = (struct Mobil*)malloc(sizeof(struct Mobil));
    strcpy(mobil1->noPlat, "BA 1234 CD");
    strcpy(mobil1->merk, "Toyota");
    strcpy(mobil1->pemilik, "Udin");
    tambahNode(&daftarMobil, mobil1);

    struct Mobil *mobil2 = (struct Mobil*)malloc(sizeof(struct Mobil));
    strcpy(mobil2->noPlat, "BA 5678 EF");
    strcpy(mobil2->merk, "Honda");
    strcpy(mobil2->pemilik, "Asep");
    tambahNode(&daftarMobil, mobil2);

    cetakMobil(daftarMobil);

    // Hapus buku dan mobil berdasarkan judul dan nomor plat
    hapusBuku(&daftarBuku, "Digital Design");
    hapusMobil(&daftarMobil, "BA 5678 EF");

    cetakBuku(daftarBuku);
    cetakMobil(daftarMobil);

    return 0;
}
