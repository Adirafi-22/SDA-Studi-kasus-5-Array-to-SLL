#include "list.h"

int main() {
    Kota daftarKota[MAX_KOTA];
    int jumlahKota = 0;
    int pilihan;

    initData(daftarKota);

    do {
        printf("\nMenu:\n");
        printf("1. Tambah Kota\n");
        printf("2. Hapus Kota\n");
        printf("3. Tambah Nama\n");
        printf("4. Hapus Nama\n");
        printf("5. Tampilkan Data\n");
        printf("6. Tampilkan Kota Tertentu\n");
        printf("7. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1: tambahKota(daftarKota, &jumlahKota); break;
            case 2: hapusKota(daftarKota, &jumlahKota); break;
            case 3: tambahNama(daftarKota, jumlahKota); break;
            case 4: hapusNama(daftarKota, jumlahKota); break;
            case 5: tampilkanData(daftarKota, jumlahKota); break;
            case 6: tampilkanKotaTertentu(daftarKota, jumlahKota); break;
			case 7: printf("Terima kasih!\n"); break;
        }
    } while (pilihan != 7);

    return 0;
}
