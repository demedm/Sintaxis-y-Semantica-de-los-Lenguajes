/*  hello.c
*   Programa que envía a stdout la línea Hello, World! o similar
*   Denise A Medina Mosquera 
*   31032025
*/
#include <stdio.h>

int main()
{
    char str[16] = "Buenos dias! :D";
    FILE *f;
    if(f=fopen("output.txt","wt"))
    {
        fprintf(f,"%s",str);
        fclose(f);
    }
    else 
    {
        printf("No se pudo abrir el archivo D:\n");
        fclose(f);
        return 1;
    }
    return 0;
}
