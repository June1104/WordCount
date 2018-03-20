#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wc.h"
#include "file.h"


int main(int argc, char **argv)
{
	/*��������*/
	int i, end;
	char *path = NULL, *p = NULL, *filename = NULL;


	/*��ʼ������*/
	for (i = 1; i < argc; ++i)/*argc���������ܵĲ�������*/
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

	/*���ļ����������ͻ�����̣���ȡ�ַ�������������������*/
	char *buf = readfile(path);
	BasicInfo *info = CWL(buf);


	/*���̿�������*/
	freopen(filename, "w", stdout);
	for (i = 1; i < end; ++i)
	{
		if (strcmp(argv[i], "-c") == 0)
			printf("%s, �ַ���:%d\n", path, info->nc);
		if (strcmp(argv[i], "-w") == 0)
			printf("%s, ������:%d\n", path, info->nw);
		if (strcmp(argv[i], "-l") == 0)
			printf("%s, ����:%d\n", path, info->nl);
	}/*��ͬ�ĺ�׺��ͬ�����ж�*/

	return EXIT_SUCCESS;
}