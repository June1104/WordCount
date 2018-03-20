#include "wc.h"
#include <stdlib.h>
#define IN  1       //在单词内
#define OUT 0       //在单词外




int isalpha(char a) {
	if ((a <= 'z'&&a >= 'a') || (a <= 'Z'&&a >= 'A'))
		return 1;
	return 0;
}/*判断是否是单词*/
int isspace(char c) {
	if ((' ' == c) || ('\n' == c) || ('\t' == c) ||
		(',' == c) || (';' == c) || (')' == c) ||
		('(' == c) || ('{' == c) || ('}' == c))
		return 1;
	return 0;
}/*判断是否是分隔符*/
 /*
 **统计文件中的字符数，单词数和行数
 **参数是buf首地址
 */
BasicInfo *CWL(char *buf)
{
	BasicInfo *info = (BasicInfo *)malloc(sizeof(BasicInfo));
	int state, c;

	info->nc = info->nl = info->nw = 0;
	state = OUT;

	while ((c = *buf++) != '\0')
	{
		++info->nc;
		if ('\n' == c)
			++info->nl;
		if (isspace(c))
			state = OUT;
		else if (isalpha(c) && OUT == state)
		{
			state = IN;
			++info->nw;
		}
	}
	++info->nl;


	return info;
}