// Cameron Atkins
// CompSci 4280
// P1 - Scanner

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "character.h"
#include "scanner.h"
#include "token.h"

typedef enum {
        ERROR = -1,
        s1 = 0, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13, s14, s15, s16, s17, s18, s19, s20, s21, s22, s23, s24,
        FINAL = 100
} state;

int fsaTable[24][26] = {

// a-z    A-Z    0-9     WS      =      <<      >>      >      <      ~      :       ;       +      -      *      /      %      .      (      )      ,      {      }      [      ]    EOF   //
// //-----------------------------------------------------------------------------------------------------------------------------------------------------------------
{s2,    ERROR,   s3,   s1,   s4,     s5,    s6,    s7,  s8,    s9,   s10,   s11,   s12,   s13,   s14,   s15,   s16,   s17,   s18,   s19,   s20,   s21, s22, s23, s24,  FINAL}, // s1
{s2,    s2,    s3,    FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL}, // s2
{FINAL, FINAL, s3,    FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL}, // s3
{FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL}, // s4
{FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL}, // s5
{FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL}, // s6
{FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL}, // s7
{FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL}, // s8
{FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL}, // s9
{FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL}, // s10
{FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL}, // s11
{FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL}, // s12
{FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL}, // s13
{FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL}, // s14
{FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL}, // s15
{FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL}, // s16
{FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL}, // s17
{FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL}, // s18
{FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL}, // s19
{FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL}, // s20
{FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL},  // s21
{FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL},  // s22
{FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL},  // s23
{FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL} // s24
};

char *keywords[] = {
	"xopen", "xclose", "xloop", "xdata", "xexit", "xin", "xout", "xcond", "xthen", "xlet", "xfunc",
};
const int NUM_KEYWORDS = 11;
const int LENGTH = 8; // Maximum length of a token instance
int lineNum = 1;
character nextChar;
FILE *iFile;


void setLookaheadChar(FILE *inputFile) {
	nextChar = filter(inputFile);
}

token scanner(FILE *inputFile) {
	return fsaDriver(inputFile);
}

token fsaDriver(FILE *inputFile) {
	state currentState = s1;
	state nextState;
	token newToken = {ERROR, "", 0};
	char word[9] = "";

	while (currentState != FINAL) {
		nextState = fsaTable[currentState][nextChar.tableColNum];

		if (nextState == ERROR) {
			printf("\nLexical Error: No token begins with '%c' (line %d)\n", nextChar.value, nextChar.lineNum);
			exit(ERROR);
		}
		if (nextState == FINAL) {
			newToken.type = currentState + NUM_KEYWORDS;
			strcpy(newToken.instance, word);
			newToken.lineNum = nextChar.lineNum;

				if (currentState == s2) {
					int i;
					for (i = 0; i < NUM_KEYWORDS; i++) {
						if (strcmp(keywords[i], newToken.instance) == 0) {
							newToken.type = i;
						}
					}
				}
			return newToken;
		}
		else {
			if (nextChar.tableColNum != WS) {
				word[strlen(word)] = nextChar.value;
				word[strlen(word)+1] = '\0';
			}

			currentState = nextState;
			nextChar = filter(inputFile);

			if (strlen(word) == LENGTH) {
				newToken.type = currentState + NUM_KEYWORDS;
				strcpy(newToken.instance, word);
				newToken.lineNum = nextChar.lineNum;
				return newToken;
			}
		}
	}
	return newToken;
}

character filter(FILE *inputFile) {
	character input;
	char x = fgetc(inputFile);
	//int colNum = getTableColNum(x);
	char nextChar = ' ';
	int colNum = getTableColNum(inputFile, x, nextChar);

        while (colNum == COMMENT) {
            do {
	        x = fgetc(inputFile);
	        if (x == '\n') {
	            lineNum++;
		}
	    } while (x != '$');
	    	x = fgetc(inputFile);
	    	//colNum = getTableColNum(x);
			colNum = getTableColNum(inputFile, x, nextChar);
	}

	if (colNum >= LOWER && colNum <= ENDOFFILE) {
		input.value = x;
		input.tableColNum = colNum;
		input.lineNum = lineNum;
		if (x == '\n') {
			lineNum++;
		}
		return input;
	}

	else {
		printf("\nScanner Error: Character '%c' not in alphabet (line %d)", x, lineNum);
		exit(colNum);
	}

	
}



int getTableColNum(FILE *inputFile, char x ,char nextChar) {
	if (islower(x)) {
		return LOWER;
	}
	if (isupper(x)) {
		return UPPER;
	}
	if (isdigit(x)) {
		return INT;
	}
	if (isspace(x)) {
		return WS;
	}
	if (x == '=') {
		return EQ;
	}
	if(x == '<'){
		char c = fgetc(inputFile);
		if (c == '<'){
			x = '&';
			return LESS_EQ;
		}
		else{
			return LESS;
		}
	}
	if(x == '>'){
		char c = fgetc(inputFile);
		if (c == '>'){
			x = '!';
			return GR_EQ;
		}
		else{
			return GREATER;
		}
	}
	if (x == '~'){
		return TILDE;
	}
	if(x == ':'){
		return COL;
	}
	if(x == ';'){
		return SEMICOL;
	}
	if (x == '+') {
		return PLUS;
	}
	if (x == '-') {
		return MINUS;
	}
	if (x == '*') {
		return MULT;
	}
	if (x == '/') {
		return DIV;
	}
	if (x == '%') {
		return MOD;
	}
	if (x == '.') {
		return DOT;
	}
	if (x == '(') {
		return LPAREN;
	}
	if (x == ')') {
		return RPAREN;
	}
	if (x == ',') {
		return COMMA;
	}
	if (x == '{') {
		return LBRACE;
	}
	if (x == '}') {
		return RBRACE;
	}
	if (x == '[') {
		return LBRACK;
	}
	if (x == ']') {
		return RBRACK;
	}
	if (x == EOF) { 
		return ENDOFFILE;
	}
	if (x == '$') {
		return COMMENT;
	}
	return ( -1 );
}


