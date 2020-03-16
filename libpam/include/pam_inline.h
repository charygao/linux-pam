/*
 * Copyright (c) 2020 Dmitry V. Levin <ldv@altlinux.org>
 *
 * Handy inline functions and macros providing some convenient functionality
 * to libpam and its modules.
 */

#ifndef PAM_INLINE_H
#define PAM_INLINE_H

#include "pam_cc_compat.h"

/*
 * Evaluates to
 * - a syntax error if the argument is 0,
 * 0, otherwise.
 */
#define PAM_FAIL_BUILD_ON_ZERO(e_)	(sizeof(int[-1 + 2 * !!(e_)]) * 0)

/*
 * Evaluates to
 * - a syntax error if the argument is not an array,
 * 0, otherwise.
 */
#define PAM_MUST_BE_ARRAY(a_)		PAM_FAIL_BUILD_ON_ZERO(!PAM_SAME_TYPE((a_), &(a_)[0]))

/* Evaluates to the number of elements in the specified array.  */
#define PAM_ARRAY_SIZE(a_)		(sizeof(a_) / sizeof((a_)[0]) + PAM_MUST_BE_ARRAY(a_))

#endif /* PAM_INLINE_H */
