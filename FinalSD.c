#include "lib/main_func.h"
#include "lib/check_func.h"
#include "lib/kls_func.h"


void dosenSign();
void mhs();
void dosen();
void editKls(struct Kls *bantu);
void lihatKls(struct Kls *bantu);
void cekId();


int main(){
	int pil;
	
	checkDirect();
//	isi();
	
	do{
		system("cls");
		
		latar();
		printf("============================================================\n");
		printf("                      MENU LOGIN\n");
		printf("============================================================\n");
		printf("--> 1. Sebagai Dosen\n");
		printf("--> 2. Sebagai Mahasiswa\n");
		printf("--> 3. Keluar\n");
		printf("============================================================\n");
		printf("--> Pilih menu : ");
		scanf("%d",&pil);
		printf("============================================================\n");
		
		switch(pil){
			case 1:
				dosenSign();
				break;
			case 2:
				mhs();
				break;
			case 3:
				
				break;
			default:
				break;
		}
		
	}while(pil!=3);
	
	return 0;
}

void dosenSign(){
	int pil;
	
	do{
		system("cls");
		
		latar();
		printf("============================================================\n");
		printf("                      MENU DOSEN\n");
		printf("============================================================\n");
		printf("--> 1. Sign In\n");
		printf("--> 2. Sign Up\n");
		printf("--> 3. Kembali\n");
		printf("============================================================\n");
		printf("--> Pilih menu : ");
		scanf("%d",&pil);
		printf("============================================================\n");
		
		switch(pil){
			case 1:
				
				dosen();
				break;
			case 2:
					
				break;
			case 3:
					
				break;
			default:
				break;
		}
		
	}while(pil!=3);
}

void mhs(){
	int pil,lanjut=1;
	
	do{
		system("cls");
		
		latar();
		printf("============================================================\n");
		printf("                     MENU MAHASISWA\n");
		printf("============================================================\n");
		printf("--> 1. Absensi\n");
		printf("--> 2. Lihat Kelas\n");
		printf("--> 3. Kembali\n");
		printf("============================================================\n");
		printf("--> Pilih menu : ");
		scanf("%d",&pil);
		printf("============================================================\n");
		
		switch(pil){
			case 1:
					
				break;
			case 2:
				
				lanjut=next(1);	
				break;
			case 3:
					
				break;
			default:
				break;
		}
		
	}while(pil!=3 && lanjut==1);	
}

void dosen(){
	int pil,lanjut=1;
	
	do{
		system("cls");
		
		latar();
		printf("============================================================\n");
		printf("                      MENU DOSEN\n");
		printf("============================================================\n");
		printf("--> 1. Buat Kelas\n");
		printf("--> 2. Edit dan Lihat Kelas\n");
		printf("--> 3. Lihat Absensi Kelas\n");
		printf("--> 4. Kelas yang Tersedia\n");
		printf("--> 5. Kembali\n");
		printf("============================================================\n");
		printf("--> Pilih menu : ");
		scanf("%d",&pil);
		printf("============================================================\n");
		
		switch(pil){
			case 1:
				buatKls();
				break;
			case 2:
				
				cekId(1);
				break;
			case 3:
				
				cekId(2);
				break;
			case 4:
				adaKls();
				lanjut=next(1);
				break;
			case 5:
				break;
			default:
				break;
		}
		
	}while(pil!=5 && lanjut==1 );
}

void editKls(struct Kls *bantu){
	int pil,lanjut=1;
	
	do{
		system("cls");
		
		latar();
		printf("============================================================\n");
		printf("                      MENU DOSEN\n");
		printf("============================================================\n");
		printf("                 EDIT DAN LIHAT KELAS\n");
		printf("============================================================\n");
		printf("--> 1. Edit Kelas\n");
		printf("--> 2. Lihat Tampilan Kelas\n");
		printf("--> 3. Hapus Kelas\n");
		printf("--> 4. Kembali\n");
		printf("============================================================\n");
		printf("--> Pilih menu : ");
		scanf("%d",&pil);
		printf("============================================================\n");
		
		switch(pil){
			case 1:
				bantu=modifKls(bantu);
				break;
			case 2:
				viewKls(bantu);
				lanjut=next(1);
				break;
			case 3:
				lanjut=next(3);
				if(lanjut==1){
					delKls(bantu);
					lanjut=0;
				}
				break;
			case 4:
				break;
			default:
				break;
		}
		
	}while(pil!=4 && lanjut==1 );
}

void lihatKls(struct Kls *bantu){
	int pil,lanjut=1;
	
	do{
		system("cls");
		
		latar();
		printf("============================================================\n");
		printf("                      MENU DOSEN\n");
		printf("============================================================\n");
		printf("                 LIHAT ABSENSI KELAS\n");
		printf("============================================================\n");
		printf("--> 1. Lihat Absensi\n");
		printf("--> 2. Edit Absensi\n");
		printf("--> 3. Cetak Absensi\n");
		printf("--> 4. Kembali\n");
		printf("============================================================\n");
		printf("--> Pilih menu : ");
		scanf("%d",&pil);
		printf("============================================================\n");
		
		switch(pil){
			case 1:
				
				lanjut=next(1);
				break;
			case 2:
					
				break;
			case 3:
				
				lanjut=next(1);
				break;
			case 4:
				break;
			default:
				break;
		}
		
	}while(pil!=4 && lanjut==1 );
}

void cekId(int n){
	int a,temu;
	struct Kls *bantu;
	menu:
	system("cls");
	
	latar();
	printf("============================================================\n");
	printf("                       CEK ID KELAS\n");
	printf("============================================================\n");
	printf("-->ID Kelas   : ");   
	scanf("%d",&a);
	temu=cariTes(a);
	if(temu==1){
		bantu=cariKls(a);
		printf("============================================================\n");
		if(n==1) editKls(bantu);
		else lihatKls(bantu);
	}else{
		printf("-->Maaf, ID tidak ditemukan\n");
		printf("============================================================\n");
		temu=next(2);
		if(temu==1) goto menu;
		else return;
	}
}