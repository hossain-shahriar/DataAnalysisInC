#include "lab13.h"

struct game *file_read(char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Unable to read file\n");
        exit(0);
    }
    struct game *games = malloc(sizeof(struct game) * MAX_LEN);
    char buff[200];
    char *sp;
    int counter = 0;
    int counter2 = 0;
    while (fgets(buff, 200, fp) != NULL)
    {
        int i = 0;
        while (buff[i] != '\n')
        {
            if (buff[i] == ',' && buff[i + 1] == ',')
            {
                int c = 0, d = i;
                while (buff[d] != '\n')
                {
                    c += 1;
                    d += 1;
                }
                for (int j = c; j > 0; j--)
                {
                    buff[i + j + 1] = buff[i + j];
                }
                buff[i + 1] = ' ';
            }
            i += 1;
        }

        if (counter2 == 0)
        {
            counter2 = 1;
            continue;
        }
        sp = strtok(buff, ",");
        games[counter].rank = atoi(sp);
        sp = strtok(NULL, ",");
        games[counter].name = malloc(strlen(sp) + 1);
        strcpy(games[counter].name, sp);
        sp = strtok(NULL, ",");
        games[counter].platform = malloc(strlen(sp) + 1);
        strcpy(games[counter].platform, sp);
        sp = strtok(NULL, ",");
        games[counter].year = atoi(sp);
        sp = strtok(NULL, ",");
        games[counter].genre = malloc(strlen(sp) + 1);
        strcpy(games[counter].genre, sp);
        sp = strtok(NULL, ",");
        games[counter].publisher = malloc(strlen(sp) + 1);
        strcpy(games[counter].publisher, sp);
        sp = strtok(NULL, ",");
        if (*sp == ' ')
        {
            games[counter].NA_sales = -1;
        }
        else
        {
            games[counter].NA_sales = atof(sp);
        }
        sp = strtok(NULL, ",");
        if (*sp == ' ')
        {
            games[counter].EU_sales = -1;
        }
        else
        {
            games[counter].EU_sales = atof(sp);
        }
        sp = strtok(NULL, ",");
        if (*sp == ' ')
        {
            games[counter].JP_sales = -1;
        }
        else
        {
            games[counter].JP_sales = atof(sp);
        }
        sp = strtok(NULL, ",");
        if (*sp == ' ')
        {
            games[counter].other_sales = -1;
        }
        else
        {
            games[counter].other_sales = atof(sp);
        }
        sp = strtok(NULL, ",");
        if (*sp == ' ')
        {
            games[counter].global_sales = -1;
        }
        else
        {
            games[counter].global_sales = atof(sp);
        }
        counter += 1;
    }
    for (int i = 0; i < MAX_LEN; i++)
    {
        if (games[i].NA_sales == -1)
        {
            games[i].NA_sales = games[i].global_sales - games[i].EU_sales - games[i].JP_sales - games[i].other_sales;
        }
        else if (games[i].EU_sales == -1)
        {
            games[i].EU_sales = games[i].global_sales - games[i].NA_sales - games[i].JP_sales - games[i].other_sales;
        }
        else if (games[i].JP_sales == -1)
        {
            games[i].JP_sales = games[i].global_sales - games[i].NA_sales - games[i].EU_sales - games[i].other_sales;
        }
        else if (games[i].other_sales == -1)
        {
            games[i].other_sales = games[i].global_sales - games[i].NA_sales - games[i].EU_sales - games[i].JP_sales;
        }
    }

    fclose(fp);
    return games;
}