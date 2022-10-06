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
    float min_freq_err = 1.0;
    int min_freq_key = 0;
    char *min_freq_str = malloc(sizeof(char)*(bytes_read+1));
    float max_bi = 0;
    int max_bi_key = 0;
    char *max_bi_str = malloc(sizeof(char)*(bytes_read+1));
    int max_tri = 0;
    int max_tri_key = 0;
    char *max_tri_str = malloc(sizeof(char)*(bytes_read+1));
    char *temp = malloc(sizeof(char)*(bytes_read+1));
    for (int key = 1; key < 25; key++){
        // Para cada clave crearemos un string descifrado y se lo pasarmeos a la funcion que compara las frecuencias
        strcpy(temp, stream);
        init_dict(&dict);
        // Rompemos caesar con cada clave
        breakcaesar(temp, key, &dict);
        if (compare_frequencies(dict) < min_freq_err){
            min_freq_err = compare_frequencies(dict);
            min_freq_key = key;
            strcpy(min_freq_str, temp);
        }
        if (compare_bigrams(dict) > max_bi){
            max_bi = compare_bigrams(dict);
            max_bi_key = key;
            strcpy(max_bi_str, temp);
        }
        if (compare_trigrams(dict) > max_tri){
            max_tri = compare_trigrams(dict);
            max_tri_key = key;
            strcpy(max_tri_str, temp);
        }
    }
    free(temp);
    printf("%d:%s\n", min_freq_key, min_freq_str);
    free(min_freq_str);
    printf("%d:%s\n", max_bi_key, max_bi_str);
    free(max_bi_str);
    printf("%d:%s\n", max_tri_key, max_tri_str);
    free(max_tri_str);
    free(stream);
    return 0;
}