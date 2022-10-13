#include "caesar_utils.h"

// Enumeracion que servira para indexar el vector de bigramas
enum BIGRAMS{
    bi_th = 0,
    bi_he,
    bi_in,
    bi_en,
    bi_nt,
    bi_re,
    bi_er,
    bi_an,
    bi_ti,
    bi_es,
    bi_on,
    bi_at,
    bi_se,
    bi_nd,
    bi_or,
    bi_ar,
    bi_al,
    bi_te,
    bi_co,
    bi_de,
    bi_to,
    bi_ra,
    bi_et,
    bi_ed,
    bi_it,
    bi_sa,
    bi_em,
    bi_ro,
} all_bigrams;

// Enumeracion que servira para indexar el vector de trigramas
enum TRIGRAMS{
    tri_the = 0,
    tri_and,
    tri_tha,
    tri_ent,
    tri_ing,
    tri_ion,
    tri_tio,
    tri_for,
    tri_nde,
    tri_has,
    tri_nce,
    tri_edt,
    tri_tis,
    tri_oft,
    tri_sth,
    tri_men,
} all_trigrams;

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
    for (int i = 0; i < 28; i++){
        dict->bigrams[i] = 0;
    }
    for (int i = 0; i < 16; i++){
        dict->trigrams[i] = 0;
    }
    dict->total = 0;
}

// Con esta funcion comprobamos si existe un bigrama en dos letras que se introducen como parametros
int find_bigram(char first, char second){
    if (first == 'T' && second == 'H')
        return bi_th;
    else if (first == 'H' && second == 'E')
        return bi_he;
    else if (first == 'I' && second == 'N')
        return bi_in;
    else if (first == 'E' && second == 'N')
        return bi_en;
    else if (first == 'N' && second == 'T')
        return bi_nt;
    else if (first == 'R' && second == 'E')
        return bi_re;
    else if (first == 'E' && second == 'R')
        return bi_er;
    else if (first == 'A' && second == 'N')
        return bi_an;
    else if (first == 'T' && second == 'I')
        return bi_ti;
    else if (first == 'E' && second == 'S')
        return bi_es;
    else if (first == 'O' && second == 'N')
        return bi_on;
    else if (first == 'A' && second == 'T')
        return bi_at;
    else if (first == 'S' && second == 'E')
        return bi_se;
    else if (first == 'N' && second == 'D')
        return bi_nd;
    else if (first == 'O' && second == 'R')
        return bi_or;
    else if (first == 'A' && second == 'R')
        return bi_ar;
    else if (first == 'A' && second == 'L')
        return bi_al;
    else if (first == 'T' && second == 'E')
        return bi_te;
    else if (first == 'C' && second == 'O')
        return bi_co;
    else if (first == 'D' && second == 'E')
        return bi_de;
    else if (first == 'T' && second == 'O')
        return bi_to;
    else if (first == 'R' && second == 'A')
        return bi_ra;
    else if (first == 'E' && second == 'T')
        return bi_et;
    else if (first == 'E' && second == 'D')
        return bi_ed;
    else if (first == 'I' && second == 'T')
        return bi_it;
    else if (first == 'S' && second == 'A')
        return bi_sa;
    else if (first == 'E' && second == 'M')
        return bi_em;
    else if (first == 'R' && second == 'O')
        return bi_ro;
    return -1;
}

// Con esta funcion comprobamos si existe un trigrama en las tres letras que se introducen como parametros
int find_trigram(char first, char second, char third){
    if (first == 'T' && second == 'H' && third == 'E')
        return tri_the;
    else if (first == 'A' && second == 'N' && third == 'D')
        return tri_and;
    else if (first == 'T' && second == 'H' && third == 'A')
        return tri_tha;
    else if (first == 'E' && second == 'N' && third == 'T')
        return tri_ent;
    else if (first == 'I' && second == 'N' && third == 'G')
        return tri_ing;
    else if (first == 'I' && second == 'O' && third == 'N')
        return tri_ion;
    else if (first == 'T' && second == 'I' && third == 'O')
        return tri_tio;
    else if (first == 'F' && second == 'O' && third == 'R')
        return tri_for;
    else if (first == 'N' && second == 'D' && third == 'E')
        return tri_nde;
    else if (first == 'H' && second == 'A' && third == 'S')
        return tri_has;
    else if (first == 'N' && second == 'C' && third == 'E')
        return tri_nce;
    else if (first == 'E' && second == 'D' && third == 'T')
        return tri_edt;
    else if (first == 'T' && second == 'I' && third == 'S')
        return tri_tis;
    else if (first == 'O' && second == 'F' && third == 'T')
        return tri_oft;
    else if (first == 'S' && second == 'T' && third == 'H')
        return tri_sth;
    else if (first == 'M' && second == 'E' && third == 'N')
        return tri_men;
    return -1;
}

// Función que compara las frecuencias con las que tiene el idioma inglés
float compare_frequencies(dict_t dict){
    // El vector que hay a continuacion esta sacado de la referencia adjunta al enunciado
    float frequencies[26] = {0.08167, 0.01492, 0.02782, 0.04253, 0.12702,
                                    0.02228, 0.02015, 0.06094, 0.06966, 0.00153,
                                    0.00772, 0.04025, 0.02406, 0.06749, 0.07507,
                                    0.01929, 0.00095, 0.05987, 0.06327, 0.09056,
                                    0.02758, 0.00978, 0.02360, 0.00150, 0.01974,
                                    0.00074};
    float error_sum = 0.0;
    for (int i = 0; i < 26; i++){
        error_sum += ((float)dict.letters[i]/dict.total - frequencies[i]) * ((float)dict.letters[i]/dict.total - frequencies[i]);
    }
    return error_sum;
}

// Comprobamos cuantos bigramas salen y los ponderamos segun su uso en el idoma ingles
float compare_bigrams(dict_t dict){
    float bigrams = 0.0;
    for (int i = 0; i < 28; i++){
        bigrams += dict.bigrams[i] * (28-i)/(float)406; // Esta es una proporcion: 28+27+...+1 = 406
    }
    return bigrams;
}

// Comprobamos cuantos trigramas salen y los ponderamos segun su uso en el idoma ingles
float compare_trigrams(dict_t dict){
    float trigrams = 0.0;
    for (int i = 0; i < 16; i++){
        trigrams += dict.trigrams[i] * (16-i)/(float)136; // Esta es una proporcion: 16+15+...+1 = 136
    }
    return trigrams;
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
    int index_bigram;
    int index_trigram;
    for (int i = 0; i<strlen(stream);i++){
        if (stream[i] != 32){
            stream[i] -= key;
            if (stream[i] < 65)
                stream[i] += 26;
            dict->letters[stream[i]-65] = dict->letters[stream[i]-65] + 1;
            dict->total = dict->total + 1;
            if (i-1 >= 0){
                index_bigram = find_bigram(stream[i-1], stream[i]);
                if (index_bigram != -1)
                    dict->bigrams[index_bigram] = dict->bigrams[index_bigram] + 1;
            }
            if (i-2 >= 0){
                index_trigram = find_trigram(stream[i-2], stream[i-1], stream[i]);
                if (index_trigram != -1)
                    dict->trigrams[index_trigram] = dict->trigrams[index_trigram] + 1;
            }
        }
    }
}
