//
//  Directory.c
//  FileDirProc
//
//  Created by Anthony Schneider on 11/21/17.
//  Copyright © 2017 Anthony Schneider. All rights reserved.
//

#define _XOPEN_SOURCE 600
#include "Directory.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ftw.h>

struct dirent *dp;

DIR *selectDirectory(char *dirpath)
{
	return opendir(dirpath);
}

void listDirectory(char *dir)
{
        DIR *dirp = opendir(dir);
	for (;;) {
		dp = readdir(dirp);
		if (dp == NULL)
			break;
		if (!(strcmp(dir, ".") == 0))
			printf("%s/", dir);
		printf("%s\n", dp->d_name);
	}

}

static int dirTree(const char *pathname, const struct stat *sbuf, int type, struct FTW *ftwb) 
{
	printf("%s\n", &pathname[ftwb->base]);
	return 0;
}

void listAllDirectory(char *dir)
{
	int flags = FTW_DEPTH;
	nftw(dir, dirTree, 10, flags); 
}
