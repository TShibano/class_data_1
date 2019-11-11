//--------------------------------------
// StudenetEx.h 学生クラス(拡張)
//--------------------------------------
#include "Student.h"

class CStudentEx::public CStudent{
private:
    int nChem;  // 化学の点数
public:
    CStudentEx(const char* lpszNewName, int nNewEng, int nNewMath, int nNewChem);
    void SetChem(int nNewChem){
        nChem = nNewChem;
    }
    int Chemical(void){
        return nChem;
    }
    void Print(void);

}