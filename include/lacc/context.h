#ifndef CONTEXT_H
#define CONTEXT_H

#include <stddef.h>

enum target {
    TARGET_NONE,
    TARGET_IR_DOT,
    TARGET_x86_64_ASM,
    TARGET_x86_64_ELF
};

enum cstd {
    STD_C89,
    STD_C99,
    STD_C11
};

/* Global information about translation unit. */
extern struct context {
    int errors;
    int verbose;
    int suppress_warning;
    enum target target;
    enum cstd standard;
} context;

/*
 * Output diagnostics info to stdout. No-op if context.verbose is not
 * set.
 */
void verbose(const char *, ...);

/*
 * Output warning to stderr. No-op if context.suppress_warning is set.
 */
void warning(const char *, ...);

/* Output error to stderr. */
void error(const char *, ...);

#endif
