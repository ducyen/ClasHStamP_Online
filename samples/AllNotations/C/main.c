#define __Main_INTERNAL__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdarg.h>
#include <unistd.h> 
#include <pthread.h> 
#include <termios.h> 
#include <fcntl.h>
#include <png.h>
#include <sys/stat.h>

#include "CommonInclude.h"
#include "ObjsBuilder.h"

int InputValue(char* pMsg) {
    char n;
    printf( "%s", pMsg );
    scanf( "%c", &n );
    char c = 0;
    while( c != '\n' ){
        scanf( "%c", &c );
    }
    return n - '0';
}

void DisplayMsg(char* pMsg) {
    printf( "%s\n", pMsg );
}

static char* g_sInputDir = "../Image/Design";
const char* getInputDir( void ) { return g_sInputDir; }
static char* g_sOutputDir = "../TransImg/Design";
const char* getOutputDir( void ) { return g_sOutputDir; }

int main(int argc, char **argv){
    printf("Number of arguments (argc): %d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("Argument %d: %s\n", i, argv[i]);
    }
    if (argc >= 3) {
        g_sInputDir  = argv[ 1 ];
        g_sOutputDir = argv[ 2 ];
        printf( "arguments: %s %s\n", g_sInputDir, g_sOutputDir );
    }
    return ObjsBuilder_startSim();
}
