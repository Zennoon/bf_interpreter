#ifndef BF_H

#define BF_H

/** Header files **/
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

/** Function prototypes **/
char *read_file(char *filename);
void execute_commands(char *commands, int *array, int *idx);
char *looper(char *command_ptr, int *array, int *idx);

#endif
