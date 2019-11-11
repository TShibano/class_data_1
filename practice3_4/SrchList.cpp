//-----------------------------------------------------------------------------
// SrchList.h 線形リストクラス(拡張)
//-----------------------------------------------------------------------------
#include	"SrchList.h"

LPLINK CSrchList::SrchFirst(void){
	return (lpFirst == lpLast) ? NULL : lpFirst;
}

LPLINK CSrchList::SrchLast(void){
	if(lpFirst == lpLast)
		return NULL;
	LPLINK				lpNow = lpFirst;
	while(lpNow->Next() != lpLast)
		lpNow = lpNow->Next();
	
	return lpNow;
}
