#include <stdio.h>
#include <math.h>
#include "SolCal.h"





/*!
    next comes the connection of the my_assert(...) function through the
    preprocessor. To enable it, you need to define debugon via the command
    line when compiling the file SolCal.cpp
    */
#ifdef debugon
    #define my_assert(test_a) \
        if (!(test_a)) \
            printf("Assert failed in file %s in line %d\n", __FILE__, __LINE__)
#else
    #define my_assert(test_a) ;
#endif


static void solve_le(struct coeff_s* coeff, struct roots_s* roots);

/*!
    This function gets the values of the coefficients and the
    structure for the output of the calculated roots. Assigns
    values to variables in the roots structure in advance to
    avoid calculation errors (for example, when the root is one,
    the second may remain undefined). Then checks the values of
    the coefficients, and if the equation turns out to be linear,
    calls a function to solve the linear equation. Otherwise, it
    calculates the roots on its own.
    */

void solve_qe(struct coeff_s* coeff, struct roots_s* roots){

    roots->n = err_s;
    roots->x1 = 0;
    roots->x2 = 0;

    double a = coeff->a, b = coeff->b, c = coeff->c;

    /*!
        Condition for checking the linearity of the equation and solving quadratic equality
        */

    my_assert((-1.7e307 < a) && (a < 1.7e307));
    my_assert((-1.7e307 < b) && (b < 1.7e307));
    my_assert((-1.7e307 < c) && (c < 1.7e307));

    if (check_equality(a, 0.0)){
        solve_le(coeff, roots);
    } else {

        double D = b * b - 4 * a * c;

        my_assert((-1.7e307 < D) && (D < 1.7e307));

        if (D < 0){
            roots->n = none_s;

        } else if (check_equality(D, 0)){

            /*!
                this operator calculates values of x1 and x2 using the next formula:
                x = \frac{-b}{2*a};
                */

            roots->x1 = -b/(2*a);
            roots->n = one_s;

        } else {
            double s = sqrt(D);

            /*! this operator calculates values of x1 and x2 using the next formula:
                x1 = \frac{-b + \sqrt[2]{D}}{2*a};
                x2 = \frac{-b - \sqrt[2]{D}}{2*a};
                */

            roots->x1 = (-b + s)/(2*a);
            roots->x2 = (-b - s)/(2*a);
            roots->n = two_s;
        }
    }
}

/*!
    This function solves the linear equation
    */

static void solve_le(struct coeff_s* coeff, struct roots_s* roots){

    double b = coeff->b, c = coeff->c;

    if (check_equality(b, 0.0)){

        if (check_equality(c, 0.0)){

            roots->n = any_s;

        } else {

            roots->n = none_s;

        }

    } else {

        roots->x1 = -c/b;
        roots->n = one_s;
    }
}


/*!
    This function compares two numbers of the double type,
    taking into account the calculation error
    */

bool check_equality(double x, double y){

    my_assert((-1.7e307 < x) && (x < 1.7e307));
    my_assert((-1.7e307 < x) && (y < 1.7e307));

    double eps = 0.000001;
    if ((x > (y - eps)) && (x < (y + eps))){
        return true;
    } else {
        return false;
    }

}
