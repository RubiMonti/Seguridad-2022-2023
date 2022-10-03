#include "caesar_utils.h"

int main(int argc, char* argv[]){
    // Leemos el mensaje de la entrada estandar
    char *stream = malloc(sizeof(char)*100);
    read(0,stream, 100);
    // Le ponemos todos los caracteres a mayúsculas y cambiamos los caracteres especiales por espacios
    parse_text(stream);
    // Inicializamos unas variables para el cálculo de frecuencias y probabilidades
    dict_t dict;
    float minimum_err = 1.0;
    float temp_err;
    int minimum_key = 0;
    char *minimum_str = malloc(sizeof(char)*100);
    char *temp;
    for (int key = 1; key < 25; key++){
        // Para cada clave crearemos un string descifrado y se lo pasarmeos a la funcion que compara las frecuencias
        temp = malloc(sizeof(char)*100);
        strcpy(temp, stream);
        init_dict(&dict);
        // Rompemos caesar con cada clave
        breakcaesar(temp, key, &dict);
        temp_err = compare_frequencies(dict);
        if (temp_err < minimum_err){
            minimum_err = temp_err;
            minimum_key = key;
            strcpy(minimum_str, temp);
        }
        // printf("%d: %s\n", key, temp);
        free(temp);
    }
    // int fd = open("./texto_descifrado.txt", O_WRONLY|O_CREAT|O_TRUNC, 00777);
    printf("%d:%s\n", minimum_key, minimum_str);
    free(minimum_str);
    free(stream);
    return 0;
}