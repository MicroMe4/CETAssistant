#pragma once
#ifdef _WIN32
#include "Core_Function_Essentail_Base_Windows_Only.h"
#endif // _WIN32

/*�����������ʾ/��������*/
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
	if (_access(file, 0) == NULL)
	{
		infomation(ERR_FILE_NONEXISTANCE);
		system("pause>nul");
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

int getline(char *file)
{
	char ch;
	int lines;
	FILE *getline = fopen(file, "r");
	while (!feof(getline))
	{
		if ((ch = fgetc(getline)) == '\n')
		{
			lines+=1;
		}
	}
	fclose(getline);
	return lines;
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
int search_vocabulary(char *file, char *intend, const char *mode)
{
	int numberfind = 0;
	FILE *read = fopen(file, "r");
	static char readcompare[1000];
	static char wordcomapre[1000];
	upperstring(intend);
	printf("\n");
	puts("���е��ʽ��ᱻɾ��:");
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
						numberfind++;
					}
				}
			}
		}
		strcpy(readcompare, "");						//��ʼ�� readcompare ����
	}
	if (numberfind == 0)
	{
		printf("�޲��ҽ��\n");
	}
	fclose(read);
	return numberfind;
}

/*������ӹ�����[Specically Designed]*/
void word_combine(char *word, char *targstr, const char *mode)
{
	if (strcmp(mode, "english") == 0)
	{
		//Nothing to do
	}
	else if (strcmp(mode, "wordmod") == 0)
	{
		strcat(targstr, "\t");
	}
	else if (strcmp(mode, "chinese") == 0)
	{
		//Nothing To do
	}
	else if (strcmp(mode, "example") == 0)
	{
		strcat(targstr, "\tӢ�����䣺");
		//Nothing To do
	}
	else if (strcmp(mode, "explain") == 0)
	{
		strcat(targstr, "\t����˵����");
		//Nothing To do
	}
	else
	{
		printf("�������ô���û�� %s ���ѡ��.\n", mode);
	}
	strcat(targstr, word);
}

/*�������������[Add/Update����]��д��targstr*/
void union_mode_nonpara(char *targstr)
{
	static char thoseword[120];
again:
	puts("������ԣ�");
	gets(thoseword);
	lowerstring(thoseword);
	if (vaild_check_wordmod(thoseword) == 1)
	{
		word_combine(thoseword, targstr, "wordmod");
	}
	else
	{
		puts("���󣺴����������");
		goto again;
	}
	puts("�������ģ�");
	gets(thoseword);
	word_combine(thoseword, targstr, "chinese");
	puts("������ͣ�");
	gets(thoseword);
	word_combine(thoseword, targstr, "explain");
	puts("�������䣺");
	gets(thoseword);
	word_combine(thoseword, targstr, "example");
}

/*���������Add��������*/
void add_specific_nopara(char *targstr)
{
	static char thoseword[120];
	puts("����Ӣ�ģ�");
	gets(thoseword);
	word_combine(thoseword, targstr, "english");
	union_mode_nonpara(targstr);
}

/*���������Update��������*/
void update_specific_nopara(char *wordbefore,char *targstr)
{
	word_combine(wordbefore, targstr, "english");
	union_mode_nonpara(targstr);
}

/*��������в���ʽ����������*/
void union_mode_para_exist(char *english, char *wordmod, char *chinese, char *explain, char *example,char *targstr)
{
	if (vaild_check_wordmod(wordmod) == 1)
	{
		lowerstring(wordmod);
		word_combine(english, targstr, "english");
		word_combine(wordmod, targstr, "wordmod");
		word_combine(chinese, targstr, "chinese");
		word_combine(explain, targstr, "explain");
		word_combine(example, targstr, "example");
	}
	else
	{
		infomation(ERR_ARGUMENT_WRONG);
		puts("���󣺴����������");
	}
}

/*�����������д���ļ�*/
void desired_writing_function(char *file,char *string)
{
	int edge = getline(file);
	fpos_t retard;
	int writetime = 0, start = 0;
	char copystring[2][1000];
	FILE *openguyys = fopen(file, "r+");
	fgetpos(openguyys, &retard);
	while (start <= edge)
	{
		fgets(copystring[0], 999, openguyys);
		if (stricmp(string, copystring[0]) < 0)
		{
			fputs(string, openguyys);
			fputs("\n", openguyys);
			fsetpos(openguyys, &retard);
			fputs(copystring[0], openguyys);
			writetime += 1;
			break;
		}
		fgetpos(openguyys, &retard);
		fgets(copystring[1], 999, openguyys);
		if ((_strcmpi(string, copystring[0]) > 0) && _stricmp(string, copystring[1]) < 0)
		{
			fsetpos(openguyys, &retard);
			fputs(string, openguyys);
			fputs("\n", openguyys);
			fputs(copystring[1], openguyys);
			writetime += 1;
			break;
		}
		start += 1;
	}
	if (writetime == 0)
	{
		fputs(string, openguyys);
		fputs("\n", openguyys);
	}
	strcpy(string, "");
	fclose(openguyys);
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
void update_word_nopara(char *file,char *word,char *targstr)
{
	desired_deleting_function(file, word);
	update_specific_nopara(word,targstr);
	desired_writing_function(file,targstr);
}

/*������в���ʽ�޸Ľṹ*/
void update_word_para_exist(char *file, char *targstr, char *english, char *wordmod, char *chinese, char *explain, char *example)
{
	desired_deleting_function(file, english);
	union_mode_para_exist(english, wordmod, chinese, explain, example, targstr);
	desired_writing_function(file, targstr);
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