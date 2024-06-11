/* Create by Oksa Bayu Widrian
    23343080 Padang State University*/
#include<stdio.h>
#include<stdlib.h>

// Mendefinisikan struktur employee_st untuk menyimpan informasi karyawan
typedef struct employee_st {
    char name[40]; // Variabel untuk menyimpan nama karyawan
    int id; // Variabel untuk menyimpan ID karyawan
} Employee; // Aliasan untuk struct employee_st

int main() {
    int myInt; // Variabel untuk menyimpan nilai integer
    Employee john; // Variabel untuk menyimpan informasi karyawan

    // Menampilkan ukuran berbagai tipe data
    printf("Size of int is %d\n", sizeof(myInt)); // Menampilkan ukuran int
    printf("Size of char is %d\n", sizeof(char)); // Menampilkan ukuran char
    printf("Size of short is %d\n", sizeof(short)); // Menampilkan ukuran short
    printf("Size of int is %d\n", sizeof(int)); // Menampilkan ukuran int
    printf("Size of long is %d\n", sizeof(long)); // Menampilkan ukuran long
    printf("Size of float is %d\n", sizeof(float)); // Menampilkan ukuran float
    printf("Size of double is %d\n", sizeof(double)); // Menampilkan ukuran double
    printf("Size of Employee is %d\n", sizeof(Employee)); // Menampilkan ukuran Employee
    printf("Size of john is %d\n", sizeof(john)); // Menampilkan ukuran variabel john

    return 0;
}

