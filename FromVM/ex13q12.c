#include "lab13.h"

struct repgame *get_repgames(struct game *games, int *l)
{
    struct repgame *repgames = calloc(MAX_LEN, sizeof(struct repgame));
    for (int i = 0; i < MAX_LEN; i++)
    {
        int flag = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (strcmp(games[j].name, games[i].name) == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            repgames[*l].name = malloc(strlen(games[i].name) + 1);
            strcpy(repgames[*l].name, games[i].name);
            *l += 1;
        }
    }
    repgames = realloc(repgames, (sizeof(struct repgame) * *l));
    for (int i = 0; i < *l; i++)
    {
        for (int j = 0; j < MAX_LEN; j++)
        {
            if (strcmp(repgames[i].name, games[j].name) == 0)
            {
                repgames[i].count += 1;
            }
        }
    }
    return repgames;
}