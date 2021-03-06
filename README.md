# GeneticProgramming

This repository implements a conventional algorithm and demonstrates its own
capabilities with sample programs of varying complexity. "test.c" is a minimal
demonstration of the genetic algorithm; individuals are strings of numeric
characters whose fitness is simply the value of the number they represent. The
executable "main-Ant" finds solutions to the artificial ant problem (as
described by John R. Koza in "Genetic Programming"), in which finite state
machines ("ants") are tasked with following a trail of "breadcrumbs" while only
being able to detect the state of the tile directly in front of them. Here is an
example world:

     -----------------------------------------
    |                 X X                     |
    | X             X         X       X       |
    | X                       X             X |
    | X X X X                               X |
    |       X       X               X         |
    |       X       X           X X X         |
    |       X                                 |
    |       X       X                       X |
    |   X X X       X             X       X X |
    |   X                   X                 |
    |   X                                     |
    |   X X X                                 |
    |       X       X     X                   |
    |               X     X                   |
    |       X       X       X                 |
    |       X                             X X |
    | X   X X                               X |
    | X             X                       X |
    | X             X                       X |
    | X X   X     X       X X X X X X X X X X |
     -----------------------------------------

A well trained ant can be seen successfully exploring this map in [this YouTube
video](https://youtu.be/cAMlH9y2bdk)

The finite state machines controlling each ant is stored as a 2D array, indexed
by the ant's current state and whether or not there is a breadcrumb in the tile
directly in front of it. The values in a given cell determine what action the
ant should take and what state it should change to.

Two ants can produce two offspring by selecting a random contiguous region of
the matrix and swapping those values between the two ants.

## Setup

Simply running `make` will compile the executables "test" and "main-Ant".

If `make` displays compilation errors, it is likely because your compiler
provides additional compilation warnings. Such errors can be suppressed by
changing the value of the variable "STRICT"; this can either be done my
modifying the makefile or by running `make STRICT=100` instead.

By default the makefile compiles in "debug" mode; this may be changed by
replacing the line `CFLAGS += $(OPTS_DEBUG)` in the makefile with `CFLAGS +=
$(OPTS_OPTIMIZED)`, doing so can decrease the runtimes by a factor of four or
more.

## Usage

If the preprocessor flag "DEBUG" was defined during compilation, the genetic
algorithm will print a message at the end of each generation. Otherwise, it will
have no output.

### main-Ant

"main-Ant" is run with no arguments.

Runtimes typically vary between two seconds and two minutes; most of the
variation is caused by the speed on your computer and whether the makefile was
configured to use debugging flags or optimization flags.

### test

"test" is run with no arguments. When complete, it will print the most fit
string it found to the console.

Runtimes typically vary between two seconds and two minutes; most of the
variation is caused by the speed on your computer and whether the makefile was
configured to use debugging flags or optimization flags.
