#ifdef __cplusplus
extern "C" {
#endif

void csv_open(const char* filename);
void csv_close(void);
void csv_write_row(void);

void clear_pre_condition(void);
void clear_input_event(void);
void clear_expected_behavior(void);
void clear_post_condition(void);
void clear_comment(void);

void add_line_pre_condition(const char* line);
void add_line_input_event(const char* line);
void add_line_expected_behavior(const char* fmt, ...); // only formatted one
void add_line_post_condition(const char* line);
void add_line_comment(const char* line);

#ifdef __cplusplus
}
#endif
