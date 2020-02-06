#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wav.h"
#include "file.h"

/**********************************************************************
Command line accessible utility for the reversal of .wav files.
pass the name of the wav file to reverse and then a name for the 
reversed file to be saved as.

@author Aaron Kopplin
@version Feb 2020
**********************************************************************/

int main(int argc, char* argv[]){
	// get the file name to read
	char* filename = argv[1];

	//get the name to store the reversed file under
	char* reversed_filename = argv[2];

	//an array of bytes to store the data from the file
	char* actual_data;
	
	//load the bytes of the file into memory
	size_t s = read_file(filename, &actual_data);

	//load the file stored in memory into a wav file
	struct wav_file* song = parse(actual_data);

	if((char) actual_data[8] != 'W'){
		printf("this file is not a WAV file!\n");
		exit(0);
	}

	//print statistics about the file
	printf("\n========== Statistics ==========\n");
	printf("bytes: \t\t\t%ld\n", s);
	printf("file type:\t\t%c%c%c%c\n", actual_data[8], 
		actual_data[9], actual_data[10], actual_data[11]);
	printf("format:\t\t\t%c%c%c%c\n", actual_data[12], 
		actual_data[13], actual_data[14], actual_data[15]);
	printf("number of channels:\t%d\n", actual_data[22]);
	printf("sample rate: \t\t%d\n", song->sampleRate);
	printf("bits per sample: \t%d\n", song->bitPerSample);
	printf("================================\n\n");

	//reverse the file
	printf("reversing %s...\n", filename);
	char* reversed_data = malloc(s+1);
	memcpy(reversed_data, actual_data, 44);

	//have a rate to read
	int bytes_per_sample = song->bitPerSample/8;

	for (int i = 44; i <= s; i += bytes_per_sample){
		reversed_data[i] = actual_data[s-i+44-2];
		reversed_data[i+1] = actual_data[s-i+44-1];
	}

	//write the reversed file to the source folder
	write_file(reversed_filename, reversed_data, s);

	//prevent memory leaks
	free(reversed_data);
	free(actual_data);

	printf("Successfully reversed file!\n");
	return 0;
}
