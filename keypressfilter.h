#pragma once
#include <QEvent>
#include <QKeyEvent>
#include <QtGui>
#include <QtCore/QCoreApplication>
#include <QDebug>
#include <QTime>
#include <QChar>
#include <iostream>
#include <Windows.h>

using namespace std;

class KeyPressFilter : public QObject
{
		Q_OBJECT

public:

	static KeyPressFilter *getInstance() {
		if (!instance)
			instance = new KeyPressFilter;
		return instance;
	}

	static void UpdateKeyState(BYTE *keystate, int keycode)
	{
		keystate[keycode] = GetKeyState(keycode);
	}

	static LRESULT CALLBACK MyLowLevelKeyBoardProc(int nCode, WPARAM wParam, LPARAM lParam);

    ~KeyPressFilter() {}

private:
	KeyPressFilter()
	{
		hHook = SetWindowsHookEx(WH_KEYBOARD_LL, MyLowLevelKeyBoardProc, NULL, 0);
      //  hHookFocus = SetWindowsHookExA(WH_KEYBOARD_LL, handleEventObjectFocus, NULL, 0);
        if(hHook == NULL)
		{
			qDebug() << "Hook failed";
		}
	}
	void emitThrow(QChar symbol) {
		emit throwChar(symbol);
	}

   // void setupEventHook(FREContext iCtx);

	HHOOK hHook;
    HHOOK hHookFocus;
	static KeyPressFilter *instance;

signals:
	void throwChar(QChar key);
};
