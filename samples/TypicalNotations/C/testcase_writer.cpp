#include "testcase_writer.h"
#include <fstream>
#include <string>
#include <cstdarg>
#include <cstdio>

static std::ofstream csvFile;
static std::string pre_condition, input_event, expected_behavior, post_condition, comment;

extern "C" {

void csv_open(const char* filename) {
    csvFile.open(filename);
    csvFile << "pre_conditions,input_event,expected_behavior,post_conditions,comment\n";
}

void csv_close() {
    if (csvFile.is_open()) {
        csvFile.close();
    }
}

void clear_pre_condition()        { pre_condition.clear(); }
void clear_input_event()          { input_event.clear(); }
void clear_expected_behavior()    { expected_behavior.clear(); }
void clear_post_condition()       { post_condition.clear(); }
void clear_comment()              { comment.clear(); }

static void add_line(std::string& target, const char* line) {
    if (!target.empty()) {
        target += "\r\n";
    }
    target += line;
}

void add_line_pre_condition(const char* line)   { add_line(pre_condition, line); }
void add_line_input_event(const char* line)     { add_line(input_event, line); }
void add_line_post_condition(const char* line)  { add_line(post_condition, line); }
void add_line_comment(const char* line)         { add_line(comment, line); }

void add_line_expected_behavior(const char* fmt, ...) {
    char buffer[1024];
    va_list args;
    va_start(args, fmt);
    vsnprintf(buffer, sizeof(buffer), fmt, args);
    va_end(args);

    add_line(expected_behavior, buffer);
}

static std::string escape_csv(const std::string& str) {
    if (str.find_first_of(",\"\n\r") != std::string::npos) {
        std::string escaped = "\"";
        for (char c : str) {
            if (c == '"') escaped += "\"\"";
            else escaped += c;
        }
        escaped += "\"";
        return escaped;
    }
    return str;
}

void csv_write_row() {
    if (!csvFile.is_open()) return;
    csvFile
        << escape_csv(pre_condition) << ","
        << escape_csv(input_event) << ","
        << escape_csv(expected_behavior) << ","
        << escape_csv(post_condition) << ","
        << escape_csv(comment) << "\n";
}

}
