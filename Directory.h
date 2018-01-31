//
//  Directory.h
//  FileDirProc
//
//  Created by Anthony Schneider on 11/21/17.
//  Copyright © 2017 Anthony Schneider. All rights reserved.
//

#include <stdio.h>
#include <dirent.h>

DIR *selectDirectory(char *dirpath);

void listDirectory(char *dir);

void listAllDirectory(char *dir);

