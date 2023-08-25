#include <stdio.h>
#include "SolMain.h"


/*!
    \author Usoltsev Ivan
    \version 2
    \date 25.08.2023
    Main creates a structure for storing the coefficients of a quadratic
    equation and passes it to the start(...) function, which starts
    communicating with the user and receives the values of the
    coefficients from the keyboard. Then main() passes the coefficients
    to the solve_qe(...) function and tells her the address of the roots
    structure, designed to store roots and their number. After main()
    sends the roots structure to the output(...) function, which outputs
    the received values to the screen. This is followed by the completion
    of the main() function
    */

int main(){

    struct coeff_s coeff;
    struct roots_s roots;

    start_s(&coeff);

    solve_qe(&coeff, &roots);

    output_s(&roots);

    return 0;
}
