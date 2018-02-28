#include <stdio.h>
#include <errno.h>
#include <stdint.h>

typedef enum { false, true } bool;

typedef struct {
    char *resultBuffer;
    bool finished;
    int bytesRead;
    char *error;
} readResult;

readResult readForward(
    char *finalBuffer,
    char *filePath,
    int fileLength,
    long int timezone,
    int offset,
    int recordLen,
    int bytesToRead,
    char *readBuffer);

readResult readBackward(
    char *finalBuffer,
    char *filePath,
    int fileLength,
    int offset,
    int recordLen,
    int bytesToRead,
    char *readBuffer,
    char *fileBuffer);

typedef struct {
    long long int seekAmt;
    long long int curPos;
    char *error;
} backwardSeekResult;

backwardSeekResult seekBackward(
    FILE *fp,
    long int relativeOffset,
    long long int lowerBound);

int packingReader(
    char *packedBuffer,
    FILE *fp,
    char *buffer,
    long long int maxRead,
    long int timezone,
    long int duration,
    int year,
    bool seekingLast);

long long int indexToEpoch(
    long long int index,
    long int timezone,
    long int duration,
    int year);