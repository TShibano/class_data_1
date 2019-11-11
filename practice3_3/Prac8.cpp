#include	<stdio.h>
#include	"Student.h"

int main(void)
{
	CStudent			mizu("水島　晃", 100,  70);
	CStudent			park("朴　宗洙",  80,  90);
	
	mizu.SetEng(90);				// 英語の点数を再設定
	mizu.Print();
	putchar('\n');
	park.Print();
	putchar('\n');
	
	return 1;
}
