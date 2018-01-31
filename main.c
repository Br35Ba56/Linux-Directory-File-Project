//
//  main.c
//  FileDirProc
//
//  Created by Anthony Schneider on 11/21/17.
//  Copyright © 2017 Anthony Schneider. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include "Directory.h"
#include "Files.h"

const char menu[] =
    "\n0 - Exit\n1 - Select directory\n2 - List directory content (first level)\n3 - List directory content (all levels)\n4 - Delete file\n5 - Display file (hexadecimal view)\n6 - Encrypt file (XOR with password)\n7 - Decrypt file (XOR with password)\n";

int main(int argc, const char *argv[])
{
	int input = 0;

	char dir[256];
	char fileName[256];
	printf("%s", menu);
	while (scanf("%d", &input) == 1) {

		switch (input) {
		case 0:
			printf("Exit\n");
			return 0;
			break;
		case 1:
			printf("1 - Select directory\nEnter directory path:\n");
			scanf("%s", dir);
			DIR *dirp = selectDirectory(dir);
			if (dirp) {
				printf("Directory opened.");
			} else {
  				printf("Directory unable to be opened");
			}
			break;
		case 2:
			printf("2 - List directory (first level)\n");
			listDirectory(dir);
			break;
		case 3:
			printf("List directory (all levels)\n");
			listAllDirectory(dir);
			break;
		case 4:
			printf("4 - Delete file\n");
			printf("File Name: ");
			scanf("%s", fileName);
			if (deleteFile(dir, fileName)) {
				printf("Success removing file\n");
			} else {
				printf("Error in removing file\n");
			}
			break;
		case 5:
			printf("Display file (hexadecimal view)\n");
			printf("File Name: ");
			scanf("%s", fileName);
			displayFile(dir, fileName);
			break;
		case 6:
			printf("Enrypt file (XOR with password)\n");
			printf("File Name: ");
			scanf("%s", fileName);
			printf("Password: ");
			char password[32];
			scanf("%s", password);
			encryptFile(dir, fileName, password);
			break;
		case 7:
			printf("Decrypt file (XOR with password)\n");
			printf("File Name: ");
			scanf("%s", fileName);
			printf("Password: ");
			char d_password[32];
			scanf("%s", d_password);
			decryptFile(dir, fileName, d_password);
			break;
		}
		printf("%s", menu);
	}
	return 0;
}
