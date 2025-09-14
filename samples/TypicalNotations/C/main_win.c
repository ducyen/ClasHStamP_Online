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
    csv_open("../output.csv");

    for( int i = 0; i < 3; i++ ){
        clear_pre_condition();
        clear_input_event();
        clear_expected_behavior();
        clear_post_condition();

        concat_format_pre_condition( "%s\n", "State A" );
        concat_format_pre_condition( "%s\n", "State B" );
        concat_format_input_event( "ev1" );
        concat_format_expected_behavior( "Transition B1 -> B2" );
        concat_format_post_condition( "Now in B2" );

        csv_write_row();
    }

    csv_close();
    return 0;
#endif
}

#endif
