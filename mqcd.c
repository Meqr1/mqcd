#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int writeHistory(char *directory) {
  const char *homeDir = getenv("USERPROFILE");
  if (homeDir == NULL) {
    printf("Error: Could not determine the home directory.\n");
    return 1;
  }

  char filePath[1024];
    snprintf(filePath, sizeof(filePath), "%s\\.history", homeDir);

    FILE *file = fopen(filePath, "w");
    if (file == NULL) {
        printf("Error: Could not open file %s for writing.\n", filePath);
        return 1;
    }

    fprintf(file, "%s", directory);

    fclose(file);

    printf("Data written to %s successfully.\n", filePath);

    return 0;
}

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("no mode provided");
    return 1;
  }

  if (strcmp("set", argv[1]) == 0) {
    writeHistory(argv[2]);
  } else if (strcmp("get", argv[1]) == 0) {
  }

  return 0;
}
