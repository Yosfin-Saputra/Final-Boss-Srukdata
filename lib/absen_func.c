#include "absen_func.h"

void absenMhs(struct Kls *bantu){
	struct List b;
	int temu;
	menu:
	system("cls");
	
	latar();
	printf("============================================================\n");
	printf("                  MENU ABSENSI MAHASISWA\n");
	printf("============================================================\n");
	printf("-->Nama  : ");
	fflush(stdin);
	scanf("%[^\n]s",b.nama);
	printf("-->NIM   : ");
	scanf("%d",&b.nim);
	printf("-->Kelas : ");
	fflush(stdin);
	scanf("%c",&b.kls);
	printf("============================================================\n");
	addMhs(b.nama,b.nim,b.kls,bantu);
}

void lihatAbsen(struct List *bantu){
	int status=0;
	system("cls");
	
	latar();
	printf("============================================================\n");
	printf("                LIHAT ABSENSI MAHASISWA\n");
	printf("============================================================\n");
	printf("+---------------+----------------------------------+-------+\n");
	printf("|      NIM      |          NAMA MAHASISWA          | KELAS |\n");
	printf("+---------------+----------------------------------+-------+\n");
	while(bantu!=NULL){
		status++;
		printf("|  %-11d  | %-32s |   %c   |\n",bantu->nim,bantu->nama,bantu->kls);
		bantu=bantu->next;
	}
	if(status==0){
		printf("|       -       |                -                 |   -   |\n");
	}
	printf("+---------------+----------------------------------+-------+\n");
	printf("============================================================\n");
}