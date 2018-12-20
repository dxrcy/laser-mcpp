// includes
#include "laser.h"
#include "str_const.h"

int main(int argc, char *argv[]){
	
//==============================================================================
//	Declarations
//==============================================================================

	FILE *fp;
	bool fileOpened = false;
	int i=1;
	
//==============================================================================
//	Parse Arguments
//==============================================================================

	if(argc==1){
		printf("%s: type 'laser -h' for help\n", argv[0]);
	}
	else{
		for(i=1; i<=argc-1; i++){
			if(strcmp(argv[i],"-v")==0){
				printf("laser is at version %s\n", version_num);
			}
			else if(strcmp(argv[i],"-h")==0){
				printf("%s", help);
			}
			else if((strcmp(argv[i],"-a")==0)&&(argc>=i+1)){
				fp=fopen(argv[i+1], "r+");
				if(fp!=NULL){
					fileOpened=true;
					parse_file(fp);
				}
				else{
					printf("Unable to open specified file: %s\n", argv[i+1]);
				}
			}
			else{
				printf("Invalid flags!\n");
			}
		}
	}

//
//	TESTING FUNCTIONS
//
	// int bin_test=101010001;
	// int bin[16];
	// char hex[4];
	// zext(bin_test, bin, size(bin));

	// printf("%i in decimal is: %i\n", bin_test, twoCompToDec(bin, size(bin)));

	// int num[16];
	// zext(bin_test, num, size(num));
	// decToTwoComp(36417, bin, size(bin));
	// printIntArr(bin, size(bin));
	// binToHex(bin, size(bin), hex, size(hex));
	// printIntArr(num, size(num));
	// printCharArr(hex, size(hex));
	// printf("%d", isKeyword("gyu"));

//
//	END TESTING
//

	// cleanup
	if(fileOpened) fclose(fp);
	return 0;
}

void printIntArr(int num[], int size){
	int i=0;
	while(i<=size-1){
		printf("%i", num[i]);
		i++;
	}
	printf("\n");
}

void printCharArr(char hex[], int size){
	int i=0;
	while(i<=size-1){
		printf("%c", hex[i]);
		i++;
	}
	printf("\n");
}