//=============================================================================
// ダイアログボックスベースのアプリケーション
// === モードレスダイアログ版 ===
//=============================================================================
#include	<windows.h>
#include	<windowsx.h>
#include	"resource.h"

BOOL CALLBACK DialogProc(HWND hWnd, UINT uMes, WPARAM wp, LPARAM lp);
BOOL QuitMessage(HWND hDlg);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow){
	// モードレスダイアログボックスを作成する
	// ダイアログボックスが作成されると処理が戻ります
	static HWND			hDlg;
	hDlg = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_DIALOG), NULL,
		(DLGPROC)DialogProc);

	// アクセラレータのロード
	//	HACCEL				hAccel;		// アクセラレータテーブルのハンドル
	//	hAccel = LoadAccelerators(hInstance, MAKEINTATOM(IDR_ACCELERATOR));

	// メッセージループを生成する
	MSG					msg;
	do{
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)){
			if (msg.message == WM_QUIT)
				break;				// PeekMessage while()ループを抜ける
			//			if(TranslateAccelerator(hWnd, hAccel, &msg))
			//				continue;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		if (msg.message == WM_QUIT)
			break;					// WaitMessage while()ループを抜ける
	} while (WaitMessage());

	return msg.wParam;
}

BOOL CALLBACK DialogProc(HWND hDlg, UINT uMsg, WPARAM wp, LPARAM lp){
	static HINSTANCE	hInstance;
	//TCHAR lpszText[128] = TEXT("hoge");
	UINT N;
	int n = 42;
	int* num = &n;

	switch (uMsg){
	case WM_INITDIALOG:				// ダイアログを作成するときに呼び出される
		hInstance = (HINSTANCE)GetWindowLong(hDlg, GWL_HINSTANCE);
		SetClassLong(hDlg, GCLP_HICON, (LONG)LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON)));
		ShowWindow(hDlg, SW_SHOW);
		UpdateWindow(hDlg);
		SetDlgItemInt(hDlg, IDC_STATIC1, n, false);
		break;

	case WM_CLOSE:					// ×印を押したとき
		if (QuitMessage(hDlg)){		// 終了確認のメッセージを表示する
			DestroyWindow(hDlg);	// ダイアログを破棄する
			PostQuitMessage(0);		// WinMainにWM_QUITを送る
			return TRUE;
		}
		return TRUE;

		// メニューから呼び出されるメッセージ
	case WM_COMMAND:
		switch (LOWORD(wp)){
		case IDM_QUIT:				// [ファイル]-[アプリケーションの終了]
			PostMessage(hDlg, WM_CLOSE, 0, 0L);
			return TRUE;
		case IDC_BUTTON1:
			MessageBox(hDlg, TEXT("OK"), TEXT("OKOK"), MB_OK);
		case IDOK:
			N = GetDlgItemInt(hDlg, IDC_EDIT1, num, false);
			SetDlgItemInt(hDlg, IDC_STATIC1, N, false);
			break;
		case IDCANCEL:
			EndDialog(hDlg, 0);
			return TRUE;
		}
		break;
	}
	return FALSE;					// 何もしないときはFALSEを返す
}

BOOL QuitMessage(HWND hDlg){
	if (MessageBox(hDlg, TEXT("終了してもよろしいですか？"), TEXT("終了確認"),
		MB_YESNO | MB_ICONQUESTION) == IDYES)
		return TRUE;
	return FALSE;
}