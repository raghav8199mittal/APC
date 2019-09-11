#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

/*
 * Complete the function below.
 */
// char res[4];
char* encode(char* input) {

    char s[64]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz+/0123456789";
    int l=0;
    int p=0;
    while(input[p]!='\0')
    {l++;p++;}
    int i=0,j=0;
    int ll=l;
    if(ll%3!=0)
    {ll+=4;}
    char *res=(char*)malloc(((ll/3)*4)*sizeof(char));
    int l1=l-l%3;
    while(l1>0)
    {
        char a,b,c,d;
        a=(input[i]&0xFC)>>2;
        b=(((input[i]&0x03)<<4)|((input[i+1]&0xF0)>>4));
        c=(((input[i+1]&0x0F)<<2)|((input[i+2]&0xC0)>>6));
        d=(input[i+2]&0x3F);
        l1-=3;
        i+=3;
        res[j++]=s[a];
        res[j++]=s[b];
        res[j++]=s[c];
        res[j++]=s[d];
    }
    if(l%3==0)
    return res;
    else
    {
        char a,b,c,d;
        int y=l%3;
        if(y==1)
        {
            a=input[i]>>2;
            b=((input[i]&0x03)<<4);
            c='=';
            d='=';
            res[j++]=s[a];
            res[j++]=s[b];
            res[j++]=c;
            res[j++]=d;
        }
        else
        {
            a=input[i]>>2;
            b=(((input[i]&0x03)<<4)|((input[i+1]&0xF0)>>4));
            c=(input[i+1]&0x0F)<<2;
            d='=';
            res[j++]=s[a];
            res[j++]=s[b];
            res[j++]=s[c];
            res[j++]=d;
        }
        return res;
    }
}
int main() {
    char *output_path = getenv("OUTPUT_PATH");
    FILE *f;
    if (output_path != NULL) {
        f = fopen(output_path, "w");
    }
    else {
        f = stdout;
    }

    char* res;
    char* input;
    input = (char *)malloc(512000 * sizeof(char));
    scanf("\n%[^\n]",input);

    res = encode(input);
    fprintf(f, "%s\n", res);

    fclose(f);
    return 0;
}
