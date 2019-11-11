//-----------------------------------------------------------------------------
// List.cpp 線形リストクラス
//-----------------------------------------------------------------------------
#include	<stdio.h>
#include	"List.h"

// CLinkクラス ----------------------------------------------------------------
CLink::CLink(char* lpszNewName /* = "" */){
	strcpy(lpszName, lpszNewName);
}

CLink* CLink::Next(void){
	return lpNext;
}

void CLink::Print(void){
	printf("%s", lpszName);
}


// CListクラス ----------------------------------------------------------------
CList::CList(void){
	lpFirst = lpLast = new CLink;
}

CList::~CList(){
	Clear();
	delete lpFirst;
}

CList& CList::Insert(const CLink& lpszNewName){
	LPLINK				lpOldFirst = lpFirst;
	
	lpFirst = new CLink;
	*lpFirst = lpszNewName;
	lpFirst->lpNext = lpOldFirst;
	
	return *this;
}

CList& CList::Append(const CLink& lpszNewName){
	LPLINK				lpOldLast = lpLast;
	
	*lpOldLast = lpszNewName;
	lpLast = new CLink;
	lpOldLast->lpNext = lpLast;
	
	return *this;
}

CList& CList::Delete(void){
	if(lpFirst != lpLast){
		LPLINK			lpFirstNext = lpFirst->lpNext;
		
		delete lpFirst;
		lpFirst = lpFirstNext;
	}
	return *this;
}

CList& CList::Remove(void){
	if(lpFirst != lpLast){
		LPLINK			lpNow = lpFirst;
		LPLINK			lpPre;
		
		while(lpNow->lpNext != lpLast){
			lpPre = lpNow;
			lpNow = lpNow->lpNext;
		}
		lpPre->lpNext = lpLast;
		delete lpNow;
	}
	
	return *this;
}

CList& CList::Clear(void){
	LPLINK				lpOld = lpFirst;
	
	while(lpOld != lpLast){
		LPLINK			lpOldNext = lpOld->lpNext;
		
		delete lpOld;
		lpOld = lpOldNext;
	}
	lpFirst = lpLast;
	
	return *this;
}

void CList::Print(void){
	puts("===== リスト一覧 =====");
	
	int					nNo = 1;
	LPLINK				lpNow = lpFirst;
	while(lpNow != lpLast){
		printf("%d : ", nNo++);
		lpNow->Print();
		putchar('\n');
		lpNow = lpNow->lpNext;
	}
}
