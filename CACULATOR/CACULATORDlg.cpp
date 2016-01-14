
// CACULATORDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CACULATOR.h"
#include "CACULATORDlg.h"
#include "afxdialogex.h"
#include"math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCACULATORDlg �Ի���




CCACULATORDlg::CCACULATORDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCACULATORDlg::IDD, pParent)
	, m_str(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCACULATORDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_str);
}

BEGIN_MESSAGE_MAP(CCACULATORDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_1, &CCACULATORDlg::OnBnClicked1)
	ON_BN_CLICKED(IDC_2, &CCACULATORDlg::OnBnClicked2)
	ON_BN_CLICKED(IDC_3, &CCACULATORDlg::OnBnClicked3)
	ON_BN_CLICKED(IDC_4, &CCACULATORDlg::OnBnClicked4)
	ON_BN_CLICKED(IDC_5, &CCACULATORDlg::OnBnClicked5)
	ON_BN_CLICKED(IDC_6, &CCACULATORDlg::OnBnClicked6)
	ON_BN_CLICKED(IDC_7, &CCACULATORDlg::OnBnClicked7)
	ON_BN_CLICKED(IDC_8, &CCACULATORDlg::OnBnClicked8)
	ON_BN_CLICKED(IDC_9, &CCACULATORDlg::OnBnClicked9)
	ON_BN_CLICKED(IDC_0, &CCACULATORDlg::OnBnClicked0)
	ON_BN_CLICKED(IDC_DOT, &CCACULATORDlg::OnBnClickedDot)
	ON_BN_CLICKED(IDC_ADD, &CCACULATORDlg::OnBnClickedAdd)
	//ON_BN_CLICKED(IDC_CACULATOR, &CCACULATORDlg::OnBnClickedCaculator)
	//ON_BN_CLICKED(IDC_BUTTON2, &CCACULATORDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_SUB, &CCACULATORDlg::OnBnClickedSub)
	ON_BN_CLICKED(IDC_MULTIPLY, &CCACULATORDlg::OnClickedMultiply)
	ON_BN_CLICKED(IDC_REDUCE, &CCACULATORDlg::OnClickedReduce)
	ON_BN_CLICKED(IDC_CACULATOR, &CCACULATORDlg::OnClickedCaculator)
	ON_BN_CLICKED(IDC_C, &CCACULATORDlg::OnBnClickedC)
	ON_BN_CLICKED(IDC_GENGHAO, &CCACULATORDlg::OnBnClickedGenghao)
	ON_BN_CLICKED(IDC_PERCENT, &CCACULATORDlg::OnBnClickedPercent)
	ON_BN_CLICKED(IDC_PLUSMINUS, &CCACULATORDlg::OnBnClickedPlusminus)
	ON_BN_CLICKED(IDC_DELETEBACK, &CCACULATORDlg::OnBnClickedDeleteback)
	//ON_BN_CLICKED(IDC_DELETEBACK2, &CCACULATORDlg::OnBnClickedDeleteback2)
	ON_BN_CLICKED(IDC_X, &CCACULATORDlg::OnBnClickedX)
	ON_WM_MOUSEMOVE()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CCACULATORDlg ��Ϣ�������

BOOL CCACULATORDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	SetTimer(1,1000,NULL);
	secag=-0.05;
	minag=-0.05;
	hag=-0.05;

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CCACULATORDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CCACULATORDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CCACULATORDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCACULATORDlg::OnBnClicked1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	m_str=m_str+L"1";
	UpdateData(false);
}


void CCACULATORDlg::OnBnClicked2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	m_str=m_str+L"2";
	UpdateData(false);
}


void CCACULATORDlg::OnBnClicked3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	m_str=m_str+L"3";
	UpdateData(false);
}


void CCACULATORDlg::OnBnClicked4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	m_str=m_str+L"4";
	UpdateData(false);
}


void CCACULATORDlg::OnBnClicked5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	m_str=m_str+L"5";
	UpdateData(false);
}


void CCACULATORDlg::OnBnClicked6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	m_str=m_str+L"6";
	UpdateData(false);
}


void CCACULATORDlg::OnBnClicked7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	m_str=m_str+L"7";
	UpdateData(false);
}


void CCACULATORDlg::OnBnClicked8()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	m_str=m_str+L"8";
	UpdateData(false);
}


void CCACULATORDlg::OnBnClicked9()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	m_str=m_str+L"9";
	UpdateData(false);
}


void CCACULATORDlg::OnBnClicked0()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	m_str=m_str+L"0";
	UpdateData(false);
}


void CCACULATORDlg::OnBnClickedDot()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	m_str=m_str+L".";
	UpdateData(false);
}


void CCACULATORDlg::OnBnClickedAdd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ��������������ӷ�
	flag=1;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	UpdateData(false);
}


void CCACULATORDlg::OnBnClickedSub()
{
	// TODO: �ڴ���ӿؼ�֪ͨ�����������������
	flag=4;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	UpdateData(false);
}


void CCACULATORDlg::OnClickedMultiply()
{
	// TODO: �ڴ���ӿؼ�֪ͨ��������������ɷ�
	flag=3;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	UpdateData(false);

}


void CCACULATORDlg::OnClickedReduce()
{
	// TODO: �ڴ���ӿؼ�֪ͨ�����������������
	flag=2;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	UpdateData(false);
}


