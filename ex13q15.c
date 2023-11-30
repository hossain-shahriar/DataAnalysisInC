#include "lab13.h"

void print_output(struct publisher *publishers, struct repgame *repgames, struct game *games, int *k, int *l){
    printf("############ Common publishers: ############\n");
    for (int i = 0; i < *k; i++)
    {
        printf("%s: %d games\n", publishers[i].name, publishers[i].count);
    }
    printf("\n############ Repeated games: ############\n");
    for (int i = 0; i < *l; i++)
    {
        printf("%s: %d times \n", repgames[i].name, repgames[i].count);
    }
    printf("\n############ Sales Percentages ############\n");
    for (int i = 0; i < MAX_LEN; i++)
    {
        printf("%s - NA: %0.1f%%, EU: %0.1f%%, JP: %0.1f%%, other: %0.1f%%\n", games[i].name, ((games[i].NA_sales / games[i].global_sales) * MAX_LEN), ((games[i].EU_sales / games[i].global_sales) * MAX_LEN), ((games[i].JP_sales / games[i].global_sales) * MAX_LEN), ((games[i].other_sales / games[i].global_sales) * MAX_LEN));
    }
    printf("\n############ Summary Statistics ############\n");
    float sum = 0;
    for (int i = 0; i < MAX_LEN; i++)
    {
        sum += games[i].global_sales;
    }
    printf("Mean global sales: %0.2f million\nMedian global sales: %0.2f million\nRange of global sales: %0.2f million\n", (sum / MAX_LEN), ((games[(MAX_LEN - 1) / 2].global_sales + games[((MAX_LEN - 1) / 2) + 1].global_sales) / 2), (games[0].global_sales - games[MAX_LEN - 1].global_sales));
    return ;
}

