#include <stdio.h>
#include <stdlib.h>

#include "saisieSecu.h"

void emptyBuffer()
{
    int c;
    while((c=getchar())!='\0' && c!='\n');
}

int typeVar(const char string[])
{
    int nbint=0,i=0,signe=FALSE;

    for(i=0;string[i]!='\0';i++)
    {
        if(string[i]>='0' && string[i]<='9')
        {
            nbint++;
            if( (i-1)>=0 ){
                if(string[i-1]=='-')
                    signe=TRUE;
            }
        }
    }

    if(nbint==i)
        return TYPE_UNSIGNED_INT;
    else if( (nbint+1)==i && signe==TRUE )
        return TYPE_SIGNED_INT;
    else if(nbint>0)
        return TYPE_ALPHA_NUM;
    else if(nbint==0)
        return TYPE_CHAR;
    else
        return 0;
}

int nbIntInChar(const char string[])
{
    int nbInt=0,thereAreInt=FALSE,i=0;

    for(i=0;string[i]!='\0';i++)
    {
        if(string[i]>='0' && string[i]<='9' && thereAreInt==FALSE )
        {
            nbInt++;
            thereAreInt=TRUE;
        }
        else if( !(string[i]>='0' && string[i]<='9') && thereAreInt==TRUE)
            thereAreInt=FALSE;
    }

    return nbInt;
}

int parseInt(const char string[],const int posNb)
{
    int nbInt=0,thereAreInt=FALSE,i=0,j=0;
    char number[20]={'0'};

    for(i=0;string[i]!='\0' && posNb>0 ;i++)
    {
        if(string[i]>='0' && string[i]<='9' && thereAreInt==FALSE )
        {
            nbInt++;
            thereAreInt=TRUE;
        }
        else if( !(string[i]>='0' && string[i]<='9') && thereAreInt==TRUE)
            thereAreInt=FALSE;

        if(posNb==nbInt && string[i]>='0' && string[i]<='9' )
        {
            number[j]=string[i];
            j++;
        }
    }
    number[j]='\0';

    return charConvertInt(number);
}

int typeVarfloat(const char string[])
{
    if(typeVar(string) == TYPE_ALPHA_NUM )
    {
        int i=0,posPoint=0,signe=FALSE,erreur=FALSE;

        for(i=0;string[i]!='\0';i++)
        {
            if(string[i]>='0' && string[i]<='9')
            {
                if( (i-1)>=0 ){
                    if(string[i-1]=='-')
                        signe=TRUE;
                }
            }
            else if( !(string[i]>='0' && string[i]<='9') && string[i]!='-' && string[i]!='.' )
                erreur=TRUE;

            if(string[i]=='.' && posPoint==0 )
                posPoint=i;
            else if(string[i]=='.' && posPoint!=0)
                erreur=TRUE;
        }

        if(erreur)
            return 0;
        else if(signe)
            return TYPE_SIGNED_FLOAT;
        else
            return TYPE_UNSIGNED_FLOAT;
    }
    else
        return 0;
}

double charConvertFloat(const char string[])
{
    int i=0,lenght=0,erreur=FALSE,signe=FALSE;
    double nb=0.0;

    //On calcul la grandeur du nombre entier et on retire le caractére . de la taile
    for(lenght=0;string[lenght]!='.';lenght++);
    lenght--;

    for(i=0;string[i]!='\0';i++)
    {
        if(string[i]>='0' && string[i]<='9')
        {
            nb+=power(10,lenght-i)*(string[i]-'0');
        }
        else
        {
            if(i==0 && string[i]=='-' && lenght>1 )
                signe=TRUE;
            else if(lenght+1==i && string[i]=='.')
                lenght++;
            else
                erreur=TRUE;
        }
    }

    if(signe==TRUE)
        nb*=-1;

    if(erreur==0)
        return nb;
    else
        return -1;
}

float power(const int a,const int b)
{
    int i=0;
    float result=1;

    for(i=0;i<b && b>0;i++)
        result*=a;
    for(i=0;i>b && b<0;i--)
        result/=a;

    return result;
}

int charConvertInt(const char string[])
{
    int i=0,lenght=0,erreur=FALSE,signe=FALSE,nb=0;

    //On calcul la grandeur de la chaine et on retire le caractére \0 de la taile
    for(lenght=0;string[lenght]!='\0';lenght++);
    lenght--;

    for(i=0;string[i]!='\0';i++)
    {
        if(string[i]>='0' && string[i]<='9')
        {
            nb+=power(10,lenght-i)*(string[i]-'0');
        }
        else
        {
            if(i==0 && string[i]=='-' && lenght>1 )
                signe=TRUE;
            else
                erreur=TRUE;
        }
    }

    if(signe==TRUE)
        nb*=-1;

    if(erreur==0)
        return nb;
    else
        return -1;
}

int scanInt()
{
    //un unsigned long long possede 20 chiffres
    char string[21];

    scanf("%20s",string);

    //sécurité du buffer
    emptyBuffer();

    if(typeVar(string))
        return charConvertInt(string);
    else
        return -1;
}

float scanFloat()
{
    //un float possede 39 chiffres ( moins le . )
    char string[41];

    scanf("%40s",string);

    //sécurité du buffer
    emptyBuffer();

    if(typeVarfloat(string))
        return charConvertFloat(string);
    else
        return -1;
}

double scanDouble()
{
    char string[300];

    scanf("%300s",string);

    //sécurité du buffer
    emptyBuffer();

    if(typeVarfloat(string))
        return charConvertFloat(string);
    else
        return -1;
}

int main()
{
    float nb=0;

    printf("Inserrer un nombre :");
    nb=scanFloat();

    printf("%f",nb);

    return 0;
}
