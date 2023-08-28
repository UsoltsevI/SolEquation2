#ifndef SOLTEST_H_INCLUDED
#define SOLTEST_H_INCLUDED

#include "SolNum.h"

bool check_equality(double x, double y);

void solve_qe(struct coeff_s* coeff, struct roots_s* roots);

#endif // SOLTEST_H_INCLUDED
