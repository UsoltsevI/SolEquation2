#ifndef SOLCAL_H_INCLUDED
#define SOLCAL_H_INCLUDED

enum n_roots {
    none_s, ///< indicates that the equation has no roots
    one_s,  ///< indicates that the equation has one root
    two_s,  ///< indicates that the equation has two roots
    any_s,  ///< indicates that the equation has infinity number of roots
    err_s,  ///< indicates that an error occurred when executing the program
};

struct coeff_s { ///< structure for storing coefficients
    double a, b, c;
};

struct roots_s { ///< structure for storing roots and number of roots
    double x1, x2;
    n_roots n;
};

void solve_qe(struct coeff_s* coeff, struct roots_s* roots);

bool check_equality(double x, double y);

#endif // SOLCAL_H_INCLUDED
