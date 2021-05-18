#include "lib/main_func.h"


void dosenSign();
void mhs();
void dosen();
void editKls();


int main(){
	int pil;
	
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
				
				lanjut=next();	
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
		printf("--> 2. Edit Kelas\n");
		printf("--> 3. Lihat Kelas\n");
		printf("--> 4. Hapus Kelas\n");
		printf("--> 5. Kembali\n");
		printf("============================================================\n");
		printf("--> Pilih menu : ");
		scanf("%d",&pil);
		printf("============================================================\n");
		
		switch(pil){
			case 1:
				
				break;
			case 2:
				
				editKls();
				break;
			case 3:
				
				lanjut=next();
				break;
			case 4:
				break;
			case 5:
				break;
			default:
				break;
		}
		
	}while(pil!=5 && lanjut==1 );
}

void editKls(){
	int pil,lanjut=1;
	
	do{
		system("cls");
		
		latar();
		printf("============================================================\n");
		printf("                      MENU DOSEN\n");
		printf("============================================================\n");
		printf("                      EDIT KELAS\n");
		printf("============================================================\n");
		printf("--> 1. Ganti ID\n");
		printf("--> 2. Ganti Password\n");
		printf("--> 3. Ganti Nama dan Keterangan\n");
		printf("--> 4. Lihat Tampilan Kelas\n");
		printf("--> 5. Kembali\n");
		printf("============================================================\n");
		printf("--> Pilih menu : ");
		scanf("%d",&pil);
		printf("============================================================\n");
		
		switch(pil){
			case 1:
				
				break;
			case 2:
					
				break;
			case 3:
				
				
				break;
			case 4:
				
				lanjut=next();
				break;
			case 5:
				break;
			default:
				break;
		}
		
	}while(pil!=5 && lanjut==1 );
}