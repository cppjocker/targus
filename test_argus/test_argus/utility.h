#pragma once

#include <cerrno>
#include <cstdlib>
#include <climits>

typedef enum {
	STR2INT_SUCCESS = 0,
	STR2INT_OVERFLOW,
	STR2INT_UNDERFLOW,
	STR2INT_INCONVERTIBLE
} STR2INT_ERROR;

inline STR2INT_ERROR str2int(int &i, char const *s, int base = 0)
{
	char *end;
	long  l;
	errno = 0;
	l = strtol(s, &end, base);
	if ((errno == ERANGE && l == LONG_MAX) || l > INT_MAX) {
		return STR2INT_OVERFLOW;
	}
	if ((errno == ERANGE && l == LONG_MIN) || l < INT_MIN) {
		return STR2INT_UNDERFLOW;
	}
	if (*s == '\0' || *end != '\0') {
		return STR2INT_INCONVERTIBLE;
	}
	i = l;
	return STR2INT_SUCCESS;
}
