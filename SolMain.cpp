#include <stdio.h>
#include "SolMain.h"


/*!
    \author Usoltsev Ivan
    \version 2
    \date 25.08.2023
    Main creates a structure for storing the coefficients of a quadratic
    equation and passes it to the start_s(...) function, which starts
    communicating with the user and receives the values of the
    coefficients from the keyboard. If (argv[1] == "--test") start_s runs
    sol_test() to test program. Then main() passes the coefficients
    to the solve_qe(...) function and tells her the address of the roots
    structure, designed to store roots and their number. After main()
    sends the roots structure to the output(...) function, which outputs
    the received values to the screen. This is followed by the completion
    of the main() function
    */

int main(int argc, char* argv[]){

    struct coeff_s coeff = {};
    struct roots_s roots = {};

    start_s(&coeff, argv[1]);

    solve_qe(&coeff, &roots);

    output_s(&roots);

    return 0;
}
