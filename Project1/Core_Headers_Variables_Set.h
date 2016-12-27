#pragma once
/* Support OS:All */
// System Functions

#include <wchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <io.h>

// Users Function
// Program Specification

/* ������Ϣ�Ķ��� */
#define ERR_NOT_ENOUGH_ARGUMENT 0xFFFFFFFF
#define ERR_ARGUMENT_WRONG	0xFFFFFFFE
#define ERR_INPUT_WRONG 0xFFFFFFFD
#define ERR_FILE_NONEXISTANCE 0xFFFFFFFC
#define ERR_CLASS_DEFINED 0xFFFFFFFB

/* ������Ϣ�Ķ��� */
#define HELP_GENERAL_ON	0x00000000
#define HELP_PARTICULAR_ON_ADD	0x00000001
#define HELP_PARTICULAR_ON_DEL	0x00000002
#define HELP_PARTICULAR_ON_UPD	0x00000003 
#define HELP_PARTICULAR_ON_SER  0x00000004

/*��������*/
#define EXIT_REQUIRED 0x00000000
#define ADD_REQUIRED 0x00000001
#define DEL_AND_UPD_REQUIRED 0x00000002

/*�������ļ�����[�ǳ���]*/
#ifdef _WIN32			//32λWindows����ϵͳ
char location[100] = "D:\\Words.txt";
#endif // _WIN32

/* Linux-based System Macro Define */

/* General Variables*/
char phrasegetin[1000]="";


