#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    const char* directory = "/path/to/location"; // Specify the target directory
    const char* prefix = "file"; // Specify the filename prefix
    const int fileCount = 99; // Specify the number of files to create
    const int fileSize = 1024 * 1024; // 1MB file size in bytes

    char filename[256];
    char content[fileSize];

    for (int n = 2; n <= fileCount + 1; n++) {
        snprintf(filename, sizeof(filename), "%s/%s%d.txt", directory, prefix, n);
        FILE* file = fopen(filename, "w");
        if (file == NULL) {
            printf("Failed to create file %s\n", filename);
            continue;
        }

        memset(content, 'A', fileSize);
        fwrite(content, 1, fileSize, file);
        fclose(file);
        printf("Created file %s\n", filename);
    }

    return 0;
}