#include <stdio.h>
#include "SolTest.h"

static bool test_code(struct keeper_v* test_c);

/*!
    The function tests solve_qe(..) by setting it the values of variables
    from the Test_one file and checking the answers with the values from
    the Test_one file using the test_code(...) function. In case of a correct
    answer, it prints "OK", in case of an incorrect one, it reports an error.
    */

void sol_test(){

    FILE *Test_one;
    Test_one = fopen("C:\\Users\\Veronika\\Desktop\\Test_one.csv", "r");

    const int len_struct_test = 5;
    struct keeper_v test [len_struct_test];
    int i = 0;

    while ((fscanf( Test_one, "%lf%lf%lf%d%lf%lf%s",
                    &(test[i].a), &(test[i].b), &(test[i].c),
                    &(test[i].n),
                    &(test[i].x1), &(test[i].x2), test[i].name) != EOF)
            && (i < len_struct_test)){

        printf("%s\n", test[i].name);

        if (test_code(&test[i])){
            printf("OK\n");
        } else {
            printf("ERROR in test\n");
        }

        i++;
    }
}

/*!
    The function runs solve_qe(...) and checks the received values with
    the correct answers, returning true or false
    */

static bool test_code(struct keeper_v* test_c){

    struct coeff_s coeff_t;
    struct roots_s roots_t;

    coeff_t.a = test_c->a;
    coeff_t.b = test_c->b;
    coeff_t.c = test_c->c;

    solve_qe(&coeff_t, &roots_t);

    return ((roots_t.n == test_c->n)
         && (check_equality(test_c->x1, roots_t.x1))
         && (check_equality(test_c->x2, roots_t.x2)));
}
