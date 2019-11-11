#include	"List.h"

int main(void)
{
	CList				List;
	
	List.Append(CLink("木瀬道夫"));
	List.Insert(CLink("石井一暢"));
	List.Append(CLink("水島　晃"));
	List.Append(CLink("朴　宗洙"));
	List.Print();
	
	return 1;
}
