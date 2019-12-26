#include <poll.h>
#include <stropts.h>
#include <stropts.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	struct pollfd fd;
	fd.fd = open("/dev/demochar", O_RDWR);
	fd.events = POLLIN;
	char msg[256];
	msg[255] = 0;
	int ret;
	while ((ret = poll(&fd, 1, -1)) > 0) {
		if (fd.revents & POLLIN) // we can read 
		{
			printf("Reading one byte\n");
			int length = read(fd.fd, msg, 255);
			printf("%s\n", msg);
		}
	}
	return 0;
}
