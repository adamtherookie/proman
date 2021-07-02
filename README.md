# ProMan
ProMan is a project manager for C/C++, written in C (ironic, right?).

# Installing
Installing is really easy, just:
```bash
# Clone this repo
git clone https://github.com/aa2006/proman
# Go into the repo
cd proman
# Build and install
make all
```
Now run `proman version`. It should output the version if everything went correctly.

# Structure:
Running `proman new [project_name]` will create a directory called `[project_name]` in the current working directory with the following structure after prompting you for some information about your project:
```
     [name]
      ├── .proman
      │    └── info.txt
      ├── src
      │    ├── include
      │    │    └── [main header]  
      │    └── [main file]
      ├── Makefile
      └── README.md
```
You will find a hello world program in the main file (either `main.c` or `main.cpp`), along with a functional Makefile (just run `make` to compile everything inside the `src` folder, along with an `include` directory for all your header files). The `README.md` file will be initialized with the name of your project, and some compliments to cheer you on ;). The `.proman` directory contains information about your project, which is also stored in `proman.cfg` in your computer's `HOME` directory.
