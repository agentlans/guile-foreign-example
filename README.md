# guile-foreign-example
Example of a foreign object containing a Scheme value

## Introduction
Guile Scheme has many functions for interfacing with C libraries.
However, the examples are scattered throughout the documentation and the code can be hard to adapt to new cases.

This repository contains the minimum C code needed to declare and work with Scheme values.

## Install
Requires Guile 2.2 on Linux.

Run `bash Make.sh`

It should also work on Guile 3.0 if you change the compiler flags (not tested).

## Use
Open Guile and run the code inside `RunBessel.scm`

## Author, License
"guile-foreign-example" by Alan Tseng is licensed under CC0 1.0 Universal 

2020
