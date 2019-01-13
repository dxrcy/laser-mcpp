#include "laser.h"
#include "calc.h"

int checkFlags(char *c)
{
	for (int i = 0; i < 4; i++) {
		if (strcmp (c, flags[i]) == 0)
			return i;
	}
	return -1;
}

int parseArgs(int argc, char **argv)
{
	int prev_flag;

	for (int i = 1; i < argc; i++) {
		int flag;
		char *file = argv[i];
		flag = checkFlags (file);

		switch (flag) {
		case 0:		// version
			printf ("laser version: %s\n", version_num);
			break;
		case 1:		// help
			printf ("%s", help);
			break;
		case 2:		// assemble
			prev_flag = flag;
			break;
		case 3:		// clean
			prev_flag = flag;
			break;
		default:
			if (checkExt (file, ".asm") && prev_flag == 2){
				
			} else if (checkExt (file, ".asm") && prev_flag == 3) {
				clean (file);
			} else {
				printf ("Invalid flags!\n");
				return 0;
			}
		}
	}
	return 1;
}

int parse (char *file)
{
	FILE *fp;
	fp = fopen (file, "r+");
	if (fp != NULL) {
		printf ("\nAssembling %s...\n", file);
		parseFile (fp, file);
		fclose (fp);
		return 1;
	} else {
		printf ("Unable to open %s!\n", file);
		return 0;
	}
}

int clean (char *file)
{
	if (remove (replaceExt (file, ".sym")))
		printf ("Unable to delete %s!\n", file);
	if (remove (replaceExt (file, ".bin")))
		printf ("Unable to delete %s!\n", file);
	if (remove (replaceExt (file, ".hex")))
		printf ("Unable to delete %s!\n", file);
	if (remove (replaceExt (file, ".lst")))
		printf ("Unable to delete %s!\n", file);
	if (remove (replaceExt (file, ".obj")))
		printf ("Unable to delete %s!\n", file);
	if (ENABLE_LOGGING) {
		if (remove (replaceExt (file, ".log")))
			printf ("Unable to delete %s!\n", file);
	}
	return 1;
}

int main (int argc, char **argv) {

	if (argc <= 1) {
		printf("%s", usage);
	} else {
		parseArgs(argc, argv);
	}

	return 0;
}
