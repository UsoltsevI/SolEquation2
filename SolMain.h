#ifndef SOLMAIN_H_INCLUDED
#define SOLMAIN_H_INCLUDED

#include "SolNum.h"

void start_s(struct coeff_s* coeff, char* argv_c);

void solve_qe(struct coeff_s* coeff, struct roots_s* roots);

void output_s(struct roots_s* roots);

#endif // SOLMAIN_H_INCLUDED
