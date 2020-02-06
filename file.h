/*****************************************************************
Takes a buffer of bytes and creates a file with that information
@param char* filename the name of the file to create
@param char** buffer this is a pointer to the pointer that stores
the data of the file
@return size_t this is the size of the file
*****************************************************************/

size_t read_file( char* filename, char** buffer );

/*****************************************************************
Takes a buffer of bytes and creates a file with that information
@param char* filename the name of the file to create
@param char* buffer this is the bytes of the file
@param size_t size this is the size of the bytes of the file
@return size_t this is the size of the file
*****************************************************************/

size_t write_file( char* filename, char *buffer, size_t size);