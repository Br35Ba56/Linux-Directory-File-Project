//
//  Files.h
//  FileDirProc
//
//  Created by Anthony Schneider on 11/21/17.
//  Copyright © 2017 Anthony Schneider. All rights reserved.
//

#include <stdio.h>
#define BUF_SIZE 1024

int deleteFile(char *pathname, char *file);

int displayFile(char *pathname, char *file);

int encryptFile(char *pathname, char *file, char *pswd);

int decryptFile(char *pathname, char *file, char *pswd);
