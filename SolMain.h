#ifndef SOLMAIN_H_INCLUDED
#define SOLMAIN_H_INCLUDED

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

void start_s(struct coeff_s* coeff, char* argv_c);

void solve_qe(struct coeff_s* coeff, struct roots_s* roots);

void output_s(struct roots_s* roots);

#endif // SOLMAIN_H_INCLUDED
