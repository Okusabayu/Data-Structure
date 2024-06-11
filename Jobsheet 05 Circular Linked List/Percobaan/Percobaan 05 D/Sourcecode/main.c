/* Create By Oksa Bayu Widrian
    23343080 Padang state University */
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>

// Mendefinisikan struktur node untuk linked list
struct node {
    struct node *next; // Pointer ke node berikutnya
    int data; // Data dalam node
    struct node *prev; // Pointer ke node sebelumnya
};

struct node *start = NULL; // Pointer untuk node pertama dalam linked list

// Deklarasi fungsi-fungsi yang akan digunakan
struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_before(struct node *);
struct node *insert_after(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_list(struct node *);

int main() {
    int option;
    // Loop untuk memperbolehkan pengguna memilih berbagai operasi
    do {
        printf("\n\n ======= DOUBLE LINKED LIST =======\n");
        printf("\n 1: Buat Double Linked List");
        printf("\n 2: Tampilkan semua node Double Linked List");
        printf("\n 3: Tambah node di awal Double Linked List");
        printf("\n 4: Tambah node di akhir Double Linked List");
        printf("\n 5: Tambah node sebelum node yang diberikan");
        printf("\n 6: Tambah node setelah node yang diberikan");
        printf("\n 7: Hapus node di awal Double Linked List");
        printf("\n 8: Hapus node di akhir Double Linked List");
        printf("\n 9: Hapus semua node Double Linked List");
        printf("\n 10: EXIT");
        printf("\n\n Enter your option : ");
        scanf("%d", &option);

        // Switch untuk memilih operasi yang diinginkan
        switch(option) {
            case 1:
                system("cls");
                start = create_ll(start);
                printf("\n DOUBLE LINKED LIST CREATED");
                break;
            case 2:
                system("cls");
                start = display(start);
                break;
            case 3:
                system("cls");
                start = insert_beg(start);
                break;
            case 4:
                system("cls");
                start = insert_end(start);
                break;
            case 5:
                system("cls");
                start = insert_before(start);
                break;
            case 6:
                system("cls");
                start = insert_after(start);
                break;
            case 7:
                system("cls");
                start = delete_beg(start);
                break;
            case 8:
                system("cls");
                start = delete_end(start);
                break;
            case 9:
                start = delete_list(start);
                printf("\n DOUBLE LINKED LIST DELETED");
                break;
        }
    } while(option != 10); // Loop akan terus berjalan hingga pengguna memilih opsi 10 (EXIT)
    getch();
    return 0;
}

// Fungsi untuk membuat linked list
struct node *create_ll(struct node *start) {
    system("cls");
    struct node *new_node, *ptr;
    int num;
    printf("\n Tekan 0 untuk berhenti input data");
    printf("\n Masukan data : ");
    scanf("%d", &num);
    // Loop untuk memasukkan data ke dalam linked list
    while(num != 0) {
        new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = num;
        if(start == NULL) {
            new_node->next = NULL;
            new_node->prev = NULL;
            start = new_node;
        } else {
            ptr = start;
            while(ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = new_node;
            new_node->prev = ptr;
            new_node->next = NULL;
        }
        printf(" Masukan data berikutnya : ");
        scanf("%d", &num);
    }
    return start;
}

// Fungsi untuk menampilkan isi linked list
struct node *display(struct node *start) {
    struct node *ptr;
    ptr = start;
    printf(" DATA DOUBLE LINKED LIST \n\n");
    while(ptr != NULL) {
        printf("\t %d", ptr->data);
        ptr = ptr->next;
    }
    return start;
}

// Fungsi untuk menambahkan node di awal linked list
struct node *insert_beg(struct node *start) {
    struct node *new_node;
    int num;
    printf(" TAMBAH DATA DI AWAL \n\n");
    printf("\n Masukan data : ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    start->prev = new_node;
    new_node->next = start;
    new_node->prev = NULL;
    start = new_node;
    printf("\n DATA BERHASIL DITAMBAHKAN! \n");
    return start;
}

// Fungsi untuk menambahkan node di akhir linked list
struct node *insert_end(struct node *start) {
    struct node *ptr, *new_node;
    int num;
    printf(" TAMBAH DATA DI AKHIR \n\n");
    printf("\n Masukan data : ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;
    while(ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = new_node;
    new_node->prev = ptr;
    new_node->next = NULL;
    printf("\n DATA BERHASIL DITAMBAHKAN! \n");
    return start;
}

// Fungsi untuk menambahkan node sebelum node yang diberikan
struct node *insert_before(struct node *start) {
    struct node *new_node, *ptr;
    int num, val;
    printf(" TAMBAH DATA SEBELUM NODE TERTENTU \n\n");
    printf("\n Masukan data : ");
    scanf("%d", &num);
    printf("\n Data baru ditambahkan sebelum node dengan data : ");
    scanf("%d", &val);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;
    while(ptr->data != val) {
        ptr = ptr->next;
        new_node->next = ptr;
        new_node->prev = ptr->prev;
        ptr->prev->next = new_node;
        ptr->prev = new_node;
    }
    return start;
}

// Fungsi untuk menambahkan node setelah node yang diberikan
struct node *insert_after(struct node *start) {
    struct node *new_node, *ptr;
    int num, val;
    printf(" TAMBAH DATA SETELAH NODE TERTENTU \n\n");
    printf("\n Masukan data : ");
    scanf("%d", &num);
    printf("\n Data baru ditambahkan setelah node dengan data : ");
    scanf("%d", &val);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;
    while(ptr->data != val) {
        ptr = ptr->next;
        new_node->prev = ptr;
        new_node->next = ptr->next;
        ptr->next->prev = new_node;
        ptr->next = new_node;
    }
    printf("\n DATA BERHASIL DITAMBAHKAN! \n");
    return start;
}

// Fungsi untuk menghapus node di awal linked list
struct node *delete_beg(struct node *start) {
    struct node *ptr;
    ptr = start;
    start = start->next;
    start->prev = NULL;
    free(ptr);
    printf("\n DATA AWAL BERHASIL DIHAPUS! \n");
    return start;
}

// Fungsi untuk menghapus node di akhir linked list
struct node *delete_end(struct node *start) {
    struct node *ptr, *preptr;
    ptr = start;
    while(ptr->next != NULL) {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;
    free(ptr);
    printf("\n DATA AKHIR BERHASIL DIHAPUS! \n");
    return start;
}

// Fungsi untuk menghapus semua node dalam linked list
struct node *delete_list(struct node *start) {
    struct node *ptr;
    if(start != NULL) {
        ptr = start;
        while(ptr != NULL) {
            printf("\n %d is to be deleted next", ptr->data);
            start = delete_beg(ptr);
            ptr = start;
        }
    }
    return start;
}


