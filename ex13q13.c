#include "lab13.h"

void sort(struct publisher *publishers, int k)
{
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < (k - 1); j++)
        {
            if (strcmp(publishers[j].name, publishers[j + 1].name) > 0)
            {
                char *temp;
                int temp2;
                temp = publishers[j].name;
                publishers[j].name= publishers[j + 1].name;
                publishers[j + 1].name = temp;
                temp2 = publishers[j].count;
                publishers[j].count = publishers[j + 1].count;
                publishers[j + 1].count = temp2;
            }
        }
    }
}
void repgamesort(struct repgame *repgames, int l)
{
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < (l - 1); j++)
        {
            if (strcmp(repgames[j].name, repgames[j + 1].name) > 0)
            {
                char *temp;
                int temp2;
                temp = repgames[j].name;
                repgames[j].name = repgames[j + 1].name;
                repgames[j + 1].name = temp;
                temp2 = repgames[j].count;
                repgames[j].count = repgames[j + 1].count;
                repgames[j + 1].count = temp2;
            } 
        }
    }
}
void repgamesort2(struct repgame *repgames, int l)
{
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < (l - 1); j++)
        {
            if (repgames[j].count < repgames[j + 1].count)
            {
                char *temp;
                int temp2;
                temp = repgames[j].name;
                repgames[j].name = repgames[j + 1].name;
                repgames[j + 1].name = temp;
                temp2 = repgames[j].count;
                repgames[j].count = repgames[j + 1].count;
                repgames[j + 1].count = temp2;
            }
        }
    }
}