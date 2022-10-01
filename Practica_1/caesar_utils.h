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

struct {
    int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,y,z;
}

void parse_text(char *stream);
int caesar_text(char *stream, int key, int mode);

#endif  // CAESAR_UTILS_H