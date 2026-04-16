#define _XPLATFORM_SOURCE
#include <sys/inotify.h>
#include <stdint.h>

/* Avoid name colisions between these functions and the inotify_* ones */

int zos_real_inotify_init(void) {
    return inotify_init();
}

int zos_real_inotify_init1(int flags) {
    return inotify_init1(flags);
}

int zos_real_inotify_add_watch(int fd, const char *path, uint32_t mask) {
    return inotify_add_watch(fd, path, mask);
}

int zos_real_inotify_rm_watch(int fd, int wd) {
    return inotify_rm_watch(fd, wd);
}

