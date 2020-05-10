#define PY_SSIZE_T_CLEAN
#include "C:\Users\�����\AppData\Local\Programs\Python\Python38\include\Python.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <Windows.h>

static PyObject *search(PyObject *self, PyObject *args)
{
    /*setlocale(LC_ALL,"Russian");*/
    /*setlocale (LC_ALL, "UTF-8");*/
    FILE *fp;
    /*char dir[100];*/
    char file_name[]="tag_file0.json";
    char symb='\0';
    int i=0;
    /*char key[100];*/
    PyObject *str;
    int key_len;
    if(!PyArg_ParseTuple(args,"O|i:decode i", &str,&key_len))
        return NULL;

    const char* key=PyUnicode_AsUTF8(str);

    char res_list[100];
    int counter=-1;
    int match=0;

    for(i=0;i<100;i++){
        res_list[i]='0';
    }

    if((fp = fopen(file_name, "r")) == NULL){
        printf("�� ������� ������� ����");
        getchar();
        return NULL;
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
                            /*return Py_BuildValue("ic", counter, symb);*/
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
    return Py_BuildValue("s#", res_list, match);
}


static PyMethodDef search_methods[] = {
{
    "search",          // �������� ������� ������ python
     search,        // ������� C
     METH_VARARGS,   // ������, ����������, ��� ������� � ��� � �����������
     "search function" // ������������ ��� ������� ������ python
},
{ NULL, NULL, 0, NULL }
// ��� ���������� sentiel. ������� �� ��������� ���������
// � ��� �� ����, ���� ������� ������� ������ ���� ������, � ��� ���� ���� ���������
};


static PyModuleDef search_module = {
    PyModuleDef_HEAD_INIT,   // ������������ ������
    "c_search",               // my_plus.__name__
    "documentation", // my_plus.__doc__
    -1,
    search_methods           // ���� �������� ������ ������
};



PyMODINIT_FUNC PyInit_c_search(void) {
      PyObject* m;
      // ������� ������
      m = PyModule_Create(&search_module);
      // ���� ��� ���������, �� ��� �������� �� ��������
      if (m == NULL)
          return Py_BuildValue("s", NULL);
      return m;
}
