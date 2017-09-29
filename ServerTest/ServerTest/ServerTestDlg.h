
// ServerTestDlg.h : 헤더 파일
//

#pragma once


// CServerTestDlg 대화 상자
class CServerTestDlg : public CDialogEx
{
// 생성입니다.
public:
	CServerTestDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_SERVERTEST_DIALOG };

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
	BOOL m_radio;
	afx_msg void OnBnClickedRadio1(UINT msg);
	afx_msg void OnBnClickedBtnConnect();
};
