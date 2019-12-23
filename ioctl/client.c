
#include <stropts.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "demo.h"
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc, char** argv) {
	if (argc == 0) {
		printf("Usage: client [count|fill|clean]");
		return 1;
	}
	int f = open("/dev/demochar", O_RDWR);
	if (strcmp(argv[1], "count") == 0) {
		int count; 
		ioctl(f, IOCTL_OPEN_COUNT, &count);
		printf("Number of open: %d", count);
	}
	else if (strcmp(argv[1], "fill") == 0) {
		ioctl(f, IOCTL_FILL,'A');
	}
	else if (strcmp(argv[1], "clean") == 0) {
		ioctl(f, IOCTL_CLEAN);
	}
	else {
		 printf("Usage: client [count|fill|clean]");
		 return 2;
	}
	return 0;
}
