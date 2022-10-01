#include "caesar_utils.h"

int main(int argc, char* argv[]){
    // Leemos el mensaje de la entrada estandar
    char *stream = malloc(sizeof(char)*100);
    read(0,stream, 100);
    // Le ponemos todos los caracteres a mayúsculas y cambiamos los caracteres especiales por espacios
    parse_text(stream);
    // Rompemos caesar con todas las claves
    char *temp;
    for (int key = 1; key < 25; key++){
        temp = malloc(sizeof(char)*100);
        strcpy(temp, stream);
        breakcaesar(temp, key);
        printf("%d: %s\n", key, temp);
        free(temp);
    }
    int fd = open("./texto_descifrado.txt", O_WRONLY|O_CREAT|O_TRUNC, 00777);
    dprintf(fd, "%s\n", stream);
    free(stream);
    return 0;
}