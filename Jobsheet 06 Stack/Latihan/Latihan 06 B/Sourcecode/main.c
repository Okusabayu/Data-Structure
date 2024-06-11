/*  Create by Oksa Bayu Widrian
    23343080 Padang State University*/
#include<stdio.h>
#include<stdlib.h>

#define MAX 5 // Jumlah item maksimum yang dapat disimpan

int top = -1, stack[MAX]; // Inisialisasi top dan array stack

void push();
void pop();
void display();

int main()
{
    int ch;
    while (1) // Loop tak terbatas, akan berakhir ketika pilihan adalah 4
    {
        printf("\n** Menu Stack **");
        printf("\n\n1.Push\n2.Pop\n3.Tampilkan\n4.Keluar");
        printf("\n\nMasukkan pilihanmu (1-4): ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nPilihan tidak valid!");
        }
    }
}

void push()
{
    int val;
    if(top == MAX - 1)
    {
        printf("\nStack penuh!!");
    }
    else
    {
        printf("\nMasukkan item yang ingin ditambahkan: ");
        scanf("%d", &val);
        top = top + 1;
        stack[top] = val;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("\nStack kosong!!");
    }
    else
    {
        printf("\nItem yang dihapus adalah %d", stack[top]);
        top = top - 1;
    }
}

void display()
{
    int i;
    if (top == -1)
    {
        printf("\nStack kosong!!");
    }
    else
    {
        printf("\nItem pada Stack adalah...\n");
        for(i = top; i >= 0; --i)
        {
            printf("%d\n", stack[i]);
        }
    }
}
