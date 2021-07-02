#include <new.h>

struct stat st = {0};

    // [name]
    //  ├── .proman
    //  │    └── info.toml
    //  ├── src
    //  │    ├── include
	//  │    │    └── [main header]  
	//  │    └── [main file]
    //  ├── Makefile
    //  └── README.md

int new(char *name) {

	FILE *readme, *info, *main, *mainh, *makefile, *config;
	
	// Directory paths
	char *src = "/src";
	char *include = "/src/include";
	char *current = "./";
	char *proman = "/.proman";
	char *dir = (char *) malloc(3 + strlen(src)+ strlen(include) ); 


	// File paths
	char *info_path = "/.proman/info.toml";
	char *main_header_path = "/src/include/main.h";
	char *main_path = "/src/main.c";
	char *make_path = "/Makefile";
	char *readme_path = "/README.md";
	char *file_path = (char *) malloc(3 + strlen(main_header_path)+ strlen(main_path) ); 

	char *config_path = "~/proman/proman.cfg";

	if (stat(name, &st) == -1) {
    	mkdir(name, 0700);
    	
    	/////////////////
    	// Directories //
    	/////////////////

    	// src directory
    	strcpy(dir, current);
    	strcat(dir, name);
    	strcat(dir, src);
    	printf("+ Creating directory %s\n", dir);
    	mkdir(dir, 0700);

    	// include directory
    	strcpy(dir, current);
    	strcat(dir, name);
    	strcat(dir, include);
    	printf("+ Creating directory %s\n", dir);
    	mkdir(dir, 0700);

    	// proman directory
    	strcpy(dir, current);
    	strcat(dir, name);
    	strcat(dir, proman);
    	printf("+ Creating directory %s\n", dir);
    	mkdir(dir, 0700);

    	///////////
    	// Files //
    	///////////

    	// README.md
    	strcpy(file_path, current);
    	strcat(file_path, name);
    	strcat(file_path, readme_path);
    	printf("+ Creating file %s\n", file_path);
    	readme = fopen(file_path, "w");

    	// info.toml
    	strcpy(file_path, current);
    	strcat(file_path, name);
    	strcat(file_path, info_path);
    	printf("+ Creating file %s\n", file_path);
    	info = fopen(file_path, "w");
    	fclose(info);

    	// main.c
    	strcpy(file_path, current);
    	strcat(file_path, name);
    	strcat(file_path, main_path);
    	printf("+ Creating file %s\n", file_path);
    	main = fopen(file_path, "w");
    	fclose(main);

    	// main.h
    	strcpy(file_path, current);
    	strcat(file_path, name);
    	strcat(file_path, main_header_path);
    	printf("+ Creating file %s\n", file_path);
    	mainh = fopen(file_path, "w");
    	fclose(mainh);

    	// Makefile
    	strcpy(file_path, current);
    	strcat(file_path, name);
    	strcat(file_path, make_path);
    	printf("+ Creating file %s\n", file_path);
    	makefile = fopen(file_path, "w");
    	fclose(makefile);

    	// Config
    	printf("+ Adding '%s' to config file\n", name);
    	config = fopen(config_path, "a");
    	fprintf(config, "Hello");
    	fclose(config);

    	free(dir);
    	free(file_path);
	} else {
		printf("Error: Directory '%s' already exists\n", name);
		return 0;
	}
	return 1;

}