/** @file
*
* MIT License

* Copyright (c) 2017 Leeway213

* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:

* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.

* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
*
**/

#pragma once

#include "Driver.h"
#include <pshpack1.h>
#include <minwindef.h>

//
// input from device to system - DO NOT modify this structure without changing the HID descriptor in the driver!
//
typedef struct _HIDINJECTOR_INPUT_REPORT {
	unsigned char ReportId;

	union {
		struct {
			UCHAR Modifiers;
			UCHAR Key1;
			UCHAR Key2;
			UCHAR Key3;
			UCHAR Key4;
			UCHAR Padding[2]; // Padding to keep the reports the same size
		} KeyReport;
		struct {
			UCHAR Buttons;
			SHORT AbsoluteX;
			SHORT AbsoluteY;
			UCHAR Padding[2]; // Padding to keep the reports the same size
		} MouseReport;
		struct {
			UCHAR Flags;  // Bit 0 = Tip Switch, Bit 1 = In Range, Bit 2-7 = unused
			UCHAR ContactIndentifier;
			USHORT AbsoluteX;
			USHORT AbsoluteY;
			UCHAR ContactCount;
		} TouchReport;
	} Report;
} HIDINJECTOR_INPUT_REPORT, *PHIDINJECTOR_INPUT_REPORT;


typedef struct tagMOUSEINPUT {
	LONG    dx;
	LONG    dy;
	DWORD	mouseData;
	DWORD   dwFlags;
	DWORD   time;
	ULONG_PTR dwExtraInfo;
} MOUSEINPUT, *PMOUSEINPUT, FAR* LPMOUSEINPUT;

typedef struct tagKEYBDINPUT {
	WORD    wVk;
	WORD wScan;
	DWORD   dwFlags;
	DWORD   time;
	ULONG_PTR dwExtraInfo;
} KEYBDINPUT, *PKEYBDINPUT, FAR* LPKEYBDINPUT;

typedef struct tagHARDWAREINPUT {
	DWORD   uMsg;
	WORD    wParamL;
	WORD    wParamH;
} HARDWAREINPUT, *PHARDWAREINPUT, FAR* LPHARDWAREINPUT;

typedef struct tagINPUT {
	DWORD   type;

	union
	{
		MOUSEINPUT      mi;
		KEYBDINPUT      ki;
		HARDWAREINPUT   hi;
	} DUMMYUNIONNAME;
} INPUT, *PINPUT, FAR* LPINPUT;

// Values for ReportId
#define KEYBOARD_REPORT_ID		1
#define MOUSE_REPORT_ID			2
#define TOUCH_REPORT_ID			3
#define MAX_COUNT_REPORT_ID		4

// Values for KeyReport.Modifiers from the HID Spec
#define KEBBOARD_LEFT_CONTROL	0x01
#define KEYBOARD_LEFT_SHIFT		0x02
#define KEYBOARD_LEFT_ALT		0x04
#define KEYBOARD_LEFT_GUI		0x08
#define KEBBOARD_RIGHT_CONTROL	0x10
#define KEYBOARD_RIGHT_SHIFT	0x20
#define KEYBOARD_RIGHT_ALT		0x40
#define KEYBOARD_RIGHT_GUI		0x80

// Values for MouseReport.Buttons from the HID Spec
#define MOUSE_BUTTON_1			0x01
#define MOUSE_BUTTON_2			0x02
#define MOUSE_BUTTON_3			0x04

// Values for TouchReport.Flags from the HID Spec
#define TOUCH_TIP_SWITCH		0x01
#define TOUCH_IN_RANGE			0x02
#define TOUCH_MAX_FINGER		0x0a // 10

#include <poppack.h>

