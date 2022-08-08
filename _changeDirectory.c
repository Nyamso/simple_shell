#include "shell.h"

/**
 * _changeDirectory - change current directory
 * @Data: data structure
 */

void _changeDirectory(appData_t *Data)
{
	char currentDirectory[500];

	getcwd(currentDirectory, 500);

	if (Data == NULL)
		return;

	if (
			!Data->arguments[1] ||
			_strcmp(Data->arguments[1], "~") == 0 ||
			_strcmp(Data->arguments[1], "~/") == 0
			)
		_changeToHomeDirectory(Data, currentDirectory);
	else if (_strcmp(Data->arguments[1], "-") == 0)
		_changeToPreviousDirectory(Data, currentDirectory);
	else
		_changeToAnyDirectory(Data, currentDirectory);
}
