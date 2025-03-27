#ifndef LIST_H
#define LIST_H

#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KOTA 5
#define MAX_STRING 50

typedef struct NamaNode {
    char nama[MAX_STRING];
    struct NamaNode* next;
} NamaNode;

typedef struct {
    char kt[MAX_STRING];
    NamaNode* p;
} Kota;

void initData(Kota daftarKota[]);
void tambahKota(Kota daftarKota[], int *jumlahKota);
void hapusKota(Kota daftarKota[], int *jumlahKota);
void tambahNama(Kota daftarKota[], int jumlahKota);
void hapusNama(Kota daftarKota[], int jumlahKota);
void tampilkanData(Kota daftarKota[], int jumlahKota);
void tampilkanKotaTertentu(Kota daftarKota[], int jumlahKota);

#endif
