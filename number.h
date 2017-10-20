#ifndef LIBLAB_NUMBER_H
#define LIBLAB_NUMBER_H

/**
 * number is the only structure that is allowed
 * to be returned and passed as a parameter.
 */

typedef
union number{
	struct{
		unsigned long long integerPart;
		unsigned long long decimalPart;
	}exact;
	double approx;
}
number_t;

#endif //LIBLAB_NUMBER_H
