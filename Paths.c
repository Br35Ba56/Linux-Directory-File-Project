#include <string.h>
#include <stdlib.h>
#include "Paths.h"

char *catFilePath(char *pathname, char *file)
{
	char *fullFilePath = malloc(strlen(pathname) + strlen(file) + 2);
	strcpy(fullFilePath, pathname);
	strcat(fullFilePath, "/");
	strcat(fullFilePath, file);
	return fullFilePath;
}
