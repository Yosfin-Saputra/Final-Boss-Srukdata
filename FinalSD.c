#include "lib/main_func.h"


void dosen();
void mhs();


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
				dosen();
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

void dosen(){
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
	int pil;
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
					
				break;
			case 3:
					
				break;
			default:
				break;
		}
		
	}while(pil!=3);	
}