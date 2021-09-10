
// TimerDlg.h: 헤더 파일
//

#pragma once


// CTimerDlg 대화 상자
class CTimerDlg : public CDialogEx
{
// 생성입니다.
public:
	CTimerDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
	~CTimerDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TIMER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CEdit m_AlarmText;
	CEdit m_TimerTime;
	BOOLEAN m_bTimer;
	clock_t m_tStartClock;
	clock_t m_tFinishClock;
	afx_msg void OnBnClickedButton1();
	int GetTime();
	CString GetText();
	afx_msg void OnBnClickedButton2();
	virtual void OnOK();
	CStatic m_csRemainTime;
};
