#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/reboot.h>
#include <linux/reboot.h>
#include <errno.h>


int main() {
    reboot(LINUX_REBOOT_CMD_CAD_OFF);
    // If we're still here, reboot has failed
    switch (errno) {
        case EPERM:
            printf("Insufficient permissions to reboot the system\n");
            break;
        default:
            perror("reboot()");
            break;
    }
    return EXIT_FAILURE;
}