void CCACULATORDlg::OnClickedCaculator()
{
	// TODO: �ڴ���ӿؼ�֪ͨ�����������������
	TRACE(L"flag=%d\n",flag);
	UpdateData(true);
	if(flag==1)
	{
		temp=temp+_ttof(m_str);
		//m_str.Format(L"%g",temp);
		
	}
	if(flag==2)
	{
		temp=temp-_ttof(m_str);
		//m_str.Format(L"%g",temp);
		
	}
	if(flag==3)
	{
		temp=temp*_ttof(m_str);
		//m_str.Format(L"%g",temp);
		
	}
	if(flag==4)
	{
		temp=temp/_ttof(m_str);
		//m_str.Format(L"%g",temp);
		
	}
	m_str.Format(L"%lf",temp);//���������ֵת��Ϊ�ַ�������
	while(m_str.Right(1)=="0")
	{
		m_str.Delete(m_str.GetLength()-1,1);
	}
	while(m_str.Right(1)==".")
	{
		m_str.Delete(m_str.GetLength()-1,1);
	}
	UpdateData(false);
}


void CCACULATORDlg::OnBnClickedC()
{
	// TODO: �ڴ���ӿؼ�֪ͨ������������0
	UpdateData(true);
	m_str="";
	UpdateData(false);

}


void CCACULATORDlg::OnBnClickedGenghao()
	
{
	// TODO: �ڴ���ӿؼ�֪ͨ���������뿪����
	if(_ttof(m_str)<0)
	{
		OnBnClickedGenghao();
		MessageBox(L"mistake!");
	}
	temp=_ttof(m_str);
	double f=sqrt(temp);
	m_str.Format(L"%f",f);
	m_str.Right(1)=="0";
	m_str.Delete(m_str.GetLength()-4,7);
	while(m_str.Right(1)=="0")
	{
		m_str.Delete(m_str.GetLength()-1,1);
	}
	while(m_str.Right(1)==".")
	{
		m_str.Delete(m_str.GetLength()-1,1);
	}
	UpdateData(false);
}



void CCACULATORDlg::OnBnClickedPercent()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	
}


void CCACULATORDlg::OnBnClickedPlusminus()
{
	// TODO: �ڴ���ӿؼ�֪ͨ������������Ӹ���
	if(m_str.Left(1)=="-")
		m_str.Delete(0,1);
	else
		m_str=L"-"+m_str;
	UpdateData(false);
}


void CCACULATORDlg::OnBnClickedDeleteback()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������ֻɾ������ӵ�����
	UpdateData(true);
	m_str.Delete(m_str.GetLength()-1,1);
	UpdateData(false);

}




void CCACULATORDlg::OnBnClickedX()
{
	// TODO: �ڴ���ӿؼ�֪ͨ��������������1/X
	UpdateData(true);
	temp=1/_ttof(m_str);
	m_str="";
	UpdateData(false);

}



void CCACULATORDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	TRACE("X=%d,Y=%d\n",point.x,point.y);
	CDialogEx::OnMouseMove(nFlags, point);
}



void CCACULATORDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	dc.SetWindowOrg(-569,-133);
	CPen *oldpen;
	CPen groundpen(PS_SOLID,4,RGB(255,255,255));
	CPen pen(PS_SOLID,3,RGB(0,0,0));
	oldpen=dc.SelectObject(&pen);
	dc.Ellipse(-100,100,100,-100);
	dc.Ellipse(-1,-1,1,1);
	dc.TextOutW(90,-8,L"3");
	dc.TextOutW(-98,-8,L"9");
	dc.TextOutW(-8,-99.5,L"12");
	dc.TextOutW(-2,83,L"6");
	for(int i=0;i<12;i++)
	{
		double l=90,ag=i*3.1415926/6;
		double a=l*sin(ag)+1,b=-l*cos(ag)+1,c=l*sin(ag)-1,d=-l*cos(ag)-1;
		dc.Ellipse(a,b,c,d);
	}


    double L1=70,L2=60,L3=50;          //miaozhen
	oldpen=dc.SelectObject(&groundpen);
	CPen secpen(PS_SOLID,2,RGB(1,150,150));
	oldpen=dc.SelectObject(&secpen);
	secag=secag+3.1415926/30;
	x=L1*sin(secag);
	y=-L1*cos(secag);
	dc.MoveTo(0,0);
	dc.LineTo(x,y);


	oldpen=dc.SelectObject(&groundpen);//fenzhen
	CPen minpen(PS_SOLID,3,RGB(0,255,150));
	oldpen=dc.SelectObject(&minpen);
	minag=minag+3.1415926/1800;
	x=L2*sin(minag);
	y=-L2*cos(minag);
	dc.MoveTo(0,0);
	dc.LineTo(x,y);



	oldpen=dc.SelectObject(&groundpen);//shizhe
	CPen hpen(PS_SOLID,3,RGB(255,0,0));
	oldpen=dc.SelectObject(&hpen);
	hag=hag+3.1415926/21600;
	x=L3*sin(hag);
	y=-L3*cos(hag);
	dc.MoveTo(0,0);
	dc.LineTo(x,y);

	CDialogEx::OnTimer(nIDEvent);
}
