/* Purpose: File I/O, makefile, and command line arguments:
 * Author: Mohammad Shahriar Hossain
 * Date: 4 December, Fall 2022
 * Persons discussed w/: Sheikh Safwan Hossain (talked about how csv files can be stored in a struct and how to compile both processing and sorting from one main function (basically how conditional compilation works)) and our instructor Guohui Lin (Helped me to solve double free compilation error)
 * References: https://www.youtube.com/watch?v=BZFD-eEkhtw&ab_channel=KimmerCodes
 * https://www.youtube.com/watch?v=aP1ijjeZc24
 * https://www.youtube.com/watch?v=8RucxSeAemw&ab_channel=PortfolioCourses
 * https://stackoverflow.com/questions/23189630/how-to-use-qsort-for-an-array-of-strings
 */

#include "lab13.h"

int main(int argc, char **argv)
{   
    #ifdef P1
    struct game *games = file_read(argv[1]);
    filecreate(games);

    int k = 0;
    struct publisher *publishers = get_publishers(games, &k);
    sort(publishers, k);
    int l = 0;
    struct repgame *repgames = get_repgames(games, &l);
    repgamesort(repgames, l);
    repgamesort2(repgames, l);
    print_output(publishers, repgames, games, &k, &l);

    for (int i = 0; i < MAX_LEN; i++)
    {
        free(games[i].name);
        free(games[i].platform);
        free(games[i].genre);
        free(games[i].publisher);
    }
    free(games);
    for (int i = 0; i < k; i++)
    {
        free(publishers[i].name);
    }
    free(publishers);
    for (int i = 0; i < l; i++)
    {
        free(repgames[i].name);
    }
    free(repgames);
    #endif
    #ifdef P2
    struct game *games = file_read(argv[1]);
    char category[13], filename[27];
    printf("Sort games by: ");
    fgets(category, 13, stdin);
    if (category[strlen(category) - 1] == '\n')
    {
        category[strlen(category) - 1] = '\0';
    }
    if (strcmp(category, "year") == 0)
    {
        sprintf(filename, "gamesales_%s.csv", category);
        qsort(games, MAX_LEN, sizeof(struct game), comparename);
        qsort(games, MAX_LEN, sizeof(struct game), compareyear);
        print_qsort(games, filename);
    }
    if (strcmp(category, "name") == 0)
    {
        sprintf(filename, "gamesales_%s.csv", category);
        qsort(games, MAX_LEN, sizeof(struct game), comparename);
        print_qsort(games, filename);
    }
    if (strcmp(category, "platform") == 0)
    {
        sprintf(filename, "gamesales_%s.csv", category);
        qsort(games, MAX_LEN, sizeof(struct game), compareplatform);
        print_qsort(games, filename);
    }
    if (strcmp(category, "genre") == 0)
    {
        sprintf(filename, "gamesales_%s.csv", category);
        qsort(games, MAX_LEN, sizeof(struct game), comparegenre);
        print_qsort(games, filename);
    }
    if (strcmp(category, "publisher") == 0)
    {
        sprintf(filename, "gamesales_%s.csv", category);
        qsort(games, MAX_LEN, sizeof(struct game), comparepublisher);
        print_qsort(games, filename);
    }
    if (strcmp(category, "NA_sales") == 0)
    {
        sprintf(filename, "gamesales_%s.csv", category);
        qsort(games, MAX_LEN, sizeof(struct game), comparename);
        qsort(games, MAX_LEN, sizeof(struct game), comparenasales);
        print_qsort(games, filename);
    }
    if (strcmp(category, "EU_sales") == 0)
    {
        sprintf(filename, "gamesales_%s.csv", category);
        qsort(games, MAX_LEN, sizeof(struct game), comparename);
        qsort(games, MAX_LEN, sizeof(struct game), compareeusales);
        print_qsort(games, filename);
    }
    if (strcmp(category, "JP_sales") == 0)
    {
        sprintf(filename, "gamesales_%s.csv", category);
        qsort(games, MAX_LEN, sizeof(struct game), comparename);
        qsort(games, MAX_LEN, sizeof(struct game), comparejpsales);
        print_qsort(games, filename);
    }
    if (strcmp(category, "other_sales") == 0)
    {
        sprintf(filename, "gamesales_%s.csv", category);
        qsort(games, MAX_LEN, sizeof(struct game), comparename);
        qsort(games, MAX_LEN, sizeof(struct game), compareother);
        print_qsort(games, filename);
    }
    if (strcmp(category, "global_sales") == 0)
    {
        sprintf(filename, "gamesales_%s.csv", category);
        qsort(games, MAX_LEN, sizeof(struct game), comparename);
        qsort(games, MAX_LEN, sizeof(struct game), compareglobal);
        print_qsort(games, filename);
    }
    for (int i = 0; i < MAX_LEN; i++)
    {
        free(games[i].name);
        free(games[i].platform);
        free(games[i].genre);
        free(games[i].publisher);
    }
    free(games);
    #endif
    return 0;
}