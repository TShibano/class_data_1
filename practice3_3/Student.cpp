//-----------------------------------------------------------------------------
// Student.cpp 学生クラス
//-----------------------------------------------------------------------------
#include	<stdio.h>
#include	<string.h>
#include	"Student.h"

CStudent::CStudent(const char* lpszNewName, int nNewEng, int nNewMath){
	strcpy(lpszName, lpszNewName);
	nEng = nNewEng;
	nMath = nNewMath;
}

void CStudent::SetName(const char* lpszNewName){
	strcpy(lpszName, lpszNewName);
}

void CStudent::Print(void){
	printf("%s%4d%4d", lpszName, nEng, nMath);
}
