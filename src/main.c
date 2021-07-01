#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	char current_dir[100];

	if (argc == 1) {
		printf("ProMan v0.0.1\nMissing command-line args\n");
	} else if (argc == 2) {
		if (strcmp(argv[1], "init") == 0 && getcwd(current_dir, sizeof(current_dir)) != NULL) {
			printf("Initializing new project in directory %s\n", current_dir);
		} else if (strcmp(argv[1], "new") == 0) {
			printf("Error: Command 'new' requires extra parameters.\n");
		} else if (strcmp(argv[1], "del") == 0) {
			printf("Error: Command 'del' requires extra parameters.\n");
		} else {
			printf("Error: Unknown argument\n");
		}
	} else if (argc == 3) {
		if (strcmp(argv[1], "new") == 0 && getcwd(current_dir, sizeof(current_dir)) != NULL) {
			printf("+ Creating new directory '%s' in %s\n", argv[2], current_dir);
		} else if (strcmp(argv[1], "del") == 0 && getcwd(current_dir, sizeof(current_dir)) != NULL) {
			printf("+ Deleting project '%s'\n", argv[2]);
		}
	}

	return 0;
}
