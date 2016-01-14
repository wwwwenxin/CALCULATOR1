
// CACULATORDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CACULATOR.h"
#include "CACULATORDlg.h"
#include "afxdialogex.h"
#include"math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CCACULATORDlg 对话框




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


// CCACULATORDlg 消息处理程序

BOOL CCACULATORDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	SetTimer(1,1000,NULL);
	secag=-0.05;
	minag=-0.05;
	hag=-0.05;

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCACULATORDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCACULATORDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCACULATORDlg::OnBnClicked1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"1";
	UpdateData(false);
}


void CCACULATORDlg::OnBnClicked2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"2";
	UpdateData(false);
}


void CCACULATORDlg::OnBnClicked3()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"3";
	UpdateData(false);
}


void CCACULATORDlg::OnBnClicked4()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"4";
	UpdateData(false);
}


void CCACULATORDlg::OnBnClicked5()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"5";
	UpdateData(false);
}


void CCACULATORDlg::OnBnClicked6()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"6";
	UpdateData(false);
}


void CCACULATORDlg::OnBnClicked7()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"7";
	UpdateData(false);
}


void CCACULATORDlg::OnBnClicked8()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"8";
	UpdateData(false);
}


void CCACULATORDlg::OnBnClicked9()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"9";
	UpdateData(false);
}


void CCACULATORDlg::OnBnClicked0()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"0";
	UpdateData(false);
}


void CCACULATORDlg::OnBnClickedDot()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L".";
	UpdateData(false);
}


void CCACULATORDlg::OnBnClickedAdd()
{
	// TODO: 在此添加控件通知处理程序代码运算加法
	flag=1;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	UpdateData(false);
}


void CCACULATORDlg::OnBnClickedSub()
{
	// TODO: 在此添加控件通知处理程序代码运算除法
	flag=4;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	UpdateData(false);
}


void CCACULATORDlg::OnClickedMultiply()
{
	// TODO: 在此添加控件通知处理程序代码运算成法
	flag=3;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	UpdateData(false);

}


void CCACULATORDlg::OnClickedReduce()
{
	// TODO: 在此添加控件通知处理程序代码运算减法
	flag=2;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	UpdateData(false);
}


void CCACULATORDlg::OnClickedCaculator()
{
	// TODO: 在此添加控件通知处理程序代码进行运算
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
	m_str.Format(L"%lf",temp);//将计算出的值转换为字符串类型
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
	// TODO: 在此添加控件通知处理程序代码清0
	UpdateData(true);
	m_str="";
	UpdateData(false);

}


void CCACULATORDlg::OnBnClickedGenghao()
	
{
	// TODO: 在此添加控件通知处理程序代码开根号
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
	// TODO: 在此添加控件通知处理程序代码
	
	
}


void CCACULATORDlg::OnBnClickedPlusminus()
{
	// TODO: 在此添加控件通知处理程序代码添加负号
	if(m_str.Left(1)=="-")
		m_str.Delete(0,1);
	else
		m_str=L"-"+m_str;
	UpdateData(false);
}


void CCACULATORDlg::OnBnClickedDeleteback()
{
	// TODO: 在此添加控件通知处理程序代码只删除新添加的数字
	UpdateData(true);
	m_str.Delete(m_str.GetLength()-1,1);
	UpdateData(false);

}




void CCACULATORDlg::OnBnClickedX()
{
	// TODO: 在此添加控件通知处理程序代码运算1/X
	UpdateData(true);
	temp=1/_ttof(m_str);
	m_str="";
	UpdateData(false);

}



void CCACULATORDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	TRACE("X=%d,Y=%d\n",point.x,point.y);
	CDialogEx::OnMouseMove(nFlags, point);
}



void CCACULATORDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
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
