#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct untuk bulan
struct Bulan {
    char *namaBulan;
};

// Fungsi untuk menginisialisasi nama bulan
void inisialisasiBulan(struct Bulan *bulan) {
    for (int i = 0; i < 12; i++) {
        bulan[i].namaBulan = (char *)malloc(20 * sizeof(char));
        switch (i) {
            case 0: strcpy(bulan[i].namaBulan, "Januari"); break;
            case 1: strcpy(bulan[i].namaBulan, "Februari"); break;
            case 2: strcpy(bulan[i].namaBulan, "Maret"); break;
            case 3: strcpy(bulan[i].namaBulan, "April"); break;
            case 4: strcpy(bulan[i].namaBulan, "Mei"); break;
            case 5: strcpy(bulan[i].namaBulan, "Juni"); break;
            case 6: strcpy(bulan[i].namaBulan, "Juli"); break;
            case 7: strcpy(bulan[i].namaBulan, "Agustus"); break;
            case 8: strcpy(bulan[i].namaBulan, "September"); break;
            case 9: strcpy(bulan[i].namaBulan, "Oktober"); break;
            case 10: strcpy(bulan[i].namaBulan, "November"); break;
            case 11: strcpy(bulan[i].namaBulan, "Desember"); break;
        }
    }
}

// Fungsi untuk menghitung huruf vokal dan nonvokal pada bulan tertentu
void hitungVokalDanNonVokal(const char *bulanPilihan, int *jumlahVokal, int *jumlahNonVokal) {
    for (int i = 0; bulanPilihan[i] != '\0'; i++) {
        char c = bulanPilihan[i];
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) { 
            if (strchr("aeiouAEIOU", c) != NULL) { //strchr mengecek adanya aeiouAEIOU pada c
                (*jumlahVokal)++; //inkremen untuk setiap huruf vokal
            } else {
                (*jumlahNonVokal)++; //inkremen untuk setiap huruf nonvokal
            }
        }
    }
}

int main() {
    struct Bulan *bulan = (struct Bulan *)malloc(12 * sizeof(struct Bulan)); // deklarasi struct, sizeof untuk mengetahui total memory, membernya dari fungsi inisialisasiBulan (0-11)
    inisialisasiBulan(bulan); //panggil fungsi untuk disimpan ke struct

    char userInput;
    int isValidInput = 0; //set to 0 (false) mengindikasikan inputan user tidak valid

    while (!isValidInput) { // iterates selama inputan invalid (!variableName)
        printf("Masukkan huruf (A-Z): ");
        scanf(" %c", &userInput);

        printf("Nama bulan dengan huruf awalan %c:\n", userInput);
        for (int i = 0; i < 12; i++) { //untuk inputan valid
            if (bulan[i].namaBulan[0] == userInput || bulan[i].namaBulan[0] == userInput + ('a' - 'A')) {
                printf("%s\n", bulan[i].namaBulan);
                isValidInput = 1; //inputan valid = 1 (true)
            }
        }

        if (!isValidInput) { //untuk inputan invalid
            printf("Tidak ada bulan dengan huruf awalan %c. Silakan coba lagi.\n", userInput);
        }
    }

    char bulanPilihan[10];
    printf("Pilih salah satu bulan : ");
    scanf("%s", bulanPilihan);

    int jumlahVokal = 0, jumlahNonVokal = 0; //jumlah awal 0, menghindari garbage value
    hitungVokalDanNonVokal(bulanPilihan, &jumlahVokal, &jumlahNonVokal); //panggil fungsi hitung vokal & nonvokal

    printf("Jumlah huruf vokal : %d\n", jumlahVokal);
    printf("Jumlah huruf nonvokal : %d\n", jumlahNonVokal);

    // Free allocated memory
    for (int i = 0; i < 12; i++) {
        free(bulan[i].namaBulan);
    }
    free(bulan);

    return 0;
}
