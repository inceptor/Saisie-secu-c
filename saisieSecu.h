#ifndef SAISIESECU_H_INCLUDED
#define SAISIESECU_H_INCLUDED

#define TRUE 1
#define FALSE 0

#define TYPE_SIGNED_INT -1
#define TYPE_UNSIGNED_INT 1
#define TYPE_CHAR 2
#define TYPE_ALPHA_NUM 3

#define TYPE_SIGNED_FLOAT -1
#define TYPE_UNSIGNED_FLOAT 1

void emptyBuffer();
int typeVar(const char string[]);
int nbIntInChar(const char string[]);
int parseInt(const char string[],const int posNb);
int typeVarfloat(const char string[]);
double charConvertFloat(const char string[]);
float power(const int a,const int b);
int charConvertInt(const char string[]);
int scanInt();
float scanFloat();
double scanDouble();


#endif // SAISIESECU_H_INCLUDED
