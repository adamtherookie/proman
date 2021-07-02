/* 
 * MIT License
 * 
 * Copyright (c) 2021 Adam Salhi
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

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

   // Get some info:

	// Check if it's a C project or C++
	int type = 0;
	do {
		printf("➡ Enter the project type: (1- C, 2- C++): ");
		scanf("%d", &type);
	} while(type != 1 && type != 2);



	FILE *readme, *info, *main, *mainh, *makefile /*, *config */;
	
	// Directory paths
	char *src = "/src";
	char *include = "/src/include";
	char *current = "./";
	char *proman = "/.proman";
	char *dir = (char *) malloc(3 + strlen(src)+ strlen(include) ); 


	// File paths
	char *info_path = "/.proman/info.toml";
	char *main_header_path = "/src/include/main.h";
	char *main_path = " ";
	if (type == 1) main_path = "/src/main.c";
	else main_path = "/src/main.cpp";
	
	char *make_path = "/Makefile";
	char *readme_path = "/README.md";
	char *file_path = (char *) malloc(3 + strlen(main_header_path)+ strlen(main_path) ); 

	// char *config_path = "~/proman/proman.cfg";

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
    	fprintf(readme, "# %s\n", name);
    	fclose(readme);

    	// info.toml
    	strcpy(file_path, current);
    	strcat(file_path, name);
    	strcat(file_path, info_path);
    	printf("+ Creating file %s\n", file_path);
    	info = fopen(file_path, "w");
    	fclose(info);

    	// main.c / main.cpp
    	strcpy(file_path, current);
    	strcat(file_path, name);
    	strcat(file_path, main_path);
    	printf("+ Creating file %s\n", file_path);
    	main = fopen(file_path, "w");
    	if (type == 1) fprintf(main, "#include <stdio.h>\n\nint main(void) {\n  printf('Hello world!');\n}\n");
    	else fprintf(main, "#include <iostream>\n\nint main(void) {\n  std::cout << 'Hello world!');\n}\n");
    	fclose(main);

    	// main.h
    	strcpy(file_path, current);
    	strcat(file_path, name);
    	strcat(file_path, main_header_path);
    	printf("+ Creating file %s\n", file_path);
    	mainh = fopen(file_path, "w");
    	fprintf(mainh, "#ifndef __HEADER_H__\n#define __HEADER_H__\n\n // Put some awesome stuff here \n\n #endif\n");
    	fclose(mainh);

    	// Makefile
    	strcpy(file_path, current);
    	strcat(file_path, name);
    	strcat(file_path, make_path);
    	printf("+ Creating file %s\n", file_path);
    	makefile = fopen(file_path, "w");
    	fclose(makefile);

    	// Config
    	//printf("+ Adding '%s' to config file\n", name);
    	//config = fopen(config_path, "a");
    	//fputs("Hello", config);
    	//fclose(config);

    	free(dir);
    	free(file_path);
	} else {
		printf("Error: Directory '%s' already exists\n", name);
		return 0;
	}
	return 1;

}