#include "shell.h"
int _cd(const char *target_dir) {
    char current_dir[1024];

    /* Get the current working directory*/
    if (getcwd(current_dir, sizeof(current_dir)) == NULL) {
        perror("cd");
        return 1;
    }

    /*Save the current working directory as the previous working directory (OLDPWD)*/
    setenv("OLDPWD", current_dir, 1);

    /* Change to the target directory*/
    if (chdir(target_dir) != 0) {
        perror("cd");
        return 1;
    }

    /*Update the PWD environment variable*/
    setenv("PWD", target_dir, 1);

    return 0;
}
