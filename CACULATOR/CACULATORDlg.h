
// CACULATORDlg.h : ͷ�ļ�
//

#pragma once


// CCACULATORDlg �Ի���
class CCACULATORDlg : public CDialogEx
{
// ����
public:
	CCACULATORDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CACULATOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_str;
	afx_msg void OnBnClicked1();
	afx_msg void OnBnClicked2();
	afx_msg void OnBnClicked3();
	afx_msg void OnBnClicked4();
	afx_msg void OnBnClicked5();
	afx_msg void OnBnClicked6();
	afx_msg void OnBnClicked7();
	afx_msg void OnBnClicked8();
	afx_msg void OnBnClicked9();
	afx_msg void OnBnClicked0();
	afx_msg void OnBnClickedDot();
	afx_msg void OnBnClickedAdd();
	int flag;
    double temp;
	//afx_msg void OnBnClickedCaculator();
	afx_msg void OnBnClickedButton();
	afx_msg void OnBnClickedSub();
	afx_msg void OnClickedMultiply();
	afx_msg void OnClickedReduce();
	afx_msg void OnClickedCaculator();
	afx_msg void OnBnClickedC();
	afx_msg void OnBnClickedGenghao();
	afx_msg void OnBnClickedPercent();
	afx_msg void OnBnClickedPlusminus();
	afx_msg void OnBnClickedDeleteback();
	
	afx_msg void OnBnClickedX();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	double x,y,secag,hag,minag;
};
