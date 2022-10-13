#ifndef CAESAR_UTILS_H
# define CAESAR_UTILS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>

//# include <sys/wait.h>

typedef struct s_dict{
    int letters[26];
    int bigrams[28];
    int trigrams[16];
    int total;
}   dict_t;

void parse_text(char *stream);
void init_dict(dict_t *dict);
float compare_frequencies(dict_t dict);
float compare_bigrams(dict_t dict);
float compare_trigrams(dict_t dict);
void caesar(char *stream, int key);
void breakcaesar(char *stream, int key, dict_t *dict);

#endif  // CAESAR_UTILS_H
