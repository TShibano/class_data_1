//-----------------------------------------------------------------------------
// Student.cpp 学生クラス
//-----------------------------------------------------------------------------
#include	<stdio.h>
#include	"StudentEx.h"

CStudentEx::CStudentEx(const char* lpszNewName, int nNewEng, int nNewMath,
		int nNewChem) : CStudent(lpszNewName, nNewEng, nNewMath){
	nChem = nNewChem;
}

void CStudentEx::Print(void){
	CStudent::Print();
	printf("%4d", nChem);
}
