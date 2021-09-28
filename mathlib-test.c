#include "mathlib.h"

#include <math.h>
#include <stdio.h>
#include <unistd.h>

#define AFLAG 0x01 // flag for all tests
#define SFLAG 0x02 // flag for arcsin test
#define CFLAG 0x04 // flag for arccos test
#define TFLAG 0x08 // flag for arctan test
#define LFLAG 0x10 // flag for log test

/* calling, printing, and comparing arcSin(x) */
static void print_arcSin() {
    double x = -1.0;
    printf("%s\t\t%4s\t\t %5s\t %5s", " x", "arcSin", "Library", "Difference\n");
    printf("%s\t\t%s\t\t%5s\t %5s", " -", "------", " -------", "----------\n");
    double mine, libraries; // avoid calling twice
    for (x = -1; x <= 1; x += 0.1) {
        mine = arcSin(x);
        libraries = asin(x); // calling
        printf("%7.4lf\t\t%11.8lf\t%11.8lf\t%13.10lf\n", x, mine, libraries,
            mine - libraries); // comparing
    }
}

/* calling, printing, and comparing arcCos(x) */
static void print_arcCos() {
    double x = -1.0;
    printf("%s\t\t %4s\t\t %5s\t %5s", " x", "arcCos", "Library", "Difference\n");
    printf("%s\t\t %s\t\t%5s\t %5s", " -", "------", " -------", "----------\n");
    double mine, libraries;
    for (x = -1; x <= 1; x += 0.1) {
        mine = arcCos(x);
        libraries = acos(x);
        printf("%7.4lf\t\t%11.8lf\t%11.8lf\t%13.10lf\n", x, mine, libraries, mine - libraries);
    }
}

/* calling, printing, and comparing arcTan(x) */
static void print_arcTan() {
    double x = 1.0;
    printf("%s\t\t %4s\t\t %5s\t %5s", " x", "arcTan", "Library", "Difference\n");
    printf("%s\t\t %s\t\t%5s\t %5s", " -", "------", " -------", "----------\n");
    double mine, libraries;
    for (x = 1.0; x <= 10; x += 0.1) {
        mine = arcTan(x);
        libraries = atan(x);
        printf("%7.4lf\t\t%11.8lf\t%11.8lf\t%13.10lf\n", x, mine, libraries, mine - libraries);
    }
}

/* calling, printing, and comparing Log(x) */
static void print_Log() {
    double x = 1.0;
    printf("%s\t\t%4s\t\t %5s\t %5s", " x", "Log", "Library", "Difference\n");
    printf("%s\t\t%s\t\t%5s\t %5s", " -", " -----", " -------", "----------\n");
    double mine, libraries;
    for (x = 1; x <= 10; x += 0.1) {
        mine = Log(x);
        libraries = log(x);
        printf("%7.4lf\t\t%11.8lf\t%11.8lf\t%13.10lf\n", x, mine, libraries, mine - libraries);
    }
}

int main(int argc, char **argv) {

    /* usage message */
    char *usage = "\n\
		-a   Runs all tests (arcsin, arccos, arctan, log)\n\
		-s   Runs arcsin tests\n\
		-c   Runs arccos tests\n\
		-t   Runs arctan tests\n\
		-l   Runs log tests";

    /* not enough arguments */
    if (argc < 2) {
        fprintf(stderr, "Program usage: %s -[asctl] %s\n", argv[0], usage);
        return -1;
    }

    int c, flags = 0x00000; // c to store arg char, flags for bitwising

    char *optlist = "asctl"; // list of options

    /* parsing arguments */
    while ((c = getopt(argc, argv, optlist)) != -1) {

        switch (c) {

        case 'a':
            flags |= AFLAG; // setting appropriate bit in flags
            break;

        case 's': flags |= SFLAG; break;

        case 'c': flags |= CFLAG; break;

        case 't': flags |= TFLAG; break;

        case 'l': flags |= LFLAG; break;

        default: fprintf(stderr, "Program usage: %s -[asctl] %s\n", argv[0], usage); return -1;
        }
    }

    /* non-option argument handling */
    if (optind != argc) {
        fprintf(stderr, "Program usage: %s -[asctl] %s\n", argv[0], usage);
        return -1;
    }

    /* checking all flags */
    if (flags & AFLAG) { // if AFLAG set, run all print functions and return
        print_arcSin();
        print_arcCos();
        print_arcTan();
        print_Log();
        return 0;
    }
    if (flags & SFLAG) { // check arcsin flag
        print_arcSin();
    }
    if (flags & CFLAG) { // check arccos flag
        print_arcCos();
    }
    if (flags & TFLAG) { // check arctan flag
        print_arcTan();
    }
    if (flags & LFLAG) { // check log flag
        print_Log();
    }
    return 0; // no error
}
