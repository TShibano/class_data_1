//-----------------------------------------------------------------------------
// Student.h 学生クラス
//-----------------------------------------------------------------------------
class CStudent {
private:
	char				lpszName[20];	// 氏名
	int					nEng;		// 英語の点数
	int					nMath;		// 数学の点数
public:
	CStudent(const char* lpszNewName, int nNewEng, int nNewMath);
	void SetName(const char* lpszNewName);
	void SetEng(int nNewEng) { nEng = nNewEng; }
	void SetMath(int nNewMath) { nMath = nNewMath; }
	char* Name(void) { return lpszName; }
	int English(void) { return nEng; }
	int Mathmatics(void) { return nMath; }
	void Print(void);
};
typedef CStudent*	LPSTUDENT;
