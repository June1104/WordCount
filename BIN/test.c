#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wc.h"
#include "file.h"


int main(int argc, char **argv)
{
    /*state val*/
    int i, end;
    char *path = NULL, *p = NULL, *filename = NULL;


    /*initialize val*/
    for(i = 1; i < argc; ++i)
    {
        p = argv[i];
        while(*++p != NULL)
            ;
        if(strcmp(p - 2, ".c") == 0)
        {
            path = argv[i];
            end  = i;
        }

        if(strcmp(p - 4, ".txt") == 0)
        {
            if(strcmp(argv[i - 1], "-o") == 0)
                filename = argv[i];
            else
            {
                printf("command line error.\n");
                return EXIT_FAILURE;
            }
        }
    }

    /*read file to buffer and process buffer,get the number of char, word, line*/
    char *buf = readfile(path);
    BasicInfo *info = CWL(buf);


    /*process  command line*/
    freopen(filename, "w", stdout);
    for(i = 1; i < end; ++i)
    {
        if(strcmp(argv[i], "-c") == 0)
            printf("%s, 字符数:%d\n", path, info->nc);
        if(strcmp(argv[i], "-w") == 0)
            printf("%s, 单词数:%d\n", path, info->nw);
        if(strcmp(argv[i], "-l") == 0)
            printf("%s, 行数:%d\n", path, info->nl);
    }
	
    return EXIT_SUCCESS;
}
