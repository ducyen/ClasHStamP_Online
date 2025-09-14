#if defined( _MSC_VER )
#pragma warning(disable : 4996)
#define __Main_INTERNAL__

extern "C" {
#include "CommonInclude.h"
#include "ObjsBuilder.h"
}

#include <iostream>
#include "csv.hpp"

static char* g_sInputDir = "../Image/Design";
const char* getInputDir(void) { return g_sInputDir; }
static char* g_sOutputDir = "../TransImg/Design";
const char* getOutputDir(void) { return g_sOutputDir; }


int main(int argc, char** argv) {
    if ( argc >= 3 ) {
        g_sInputDir = argv[1];
        g_sOutputDir = argv[2];
        printf("arguments: %s %s\n", g_sInputDir, g_sOutputDir);
    }
#if 1
    const char* path = "../sample.csv";

    // STEP 1: Create or overwrite CSV file
    std::ofstream out(path, std::ios::trunc); // trunc = overwrite if exists
    if ( !out ) {
        std::cerr << "❌ Failed to create file.\n";
        return 1;
    }

    // STEP 2: Write headers and rows
    out << "Name,Comment\n";
    out << "John Doe,\"Hello,\nthis is a multiline comment.\"\n";
    out << "Jane \"JJ\" Smith,\"She said \"\"Hi!\"\"\"\n";
    out.close();
    std::cout << "✅ File written: " << path << "\n";

    // STEP 3: Read it back using csv-parser
    try {
        csv::CSVReader reader(path);
        for ( csv::CSVRow& row : reader ) {
            std::string name = row["Name"].get<>();
            std::string comment = row["Comment"].get<>();
            std::cout << "Name: " << name << "\n";
            std::cout << "Comment: " << comment << "\n";
            std::cout << "------------------------\n";
        }
    }
    catch ( const std::exception& e ) {
        std::cerr << "❌ CSV parse error: " << e.what() << "\n";
    }
    return 0;
#else
    return ObjsBuilder_startSim();
#endif
}

#endif
