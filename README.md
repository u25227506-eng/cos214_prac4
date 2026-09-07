# TaskForge

-Leanne van der Horst
-Matshidiso Dibakoane: u25227506
-Simon Vogel: u25087984

A hierarchical work-processing system for the film production domain, implemented in C++11.
Models nested production phases (Pre-Production, Production, Post-Production) as a
Composite structure, with tasks that move through a lifecycle (State pattern), can be
traversed independently and in multiple ways (Iterator pattern), and can gain optional
runtime responsibilities (Decorator pattern).

## Requirements

Everything needed to build, run, debug and check this project is provided inside the
supplied Docker image — you do not need g++, make, gdb, or valgrind installed on your
host machine. You only need Docker itself.

## 1. Build the Docker image

Run this once, from the project root (where the `Dockerfile` lives):

```bash
docker build -t taskforge-image .
```

This installs g++, make, gdb and valgrind inside the image, copies the project in,
and runs `make` to produce the `taskforge` executable.

## 2. Run the program

```bash
docker run --rm -it taskforge-image
```

## 3. Debug with GDB

GDB needs two extra flags to attach to a process inside a container (Docker blocks
`ptrace` by default for security):

```bash
docker run --rm -it --cap-add=SYS_PTRACE --security-opt seccomp=unconfined taskforge-image gdb ./taskforge
```

Common commands once inside GDB:

```gdb
break main.cpp:40      # set a breakpoint at a given line
run                     # start the program
next                    # step over a line
step                    # step into a function call
print someVariable      # inspect a variable's value
backtrace               # show the call stack
continue                # resume execution
quit                    # exit gdb
```

## 4. Check for memory errors with Valgrind

```bash
docker run --rm -it taskforge-image valgrind --leak-check=full --show-leak-kinds=all ./taskforge
```

Look for `All heap blocks were freed -- no leaks are possible` or `0 bytes in 0 blocks
definitely lost` in the summary at the end of the output.

## 5. (Optional) Work interactively inside the container

Rather than typing separate `docker run` commands for each tool, you can open a single
shell inside the container and run `make`, `./taskforge`, `gdb ./taskforge`, and
`valgrind ...` all from there:

```bash
docker run --rm -it --cap-add=SYS_PTRACE --security-opt seccomp=unconfined taskforge-image bash
```

## Rebuilding after code changes

If you edit source files on your host and want to rebuild, either:

- rebuild the image (`docker build -t taskforge-image .` again), or
- mount the project directory as a volume and run `make` inside the container, e.g.:

```bash
docker run --rm -it -v "$(pwd)":/taskforge --cap-add=SYS_PTRACE --security-opt seccomp=unconfined taskforge-image bash
make clean && make
```

## Building locally without Docker

If you do have g++/make installed locally:

```bash
make        # builds ./taskforge
make run    # builds (if needed) and runs it
make clean  # removes build artifacts
```

## Project structure