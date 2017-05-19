# CS 433 Paging Simulation

*Copyright 2017 Caleb Evans, Jonathan Tapia*

This program is a simulation of various page replacement algorithms, written in
C++. The algorithms tested include:

- Random
- First-In-First-Out (FIFO)
- Least-Recently-Used (LRU)

## How to run

Run `make` to compile the program, then execute the compiled program by running
`./sim.out` with two arguments. The first argument is the page size is bytes
(B). The second argument is the physical memory size in megabytes (MB). When the
program starts, you will be prompted to choose a replacement algorithm under
which to run the simulation.
