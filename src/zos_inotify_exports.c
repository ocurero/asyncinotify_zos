#include <stdint.h>

/* Declaraciones de las funciones “reales” del otro fichero */
int zos_real_inotify_init(void);
int zos_real_inotify_init1(int flags);
int zos_real_inotify_add_watch(int fd, const char *path, uint32_t mask);
int zos_real_inotify_rm_watch(int fd, int wd);

/* Estos nombres son los que asyncinotify busca */
int inotify_init(void) {
    return zos_real_inotify_init();
}

/* Para z/OS: evita flags raros -> si flags!=0, ignóralos */
int inotify_init1(int flags) {
    return zos_real_inotify_init();
}

int inotify_add_watch(int fd, const char *path, uint32_t mask) {
    return zos_real_inotify_add_watch(fd, path, mask);
}

int inotify_rm_watch(int fd, int wd) {
    return zos_real_inotify_rm_watch(fd, wd);
}
