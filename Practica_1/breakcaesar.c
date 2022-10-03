#include "caesar_utils.h"

int main(int argc, char* argv[]){
    // Leemos el mensaje de la entrada estandar
    char *temp_read = malloc(sizeof(char)*INT_MAX);
    int bytes_read = read(0,temp_read, INT_MAX);
    char *stream = malloc(sizeof(char)*(bytes_read+1));
    strcpy(stream, temp_read);
    free(temp_read);
    // Le ponemos todos los caracteres a mayúsculas y cambiamos los caracteres especiales por espacios
    parse_text(stream);
    // Inicializamos unas variables para el cálculo de frecuencias y probabilidades
    dict_t dict;
    float minimum_err = 1.0;
    float temp_err;
    int minimum_key = 0;
    char *minimum_str = malloc(sizeof(char)*(bytes_read+1));
    char *temp = malloc(sizeof(char)*(bytes_read+1));
    for (int key = 1; key < 25; key++){
        // Para cada clave crearemos un string descifrado y se lo pasarmeos a la funcion que compara las frecuencias
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
    }
    free(temp);
    printf("%d:%s\n", minimum_key, minimum_str);
    free(minimum_str);
    free(stream);
    return 0;
}