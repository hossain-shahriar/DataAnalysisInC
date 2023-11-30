#include "lab13.h"

int comparename(const void *a, const void *b)
{
    struct game *orderA = (struct game *)a;
    struct game *orderB = (struct game *)b;
    return strcmp(orderA->name, orderB->name);
}
int compareplatform(const void *a, const void *b)
{

    struct game *orderA = (struct game *)a;
    struct game *orderB = (struct game *)b;

    return strcmp(orderA->platform, orderB->platform);
}
int compareyear(const void *a, const void *b)
{

    struct game *orderA = (struct game *)a;
    struct game *orderB = (struct game *)b;

    return (orderA->year - orderB->year);
}
int comparegenre(const void *a, const void *b)
{

    struct game *orderA = (struct game *)a;
    struct game *orderB = (struct game *)b;

    return strcmp(orderA->genre, orderB->genre);
}
int comparepublisher(const void *a, const void *b)
{

    struct game *orderA = (struct game *)a;
    struct game *orderB = (struct game *)b;

    return strcmp(orderA->publisher, orderB->publisher);
}
int comparenasales(const void *a, const void *b)
{

    struct game *orderA = (struct game *)a;
    struct game *orderB = (struct game *)b;

    return (orderA->NA_sales - orderB->NA_sales);
}
int compareeusales(const void *a, const void *b)
{

    struct game *orderA = (struct game *)a;
    struct game *orderB = (struct game *)b;

    return (orderA->EU_sales - orderB->EU_sales);
}
int comparejpsales(const void *a, const void *b)
{

    struct game *orderA = (struct game *)a;
    struct game *orderB = (struct game *)b;

    return (orderA->JP_sales - orderB->JP_sales);
}
int compareother(const void *a, const void *b)
{

    struct game *orderA = (struct game *)a;
    struct game *orderB = (struct game *)b;

    return (orderA->other_sales - orderB->other_sales);
}
int compareglobal(const void *a, const void *b)
{

    struct game *orderA = (struct game *)a;
    struct game *orderB = (struct game *)b;

    return (orderA->global_sales - orderB->global_sales);
}