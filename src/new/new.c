#include <new.h>

struct stat st = {0};

int new(char *name) {

	if (stat(name, &st) == -1) {
    	mkdir(name, 0700);
	} else {
		printf("--> Directory '%s' already exists\n", name);
		return 0;
	}
	return 1;

}