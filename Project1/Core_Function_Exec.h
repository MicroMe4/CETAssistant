#pragma once
#include "Core_Function_Essentials.h"

/*选项功能*/
int choose()
{
	int thewaytorun;
	puts("1.添加单词\t2.删除单词\t3.替换\t4.读取特定单词\t5.显示文件\t0.退出");
	printf("输入选项：");
	scanf("%d", &thewaytorun);
	return(thewaytorun);
}

void execute_general(int *parameters, char *p[])
{
	if (*parameters == 1)			//无参数运行
	{
		static char thoseword[100];
		int runoption;
		while ((runoption = choose()) != 0)
		{
			getchar();
			if (runoption == 1)
			{
				add_specific_nopara(phrasegetin);
				desired_writing_function(location,phrasegetin);
			}
			else if (runoption == 2)
			{
				file_validity_check(location);
				puts("输入你需要删除的内容");
				gets(thoseword);
				if (delete_confirm_dialog(thoseword, "delete") == DEL_AND_UPD_REQUIRED)
				{
					desired_deleting_function(location, thoseword);
				}
			}
			else if(runoption==3)
			{
				file_validity_check(location);
				puts("输入你需要修改的内容");
				gets(thoseword);
				if (delete_confirm_dialog(thoseword, "update") == DEL_AND_UPD_REQUIRED)
				{
					update_word_nopara(location, thoseword, phrasegetin);
				}
			}
			else if (runoption == 4)
			{
				file_validity_check(location);
				puts("输入你记得的部分");
				gets(thoseword);
				search_vocabulary(location, thoseword,"loose");
			}
			else if (runoption == 5)
			{
				file_validity_check(location);
				file_type_function(location);
			}
		}
		strcpy(thoseword, "");			// 变量初始化
	}
	else if (*parameters == 2)							//读取文件的 1 参数运行
	{
		if (strcmp(p[1], "view") == 0)
		{
			file_type_function(location);
		}
		else if ((strcmp(p[1], "add") == 0) || (strcmp(p[1], "update") == 0))
		{
			infomation(ERR_NOT_ENOUGH_ARGUMENT);
		}
		else if (strcmp(p[1], "help") == 0)		//1 参数帮助运行
		{
			infomation(HELP_GENERAL_ON);
		}
	}
	else if (*parameters == 3)							//删除、读取特定文件[未确定]
	{
		if (stricmp(p[1], "delete") == 0)
		{
			if (delete_confirm_dialog(p[2], "delete") == DEL_AND_UPD_REQUIRED)
			{
				desired_deleting_function(location, p[2]);
			}
		}
		else if (stricmp(p[1], "view") == 0)
		{
			file_validity_check(p[2]);
			file_type_function(p[2]);
		}
		else if (stricmp(p[1], "search") == 0)
		{
			search_vocabulary(location, p[2],"loose");
		}
		else if (stricmp(p[1], "help") == 0)		//detailed help
		{
			if (stricmp(p[2], "add") == 0)
			{
				infomation(HELP_PARTICULAR_ON_ADD);
			}
			else if (strcmp(p[2], "search") == 0)
			{
				infomation(HELP_PARTICULAR_ON_SER);
			}
			else if (strcmp(p[2], "update") == 0)
			{
				infomation(HELP_PARTICULAR_ON_UPD);
			}
			else if (strcmp(p[2], "delete") == 0)
			{
				infomation(HELP_PARTICULAR_ON_DEL);
			}
		}
		else if ((strcmp(p[1], "add") == 0) || (strcmp(p[1], "update") == 0))
		{
			infomation(ERR_NOT_ENOUGH_ARGUMENT);
		}
	}
	else if (*parameters == 4)			//删除模式，强制确定
	{
		if ((stricmp(p[2], "delete") == 0) && (stricmp(p[4], "--no-warning") == 0))
		{
			desired_deleting_function(location, p[3]);
		}
		else if ((strcmp(p[1], "add") == 0) || (strcmp(p[1], "update") == 0))
		{
			infomation(ERR_NOT_ENOUGH_ARGUMENT);
		}
	}
	else if (*parameters == 5)									
	{
		if (strcmp(p[1], "location") == 0)
		{
			strcpy(location, p[2]);
			file_validity_check(location);
			if (strcmp(p[3], "delete") == 0)		//删除在位置 location 的单词，没有强制确定
			{
				if (delete_confirm_dialog(p[4], "delete") == DEL_AND_UPD_REQUIRED)
				{
					desired_deleting_function(location,p[4]);
				}
			}
			if (strcmp(p[3], "search") == 0)		//搜索含有 p[4] 内容的单词
			{
				search_vocabulary(location, p[4],"loose");
			}
		}
		else if ((strcmp(p[1], "add") == 0) || (strcmp(p[1], "update") == 0))
		{
			infomation(ERR_NOT_ENOUGH_ARGUMENT);
		}
	}
	else if (*parameters == 6)							//删除在位置 location 的单词，强制确定
	{
		if (strcmp(p[1], "location") == 0)
		{
			strcpy(location, p[2]);
			file_validity_check(location);
			if (strcmp(p[3], "delete") == 0)
			{
				if (strcmp(p[5], "--no-warnings") == 0)
				{
					desired_deleting_function(location, p[4]);
				}
			}
		}
		else if ((strcmp(p[1], "add") == 0) || (strcmp(p[1], "update") == 0))
		{
			infomation(ERR_NOT_ENOUGH_ARGUMENT);
		}
	}
	else if (*parameters == 7)									//location未定义的add & update 6参数运行，没有进行强制确定
	{
		if (strcmp(p[1], "add") == 0)						//添加单词
		{
			union_mode_para_exist(p[2], p[3], p[4], p[5], p[6],phrasegetin);
			desired_writing_function(location,phrasegetin);
		}
		else if (strcmp(p[1], "update") == 0)				//修改单词
		{
			if (delete_confirm_dialog(p[2], "update") == DEL_AND_UPD_REQUIRED)
			{
				update_word_para_exist(location, phrasegetin, p[2], p[3], p[4], p[5], p[6]);
			}
		}
	}
	else if (*parameters == 8)
	{
		if (strcmp(p[1], "update") == 0)
		{
			if (strcmp(p[7], "--no-warning") == 0)
			{
				update_word_para_exist(location, phrasegetin, p[2], p[3], p[4], p[5], p[6]);
			}
		}
	}
	else if (*parameters == 9)								//带有location参数的 add & update 的8 参数运行，没有强制确定
	{
		if (strcmp(p[1], "location") == 0)
		{
			strcpy(location, p[2]);
			file_validity_check(location);
			if (strcmp(p[3], "add") == 0)
			{
				union_mode_para_exist(p[4], p[5], p[6], p[7], p[8],phrasegetin);
				desired_writing_function(location, phrasegetin);
			}
			else if (strcmp(p[3], "update") == 0)
			{
				if (delete_confirm_dialog(p[4], "update") == DEL_AND_UPD_REQUIRED)
				{
					desired_deleting_function(location, p[4]);
					union_mode_para_exist(p[4], p[5], p[6], p[7], p[8],phrasegetin);
					desired_writing_function(location, phrasegetin);
				}
			}
		}
	}
	else if (*parameters == 10)
	{
		if (strcmp(p[1], "location") == 0)
		{
			strcpy(location, p[2]);
			file_validity_check(location);
			if (strcmp(p[3], "update") == 0)
			{
				if (strcmp(p[9], "--no-warning") == 0)
				{
					desired_deleting_function(location, p[4]);
					union_mode_para_exist(p[4], p[5], p[6], p[7], p[8],phrasegetin);
					desired_writing_function(location, phrasegetin);
				}
			}
		}
	}
	else
	{
		infomation(ERR_ARGUMENT_WRONG);
	}
}