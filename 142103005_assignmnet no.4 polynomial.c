#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Polynomial
{
    int coeff;
    int exp;
    struct Polynomial *next;
} Polynomial;

int size(char p1[])
{
    int node = 1;

    for (int l = 0; l < strlen(p1); l++)
    {
        if (p1[l] == '+')
        {
            node++;
        }
    }
    return node;
}

void display(Polynomial *p, char var)
{

    char poly[50] = "";

    while (p != NULL)
    {
        char tmp[10];
        sprintf(tmp, "%d", p->coeff);
        strcat(poly, tmp);
        strcat(poly, "x^");
        char exp_tmp[10];
        sprintf(exp_tmp, "%d", p->exp);
        strcat(poly, exp_tmp);

        if (p->next != NULL)
        {
            strcat(poly, " + ");
        }
        p = p->next;
    }
    printf("%s\n", poly);
}

void initPolynomial(Polynomial *poly, char *s, int num)
{
    int n = size(s);
    int i = 0;
    char *array[n];
    char *token = strtok(s, "+");
    Polynomial *p;
    p = poly;

    while (token != NULL)
    {

        array[i] = token;
        token = strtok(NULL, "+");
        i++;
    }

    for (int i = 0; i < n; i++)
    {
        if (i != 0)
        {
            p->next = (Polynomial *)malloc(sizeof(Polynomial));
            p = p->next;
        }
        char *coef_exp = strtok(array[i], "x^");

        char *coef_arr[2];
        int j = 0;

        while (coef_exp != NULL)
        {
            coef_arr[j] = coef_exp;
            j++;
            coef_exp = strtok(NULL, "x^");
        }
        p->coeff = atoi(coef_arr[0]);
        p->exp = atoi(coef_arr[1]);
        p->next = NULL;
    }
}

Polynomial *addPolynomial(Polynomial *p1, Polynomial *p2)
{
    Polynomial *poly_sum = (Polynomial *)malloc(sizeof(Polynomial));
    Polynomial *t;
    Polynomial *p = p1;
    Polynomial *q = p2;

    poly_sum = (Polynomial *)malloc(sizeof(Polynomial));
    if (p->exp == q->exp)
    {
        poly_sum->coeff = p->coeff + q->coeff;
        poly_sum->exp = p->exp;
        p = p->next;
        q = q->next;
    }
    else if (p->exp < q->exp)
    {
        poly_sum->coeff = q->coeff;
        poly_sum->exp = q->exp;
        q = q->next;
    }
    else
    {
        poly_sum->coeff = p->coeff;
        poly_sum->exp = p->exp;
        p = p->next;
    }

    poly_sum->next = NULL;
    t = poly_sum;
    Polynomial *tmp = NULL;
    while (p && q)
    {
        tmp = (Polynomial *)malloc(sizeof(Polynomial));

        if (p->exp == q->exp)
        {
            tmp->coeff = p->coeff + q->coeff;
            tmp->exp = p->exp;
            p = p->next;
            q = q->next;
        }
        else if (p->exp < q->exp)
        {
            tmp->coeff = q->coeff;
            tmp->exp = q->exp;
            q = q->next;
        }
        else
        {
            tmp->coeff = p->coeff;
            tmp->exp = p->exp;
            p = p->next;
        }
        tmp->next = NULL;
        t->next = tmp;
        t = t->next;
    }
    if (p == NULL)
    {
        while (q)
        {
            t->next = (Polynomial *)malloc(sizeof(Polynomial));
            t = t->next;
            t->coeff = q->coeff;
            t->exp = q->exp;
            q = q->next;
            t->next = NULL;
        }
    }
    else if (q == NULL)
    {
        while (p)
        {
            t->next = (Polynomial *)malloc(sizeof(Polynomial));
            t = t->next;
            t->coeff = p->coeff;
            t->exp = p->exp;
            p = p->next;
            t->next = NULL;
        }
    }

    return poly_sum;
}

int main()
{
    char p1[50];
    printf("Enter first polynomial : ");
    gets(p1);

    char p2[50];
    printf("Enter second polynomial : ");
    gets(p2);

    Polynomial *poly1 = (Polynomial *)malloc(sizeof(Polynomial));
    Polynomial *poly2 = (Polynomial *)malloc(sizeof(Polynomial));

    initPolynomial(poly1, p1, strlen(p1));
    initPolynomial(poly2, p2, strlen(p2));

    printf("First Polynomial is: ");
    display(poly1, 's');
    printf("Second Polynomial is: ");
    display(poly2, 't');

    Polynomial *poly_sum = addPolynomial(poly1, poly2);

    printf("Addition of Polynomials : ");
    display(poly_sum, 'x');

    return 0;
}
