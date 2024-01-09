// Cameron Atkins
// CompSci 4280
// P1 - Scanner

#include <stdio.h>
#include "token.h"
#include "scanner.h"
#include "testScanner.h"


char *tokenNames[]= {//"xopentk", "xclosetk", "xlooptk", "xdatatk", "xexittk", "xinttk", "xouttk", "xcondtk", "xthentk", "xlettk", "xfunctk",
                            "XOPENTK", "XCLOSETK", "XLOOPTK", "XDATATK", "XEXITTK", "XINTTK", "XOUTTK", "XCONDTK", "XTHENTK", "XLETTK", "XFUNCTK",
        "EOFTk", "IDTk", "INTEGERTk", 
  	"EQTk", "LESS_EQTk", "GR_EQTk", "GREATERTk", "LESSTk", "TILDETk", "COLTk", "SEMICOLTk", "PLUSTk", "MINUSTk", "MULTTk", "DIVTk", "MODTk", 
	"DOTTk", "LPARENTk", "RPARENTk", "COMMATk", "LBRACETk", "RBRACETk", "LBRACKTk", "RBRACKTk", 
};

void testScanner(FILE *inputFile) {
    token t;
    int endOfFile = 0;

    setLookaheadChar(inputFile);

    while (!endOfFile) {
    	t = scanner(inputFile);
	if (t.type == EOFtk) {
        	endOfFile = 1;
	}
	printToken(t);
    }
}

void printToken(token t) {
    if (t.type == LESS_EQtk){
        printf("Token Type: %s, Token Instance: %s, Line Number: %d\n", tokenNames[t.type], "<<", t.lineNum);
    }
    else if(t.type == GR_EQtk){
        printf("Token Type: %s, Token Instance: %s, Line Number: %d\n", tokenNames[t.type], ">>", t.lineNum);
    }
    else{
        printf("Token Type: %s, Token Instance: %s, Line Number: %d\n", tokenNames[t.type], t.instance, t.lineNum);
    }
}
