// Cameron Atkins
// CompSci 4280
// P1 - Scanner

#ifndef SCANNER_H
#define SCANNER_H

#include <stdio.h>
#include "token.h"
#include "character.h"

void setLookaheadChar(FILE *);
token scanner(FILE *);
token fsaDriver(FILE *);
character filter(FILE *);
//int getTableColNum(char);
int getTableColNum(FILE *, char,char);



#endif
