#ifndef SOLCAL_H_INCLUDED
#define SOLCAL_H_INCLUDED

#include "SolNum.h"

void solve_qe(struct coeff_s* coeff, struct roots_s* roots);

bool check_equality(double x, double y);

#endif // SOLCAL_H_INCLUDED
