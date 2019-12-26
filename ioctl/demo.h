#ifndef DEMO_DEMO_H
#define DEMO_DEMO_H

#include <linux/ioctl.h>

#define IOCTL_NUMBER 101

#define IOCTL_CLEAN 		_IO(IOCTL_NUMBER, 1)
#define IOCTL_FILL 		_IOW(IOCTL_NUMBER, 2, char)
#define IOCTL_OPEN_COUNT 	_IOR(IOCTL_NUMBER, 3, unsigned long long)

#endif // DEMO_DEMO_H
