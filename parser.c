#include "shell.h"

/**
 * is_executable - détermine si un fichier est une commande exécutable
 * @info: la structure d'informations
 * @path: chemin vers le fichier
 *
 * Retourne : 1 si vrai, 0 sinon
 */
int is_executable(info_t *info, char *path)
{
    struct stat st;

    (void)info;
    if (!path || stat(path, &st))
        return (0);

    if (st.st_mode & S_IFREG)
    {
        return (1);
    }
    return (0);
}

/**
 * duplicate_chars - duplique les caractères
 * @pathstr: la chaîne PATH
 * @start: index de départ
 * @stop: index de fin
 *
 * Retourne : pointeur vers le nouveau tampon
 */
char *duplicate_chars(char *pathstr, int start, int stop)
{
    static char buf[1024];
    int i = 0, k = 0;

    for (k = 0, i = start; i < stop; i++)
        if (pathstr[i] != ':')
            buf[k++] = pathstr[i];
    buf[k] = 0;
    return (buf);
}

/**
 * find_in_path - cherche la commande dans la chaîne PATH
 * @info: la structure d'informations
 * @pathstr: la chaîne PATH
 * @cmd: la commande à trouver
 *
 * Retourne : le chemin complet de la commande s'il est trouvé, sinon NULL
 */
char *find_in_path(info_t *info, char *pathstr, char *cmd)
{
    int i = 0, curr_pos = 0;
    char *path;

    if (!pathstr)
        return (NULL);
    if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
    {
        if (is_executable(info, cmd))
            return (cmd);
    }
    while (1)
    {
        if (!pathstr[i] || pathstr[i] == ':')
        {
            path = duplicate_chars(pathstr, curr_pos, i);
            if (!*path)
                _strcat(path, cmd);
            else
            {
                _strcat(path, "/");
                _strcat(path, cmd);
            }
            if (is_executable(info, path))
                return (path);
            if (!pathstr[i])
                break;
            curr_pos = i;
        }
        i++;
    }
    return (NULL);
}
