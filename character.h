//Cameron Atkins
//CompSci 4280
//P1 - Scanner

#ifndef CHARACTER_H
#define CHARACTER_H

typedef struct {
        char value;
        int tableColNum;
        int lineNum;
} character;

/*
typedef enum {
	LOWER, UPPER, INT, WS, EQ, LESS, GREATER, COL, PLUS, MINUS, MULT, DIV, MOD, DOT, LPAREN,
	RPAREN, COMMA, LBRACE, RBRACE, SEMICOL, LBRACK, RBRACK, ENDOFFILE, COMMENT
} characterType;
*/

typedef enum {
        LOWER, UPPER, INT, WS, EQ, LESS_EQ, GR_EQ, GREATER, LESS, TILDE, COL, SEMICOL, PLUS, MINUS, MULT, DIV, MOD, DOT, LPAREN,
        RPAREN, COMMA, LBRACE, RBRACE, LBRACK, RBRACK, ENDOFFILE, COMMENT,
} characterType;

#endif
