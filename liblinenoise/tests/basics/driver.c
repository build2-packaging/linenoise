#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//
#include <linenoise.h>

int main() {
  while (1) {
    char* line = linenoise("prompt> ");
    if (!line) break;

    printf("echo: '%s'\n", line);
    linenoiseHistoryAdd(line);
    linenoiseHistorySave("history.txt");

    free(line);
  }

  return 0;
}
