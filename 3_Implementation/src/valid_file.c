#include "fun.h"

error_t isFileExists(const char *path)
{
    // Try to open file
    FILE *fp = fopen(path, "rb");
    error_t status = FILE_NOT_FOUND;
    // If file does not exists
    if (fp != NULL)
    {
        status = SUCCESS;
        // File exists hence close file
        fclose(fp);
    }
    return status;
}