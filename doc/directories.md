Directory structure {#page_directories}
===================

[TOC]

The following page describes the directory structure of the openPOWERLINK stack distribution package.

# Main directories {#sect_directories_main}

Directory                     | Description
----------------------------- | -----------------------------------------------
apps                          | Demo applications for evaluating the openPOWERLINK stack
bin                           | Installation directory for binaries (drivers and applications)
contrib                       | Additional libraries used by the openPOWERLINK stack
doc                           | Documentation of the openPOWERLINK stack
drivers                       | openPOWERLINK drivers (kernel layer of a split-stack design)
hardware                      | Hardware specific sources like IP cores, VHDL code and board specific software
include                       | Include files needed for applications which link to the openPOWERLINK stack
lib                           | openPOWERLINK stack library installation directory
objdicts                      | CANopen object dictionaries used by the stack
stack                         | openPOWERLINK stack sources
staging                       | Unstable, unclean and untested source code
tools                         | Miscellaneous tools and utilities
unittests                     | CUnit Unit test framework


## Apps {#sect_directories_examples}
A set of demo applications is included in the openPOWERLINK distribution. The
demos contain examples of how to implement an MN or CN using the openPOWERLINK
stack.

Directory                     | Description
----------------------------- | -----------------------------------------------
demo_cn_console               | Console application which implements a CN
demo_cn_embedded              | Application which implements a CN on an embedded board
demo_mn_console               | Console application which implements an MN
demo_mn_embedded              | Application which implements an MN on an embedded board
demo_mn_qt                    | QT based application which implements an MN
common                        | Contains common configuration and source code used by all demos


## Additional Libraries {#sect_directories_libraries}
The __contrib__ directory contains additional libraries used by the openPOWERLINK stack.

Directory                     | Description
----------------------------- | -----------------------------------------------
console                       | Utilities for console input and output
getopt                        | Command line parser
pcap                          | libPcap library implementations
timer                         | Timer library
trace                         | Functions for handling trace output

## Object dictionaries {#sect_directories_objdict}

The directory contains the CANopen object dictionaries used by the stack.

Directory                     | Description
----------------------------- | -----------------------------------------------
CiA302-4_MN                   | Object dictionary according to the CiA profile 302-4 for MN implementations
CiA401_CN                     | Object dictionary according to the CiA 401 profile for I/O CN implementations


## Stack sources {#sect_directories_stack}

This directory contains the whole openPOWERLINK stack sources.

Directory                     | Description
----------------------------- | -----------------------------------------------
build                         | Build directory for the stack library
cmake                         | Files for the CMake build tool
include                       | Stack internal include files
proj                          | Stack library projects (build and configuration files)
src                           | Stack sources
src/arch                      | Architecture specific helper functions
src/common                    | Common sources used by the user and the kernel layer
src/user                      | User layer stack sources
src/kernel                    | Kernel layer stack sources
