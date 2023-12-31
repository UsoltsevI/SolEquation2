#include <stdio.h>
#include "SolStart.h"
#include <windows.h>
#include <string.h>


static void get_input(struct coeff_s* coeff);
static double input_double();
static void clean_buffer();

const HANDLE color_c = GetStdHandle(STD_OUTPUT_HANDLE);

/*!
    This function starts communicating with the user with a brief description
    of the program. start_s(...) takes string argv_c from main(...) and if
    argv_c == "--test" runs the sol_test(). Then start_s(...) proceeds to get the values that it
    assigns to the coeff structure obtained from main().
    \param coeff structure for the content of coefficient values
    */

void start_s(struct coeff_s* coeff, char* argv_c){

    SetConsoleTextAttribute(color_c, red_on_green);
    printf("# Square equation solver\n"
           "# (c) Ded, 2023\n");

    SetConsoleTextAttribute(color_c, white_on_black);

    if (argv_c == NULL) {
        char zero [] = "0";
        argv_c = zero;
    }
    if (strcmp(argv_c, "--test") == 0) { sol_test();}

    get_input(coeff);

}


/*!
    This function accesses input_double(...) and assigns the obtained values to
    the coefficients in the coeff structure
    \param coeff structure for the content of coefficient values
    */

static void get_input(struct coeff_s* coeff){

    printf("Enter a, b, c:\n");

    coeff->a = input_double();
    coeff->b = input_double();
    coeff->c = input_double();
}


/*!
    This function gets values from the display using scanf(...) and checks
    whether the values of the variables are entered correctly. If there is an
    input error, it clears the buffer via clean_buffer() and starts itself again.
    */

static double input_double(){

    double result = 0;

    int check = scanf("%lg", &result);

    if (check != 1){

        clean_buffer();

        SetConsoleTextAttribute(color_c, red_on_black);
        printf("You have a mistake when entering\n"
               "Try it again\n");
        SetConsoleTextAttribute(color_c, white_on_black);

        return input_double();
    }

    return result;
}


/*!
    This function cleans the input buffer
    */

static void clean_buffer(){

    int c = 0;

    while ((c = getchar()) != '\n')
        ;
}


/*!
    This function gets the robots structure containing the number of roots and
    their values and, depending on the number of roots, displays different
    messages on the screen with the values of the roots
    */

void output_s(struct roots_s* roots){

    switch(roots->n){

        case none_s:
            printf("No Roots");
            break;

        case one_s:
            printf("x = %lg", roots->x1);
            break;

        case two_s:
            printf("x1 = %lg, x2 = %lg", roots->x1, roots->x2);
            break;

        case any_s:
            printf("Any number");
            break;

        case err_s:
            SetConsoleTextAttribute(color_c, red_on_black);
            printf("There is an ERROR in program");
            SetConsoleTextAttribute(color_c, white_on_black);
            break;

        default:
            SetConsoleTextAttribute(color_c, red_on_black);
            printf( "void output(struct coeff_s): ERROR: n = %d", roots->n);
            SetConsoleTextAttribute(color_c, white_on_black);
            break;
        }
}
