//
//  Files.c
//  FileDirProc
//
//  Created by Anthony Schneider on 11/21/17.
//  Copyright © 2017 Anthony Schneider. All rights reserved.
//

#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include "Paths.h"
#include "Files.h"

int deleteFile(char *pathname, char *file)
{
	char *fullFilePath = malloc(strlen(pathname) + strlen(file) + 2);
	strcpy(fullFilePath, pathname);
	strcat(fullFilePath, "/");
	strcat(fullFilePath, file);

	printf("%s\n", fullFilePath);
	if (remove(fullFilePath)) {
		free(fullFilePath);
		return 0;
	}
	free(fullFilePath);
	return -1;
}

int displayFile(char *pathname, char *file)
{
	int inputFd;
	ssize_t numRead;
	char buf[BUF_SIZE];
	char *fullFilePath = catFilePath(pathname, file);;

	if ((inputFd = open(fullFilePath, O_RDONLY)) == -1) {
		printf("Error opening file");
		return -1;
	}

	free(fullFilePath);

	while ((numRead = read(inputFd, buf, BUF_SIZE)) > 0) {
		for (int i = 0; i < numRead; i++) {
			printf("%X", buf[i]);
			if ((i % 50) == 0)
				printf("\n");
		}
	}
	if (close(inputFd) == -1) {
		printf("File close error");
		return -1;
	}
	return 0;
}

int encryptFile(char *pathname, char *file, char *pswd)
{
	int inputFd;
	ssize_t numRead, index = 0;
	ssize_t pswdLength = strlen(pswd);
	char buf[BUF_SIZE];
	char *fullFilePath = catFilePath(pathname, file);

	inputFd = open(fullFilePath, O_RDWR);
	free(fullFilePath);
	if (inputFd == -1)
		return -1;

	while ((numRead = read(inputFd, buf, BUF_SIZE)) > 0) {
		for (int i = 0; i < numRead; i++) {
			buf[i] ^= pswd[index++ % pswdLength];
		}
		if (lseek(inputFd, -numRead, SEEK_CUR) == -1) {
			printf("lseek failed");
			return -1;
		}

		if (write(inputFd, buf, numRead) != numRead) {
			printf("Not all buffer was written");
			return -1;
		}
	}
	if (close(inputFd) == -1) {
		printf("File close error");
		return -1;
	}
	return 0;
}

int decryptFile(char *pathname, char *file, char *pswd)
{
	encryptFile(pathname, file, pswd);
	return 0;
}
