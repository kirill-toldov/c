#define PY_SSIZE_T_CLEAN
#include "C:\Users\Ирина\AppData\Local\Programs\Python\Python38\include\Python.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <Windows.h>

static PyObject *search(PyObject *self, PyObject *args)
{
    setlocale(LC_ALL,"Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    FILE *fp;
    /*char dir[100];*/
    char file_name[]="tag_file.json";
    char symb='\0';
    int i=0;
    /*char key[100];*/
    PyObject *str;
    if(!PyArg_ParseTuple(args,"O|i:decode", &str))
        return NULL;

    const char* key=PyUnicode_AsUTF8(str);

    char res_list[100];
    int key_len=0;
    while(key[i]!='\0'){
        i++;
        key_len++;
    }
    int counter=-1;
    int match=0;

    for(i=0;i<=100;i++){
        res_list[i]='0';
    }

    if((fp = fopen(file_name, "r")) == NULL){
        printf("Не удалось открыть файл");
        getchar();
        return 0;
    }

    while(!feof(fp)){
        symb=fgetc(fp);
        if(symb=='{'){
            counter++;
            /*
            for(i=0;i<10;i++){
                symb=fgetc(fp);
            }
            */
            /*
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
            */
            /*
            while(symb!='['){
                symb=fgetc(fp);
            }
            */

            while(symb!='}'){
                i=0;
                while(symb!=']'){
                    if(key[i]==symb){
                        i++;
                    }
                    else{
                        if(i==key_len){
                            res_list[match]=(char)counter;
                            match++;
                            printf("%d\n",counter);
                        }
                        i=0;
                    }
                    symb=fgetc(fp);
                }
                while(symb!='[' && symb!='}'){
                    symb=fgetc(fp);
                }
            /*printf("\n");*/
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
    return Py_BuildValue("s", key);
}


static PyMethodDef search_methods[] = {
{
    "search",          // название функции внутри python
     search,        // функция C
     METH_VARARGS,   // макрос, поясняющий, что функция у нас с аргументами
     "search function" // документация для функции внутри python
},
{ NULL, NULL, 0, NULL }
// так называемый sentiel. Сколько бы элементов структуры
// у вас не было, этот нулевой элемент должен быть всегда, и при этом быть последним
};


static PyModuleDef search_module = {
    PyModuleDef_HEAD_INIT,   // обязательный макрос
    "c_search",               // my_plus.__name__
    "documentation", // my_plus.__doc__
    -1,
    search_methods           // сюда передаем методы модуля
};



PyMODINIT_FUNC PyInit_c_search(void) {
      PyObject* m;
      // создаем модуль
      m = PyModule_Create(&search_module);
      // если все корректно, то эта проверка не проходит
      if (m == NULL)
          return Py_BuildValue("s", NULL);
      return m;
}
