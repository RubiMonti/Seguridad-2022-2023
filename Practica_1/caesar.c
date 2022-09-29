#include "caesar_utils.h"

int main(int argc, char* argv[]){
    if (argc != 2)
        printf("Error in retrieving the key\n");
    int key = atoi(argv[1])%25;
    printf("Key is: %d\n", key);
    char *stream = malloc(sizeof(char)*100);
    read(0,stream, 100);
    parse_text(stream);
    if (caesar_text(stream, key, 0) == -1)
        return -1;
    int fd = open("./texto_cifrado.txt", O_WRONLY|O_CREAT|O_TRUNC, 00777);
    dprintf(fd, "%s\n", stream);
    return 0;
}