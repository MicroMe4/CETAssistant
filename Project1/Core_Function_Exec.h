#pragma once
#include "Core_Function_Essentials.h"

/*ѡ���*/
int choose()
{
	int thewaytorun;
	puts("1.��ӵ���\t2.ɾ������\t3.�滻\t4.��ȡ�ض�����\t5.��ʾ�ļ�\t0.�˳�");
	printf("����ѡ�");
	scanf("%d", &thewaytorun);
	return(thewaytorun);
}

void execute_general(int *parameters, char *p[])
{
	if (*parameters == 1)			//�޲�������
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
				puts("��������Ҫɾ��������");
				gets(thoseword);
				if (delete_confirm_dialog(thoseword, "delete") == DEL_AND_UPD_REQUIRED)
				{
					desired_deleting_function(location, thoseword);
				}
			}
			else if(runoption==3)
			{
				file_validity_check(location);
				puts("��������Ҫ�޸ĵ�����");
				gets(thoseword);
				if (delete_confirm_dialog(thoseword, "update") == DEL_AND_UPD_REQUIRED)
				{
					update_word_nopara(location, thoseword, phrasegetin);
				}
			}
			else if (runoption == 4)
			{
				file_validity_check(location);
				puts("������ǵõĲ���");
				gets(thoseword);
				search_vocabulary(location, thoseword,"loose");
			}
			else if (runoption == 5)
			{
				file_validity_check(location);
				file_type_function(location);
			}
		}
		strcpy(thoseword, "");			// ������ʼ��
	}
	else if (*parameters == 2)							//��ȡ�ļ��� 1 ��������
	{
		if (strcmp(p[1], "view") == 0)
		{
			file_type_function(location);
		}
		else if ((strcmp(p[1], "add") == 0) || (strcmp(p[1], "update") == 0))
		{
			infomation(ERR_NOT_ENOUGH_ARGUMENT);
		}
		else if (strcmp(p[1], "help") == 0)		//1 ������������
		{
			infomation(HELP_GENERAL_ON);
		}
	}
	else if (*parameters == 3)							//ɾ������ȡ�ض��ļ�[δȷ��]
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
	else if (*parameters == 4)			//ɾ��ģʽ��ǿ��ȷ��
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
			if (strcmp(p[3], "delete") == 0)		//ɾ����λ�� location �ĵ��ʣ�û��ǿ��ȷ��
			{
				if (delete_confirm_dialog(p[4], "delete") == DEL_AND_UPD_REQUIRED)
				{
					desired_deleting_function(location,p[4]);
				}
			}
			if (strcmp(p[3], "search") == 0)		//�������� p[4] ���ݵĵ���
			{
				search_vocabulary(location, p[4],"loose");
			}
		}
		else if ((strcmp(p[1], "add") == 0) || (strcmp(p[1], "update") == 0))
		{
			infomation(ERR_NOT_ENOUGH_ARGUMENT);
		}
	}
	else if (*parameters == 6)							//ɾ����λ�� location �ĵ��ʣ�ǿ��ȷ��
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
	else if (*parameters == 7)									//locationδ�����add & update 6�������У�û�н���ǿ��ȷ��
	{
		if (strcmp(p[1], "add") == 0)						//��ӵ���
		{
			union_mode_para_exist(p[2], p[3], p[4], p[5], p[6],phrasegetin);
			desired_writing_function(location,phrasegetin);
		}
		else if (strcmp(p[1], "update") == 0)				//�޸ĵ���
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
	else if (*parameters == 9)								//����location������ add & update ��8 �������У�û��ǿ��ȷ��
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