/*
** EPITECH PROJECT, 2019
** my word to str
** File description:
** in[0] :number of words
** in[1] :length of str
** in[2] :length of word
** re[0] :mark to know if we begin a word
** re[1] :mark to know in wich word we are
*/
#include <stdlib.h>
#include "my.h"

char **my_str_to_word_array(char const *str)
{
    char **tab;
    char in[3] = {my_str_words(str), my_strlen(str), 0};
    int re[2] = {0};

    tab = malloc (sizeof(char *) * (in[0] + 1));
    for (int i = 0 ; i < in[1] ; i++){
        if (my_char_isalphanum(str[i]) && !re[0]) {
            in[2] = my_wordlen(str, i);
            tab[re[1]] = malloc(sizeof(char) * (in[2]+1));
            re[0] = 1;
            my_istrncat(tab[re[1]], str, in[2], i);
            re[1]++;
        }

        if (!my_char_isalphanum(str[i]) && re[0])
            re[0] = 0;
    }
    tab[re[1]] = 0;

    return (tab);
}
