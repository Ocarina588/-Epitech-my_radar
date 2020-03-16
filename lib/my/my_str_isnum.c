/*
** EPITECH PROJECT, 2019
** cc
** File description:
** cc
*/

int my_str_isnum(char const *str)
{
    int i = 0;

    if (str[i] == '\0')
        return (1);

    while (str[i] != '\0')
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);

        i++;
    }

    return (1);
}
