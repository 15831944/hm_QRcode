
// hm_QRcodeDlg.h : ͷ�ļ�
//

#pragma once


// Chm_QRcodeDlg �Ի���
class Chm_QRcodeDlg : public CDialogEx
{
// ����
public:
	Chm_QRcodeDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_HM_QRCODE_DIALOG };

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
	CString m_path_src;
	CString m_path_bg;
	CString m_path_dest;
	CString m_pixel_width;
	CString m_animate_speed;
	BOOL m_tailor;
	CString m_status;
	afx_msg void OnBnClickedButton1 ();
	afx_msg void OnBnClickedButton2 ();
	afx_msg void OnBnClickedButton3 ();
	afx_msg void OnBnClickedButton4 ();
};
