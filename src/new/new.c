#include <new.h>

struct stat st = {0};

void new(char *name) {

	if (stat(name, &st) == -1) {
    	mkdir(name, 0700);
	}

}