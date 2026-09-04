#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const char *home = getenv("HOME");

    if (home == NULL) {
        fprintf(stderr, "Error: HOME is not set.\n");
        return 1;
    }

    char cmd[1024];

    printf("Creating Fastfetch config directory...\n");

    snprintf(cmd, sizeof(cmd),
             "mkdir -p \"%s/.config/fastfetch\"", home);

    if (system(cmd) != 0) {
        fprintf(stderr, "Failed to create directory.\n");
        return 1;
    }

    printf("Copying config.jsonc...\n");

    snprintf(cmd, sizeof(cmd),
             "cp config.jsonc \"%s/.config/fastfetch/config.jsonc\"",
             home);

    if (system(cmd) != 0) {
        fprintf(stderr, "Failed to copy config.jsonc.\n");
        return 1;
    }

    printf("Copying fastfetch.sixel...\n");

    snprintf(cmd, sizeof(cmd),
             "cp fastfetch.sixel \"%s/.config/fastfetch.sixel\"",
             home);

    if (system(cmd) != 0) {
        fprintf(stderr, "Failed to copy fastfetch.sixel.\n");
        return 1;
    }

    printf("\nFastfetch configuration installed successfully.\n");

    return 0;
}
