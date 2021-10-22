#pragma once


// m_comboBox 대화 상자

class m_comboBox : public CDialogEx
{
	DECLARE_DYNAMIC(m_comboBox)

public:
	m_comboBox(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~m_comboBox();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TIMER_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
