#pragma once
#include "Core_Headers_Variables_Set.h"
/* For Windows-Related Function */
// using type command in Windows.

void file_type_function(char *file)
{
	char type[100] = "type ";
	strcat(type, file);
	system(type);
}

// using move command in Windows.
void move_type_function(char *Sourcefile, char *Destination)
{
	char move[100] = "move ";
	strcat(move, Sourcefile);
	strcat(move, " ");
	strcat(move, Destination);
	strcat(move, ">nul");			//不进行回显。
	system(move);
}

/*Using Powershell command*/
int new_item_automatic_check(char *file)
{
	char newfile[150] = "powershell -command New-Item ";
	if (_access(file, 0) != 0)
	{
		strcat(newfile, file);
		system(newfile);
	}
}
