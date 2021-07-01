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
		} else {
			printf("Error: Unknown argument\n");
		}
	} 
	return 0;
}