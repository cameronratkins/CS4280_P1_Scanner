// Cameron Atkins
// CompSci 4280
// P1 - Scanner

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scanner.h"
#include "testScanner.h"

int main(int argc, char *argv[]) {
	if (argc > 2) {
		printf("Error: Expected 1 or no arguments\n");
		return 1;
	}

	FILE *inFilePtr = NULL;
	inFilePtr = fopen(argv[1], "r");
	
	
    
    testScanner(inFilePtr);
    fclose(inFilePtr);
	return ( 0 );
}
