#define _XPLATFORM_SOURCE
#include <sys/inotify.h>
#include <stdint.h>

/* Estas funciones NO se llaman como inotify_* para evitar líos de export/mapping */
int zos_real_inotify_init(void) {
    return inotify_init();
}

int zos_real_inotify_init1(int flags) {
    return inotify_init1(flags);
}

int zos_real_inotify_add_watch(int fd, const char *path, uint32_t mask) {
    return inotify_add_watch(fd, path, mask);
}

/* En tu header de z/OS se ve que wd es int */
int zos_real_inotify_rm_watch(int fd, int wd) {
    return inotify_rm_watch(fd, wd);
}

