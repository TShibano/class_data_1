#include	"SrchList.h"

enum {
	Insert = 1, Append, DspFst, DspLst, Delete, Remove, Print, Clear
};

CLink Input(char* lpszMessage);
int SelectMenu(void);

int main(void)
{
	int					nMenu;
	CSrchList			List;
	
	do{
		CLink			Temp;
		LPLINK			lpTemp;
		
		nMenu = SelectMenu();
		switch(nMenu){
		case Insert:
			Temp = Input("挿入");
			List.Insert(Temp);
			break;
		case Append:
			Temp = Input("追加");
			List.Append(Temp);
			break;
		case DspFst:
			if((lpTemp = List.SrchFirst()) != NULL){
				lpTemp->Print();
				putchar('\n');
			}
			break;
		case DspLst:
			if((lpTemp = List.SrchLast()) != NULL){
				lpTemp->Print();
				putchar('\n');
			}
			break;
		case Delete:
			List.Delete();
			break;
		case Remove:
			List.Remove();
			break;
		case Print:
			List.Print();
			break;
		case Clear:
			List.Clear();
			break;
		}
	}while(nMenu);
	
	return 1;
}

CLink Input(char* lpszMessage){
	char				lpszData[20];
	
	fprintf(stderr, "%sする文字列を入力してください：", lpszMessage);
	scanf("%s", lpszData);
	
	return CLink(lpszData);
}

int SelectMenu(void){
	int					nCh;
	
	do{
		puts("(1)・・・先頭に要素を追加　　(2)・・・末尾に要素を追加");
		puts("(3)・・・先頭の要素を表示　　(4)・・・末尾の要素を表示");
		puts("(5)・・・先頭の要素を削除　　(6)・・・末尾の要素を削除");
		puts("(7)・・・全ての要素を表示　　(8)・・・全ての要素を削除");
		puts("(0)・・・処理終了");
		scanf("%d", &nCh);
	}while(nCh < 0 || nCh > 8);
	
	return nCh;
}
