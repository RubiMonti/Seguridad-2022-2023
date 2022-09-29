#ifndef CAESAR_UTILS_H
# define CAESAR_UTILS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

//# include <sys/wait.h>

void parse_text(char *stream);
int caesar_text(char *stream, int key, int mode);

#endif  // CAESAR_UTILS_H