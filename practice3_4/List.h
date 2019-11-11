//-----------------------------------------------------------------------------
// List.h 線形リストクラス
//-----------------------------------------------------------------------------
#include	<stdio.h>
#include	<string.h>

class CLink {
private:
	friend class		CList;		// CListクラスのlpFirst, lpLastにアクセス
	CLink*				lpNext;		// 次の要素へのポインタ
	char				lpszName[20];
									// 実際のデータ
public:
	CLink(char* lpszNewName = "");	// コンストラクタ
	
	CLink* Next(void);
	void Print(void);
};
typedef	CLink*	LPLINK;

class CList {
protected:
	LPLINK				lpFirst;	// 最初の要素へのポインタ
	LPLINK				lpLast;		// 最後の要素へのポインタ
public:
	CList(void);					// コンストラクタ
	~CList();						// デストラクタ
	
	CList& Insert(const CLink& lpszNewName);
									// 先頭に要素を追加
	CList& Append(const CLink& lpszNewName);
									// 末尾に要素を追加
	CList& Delete(void);			// 先頭要素を削除
	CList& Remove(void);			// 末尾要素を削除
	CList& Clear(void);				// 全要素を削除
	void Print(void);				// 全要素を表示
};
typedef CList*	LPLIST;
