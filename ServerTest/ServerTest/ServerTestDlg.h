
// ServerTestDlg.h : ��� ����
//

#pragma once


// CServerTestDlg ��ȭ ����
class CServerTestDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CServerTestDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_SERVERTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	BOOL m_radio;
	afx_msg void OnBnClickedRadio1(UINT msg);
	afx_msg void OnBnClickedBtnConnect();
};
