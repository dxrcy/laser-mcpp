// include statements
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "config.h"

#ifndef LASER_H
#define LASER_H

const char *version_num = "1.0.0";

const char *usage = "laser usage:\n"
					"\t'laser -v' to display version number\n"
					"\t'laser -h' to display a more detailed help message\n"
					"\t'laser -a <file>' to assemble a file\n"
					"\t'laser -c <file>' to remove all files generated by 'laser -a <file>'\n";

const char *help = "Description:\n"
					"\tAn assembler for the LC3 assembly language written entirely in C by Pete Fan.\n"
					"Usage:\n"
					"\t-v: 'laser -v' displays version number\n"
					"\t-h: 'laser -h' displays this message again\n"
					"\t-a: 'laser -a <file>' assembles the specified file\n"
					"\t    'laser -a *.asm' assembles all assembly files in current directory\n"
					"\t-c: 'laser -c <file>' removes all files generated by 'laser -a <file'\n"
					"\t    'laser -c *.asm' removes all files generated by 'laser -a *.asm'\n";

const char *flags[] = { "-v", "-h", "-a", "-c" };

int checkFlags(char *c);

void parseFile (FILE *fp, char *fname);

int parseArgs(int argc, char **argv);

int parse (char *file);

int clean (char *file);

int main (int argc, char **argv);

#endif