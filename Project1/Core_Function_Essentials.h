#pragma once
#ifdef _WIN32
#include "Core_Function_Essentail_Base_Windows_Only.h"
#endif // _WIN32

void infomation(const int detail)
{
	if (detail == ERR_NOT_ENOUGH_ARGUMENT)
	{
		printf("错误：参数过少.\n获得帮助，请运行executable.exe(此程序文件名） help\n");
	}
	else if (detail == HELP_GENERAL_ON)
	{
		printf("此应用是为四六级考试所开发的C语言CLI程序，具有以下功能：添加、修改、搜索、删除等\n");
		printf("输入 executable help command(add/delete/update/search) 以获取更多信息；\n");
	}
	else if (detail == HELP_PARTICULAR_ON_ADD)
	{
		puts("executable (location <dir>) add <english> <wordmod> <chinese> <explain> <example>：可以指定位置添加词语。");
		puts("<dir>：文档所在位置\t<english>：英文单词。\t<wordmod>：词性。\n<chinese>：中文。\t<explain>：解释。\t<example>：举例。");
		puts("建议在 <explain> 和 <example> 部分添加双引号，以免导致导入错误。");
	}
	else if (detail == HELP_PARTICULAR_ON_DEL)
	{
		puts("executable (location <dir>) del <context> （--no-warning)：可以指定位置删除词语，如果带有 --no-warning 开关将不经过确认直接删除。");
		puts("<dir>：文档所在位置。");
	}
	else if (detail == HELP_PARTICULAR_ON_UPD)
	{
		puts("executable (location <dir>) update <english_context> <wordmod> <chinese> <explain> <example> (--no-warning)：修改带有<english_context>部分的词语。");
		puts("<dir>：文档所在位置\t<english>：英文单词。\t<wordmod>：词性。\n<chinese>：中文。\t<explain>：解释。\t<example>：举例。<english_context>：英文内容");
		puts("建议在 <explain> 和 <example> 部分添加双引号，以免导致导入错误。");
	}
	else if (detail == HELP_PARTICULAR_ON_SER)
	{
		puts("executable (location <dir> search <context>：搜索带有<context>字符的单词。\n");
	}
	else if (detail == ERR_ARGUMENT_WRONG)
	{
		puts("参数错误，请重新指定。");
	}
	else if (detail == ERR_FILE_NONEXISTANCE)
	{
		puts("错误：在默认位置下没有此文件存在。");
	}
	else if (detail == ERR_CLASS_DEFINED)
	{
		puts("错误：没有此种词性。");
	}
	exit(0);
}

/*组件：文件存在性检测*/
void file_validity_check(char *file)
{
	FILE *valid;
	if ((valid = fopen(file, "r")) == NULL)
	{
		infomation(ERR_FILE_NONEXISTANCE);
	}
}

/*组件：词性检查*/
int vaild_check_wordmod(char *word)
{
	if ((stricmp(word, "n.") == 0) || (stricmp(word, "adj.") == 0) || (stricmp(word, "a.") == 0) || (stricmp(word, "adv.") == 0) || (stricmp(word, "v.") == 0) || (stricmp(word, "vi") == 0) || (stricmp(word, "vt.") == 0) || (stricmp(word, "art.") == 0) || (stricmp(word, "prep.") == 0) || (stricmp(word, "conj.") == 0) || (stricmp(word, "int.") == 0))
	{
		return 1;
	}
	else return 0;
}

/*组件：小写文字转换*/
void lowerstring(char *word)
{
	int count;
	for (count = 0; count < strlen(word); count++)
	{
		word[count] = tolower(word[count]);
	}
}

/*组件：大写文字转换*/
void upperstring(char *word)
{
	int count;
	for (count = 0; count < strlen(word); count++)
	{
		word[count] = toupper(word[count]);
	}
}

/*组件：搜索文字*/
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
		strcpy(readcompare, "");						//初始化 readcompare 内容
	}
}

/*组件：加工文字[Specically Designed]*/
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
		strcat(phrasegetin, "\t英文例句：");
		//Nothing To do
	}
	else if (strcmp(mode, "explain") == 0)
	{
		strcat(phrasegetin, "\t解释说明：");
		//Nothing To do
	}
	else
	{
		printf("函数调用错误，没有 %s 这个选项.\n", mode);
	}
	strcat(phrasegetin, word);
}

/*组件：输入文字[Add/Update共用]*/
void union_mode_nonpara()
{
	static char thoseword[120];
again:
	puts("输入词性：");
	gets(thoseword);
	lowerstring(thoseword);
	if (vaild_check_wordmod(thoseword) == 1)
	{
		word_combine(thoseword, "wordmod");
	}
	else
	{
		puts("错误：词性输入错误");
		goto again;
	}
	puts("输入中文：");
	gets(thoseword);
	word_combine(thoseword, "chinese");
	puts("输入解释：");
	gets(thoseword);
	word_combine(thoseword, "explain");
	puts("输入例句：");
	gets(thoseword);
	word_combine(thoseword, "example");
}

/*组件：调用Add输入文字*/
void add_specific_nopara()
{
	static char thoseword[120];
	puts("输入英文：");
	gets(thoseword);
	word_combine(thoseword, "english");
	union_mode_nonpara();
}

/*组件：调用Update输入文字*/
void update_specific_nopara(char *wordbefore)
{
	word_combine(wordbefore, "english");
	union_mode_nonpara();
}

/*组件：具有参数式的输入文字*/
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
		puts("错误：词性输入错误");
	}
}

/*组件：将文字写入文件*/
void desired_writing_function(char *file,char *word)
{
	FILE *insert;
	insert = fopen(file, "a");
	fputs(word, insert);
	fputs("\n", insert);
	fclose(insert);
	strcpy(word, " ");
	printf("写入操作已完成。\n");
}

/*组件：删除文字*/
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

/*组件：无参数式修改结构*/
void update_word_nopara(char *file,char *word,char *deststr)
{
	desired_deleting_function(file, word);
	update_specific_nopara(word);
	desired_writing_function(file,deststr);
}

/*组件：有参数式修改结构*/
void update_word_para_exist(char *file, char *deststr, char *english, char *wordmod, char *chinese, char *explain, char *example)
{
	desired_deleting_function(file, english);
	union_mode_para_exist(english, wordmod, chinese, explain, example);
	desired_writing_function(file, deststr);
}

/*组件：删除/修改确定对话*/
int delete_confirm_dialog(char *words,const char *mode)
{
	char confirmword[4];
	search_vocabulary(location, words,"strict");
	if (strcmp(mode, "delete") == 0)
	{
		puts("上述单词将会被删除，是否确定删除？");
	}
	else if (strcmp(mode, "update") == 0)
	{
		puts("上述单词将会被替换，是否确定替换？");
	}
	gets(confirmword);
	if (strcmp(confirmword, "yes") == 0)
	{
		puts("正在处理");
		return (DEL_AND_UPD_REQUIRED);
	}
	else return (EXIT_REQUIRED);
}