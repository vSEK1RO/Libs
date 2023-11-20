#ifndef CLIB_LOGICEXP_H
#define CLIB_LOGICEXP_H

/****************************** LOGICAL FUNCIONS ******************************/
/****************************** WITH ONE ARGUMENT *****************************/
/*
    ∀ universal = any(x)
    ∃ existential = exi(x)
*/
/***************************** WITH TWO ARGUMENTS *****************************/
/*
    ⇒ implication = imp(x,y)
    ⇔ equivalence = equ(x,y)
*/
/************************ WITH VARIABLE NUMBER OF ARGS ************************/
/*
    ¬ negation = not(x,y, ...)
    ∧ conjunction = and(x,y, ...)
    ∨ disjunction = or(x,y, ...)
    ⊕ exclusive disjunction = xor(x,y, ...)
    ↑ sheffer stroke = nand(x,y, ...)
    ↓ peirce arrow = nor(x,y, ...)
    ⊙ negation of xor = xnor(x,y, ...)
*/
/******************************************************************************/

/************************** EXAMPLE FOR INPUT STRING **************************/
/*
    char * str1 = str_cast("imp(any(x)any(y)P(x,y),exi(x)exi(y)P(x,y)")
    //similar to "∀x∀yP(x,y) ⇒ ∃x∃yP(x,y)"
    char * str2 = str_cast("any(x)exi(y)any(z)or(P(x),P(y),P(z))")
    //similar to "∀x∃y∀z(P(x) ∨ P(y) ∨ P(z))"
*/
/******************************************************************************/

typedef enum{
    ANY,
    EXI,
    IMP,
    EQU,
    NOT,
    AND,
    OR,
    XOR,
    NAND,
    NOR,
    XNOR,
}LogicFunc;

typedef struct{
    LogicFunc func,
    
}LogicNode;

{
    /* data */
};


#endif