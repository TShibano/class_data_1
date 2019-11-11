//-----------------------------------------------------------------------------
// SrchList.h 線形リストクラス(拡張)
//-----------------------------------------------------------------------------
#include	"List.h"

class CSrchList : public CList {
public:
	LPLINK SrchFirst(void);
	LPLINK SrchLast(void);
};
typedef	CSrchList*	LPSRCHLIST;
