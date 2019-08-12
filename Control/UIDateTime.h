#ifndef __UIDATETIME_H__
#define __UIDATETIME_H__

#pragma once

namespace DuiLib
{
	class CDateTimeWnd;

	/// 时间选择控件
	class UILIB_API CDateTimeUI : public CLabelUI
	{
		DECLARE_DUICONTROL(CDateTimeUI)
		friend class CDateTimeWnd;
	public:
		CDateTimeUI();
		LPCTSTR GetClass() const;
		LPVOID GetInterface(LPCTSTR pstrName);

		SYSTEMTIME& GetTime();
		void SetTime(SYSTEMTIME* pst);

		void SetReadOnly(bool bReadOnly);
		bool IsReadOnly() const;

		void UpdateText();

		void DoEvent(TEventUI& event);
		void Format(LPCTSTR lpstrFormat);
		void SetDateTimePickerStyle(LONG lStyle);
		void SetDateTimePickerFormat(LPCTSTR lpstrFormat);
	protected:
		SYSTEMTIME m_sysTime;
		int        m_nDTUpdateFlag;
		bool       m_bReadOnly;

		CDateTimeWnd* m_pWindow;
		LONG	   m_lDTPickerStyle;
		CDuiString m_strFormat;
	};
}
#endif // __UIDATETIME_H__