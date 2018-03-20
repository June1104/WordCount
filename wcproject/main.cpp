#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wc.h"
#include "file.h"


int main(int argc, char **argv)
{
	/*声明变量*/
	int i, end;
	char *path = NULL, *p = NULL, *filename = NULL;


	/*初始化变量*/
	for (i = 1; i < argc; ++i)/*argc是命令行总的参数个数*/
	{
		p = argv[i];
		while (*++p != NULL);
		if (strcmp(p - 2, ".c") == 0)
		{
			path = argv[i];
			end = i;
		}

		if (strcmp(p - 4, ".txt") == 0)
		{
			if (strcmp(argv[i - 1], "-o") == 0)
				filename = argv[i];
			else
			{
				printf("error.\n");
				return EXIT_FAILURE;
			}
		}
	}

	/*读文件到缓冲区和缓冲进程，获取字符数，单词数，代码数*/
	char *buf = readfile(path);
	BasicInfo *info = CWL(buf);


	/*进程控制命令*/
	freopen(filename, "w", stdout);
	for (i = 1; i < end; ++i)
	{
		if (strcmp(argv[i], "-c") == 0)
			printf("%s, 字符数:%d\n", path, info->nc);
		if (strcmp(argv[i], "-w") == 0)
			printf("%s, 单词数:%d\n", path, info->nw);
		if (strcmp(argv[i], "-l") == 0)
			printf("%s, 行数:%d\n", path, info->nl);
	}/*不同的后缀不同功能判断*/

	return EXIT_SUCCESS;
}