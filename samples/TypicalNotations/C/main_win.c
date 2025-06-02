#if defined( _MSC_VER )
#pragma warning(disable : 4996)
#define __Main_INTERNAL__

#include "CommonInclude.h"
#include "ObjsBuilder.h"

static char* g_sInputDir = "../Image/Design";
const char* getInputDir(void) { return g_sInputDir; }
static char* g_sOutputDir = "../TransImg/Design";
const char* getOutputDir(void) { return g_sOutputDir; }

HsmStates** g_activeHsmStates = NULL;

int main(int argc, char** argv) {
    if ( argc >= 3 ) {
        g_sInputDir = argv[1];
        g_sOutputDir = argv[2];
        printf("arguments: %s %s\n", g_sInputDir, g_sOutputDir);
    }
#if 1
    return ObjsBuilder_startSim();
#else
    FILE* fp = csv_open("../output.csv");
    if ( !fp ) {
        perror("Cannot open file");
        return 1;
    }

    const char* header[] = { "Name", "Comment" };
    const char* row1[] = { "John Doe", "Hello,\nthis is a multiline comment." };
    const char* row2[] = { "Jane \"JJ\" Smith", "She said \"Hi!\"" };
    const char* row3[] = { "Foo, Bar", "Comma, newline\nand \"quotes\" test" };

    csv_write_row(fp, header, 2);
    csv_write_row(fp, row1, 2);
    csv_write_row(fp, row2, 2);
    csv_write_row(fp, row3, 2);

    csv_close(fp);
    return 0;
#endif
}

#endif
