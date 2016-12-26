#pragma once
#ifdef _WIN32
#include "Core_Function_Essentail_Base_Windows_Only.h"
#endif // _WIN32

void infomation(const int detail)
{
	if (detail == ERR_NOT_ENOUGH_ARGUMENT)
	{
		printf("���󣺲�������.\n��ð�����������executable.exe(�˳����ļ����� help\n");
	}
	else if (detail == HELP_GENERAL_ON)
	{
		printf("��Ӧ����Ϊ������������������C����CLI���򣬾������¹��ܣ���ӡ��޸ġ�������ɾ����\n");
		printf("���� executable help command(add/delete/update/search) �Ի�ȡ������Ϣ��\n");
	}
	else if (detail == HELP_PARTICULAR_ON_ADD)
	{
		puts("executable (location <dir>) add <english> <wordmod> <chinese> <explain> <example>������ָ��λ����Ӵ��");
		puts("<dir>���ĵ�����λ��\t<english>��Ӣ�ĵ��ʡ�\t<wordmod>�����ԡ�\n<chinese>�����ġ�\t<explain>�����͡�\t<example>��������");
		puts("������ <explain> �� <example> �������˫���ţ����⵼�µ������");
	}
	else if (detail == HELP_PARTICULAR_ON_DEL)
	{
		puts("executable (location <dir>) del <context> ��--no-warning)������ָ��λ��ɾ������������ --no-warning ���ؽ�������ȷ��ֱ��ɾ����");
		puts("<dir>���ĵ�����λ�á�");
	}
	else if (detail == HELP_PARTICULAR_ON_UPD)
	{
		puts("executable (location <dir>) update <english_context> <wordmod> <chinese> <explain> <example> (--no-warning)���޸Ĵ���<english_context>���ֵĴ��");
		puts("<dir>���ĵ�����λ��\t<english>��Ӣ�ĵ��ʡ�\t<wordmod>�����ԡ�\n<chinese>�����ġ�\t<explain>�����͡�\t<example>��������<english_context>��Ӣ������");
		puts("������ <explain> �� <example> �������˫���ţ����⵼�µ������");
	}
	else if (detail == HELP_PARTICULAR_ON_SER)
	{
		puts("executable (location <dir> search <context>����������<context>�ַ��ĵ��ʡ�\n");
	}
	else if (detail == ERR_ARGUMENT_WRONG)
	{
		puts("��������������ָ����");
	}
	else if (detail == ERR_FILE_NONEXISTANCE)
	{
		puts("������Ĭ��λ����û�д��ļ����ڡ�");
	}
	else if (detail == ERR_CLASS_DEFINED)
	{
		puts("����û�д��ִ��ԡ�");
	}
	exit(0);
}

/*������ļ������Լ��*/
void file_validity_check(char *file)
{
	FILE *valid;
	if ((valid = fopen(file, "r")) == NULL)
	{
		infomation(ERR_FILE_NONEXISTANCE);
	}
}

/*��������Լ��*/
int vaild_check_wordmod(char *word)
{
	if ((stricmp(word, "n.") == 0) || (stricmp(word, "adj.") == 0) || (stricmp(word, "a.") == 0) || (stricmp(word, "adv.") == 0) || (stricmp(word, "v.") == 0) || (stricmp(word, "vi") == 0) || (stricmp(word, "vt.") == 0) || (stricmp(word, "art.") == 0) || (stricmp(word, "prep.") == 0) || (stricmp(word, "conj.") == 0) || (stricmp(word, "int.") == 0))
	{
		return 1;
	}
	else return 0;
}

/*�����Сд����ת��*/
void lowerstring(char *word)
{
	int count;
	for (count = 0; count < strlen(word); count++)
	{
		word[count] = tolower(word[count]);
	}
}

/*�������д����ת��*/
void upperstring(char *word)
{
	int count;
	for (count = 0; count < strlen(word); count++)
	{
		word[count] = toupper(word[count]);
	}
}

/*�������������*/
void search_vocabulary(char *file, char *intend, const char *mode)
{
	FILE *read = fopen(file, "r");
	static char readcompare[1000];
	static char wordcomapre[1000];
	upperstring(intend);
	while (!feof(read))
	{
		fgets(readcompare, 999, read);
		strcpy(wordcomapre, readcompare);
		upperstring(wordcomapre);
		if (strstr(wordcomapre, intend) != NULL)
		{
			if (strcmp(mode, "loose") == 0)
			{
				printf("%s", readcompare);
			}
			else if (strcmp(mode, "strict") == 0)
			{
				if (wordcomapre[0] == intend[0])
				{
					if (wordcomapre[strlen(intend)] == '\t')
					{
						puts(readcompare);
					}
				}
			}
		}
		strcpy(readcompare, "");						//��ʼ�� readcompare ����
	}
}

