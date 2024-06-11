/*  Create by Oksa Bayu Widrian
    23343080 Padang State University*/
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*atas = NULL;

// Fungsi untuk menambahkan elemen ke atas stack
void push(int value)
{
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node)); // Alokasi memori untuk node baru
    newNode->data = value; // Mengisi data pada node baru

    if(atas == NULL)
        newNode->next = NULL;
    else
        newNode->next = atas;

    atas = newNode; // Mengatur atas agar menunjuk ke node baru
    printf("\nItem berhasil ditambahkan\n");
}

// Fungsi untuk menghapus elemen dari atas stack
void pop()
{
    if(atas == NULL)
        printf("\nStack kosong!!!\n");
    else{
        struct Node *temp = atas;
        printf("\nItem berhasil dihapus: %d", temp->data);
        atas = temp->next;
        free(temp); // Membebaskan memori yang dialokasikan untuk node yang dihapus
    }
}

// Fungsi untuk menampilkan elemen-elemen dalam stack
void tampilkan()
{
    if(atas == NULL)
        printf("\nStack kosong!!!\n");
    else{
        struct Node *temp = atas;
        while(temp->next != NULL){
            printf("%d--->",temp->data);
            temp = temp -> next;
        }
        printf("%d--->NULL",temp->data);
    }
}

int main()
{
    int pilihan, value;
    printf("\n== Stack Menggunakan Linked List ==\n");

    while(1){
        printf("\n****** MENU ******\n");
        printf("1. Push\n2. Pop\n3. Tampilkan\n4. Keluar\n");
        printf("Masukan pilihanmu: ");
        scanf("%d",&pilihan);

        switch(pilihan){
            case 1:
                printf("Masukan nilai yang ingin ditambahkan ke stack: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                tampilkan();
                break;
            case 4:
                exit(0);
            default:
                printf("\nPilihan tidak valid, silakan coba lagi!\n");
        }
    }

    return 0;
}

