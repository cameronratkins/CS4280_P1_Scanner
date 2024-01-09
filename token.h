// Cameron Atkins
// CompSci 4280
// P1 - Scanner

#ifndef TOKEN_H
#define TOKEN_H 

typedef enum{ 
	// keywords
	
        XOPENtk, XCLOSEtk, XLOOPtk, XDATAtk, XEXITtk, XINtk, XOUTtk, XCONDtk, XTHENtk, XLETtk, XFUNCtk,
		EOFtk, IDtk, INTEGERtk, // identifiers, integers
        EQtk, LESS_EQtk, GR_EQtk, GREATERtk, LESStk, TILDEtk, COLtk, SEMICOLtk, PLUStk, MINUStk, MULTtk, DIVtk, MODtk, DOTtk, LPARENtk, // relational operators
        RPARENtk, COMMAtk, LBRACEtk, RBRACEtk, LBRACKtk, RBRACKtk, // and delimeters
} tokenType;

typedef struct {
        tokenType type;
        char instance[9]; 
        int lineNum;
} token;

#endif
