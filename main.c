#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main()
{
    setlocale(LC_ALL,"Russian");
    FILE *fp;
    char dir[100];
    char file_name[]="tag_file.json";
    char symb='\0';
    int i=0,j=0;
    char key[]="beka";
    char *res_list[100];
    int key_len=strlen(key);


    if((fp = fopen(file_name, "r")) == NULL){
        printf("Не удалось открыть файл");
        getchar();
        return 0;
    }
    while(!feof(fp)){
        symb=fgetc(fp);
        if(symb=='{'){
            for(i=0;i<10;i++){
                symb=fgetc(fp);
            }

            for(i=0;i<100;i++){
                dir[i]='\0';
            }

            i=1;
            dir[0]='.';
            while(symb!='"'){
                dir[i]=symb;
                symb=fgetc(fp);
                i++;
            }
            printf("%s\n",dir);


           while(symb!='['){
                symb=fgetc(fp);
            }

            while(symb!='}'){
                while(symb!=']'){
                    printf("%c",symb);
                    symb=fgetc(fp);
                }
                while(symb!='[' && symb!='}'){
                    symb=fgetc(fp);
                }
            printf("\n");
            }

            }
        }
/*
    for(i=0;i<=10000;i++){
        symb=fgetc(fp);
        printf("%c",symb);
    }
*/
/*
    symb='\0';
    while(!feof(fp)){
        symb=fgetc(fp);
        printf("%c",symb);
    }
*/
    fclose(fp);
    return 0;
}
