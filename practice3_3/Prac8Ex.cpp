#include	<stdio.h>
#include	"StudentEx.h"

int main(void)
{
	CStudentEx			mizu("水島　晃", 100,  70, 90);
	CStudentEx			park("朴　宗洙",  80,  90, 80);
	
	mizu.SetEng(90);				// 英語の点数を再設定
	mizu.Print();
	putchar('\n');
	park.Print();
	putchar('\n');
	
	return 1;
}
