#pragma once
#include <gdiplus.h>
#include <vector>

//================================================================================
/// @brief ��̬Gifͼ��ı���
///
/// ͨ����̬��Ӷ��ͼ����ϲ���Gif����ͼ��
//================================================================================
class CGifEncoder {
public:
	CGifEncoder ();
	~CGifEncoder ();

public:
	//=================================StartEncoder()=================================
	/// @brief ��ʼgif����
	///
	/// @param [in] saveFilePath gifͼ�񱣴��ȫ·��
	///
	/// @return �ɹ�����true
	//================================================================================
	bool StartEncoder (CString &saveFilePath);
	//===================================AddFrame()===================================
	/// @brief ���ͼ��
	///
	/// @param [in] im  Image����
	///
	/// @return �ɹ�����true
	//================================================================================
	bool AddFrame (Gdiplus::Image *pImage);
	//===================================AddFrame()===================================
	/// @brief ���ͼ��
	///
	/// @param [in] framePath ͼ���ȫ·��
	///
	/// @return  �ɹ�����true
	//================================================================================
	bool AddFrame (CString &framePath);
	//================================FinishEncoder()===============================
	/// @brief ����gif�ı���
	///
	/// @return  �ɹ�����true
	//================================================================================
	bool FinishEncoder (PropertyItem* pItem);
	//=================================SetDelayTime()=================================
	/// @brief ��������ͼ���л���ʱ����
	///
	/// @param [in] ms ʱ��,�Ժ���Ϊ��λ
	///
	/// @return ��
	//================================================================================
	void SetDelayTime (int ms);
	//=================================SetRepeatNum()=================================
	/// @brief ����gif�������ŵĴ���
	///
	/// @param [in] num ������0��ʾ���޴�
	///
	/// @return ��
	//================================================================================
	void SetRepeatNum (int num);
	//=================================SetFrameRate()=================================
	/// @brief ����ͼ���֡��
	///
	/// @param [in] fps ֡�ʣ�ÿ�벥��ͼ�����Ŀ
	///
	/// @return ��
	//================================================================================
	void SetFrameRate (float fps);
	//=================================SetFrameSize()=================================
	/// @brief ����ͼ��ĳߴ�
	///
	/// @param [in] width  ͼ��Ŀ��
	/// @param [in] height ͼ��ĸ߶�
	///
	/// @return ��
	//================================================================================
	void SetFrameSize (int width, int height);

private:
	void SetImagePropertyItem (PropertyItem* pItem);
	bool GetEncoderClsid (const WCHAR* format, CLSID* pClsid);

private:
	int                 m_width;
	int                 m_height;
	int                 m_repeatNum;
	int                 m_delayTime;
	bool                m_started;
	bool                m_haveFrame;

	CString             *m_pStrSavePath;
	Gdiplus::Bitmap     *m_pImage;
	std::vector<Gdiplus::Bitmap *> m_pBitMapVec;
};