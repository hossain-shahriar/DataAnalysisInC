#include "lab13.h"

void filecreate(struct game *games){
    FILE *fp2 = fopen("processing.csv", "w");
    if (fp2 == NULL)
    {
        printf("Unable to read file\n");
        exit(0);
    }
    fprintf(fp2, "Rank,Name,Platform,Year,Genre,Publisher,NA_Sales,EU_Sales,JP_Sales,Other_Sales,Global_Sales\n");
    for (int i = 0; i < MAX_LEN; i++)
    {
        fprintf(fp2, "%d,%s,%s,%d,%s,%s,%f,%f,%f,%f,%f\n", games[i].rank, games[i].name, games[i].platform, games[i].year, games[i].genre, games[i].publisher, games[i].NA_sales, games[i].EU_sales, games[i].JP_sales, games[i].other_sales, games[i].global_sales);
    }
    fclose(fp2);
}