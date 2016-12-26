#define _CRT_SECURE_NO_WARNINGS //关闭安全检查
#include "Core_Function_Exec.h"

//主程序
/*
Support OS: ALL
*/

int main(int argc, char *argv[])
{
	execute_general(&argc, argv);
	return (EXIT_SUCCESS);
}