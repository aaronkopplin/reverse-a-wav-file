# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "wav.h"

/*****************************************************************
Store a char* contents in the wav file struct
@param char* contents this is the bytes of the wav file
@returns wav_file* this is a pointer to the location of the 
wav file
*****************************************************************/

struct wav_file* parse(char* contents){ 
	return (struct wav_file*) contents;
}
