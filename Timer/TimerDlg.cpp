
#include "pch.h"
#include "framework.h"
#include "Timer.h"
#include "TimerDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



CTimerDlg::CTimerDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TIMER_DIALOG, pParent){
	m_bTimer = false;
	m_tStartClock = 0;
	m_tFinishClock = 0;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CTimerDlg::~CTimerDlg() {
	KillTimer(1);
}

void CTimerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_ALARM_TEXT, m_AlarmText);
	DDX_Control(pDX, IDC_EDIT_TIMER_TIME, m_TimerTime);
	DDX_Control(pDX, IDC_STATIC_REMAIN_TIME, m_csRemainTime);
	DDX_Control(pDX, IDC_COMBO1, m_combo);
}

BEGIN_MESSAGE_MAP(CTimerDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON1, &CTimerDlg::OnBnClickedButtonStart)
	ON_BN_CLICKED(IDC_BUTTON2, &CTimerDlg::OnBnClickedButtonStop)
END_MESSAGE_MAP()

BOOL CTimerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetIcon(m_hIcon, TRUE);			
	SetIcon(m_hIcon, FALSE);		

	SetWindowText(_T("알림 프로그램 Ver.0.2"));
	m_AlarmText.SetWindowTextW(_T("허리를 쭉 펴세요 \r\n눈을 깜빡이세요 \r\n머리를 뒤로 가져오세요."));
	m_TimerTime.SetWindowTextW(_T("10"));

	AddComboItem();

	CButton* pRadio1 = (CButton*)GetDlgItem(IDC_RADIO1);
	CButton* pRadio2 = (CButton*)GetDlgItem(IDC_RADIO2);
	pRadio1->SetCheck(false);
	pRadio2->SetCheck(true);
	pRadio1->EnableWindow(false);
	pRadio2->EnableWindow(true);

	return TRUE;  
}

void CTimerDlg::AddComboItem() {
	m_combo.AddString(_T("초"));
	m_combo.AddString(_T("분"));
	m_combo.AddString(_T("시간"));
	m_combo.SetCurSel(1);
}

void CTimerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); 

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

HCURSOR CTimerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTimerDlg::OnTimer(UINT_PTR nIDEvent)
{
	if (m_bTimer) {
		m_tFinishClock = clock();
		
		CString text;
		int leftTime = GetTime() - (m_tFinishClock - m_tStartClock);
		text.Format(_T("남은시간 : %d분 %d초"),
					leftTime/1000/60, leftTime/1000%60);

		m_csRemainTime.SetWindowTextW(text);

		if (GetTime() < m_tFinishClock - m_tStartClock) {
			m_bTimer = false;
			::SetWindowPos(GetSafeHwnd(), HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
			if (MessageBoxW(GetText(), _T("알림!!!"), MB_OK) == IDOK) {
				m_tStartClock = clock();
				m_bTimer = true;
			}
		}
	}


	CDialogEx::OnTimer(nIDEvent);
}


void CTimerDlg::OnBnClickedButtonStart()
{
	m_bTimer = true;
	m_tStartClock = clock();



	SetTimer(1, 100, NULL);

	m_TimerTime.SetReadOnly();
	CButton* pRadio1 = (CButton*)GetDlgItem(IDC_RADIO1);
	CButton* pRadio2 = (CButton*)GetDlgItem(IDC_RADIO2);
	pRadio1->SetCheck(true);
	pRadio2->SetCheck(false);
	pRadio1->EnableWindow(true);
	pRadio2->EnableWindow(false);
}

int CTimerDlg::GetTime() {
	CString temp;
	m_TimerTime.GetWindowTextW(temp);
	int selectedTime = m_combo.GetCurSel();
	int writedTime = _ttoi(temp);
	if (selectedTime == 0) {
		return writedTime * 1000;
	}
	else if(selectedTime == 1){
		return writedTime * 1000 * 60;
	}
	else if(selectedTime == 2){
		return writedTime * 1000 * 60 * 60;
	}

	return _ttoi(temp);
}

CString CTimerDlg::GetText() {
	CString temp;
	m_AlarmText.GetWindowTextW(temp);
	return temp;
}


void CTimerDlg::OnBnClickedButtonStop()
{
	KillTimer(1);

	m_TimerTime.SetReadOnly(false);
	CButton* pRadio1 = (CButton*)GetDlgItem(IDC_RADIO1);
	CButton* pRadio2 = (CButton*)GetDlgItem(IDC_RADIO2);

	pRadio1->SetCheck(false);
	pRadio1->EnableWindow(false);
	pRadio2->SetCheck(true);
	pRadio2->EnableWindow(true);


}


void CTimerDlg::OnOK()
{
	//CDialogEx::OnOK();
}
