/* Create By Oksa Bayu Widrian
    23343080 Padang state University */
#include<stdio.h>
#include<stdlib.h>

// Definisi struktur node
struct node {
    int data;
    struct node *next;
};

// Pointer kepala linked list
struct node *head;

// Prototipe fungsi-fungsi
void tambahAwal();
void tambahAkhir();
void hapusAwal();
void hapusAkhir();
void cari();
void tampilkan();

int main() {
    int choice = 0;

    // Loop menu utama
    while(choice != 7) {
        printf("\n*********Main Menu*********\n");
        printf("\nSilakan pilih salah satu dari menu berikut ...\n");
        printf("\n===============================================\n");
        printf("\n1. Masukkan data di awal\n2. Masukkan data di akhir\n3. Hapus dari awal\n4. Hapus dari akhir\n5. Cari sebuah elemen\n6. Tampilkan\n7. Exit\n");
        printf("\nMasukkan pilihanmu: ");
        scanf("\n%d", &choice);

        // Switch untuk memilih opsi
        switch(choice) {
            case 1:
                tambahAwal();
                break;
            case 2:
                tambahAkhir();
                break;
            case 3:
                hapusAwal();
                break;
            case 4:
                hapusAkhir();
                break;
            case 5:
                cari();
                break;
            case 6:
                tampilkan();
                break;
            case 7:
                exit(0);
                break;
            default:
                printf("Mohon masukkan pilihan yang sesuai menu..\n");
        }
    }
}

// Fungsi untuk menambah node di awal linked list
void tambahAwal() {
    struct node *ptr, *temp;
    int item;

    // Alokasi memori untuk node baru
    ptr = (struct node *)malloc(sizeof(struct node));
    if(ptr == NULL) {
        printf("\nOVERFLOW");
    } else {
        printf("\nMasukkan data node: ");
        scanf("%d", &item);
        ptr->data = item;

        // Jika linked list masih kosong
        if(head == NULL) {
            head = ptr;
            ptr->next = head;
        } else {
            temp = head;

            // Traverse ke akhir linked list
            while(temp->next != head)
                temp = temp->next;

            ptr->next = head;
            temp->next = ptr;
            head = ptr;
        }
        printf("\nNode telah dimasukkan\n");
    }
}

// Fungsi untuk menambah node di akhir linked list
void tambahAkhir() {
    struct node *ptr, *temp;
    int item;

    // Alokasi memori untuk node baru
    ptr = (struct node *)malloc(sizeof(struct node));
    if(ptr == NULL) {
        printf("\nOVERFLOW\n");
    } else {
        printf("\nMasukkan data: ");
        scanf("%d", &item);
        ptr->data = item;

        // Jika linked list masih kosong
        if(head == NULL) {
            head = ptr;
            ptr->next = head;
        } else {
            temp = head;

            // Traverse ke akhir linked list
            while(temp->next != head)
                temp = temp->next;

            temp->next = ptr;
            ptr->next = head;
        }
        printf("\nNode dimasukkan\n");
    }
}

// Fungsi untuk menghapus node di awal linked list
void hapusAwal() {
    struct node *ptr;

    // Jika linked list kosong
    if(head == NULL) {
        printf("\nUNDERFLOW");
    } else if(head->next == head) {
        head = NULL;
        free(head);
        printf("\nNode dihapus\n");
    } else {
        ptr = head;

        // Traverse ke node terakhir
        while(ptr->next != head)
            ptr = ptr->next;

        ptr->next = head->next;
        free(head);
        head = ptr->next;
        printf("\nNode dihapus\n");
    }
}

// Fungsi untuk menghapus node di akhir linked list
void hapusAkhir() {
    struct node *ptr, *preptr;

    // Jika linked list kosong
    if(head == NULL) {
        printf("\nUNDERFLOW");
    } else if (head->next == head) {
        head = NULL;
        free(head);
        printf("\nNode dihapus\n");
    } else {
        ptr = head;

        // Traverse ke node terakhir
        while(ptr->next != head) {
            preptr = ptr;
            ptr = ptr->next;
        }

        preptr->next = ptr->next;
        free(ptr);
        printf("\nNode dihapus\n");
    }
}

// Fungsi untuk mencari sebuah elemen dalam linked list
void cari() {
    struct node *ptr;
    int item, i = 0, flag = 1;

    ptr = head;
    if(ptr == NULL) {
        printf("\nList Kosong\n");
    } else {
        printf("\nMasukkan item yang ingin dicari: ");
        scanf("%d", &item);

        // Cek apakah item ditemukan di awal linked list
        if(head->data == item) {
            printf("Item ditemukan pada lokasi %d", i+1);
            flag = 0;
        } else {
            // Traverse linked list
            while(ptr->next != head) {
                if(ptr->data == item) {
                    printf("Item ditemukan pada lokasi %d ", i+1);
                    flag = 0;
                    break;
                } else {
                    flag = 1;
                }
                i++;
                ptr = ptr->next;
            }
        }

        if(flag != 0) {
            printf("Item tidak ditemukan\n");
        }
    }
}

// Fungsi untuk menampilkan semua elemen dalam linked list
void tampilkan() {
    struct node *ptr;
    ptr = head;

    // Jika linked list kosong
    if(head == NULL) {
        printf("\nTidak ada yang ditampilkan\n");
    } else {
        printf("\nMenampilkan nilai... \n");

        // Traverse linked list
        while(ptr->next != head) {
            printf("%d\n", ptr->data);
            ptr = ptr->next;
        }
        printf("%d\n", ptr->data);
    }
}

