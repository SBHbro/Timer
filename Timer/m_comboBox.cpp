// m_comboBox.cpp: 구현 파일
//

#include "pch.h"
#include "Timer.h"
#include "m_comboBox.h"
#include "afxdialogex.h"


// m_comboBox 대화 상자

IMPLEMENT_DYNAMIC(m_comboBox, CDialogEx)

m_comboBox::m_comboBox(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TIMER_DIALOG, pParent)
{

}

m_comboBox::~m_comboBox()
{
}

void m_comboBox::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(m_comboBox, CDialogEx)
END_MESSAGE_MAP()


// m_comboBox 메시지 처리기
