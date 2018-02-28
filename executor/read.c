#include "read.h"

#include <stdio.h>
#include <time.h>

readResult readForward(
    char *finalBuffer,
    char *filePath,
    int fileLength,
    long int timezone,
    int offset,
    int recordLen,
    int bytesToRead,
    char *readBuffer) {
    
    FILE *fp;
    readResult rr;

    if (finalBuffer == NULL) {
        finalBuffer = malloc(bytesToRead);
    }
    
    fp = fopen(filePath, "r");
    if (fseek(fp, offset, SEEK_SET) != 0) {
        rr.error = "initial seek failed";
        return rr;
    }
    fclose(fp);
}

// readResult readBackward(
//     char *finalBuffer,
//     char *filePath,
//     int fileLength,
//     int offset,
//     int recordLen,
//     int bytesToRead,
//     char *readBuffer,
//     char *fileBuffer) {

//     FILE *fp;
//     readResult rr;

//     fp = fopen(filePath, "r");
//     if (fseek(fp, offset+fileLength, SEEK_SET) != 0) {
//         rr.error = "failed to seek";
//         return rr;
//     }
//     backwardSeekResult bsr = seekBackward(fp, )
// }

backwardSeekResult seekBackward(
    FILE *fp,
    long int relativeOffset,
    long long int lowerBound) {
    
    backwardSeekResult bsr;

    if (fseek(fp, 0, SEEK_CUR) != 0) {
        bsr.error = "failed to seek to beginning of file";
        return bsr;
    }

    if (bsr.curPos - (long long int)relativeOffset <= lowerBound) {
        bsr.seekAmt = bsr.curPos - lowerBound;
    } else {
        bsr.seekAmt = (long long int)relativeOffset;
    }
    if (fseek(fp, -bsr.seekAmt, SEEK_CUR) != 0) {
        bsr.error = "failed to seek -seekAmt";
        return bsr;
    }
    bsr.curPos = bsr.curPos - bsr.seekAmt;
    return bsr;
}

int packingReader(
    char *packedBuffer,
    FILE *fp,
    char *buffer,
    long long int maxRead,
    long int timezone,
    long int duration,
    int year,
    bool seekingLast) {
    
    
}

long long int indexToEpoch(
    long long int index,
    long int timezone,
    long int duration,
    int year) {
    
    time_t startOfYear;
    struct tm *timeinfo;

    time(&startOfYear);
    timeinfo = localtime(&startOfYear);
    timeinfo
}