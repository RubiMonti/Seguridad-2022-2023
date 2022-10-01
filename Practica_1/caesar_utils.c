#include "caesar_utils.h"

void parse_text(char *stream){
    for (int i = 0; i<strlen(stream);i++){
        if (stream[i] >= 97 && stream[i] <= 122)
            stream[i] -= 32;
        else if(!(stream[i] >= 65 && stream[i] <= 90))
            stream[i] = 32;
    }
}

void caesar(char *stream, int key){
    for (int i = 0; i<strlen(stream);i++){
        if (stream[i] != 32){
            stream[i] += key;
            if (stream[i] > 90)
                stream[i] -= 25;
        }
    }
}

void breakcaesar(char *stream, int key){
    for (int i = 0; i<strlen(stream);i++){
        if (stream[i] != 32){
            stream[i] -= key;
            if (stream[i] < 65)
                stream[i] += 25;
        }
    }
}