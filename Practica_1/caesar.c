#include "caesar_utils.h"

int main(int argc, char* argv[]){
    // Comprobamos que unicamente reciba el argumento de la llave
    if (argc != 2)
        printf("Error in retrieving the key\n");
    int key = atoi(argv[1])%25;
    printf("Key is: %d\n", key);
    // Leemos el mensaje de la entrada estandar
    char *stream = malloc(sizeof(char)*100);
    read(0,stream, 100);
    // Le ponemos todos los caracteres a mayúsculas y cambiamos los caracteres especiales por espacios
    parse_text(stream);
    // Lo ciframos con caesar
    caesar(stream, key);
    // Lo imprimimos en el fichero texto_cifrado.txt
    int fd = open("./texto_cifrado.txt", O_WRONLY|O_CREAT|O_TRUNC, 00777);
    dprintf(fd, "%s\n", stream);
    free(stream);
    return 0;
}