/*������ӹ�����[Specically Designed]*/
void word_combine(char *word, const char *mode)
{
	if (strcmp(mode, "english") == 0)
	{
		//Nothing to do
	}
	else if (strcmp(mode, "wordmod") == 0)
	{
		strcat(phrasegetin, "\t");
	}
	else if (strcmp(mode, "chinese") == 0)
	{
		//Nothing To do
	}
	else if (strcmp(mode, "example") == 0)
	{
		strcat(phrasegetin, "\tӢ�����䣺");
		//Nothing To do
	}
	else if (strcmp(mode, "explain") == 0)
	{
		strcat(phrasegetin, "\t����˵����");
		//Nothing To do
	}
	else
	{
		printf("�������ô���û�� %s ���ѡ��.\n", mode);
	}
	strcat(phrasegetin, word);
}

/*�������������[Add/Update����]*/
void union_mode_nonpara()
{
	static char thoseword[120];
again:
	puts("������ԣ�");
	gets(thoseword);
	lowerstring(thoseword);
	if (vaild_check_wordmod(thoseword) == 1)
	{
		word_combine(thoseword, "wordmod");
	}
	else
	{
		puts("���󣺴����������");
		goto again;
	}
	puts("�������ģ�");
	gets(thoseword);
	word_combine(thoseword, "chinese");
	puts("������ͣ�");
	gets(thoseword);
	word_combine(thoseword, "explain");
	puts("�������䣺");
	gets(thoseword);
	word_combine(thoseword, "example");
}

/*���������Add��������*/
void add_specific_nopara()
{
	static char thoseword[120];
	puts("����Ӣ�ģ�");
	gets(thoseword);
	word_combine(thoseword, "english");
	union_mode_nonpara();
}

/*���������Update��������*/
void update_specific_nopara(char *wordbefore)
{
	word_combine(wordbefore, "english");
	union_mode_nonpara();
}

/*��������в���ʽ����������*/
void union_mode_para_exist(char *english, char *wordmod, char *chinese, char *explain, char *example)
{
	if (vaild_check_wordmod(wordmod) == 1)
	{
		lowerstring(wordmod);
		word_combine(english, "english");
		word_combine(wordmod, "wordmod");
		word_combine(chinese, "chinese");
		word_combine(explain, "explain");
		word_combine(example, "example");
	}
	else
	{
		infomation(ERR_ARGUMENT_WRONG);
		puts("���󣺴����������");
	}
}

/*�����������д���ļ�*/
void desired_writing_function(char *file,char *word)
{
	FILE *insert;
	insert = fopen(file, "a");
	fputs(word, insert);
	fputs("\n", insert);
	fclose(insert);
	strcpy(word, " ");
	printf("д���������ɡ�\n");
}

/*�����ɾ������*/
void desired_deleting_function(char *file, char *word)
{
	static char copyword[1000];
	static char no_diff_copy[1000];
	FILE *fromfile = fopen(file , "r");
	FILE *tofile = fopen("temp.txt", "w");
	upperstring(word);
	while (!feof(fromfile))
	{
		fgets(copyword, 999, fromfile);
		strcpy(no_diff_copy, copyword);
		upperstring(no_diff_copy);
		if (strstr(no_diff_copy, word) == NULL)
		{
			fputs(copyword, tofile);
		}
		else if (no_diff_copy[0] != word[0])
		{
			fputs(copyword, tofile);
		}
		else if (no_diff_copy[strlen(word)] != '\t')
		{
			fputs(copyword, tofile);
		}
	}
	fclose(fromfile);
	fclose(tofile);
	move_type_function("temp.txt", file);
}

/*������޲���ʽ�޸Ľṹ*/
void update_word_nopara(char *file,char *word,char *deststr)
{
	desired_deleting_function(file, word);
	update_specific_nopara(word);
	desired_writing_function(file,deststr);
}

/*������в���ʽ�޸Ľṹ*/
void update_word_para_exist(char *file, char *deststr, char *english, char *wordmod, char *chinese, char *explain, char *example)
{
	desired_deleting_function(file, english);
	union_mode_para_exist(english, wordmod, chinese, explain, example);
	desired_writing_function(file, deststr);
}

/*�����ɾ��/�޸�ȷ���Ի�*/
int delete_confirm_dialog(char *words,const char *mode)
{
	char confirmword[4];
	search_vocabulary(location, words,"strict");
	if (strcmp(mode, "delete") == 0)
	{
		puts("�������ʽ��ᱻɾ�����Ƿ�ȷ��ɾ����");
	}
	else if (strcmp(mode, "update") == 0)
	{
		puts("�������ʽ��ᱻ�滻���Ƿ�ȷ���滻��");
	}
	gets(confirmword);
	if (strcmp(confirmword, "yes") == 0)
	{
		puts("���ڴ���");
		return (DEL_AND_UPD_REQUIRED);
	}
	else return (EXIT_REQUIRED);
}