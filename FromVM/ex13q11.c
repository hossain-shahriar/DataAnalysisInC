#include "lab13.h"

struct publisher *get_publishers(struct game *games, int *k){
struct publisher *publishers = calloc(MAX_LEN, sizeof(struct publisher));
    for (int i = 0; i < MAX_LEN; i++)
    {
        int flag = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (strcmp(games[j].publisher, games[i].publisher) == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            publishers[*k].name = malloc(strlen(games[i].publisher) + 1);
            strcpy(publishers[*k].name, games[i].publisher);
            *k += 1;
        }
    }
    publishers = realloc(publishers, (sizeof(struct publisher) * *k));

    for (int i = 0; i < *k; i++)
    {
        for (int j = 0; j < MAX_LEN; j++)
        {
            if (strcmp(publishers[i].name, games[j].publisher) == 0)
            {
                publishers[i].count += 1;
            }
        }
    }
    return publishers;
}