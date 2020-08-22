//
//  logging.hpp
//  firstSketch
//
//  Created by Tomoki Nagatani on 2016/03/16.
//
//

#ifndef logging_hpp
#define logging_hpp

#include <string.h>
#include <stdarg.h>
#include "mcutime.h"
#define FATAL(...)  fatal(loggingLevel,loggingFileName,__LINE__,(int)millis(),__VA_ARGS__)
#define WARN(...)   warn(loggingLevel,loggingFileName,__LINE__,(int)millis(),__VA_ARGS__)
#define INFO(...)   info(loggingLevel,loggingFileName,__LINE__,(int)millis(),__VA_ARGS__)
#define DEBUG(...) debug(loggingLevel,loggingFileName,__LINE__,(int)millis(),__VA_ARGS__)
#define LOGPUTS(X) logPuts(loggingLevel,X);

#define LOGGING_LEVEL_NONE 0
#define LOGGING_LEVEL_DEBUG 1
#define LOGGING_LEVEL_INFO 2
#define LOGGING_LEVEL_WARN 3
#define LOGGING_LEVEL_FATAL 4

__attribute__((unused))static int loggingLevel=LOGGING_LEVEL_INFO;
__attribute__((unused))static char* loggingFileName=(strrchr(__FILE__,'\\' ) + 1 );
//__attribute__((unused))static char* loggingFileName=(strrchr(__FILE__,'/' ) + 1 );

class Logging{
public:
    virtual void fatal(char *file,int line,int time,char *format,va_list arg)=0;
    virtual void warn(char *file,int line,int time,char *format,va_list arg)=0;
    virtual void info(char *file,int line,int time,char *format,va_list arg)=0;
    virtual void debug(char *file,int line,int time,char *format,va_list arg)=0;
    virtual void puts(char *value)=0;
};

void fatal(int loggingStatus,char *file,int line,int time,char *pFormat, ...);
void warn(int loggingStatus,char *file,int line,int time,char *pFormat, ...);
void info(int loggingStatus,char *file,int line,int time,char *pFormat, ...);
void debug(int loggingStatus,char *file,int line,int time,char *pFormat, ...);
void logPuts(int loggingStatus,char *file);

int loggingSetup(Logging &arg);


#endif /* logging_hpp */
