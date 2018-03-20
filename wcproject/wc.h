#ifndef WC_H_
#define WC_H_

typedef struct BasicInfo
{
	int nc;     //字符数
	int nw;     //单词数
	int nl;     //行数
}BasicInfo;

BasicInfo *CWL(char *buf);

#endif // WC_H_

