
#include "logging.hpp"

class DefaultLogging:public Logging{
public:
    void fatal(char *file,int line,int time,char *format,va_list arg){};
    void warn(char *file,int line,int time,char *format,va_list arg){};
    void info(char *file,int line,int time,char *format,va_list arg){};
    void debug(char *file,int line,int time,char *format,va_list arg){};
    void puts(char *value){};
};
DefaultLogging defaultLogging;
Logging *logging=&defaultLogging;

void fatal(int loggingLevelArg,char *file,int line,int time,char *pFormat, ...){
    if(loggingLevelArg<LOGGING_LEVEL_FATAL)return;
    va_list ap;
    va_start(ap, pFormat);
    logging->fatal(file,line,time,pFormat,ap);
    va_end(ap);
}

void warn(int loggingLevelArg,char *file,int line,int time,char *pFormat, ...){
    if(loggingLevelArg<LOGGING_LEVEL_WARN)return;
    va_list ap;
    va_start(ap, pFormat);
    logging->warn(file,line,time,pFormat,ap);
    va_end(ap);
}

void info(int loggingLevelArg,char *file,int line,int time,char *pFormat, ...){
    if(loggingLevelArg<LOGGING_LEVEL_INFO)return;
    va_list ap;
    va_start(ap, pFormat);
    logging->info(file,line,time,pFormat,ap);
    va_end(ap);
}

void debug(int loggingLevelArg,char *file,int line,int time,char *pFormat, ...){
    if(loggingLevelArg<LOGGING_LEVEL_DEBUG)return;
    va_list ap;
    va_start(ap, pFormat);
    logging->debug(file,line,time,pFormat,ap);
    va_end(ap);
}

void logPuts(int loggingLevelArg,char* value){
    logging->puts(value);
}

int loggingSetup(Logging &arg){
    logging=&arg;
    INFO((char*)"logging setuped.");
    if(loggingLevel==LOGGING_LEVEL_NONE){
    	INFO((char*)"logging level is NONE");
    }else if(loggingLevel==LOGGING_LEVEL_DEBUG){
    	INFO((char*)"logging level is DEBUG");
    }else if(loggingLevel==LOGGING_LEVEL_INFO){
    	INFO((char*)"logging level is INFO");
    }else if(loggingLevel==LOGGING_LEVEL_WARN){
    	INFO((char*)"logging level is NONE");
    }else if(loggingLevel==LOGGING_LEVEL_FATAL){
    	INFO((char*)"logging level is NONE");
    }else{
    	INFO((char*)"bad logging level,%d",loggingLevel);
    }
    return 0;
}
