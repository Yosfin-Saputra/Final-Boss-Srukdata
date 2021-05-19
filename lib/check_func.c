#include "check_func.h"

void checkDirect(){
	struct stat st = { 0 };

    if (stat("db_cetak", &st) == -1) {
        mkdir("db_cetak");
    }
    if (stat("db_kls", &st) == -1) {
        mkdir("db_kls");
    }
}