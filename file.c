# include <stdio.h>
# include <stdlib.h>
# include "file.h"

/*****************************************************************
Takes a buffer of bytes and creates a file with that information
@param char* filename the name of the file to create
@param char** buffer this is a pointer to the pointer that stores
the data of the file
@return size_t this is the size of the file
*****************************************************************/

size_t read_file( char* filename, char** buffer ){
	FILE* file = fopen(filename, "r");

	//co-opted from https://www.programiz.com/
	// c-programming/c-file-input-output
	if(file == NULL){
	    printf("Error opening file!\n");   
	    exit(1);             
	}

	fseek(file, 0, SEEK_END);
	size_t size = ftell(file);
	// rewinding the reader what is this a VHS?
	fseek(file, 0, SEEK_SET); 
	//set the buffer to point at the beginning of the file space
	*buffer = (char*) malloc(size); 
	fread(*buffer, size, 1, file);
	fclose(file);
	return size;
}

/*****************************************************************
Takes a buffer of bytes and creates a file with that information
@param char* filename the name of the file to create
@param char* buffer this is the bytes of the file
@param size_t size this is the size of the bytes of the file
@return size_t this is the size of the file
*****************************************************************/

size_t write_file( char* filename, char *buffer, size_t size){
	printf("writing file \"%s\"\n", filename);
	FILE* reversed_file	= fopen(filename, "wb");

	//inspired by https://www.programiz.com/c-programming/
	// c-file-input-output
	if(reversed_file == NULL){
    	printf("Error opening file for reversal\n");   
        exit(1);             
    }

	fwrite(buffer, 1, size, reversed_file);
	fclose(reversed_file);

    return size;
}
