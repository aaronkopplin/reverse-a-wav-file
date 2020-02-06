struct wav_file {
	char riff[4];
	int chunkSize;
	char wave[4];
	char fmt[4];
	int formatSeclen;
	short formatType;
	short numOfChannels;
	int sampleRate;
	int byteRate;
	short blockAlign;
	short bitPerSample;
	char beginDataSection[4];
	int numofByteInSec;
	char* actualData; 
};

struct wav_file* parse(char* contents); //function declaration//