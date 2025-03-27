#include "list.h"
#ifdef _WIN32
#define strcasecmp _stricmp  
#endif

void initData(Kota daftarKota[]) {
    int i;
    for (i = 0; i < MAX_KOTA; i++) {
        daftarKota[i].p = NULL;
    }
}

void tambahKota(Kota daftarKota[], int *jumlahKota) {
    if (*jumlahKota >= MAX_KOTA) {
        printf("Kota sudah penuh!\n");
        return;
    }

    printf("Masukkan nama kota: ");
    scanf(" %[^\n]", daftarKota[*jumlahKota].kt);
    daftarKota[*jumlahKota].p = NULL;
    (*jumlahKota)++;
	system("cls");
    printf("Kota berhasil ditambahkan!\n");
}

void hapusKota(Kota daftarKota[], int *jumlahKota) {
    if (*jumlahKota == 0) {
        printf("Belum ada kota yang tersimpan.\n");
        return;
    }

    char namaKota[MAX_STRING];
    printf("Masukkan nama kota yang akan dihapus: ");
    scanf(" %[^\n]", namaKota);

    int i, j;
    for (i = 0; i < *jumlahKota; i++) {
        if (strcasecmp(daftarKota[i].kt, namaKota) == 0) {
            NamaNode* temp = daftarKota[i].p;
            while (temp != NULL) {
                NamaNode* toDelete = temp;
                temp = temp->next;
                free(toDelete);
            }

            for (j = i; j < (*jumlahKota) - 1; j++) {
                daftarKota[j] = daftarKota[j + 1];
            }
            (*jumlahKota)--;
			system("cls");
            printf("Kota dan semua data nama berhasil dihapus!\n");
            return;
        }
    }
    printf("Kota tidak ditemukan!\n");
}

void tambahNama(Kota daftarKota[], int jumlahKota) {
    if (jumlahKota == 0) {
        printf("Belum ada kota yang tersedia.\n");
        return;
    }

    char namaKota[MAX_STRING], namaOrang[MAX_STRING];
    printf("Masukkan nama kota: ");
    scanf(" %[^\n]", namaKota);

    int i;
    for (i = 0; i < jumlahKota; i++) {
        if (strcasecmp(daftarKota[i].kt, namaKota) == 0) {
            printf("Masukkan nama orang: ");
            scanf(" %[^\n]", namaOrang);

            NamaNode* newNode = (NamaNode*)malloc(sizeof(NamaNode));
            strcpy(newNode->nama, namaOrang);
            newNode->next = daftarKota[i].p;
            daftarKota[i].p = newNode;
			
			system("cls");
            printf("Nama berhasil ditambahkan!\n");
            return;
        }
    }
    printf("Kota tidak ditemukan!\n");
}

void hapusNama(Kota daftarKota[], int jumlahKota) {
    if (jumlahKota == 0) {
        printf("Belum ada kota yang tersedia.\n");
        return;
    }

    char namaKota[MAX_STRING], namaOrang[MAX_STRING];
    printf("Masukkan nama kota: ");
    scanf(" %[^\n]", namaKota);

    int i;
    for (i = 0; i < jumlahKota; i++) {
        if (strcasecmp(daftarKota[i].kt, namaKota) == 0) {
            printf("Masukkan nama orang yang akan dihapus: ");
            scanf(" %[^\n]", namaOrang);

            NamaNode* temp = daftarKota[i].p;
            NamaNode* prev = NULL;

            while (temp != NULL && strcasecmp(temp->nama, namaOrang) != 0) {
                prev = temp;
                temp = temp->next;
            }

            if (temp == NULL) {
                printf("Nama tidak ditemukan di kota ini.\n");
                return;
            }

            if (prev == NULL) {
                daftarKota[i].p = temp->next;
            } else {
                prev->next = temp->next;
            }

            free(temp);
            system("cls");
            printf("Nama berhasil dihapus!\n");
            return;
        }
    }
    printf("Kota tidak ditemukan!\n");
}

void tampilkanData(Kota daftarKota[], int jumlahKota) {
    int i;
    for (i = 0; i < jumlahKota; i++) {
    	system("cls");
        printf("Kota: %s\n", daftarKota[i].kt);
        NamaNode* temp = daftarKota[i].p;
        while (temp != NULL) {
            printf("  - %s\n", temp->nama);
            temp = temp->next;
        }
    }
}

void tampilkanKotaTertentu(Kota daftarKota[], int jumlahKota) {
    if (jumlahKota == 0) {
        printf("Belum ada kota yang tersedia.\n");
        return;
    }

    char namaKota[MAX_STRING];
    printf("Masukkan nama kota yang ingin ditampilkan: ");
    scanf(" %[^\n]", namaKota);

    int i;
    for (i = 0; i < jumlahKota; i++) {
        if (strcasecmp(daftarKota[i].kt, namaKota) == 0) {
            printf("Kota: %s\n", daftarKota[i].kt);
            NamaNode* temp = daftarKota[i].p;
            while (temp != NULL) {
                printf("  - %s\n", temp->nama);
                temp = temp->next;
            }
            return;
        }
    }
    printf("Kota tidak ditemukan!\n");
}


