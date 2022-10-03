#include "caesar_utils.h"

// Función que sirve para convertir todos los caracteres a mayúscualas o a espacios
void parse_text(char *stream){
    for (int i = 0; i<strlen(stream);i++){
        if (stream[i] >= 97 && stream[i] <= 122)
            stream[i] -= 32;
        else if(!(stream[i] >= 65 && stream[i] <= 90))
            stream[i] = 32;
    }
}

// Funcion que inicializa el diccionario que usaremos para calcular las probabilidades
void init_dict(dict_t *dict){
    for (int i = 0; i < 26; i++){
        dict->letters[i] = 0;
    } 
    dict->total = 0;
}

// Función de depuración que imprime la frecuencia de cada letra
void print_frecuencies(dict_t dict){
    for (int i = 0; i < 26; i++){
        printf("Parea el caracter %c\n\tLa frecuencia es: %d\n\tEl total es: %d\n\tEl porcentaje es: %f\n", i + 65, dict.letters[i], dict.total, (float)dict.letters[i]/dict.total);
    }
}

// Función que compara las frecuencias con las que tiene el idioma inglés
float compare_frequencies(dict_t dict){
    float frequencies[26] = {0.08167, 0.01492, 0.02782, 0.04253, 0.12702,
                                    0.02228, 0.02015, 0.06094, 0.06966, 0.00153,
                                    0.00772, 0.04025, 0.02406, 0.06749, 0.07507,
                                    0.01929, 0.00095, 0.05987, 0.06327, 0.09056,
                                    0.02758, 0.00978, 0.02360, 0.00150, 0.01974,
                                    0.00074};
    float error_sum = 0.0;
    for (int i = 0; i < 26; i++){
        error_sum += ((float)dict.letters[i]/dict.total - frequencies[i]) * ((float)dict.letters[i]/dict.total - frequencies[i]);
        // printf("El error en esta iteración es: %f\n", ((float)dict.letters[i]/dict.total - frequencies[i]) * ((float)dict.letters[i]/dict.total - frequencies[i]));
    }
    // printf("El error al final es es: %f\n", error_sum);
    return error_sum;
}

// Función que cifra el mensaje con el algoritmo caesar y con la clave key
void caesar(char *stream, int key){
    for (int i = 0; i<strlen(stream);i++){
        if (stream[i] != 32){
            stream[i] += key;
            if (stream[i] > 90)
                stream[i] -= 26;
        }
    }
}

// Función que intenta descifrar el algoritmo caesar con la clave introducida
void breakcaesar(char *stream, int key, dict_t *dict){
    for (int i = 0; i<strlen(stream);i++){
        if (stream[i] != 32){
            stream[i] -= key;
            if (stream[i] < 65)
                stream[i] += 26;
            dict->letters[stream[i]-65] = dict->letters[stream[i]-65] + 1;
            dict->total = dict->total + 1;
        }
    }
}