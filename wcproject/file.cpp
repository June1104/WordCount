#pragma warning(disable:4996)
#include "file.h"
#include <stdio.h>
#include <stdlib.h>

/*
**返回文件中字符数
**参数是文件指针
*/
static int
filelength(FILE *fp)
{
	int num;
	fseek(fp, 0, SEEK_END);
	num = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	return num;
}



char *readfile(char *path)/*返回buf首地址 参数是文件路径*/
{
	FILE *fp;
	int len;
	char *buf;


	if ((fp = fopen(path, "r")) == NULL)
	{
		printf("open file %s error.\n", path);
		exit(0);
	}


	len = filelength(fp);
	buf = (char *)malloc(len);
	fread(buf, sizeof(char), len, fp);
	fclose(fp);
	*(buf + len - 1) = '\0';
	return buf;
}