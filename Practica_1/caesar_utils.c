#include "caesar_utils.h"

void parse_text(char *stream){
    for (int i = 0; i<strlen(stream);i++){
        printf("El carácter a analizar es: %c", stream[i]);
        if (stream[i] >= 97 && stream[i] <= 122)
            stream[i] -= 32;
        else if(!(stream[i] >= 65 && stream[i] <= 90))
            stream[i] = 32;
        printf("\tEl carácter después de analizar es: %c\n", stream[i]);
    }
}

int caesar_text(char *stream, int key, int mode){
    int increment = 0;
    if (mode == 0)
        increment = key;
    else if (mode == 1)
        increment = -key;
    else{
        printf("Error in cryipting, please insert a valid mode");
        return -1;
    }
    for (int i = 0; i<strlen(stream);i++){
        printf("El carácter a cifrar es: %c", stream[i]);
        if (stream[i] != 32){
            stream[i] += increment;
            if (stream[i] > 90)
                stream[i] -= 25;
        }
        printf("\tEl carácter después de cifrar es: %c\n", stream[i]);
    }
    return 0;
}