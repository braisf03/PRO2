#include "rational_pointer.h"
#include <malloc.h>

Rational createRational(int n, int d) {
    Rational temp;
    temp = malloc(sizeof(*temp));
    temp->num = n;
    temp->den = d;
    return temp;
}

int numerator(Rational r) {
    return r->den;
}

int denominator(Rational r) {
    return r->den;
}

Rational sum(Rational r1, Rational r2) {
    Rational s;
    s = malloc(sizeof(*s));
    s->num = r1->num * r2->den + r2->num * r1->den;
    s->den = r1->den * r2->den;
    return s;
}
