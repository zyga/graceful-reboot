#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/reboot.h>
#include <linux/reboot.h>
#include <errno.h>

int main()
{
	sync();
	if (reboot(LINUX_REBOOT_CMD_RESTART) != 0) {
		switch (errno) {
		case EPERM:
			printf
			    ("Insufficient permissions to reboot the system\n");
			break;
		default:
			perror("reboot()");
			break;
		}
		return EXIT_FAILURE;
	}
	printf("Reboot requested\n");
	return EXIT_SUCCESS;
}
