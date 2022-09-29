#include "caesar_utils.h"

int main(int argc, char* argv[]){
    printf("El número de argumentos es: %d\n",argc);
    char *stream = malloc(sizeof(char)*100);
    read(0,stream, 100);
    printf("El texto plano de entrada es: %s\n",stream);
}