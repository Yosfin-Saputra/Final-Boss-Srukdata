#ifndef CHECK_H_
#define CHECK_H_

#include "main_func.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void checkDirect();
int loginD(char u[],char p[]);
void tes();
void saveKlsMhs();
int barisF(char file[]);
void loadKlsMhs();

#endif