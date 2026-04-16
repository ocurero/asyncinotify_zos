#include <stdint.h>

/* "Real" declarations from the other file */

int zos_real_inotify_init(void);
int zos_real_inotify_init1(int flags);
int zos_real_inotify_add_watch(int fd, const char *path, uint32_t mask);
int zos_real_inotify_rm_watch(int fd, int wd);

int inotify_init(void) {
    return zos_real_inotify_init();
}

int inotify_init1(int flags) {
    return zos_real_inotify_init();
}

int inotify_add_watch(int fd, const char *path, uint32_t mask) {
    return zos_real_inotify_add_watch(fd, path, mask);
}

int inotify_rm_watch(int fd, int wd) {
    return zos_real_inotify_rm_watch(fd, wd);
}
