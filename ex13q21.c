#include "lab13.h"

void print_qsort(struct game *games, char filename[])
{
    FILE *fp3 = fopen(filename, "w");
    if (fp3 == NULL)
    {
        printf("Unable to read file\n");
        exit(0);
    }
    fprintf(fp3, "Rank,Name,Platform,Year,Genre,Publisher,NA_Sales,EU_Sales,JP_Sales,Other_Sales,Global_Sales\n");
    for (int i = 0; i < MAX_LEN; i++)
    {
        games[i].rank = i + 1;
        fprintf(fp3, "%d,%s,%s,%d,%s,%s,%0.2f,%0.2f,%0.2f,%0.2f,%0.2f\n", games[i].rank, games[i].name, games[i].platform, games[i].year, games[i].genre, games[i].publisher, games[i].NA_sales, games[i].EU_sales, games[i].JP_sales, games[i].other_sales, games[i].global_sales);
    }
    fclose(fp3);
}