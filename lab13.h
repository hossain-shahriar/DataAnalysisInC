#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 100
#ifdef PART1
    #define P1

    struct game {
        int rank;
        int year;
        char *name;
        char *platform;
        char *genre;
        char *publisher;

        // sales below represented in millions
        float NA_sales;
        float EU_sales;
        float JP_sales;
        float other_sales;
        float global_sales;
    };
    struct publisher {
        char *name;
        int count;
    };
    struct repgame {
        char *name;
        int count;
    };

    struct publisher *get_publishers(struct game *games, int *k);
    struct repgame *get_repgames(struct game *games, int *l);
    struct game *file_read(char *filename);
    void sort(struct publisher *publishers, int k);
    void repgamesort(struct repgame *repgames, int l);
    void repgamesort2(struct repgame *repgames, int l);
    void filecreate(struct game *games);
    void print_output(struct publisher *publishers, struct repgame *repgames, struct game *games, int *k, int *l);
#endif

#ifdef PART2
#define P2

struct game {
    int rank;
    int year;
    char *name;
    char *platform;
    char *genre;
    char *publisher;
    
    // sales below represented in millions
    float NA_sales;
    float EU_sales;
    float JP_sales;
    float other_sales;
    float global_sales;
};
struct game *file_read(char *filename);
int comparename(const void *a, const void *b);
int compareplatform(const void *a, const void *b);
int compareyear(const void *a, const void *b);
int comparegenre(const void *a, const void *b);
int comparepublisher(const void *a, const void *b);
int comparenasales(const void *a, const void *b);
int compareeusales(const void *a, const void *b);
int comparejpsales(const void *a, const void *b);
int compareother(const void *a, const void *b);
int compareglobal(const void *a, const void *b);
void print_qsort(struct game *games, char filename[]);
#endif