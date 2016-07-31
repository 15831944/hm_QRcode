
// hm_QRcodeDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "hm_QRcode.h"
#include "hm_QRcodeDlg.h"
#include "afxdialogex.h"

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


// Chm_QRcodeDlg �Ի���



Chm_QRcodeDlg::Chm_QRcodeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Chm_QRcodeDlg::IDD, pParent)
	, m_path_src (_T ("")), m_path_bg (_T ("")), m_path_dest (_T ("")), m_pixel_width (_T ("")), m_animate_speed (_T ("")), m_tailor (FALSE), m_status (_T ("")) {
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Chm_QRcodeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange (pDX);
	DDX_Text (pDX, IDC_EDIT1, m_path_src);
	DDX_Text (pDX, IDC_EDIT2, m_path_bg);
	DDX_Text (pDX, IDC_EDIT3, m_path_dest);
	DDX_Text (pDX, IDC_EDIT4, m_pixel_width);
	DDX_Text (pDX, IDC_EDIT5, m_animate_speed);
	DDX_Check (pDX, IDC_CHECK1, m_tailor);
	DDX_Text (pDX, IDC_STATUS, m_status);
}

BEGIN_MESSAGE_MAP(Chm_QRcodeDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED (IDC_BUTTON1, &Chm_QRcodeDlg::OnBnClickedButton1)
	ON_BN_CLICKED (IDC_BUTTON2, &Chm_QRcodeDlg::OnBnClickedButton2)
	ON_BN_CLICKED (IDC_BUTTON3, &Chm_QRcodeDlg::OnBnClickedButton3)
	ON_BN_CLICKED (IDC_BUTTON4, &Chm_QRcodeDlg::OnBnClickedButton4)
END_MESSAGE_MAP ()


// Chm_QRcodeDlg ��Ϣ�������

BOOL Chm_QRcodeDlg::OnInitDialog()
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	m_pixel_width = _T ("5");
	m_animate_speed = _T ("0");
	m_tailor = TRUE;
	m_status = _T ("������");
	UpdateData (FALSE);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void Chm_QRcodeDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void Chm_QRcodeDlg::OnPaint()
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
HCURSOR Chm_QRcodeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



CString fdsel = _T ("ͼƬ�ļ� (*.gif;*.png;*.jpg;*.bmp)|*.gif;*.png;*.jpg;*.bmp\0�����ļ� (*.*)|*.*\0\0");

void Chm_QRcodeDlg::OnBnClickedButton1 () {
	CFileDialog fd (TRUE, NULL, NULL, OFN_OVERWRITEPROMPT, fdsel, this);
	if (IDOK == fd.DoModal ()) {
		UpdateData (TRUE);
		m_path_src = fd.GetPathName ();
		UpdateData (FALSE);
	}
}


void Chm_QRcodeDlg::OnBnClickedButton2 () {
	CFileDialog fd (TRUE, NULL, NULL, OFN_OVERWRITEPROMPT, fdsel, this);
	if (IDOK == fd.DoModal ()) {
		UpdateData (TRUE);
		m_path_bg = fd.GetPathName ();
		UpdateData (FALSE);
	}
}


void Chm_QRcodeDlg::OnBnClickedButton3 () {
	CFileDialog fd (FALSE, NULL, NULL, OFN_OVERWRITEPROMPT, fdsel, this);
	if (IDOK == fd.DoModal ()) {
		UpdateData (TRUE);
		m_path_dest = fd.GetPathName ();
		UpdateData (FALSE);
	}
}


INT GetEncoderClsid (CString format, CLSID *pClsid) {
	UINT  num = 0;          // number of image encoders
	UINT  size = 0;         // size of the image encoder array in bytes

	Gdiplus::ImageCodecInfo *pImageCodecInfo = NULL;

	Gdiplus::GetImageEncodersSize (&num, &size);
	if (size == 0)
		return -1;  // Failure

	pImageCodecInfo = (Gdiplus::ImageCodecInfo*) (malloc (size));
	if (pImageCodecInfo == NULL)
		return -1;  // Failure

	GetImageEncoders (num, size, pImageCodecInfo);

	for (UINT j = 0; j < num; ++j) {
		if (wcscmp (pImageCodecInfo [j].MimeType, format) == 0) {
			*pClsid = pImageCodecInfo [j].Clsid;
			free (pImageCodecInfo);
			return j;  // Success
		}
	}

	free (pImageCodecInfo);
	return -1;  // Failure
}


void Chm_QRcodeDlg::OnBnClickedButton4 () {
	//����ļ��Ƿ����
	auto check_file_exist = [] (CString path) {
		HANDLE hFile = ::CreateFile (path, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
		if (INVALID_HANDLE_VALUE == hFile) return FALSE;
		CloseHandle (hFile);
		return TRUE;
	};
	//����״̬��Ϣ
	auto update_status = [this] (CString s) { this->m_status = s; UpdateData (FALSE); };
	UpdateData (TRUE);

	//
	// ���������Ч��
	//
	if (!check_file_exist (m_path_src)) { update_status (_T ("����ʧ�ܣ���ά��ͼƬ�����ڡ�")); return; }
	if (!check_file_exist (m_path_bg)) { update_status (_T ("����ʧ�ܣ�����ͼƬ�����ڡ�")); return; }
	//if (check_file_exist (m_path_dest)) {
	//	if (IDYES != AfxMessageBox (_T ("Ŀ���ļ��Ѵ��ڣ��Ƿ񸲸ǣ�"), MB_ICONQUESTION | MB_YESNO)) {
	//		update_status (_T ("����ʧ�ܣ�Ŀ���ļ����ڣ��û���ȡ����")); return;
	//	}
	//}
	int pixel_width = _wtoi (m_pixel_width);
	if (!(pixel_width % 2)) { update_status (_T ("����ʧ�ܣ���ά���ȱ���Ϊ������")); return; }
	if (pixel_width < 3 || pixel_width > 15) { update_status (_T ("����ʧ�ܣ���ά���ȷ�Χ����")); return; }
	if (pixel_width > 9) {
		if (IDYES != AfxMessageBox (_T ("��ά������̫�����ܵ��¶�ά���޷�ʶ���Ƿ������"), MB_ICONQUESTION | MB_YESNO)) {
			update_status (_T ("����ʧ�ܣ���ά������̫���û���ȡ����")); return;
		}
	}
	int animate_speed = _wtoi (m_animate_speed);
	if (animate_speed < 0) { update_status (_T ("����ʧ�ܣ���ͼ֡�������Ϊ��������")); return; }

	Bitmap img_src (m_path_src), img_bg (m_path_bg);
	int src_width = img_src.GetWidth (), src_height = img_src.GetHeight ();
	if (src_width < 1 || src_height < 1) { update_status (_T ("����ʧ�ܣ���ά��ͼƬ��ʽ����")); return; }
	int bg_width = img_bg.GetWidth (), bg_height = img_bg.GetHeight ();
	if (bg_width < 1 || bg_height < 1) { update_status (_T ("����ʧ�ܣ�����ͼƬ��ʽ����")); return; }

	//
	// ��ȡԴ��ά���С
	//
	int i, j, k, l, m;
	Gdiplus::Color c;
#define GET_PIXEL(x,y) img_src.GetPixel(x,y,&c)
#define IF_BLACK if(c.GetR()<128)
#define IF_WRITE if(c.GetR()>127)
	for (i = j = k = l = 0; i < src_width; ++i) {
		//i����ѭ������
		//j����ǰѰ�ҵ��ĵڼ������裬�Լ�ʵ���ۼ�
		//k����ǰѭ�����ڼ�����С
		//l����ÿ�����ؿ��ŵĴ�С
		//m��������ά����ʱ��y��ֵ����������Ⱦ�Ϊy��
		switch ((BYTE) (j)) {
		case 0://�����ϱ߾��У����ҵ����ϽǶ�λ��
			GET_PIXEL (i, i);
			IF_BLACK ++j;
			break;
		case 1://������(0, 0)���У�����ÿ����Ĵ�Ŵ�С
			GET_PIXEL (i, i);
			IF_WRITE ++j; else ++k;
			break;
		case 2://������(1, 1)���У�׼����ʼ��ֱѭ�������caseִֻ��һ��
			l = k;
			m = i + l / 2;
			++j;
			break;
		case 3://������(1, 1)~(5, 1)���У�����ˮƽ�����һ����ɫ�飬Ҳ�������ϽǶ�λ������·��ĺ�ɫ��
			GET_PIXEL (i, m);
			IF_BLACK ++j;
			break;
		case 4://��ʱ������ɨ��һ���ˣ�ֱ�ӽ������(6, 1)��λ��(6, 6), ���caseִֻ��һ��
			m = i;
			k = 0;
			j += 3;
			break;
		default://��ʼ˳����������������ͬɫ�����ôj+1
			//jΪ��������ǰɫ��Ϊ��ɫ�����Ϊż������ǰɫ��Ϊ��ɫ
			GET_PIXEL (i, m);
			if (c.GetR () < 128/*black*/ == j % 2) {//��ǰ��ɫ��ͬ
				if (++k > l * 2) k = -1;//������ɫ����һ�����ؿ飬��������ѭ����
			} else {//��ǰ��ɫ��ͬ
				k = 0;
				++j;
			}
			break;
		}
		if (k == -1) break;//��ȷ����ѭ��
	}
#undef IF_WRITE
#undef IF_BLACK
#undef GET_PIXEL
	//δ��ȷ����
	if (k != -1) { update_status (_T ("��ά��δ��ȷ������")); return; }

	int code_size = j + 6, src_pixel_size = code_size * pixel_width;
	auto get_pixel = [&img_src, src_width, code_size] (int x, int y, Gdiplus::Color *c) { img_src.GetPixel ((src_width * x / (code_size + 2)) + 10, (src_width * y / (code_size + 2)) + 10, c); };

	//
	// ������ֻ�ͼ��С
	//
	Rect r_dest (0, 0, src_pixel_size, src_pixel_size);
	Rect r_bg (0, 0, bg_width, bg_height);
	Rect r_code (0, 0, src_pixel_size, src_pixel_size);
	if (!m_tailor) {
		//r_dest
		if (bg_width >= bg_height) r_dest.Width = src_pixel_size * bg_width / bg_height;
		else r_dest.Height = src_pixel_size * bg_height / bg_width;
	} else {
		//r_bg
		if (bg_width >= bg_height) {
			r_bg.X = (bg_width - bg_height) / 2;
			r_bg.Width = bg_height;
		} else {
			r_bg.Y = (bg_height - bg_width) / 2;
			r_bg.Height = bg_width;
		}
	}

	//
	// ���ɶ�ά��ͼƬ
	//
	Bitmap img_code (src_pixel_size, src_pixel_size, PixelFormat32bppARGB);
	//����һ�����ؿ��е�����ά������
	auto set_single = [&img_code, src_pixel_size] (int x, int y, Gdiplus::Color *c) {
		img_code.SetPixel (x * src_pixel_size + src_pixel_size / 2, y * src_pixel_size + src_pixel_size / 2, *c);
	};
	//����һ�����ؿ������ж�ά������
	auto set_multi = [&img_code, src_pixel_size] (int x, int y, Gdiplus::Color *c) {
		for (int i = 0; i < src_pixel_size; ++i) {
			for (int j = 0; j < src_pixel_size; ++j) {
				img_code.SetPixel (x * src_pixel_size + i, y * src_pixel_size + j, *c);
			}
		}
	};

	//�������ö�ά������
	for (i = 0; i < code_size; ++i) {
		for (j = 0; j < code_size; ++j) {
			get_pixel (j, i, &c);
			if (c.GetR () < 128 || c.GetG () < 128 || c.GetB () < 128) {
				c.SetValue (Gdiplus::Color::MakeARGB (255, 0, 0, 0));
			} else {
				c.SetValue (Gdiplus::Color::MakeARGB (255, 255, 255, 255));
			}
			k = code_size - i - 1;
			l = code_size - j - 1;
			if (i == 6 || j == 6                             //�����л������
				|| (i < 8 && j < 8)                          //���ϽǶ�λ��
				|| (k < 8 && j < 8)                          //���ϽǶ�λ��
				|| (i < 8 && l < 8)                          //���½Ƕ�λ��
				|| (k >= 4 && k <= 8 && l >= 4 && l <= 8)) { //���½Ƕ�λ��
				set_multi (j, i, &c);
			} else {
				set_single (j, i, &c);
			}
		}
	}

	//
	// ����Ŀ��ͼƬ
	//
	Bitmap img_dest (r_dest.Width, r_dest.Height, PixelFormat32bppARGB);
	Graphics g (&img_dest);

	//��ȡ֡��
	int count = img_bg.GetFrameDimensionsCount ();
	GUID *pDimensionIDs = new GUID [count];
	img_bg.GetFrameDimensionsList (pDimensionIDs, count);
	wchar_t strGuid [40];
	StringFromGUID2 (pDimensionIDs [0], strGuid, 40);
	count = img_bg.GetFrameCount (&pDimensionIDs [0]);
	delete []pDimensionIDs;

	CString file_ext = m_path_dest.Right (m_path_dest.GetLength () - m_path_dest.ReverseFind (_T ('.')) - 1).MakeLower (), tmp;
	if (count > 1) {
		//��֡ͼƬ
		if (file_ext.Compare (_T ("gif"))) {
			tmp = m_path_dest.Left (m_path_dest.ReverseFind (_T ('.')));
			m_path_dest.Format (_T ("%s.gif"), tmp);
		}

		CGifEncoder ge;
		ge.SetFrameSize (src_pixel_size, src_pixel_size);
		//ge.SetDelayTime (animate_speed ? animate_speed : img_bg.getfra);
		ge.StartEncoder (m_path_dest);

		PropertyItem* pItem;
		if (animate_speed) {
			ge.SetDelayTime (animate_speed);
			pItem = NULL;
		} else {
			UINT TotalBuffer = img_bg.GetPropertyItemSize (PropertyTagFrameDelay);
			pItem = (PropertyItem*) malloc (TotalBuffer);
			img_bg.GetPropertyItem (PropertyTagFrameDelay, TotalBuffer, pItem);
		}

		GUID guid = Gdiplus::FrameDimensionTime;
		for (i = 0; i < count; ++i) {
			img_bg.SelectActiveFrame (&guid, i);
			g.DrawImage (&img_bg, r_dest, r_bg.X, r_bg.Y, r_bg.Width, r_bg.Height, Unit::UnitPixel);
			g.DrawImage (&img_code, r_dest, r_code.X, r_code.Y, r_code.Width, r_code.Height, Unit::UnitPixel);
			ge.AddFrame (&img_dest);
		}
		ge.FinishEncoder (pItem);

		if (pItem) delete pItem;
	} else {
		//��֡ͼƬ
		g.DrawImage (&img_bg, r_dest, r_bg.X, r_bg.Y, r_bg.Width, r_bg.Height, Unit::UnitPixel);
		g.DrawImage (&img_code, r_dest, r_code.X, r_code.Y, r_code.Width, r_code.Height, Unit::UnitPixel);

		if (!file_ext.Compare (_T ("jpg"))) file_ext = _T ("jpeg");
		tmp.Format (_T ("image/%s"), file_ext);

		CLSID clsid;
		GetEncoderClsid (tmp, &clsid);
		img_code.Save (m_path_dest, &clsid);
	}

	update_status (_T ("��ɡ�"));
}
