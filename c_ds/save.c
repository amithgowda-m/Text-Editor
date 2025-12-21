#include "save.h"
#include <stdio.h>

void save_to_file(const char* filename, const char* text) {
    FILE* f = fopen(filename, "w");
    if (f) {
        fprintf(f, "%s", text);
        fclose(f);
    }
}
