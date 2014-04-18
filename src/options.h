#ifndef __OPTIONS_H__
#define __OPTIONS_H__

struct options_t {
	bool call_dt_init;
	bool call_dt_init_array;
	bool call_dt_finit;
	bool call_dt_finit_array;
	bool load_pre_libs;
	bool load_needed_libs;

	bool not_call_any_if_loader_is_not_main;
};

struct options_t* handle_arguments(int argc, char* argv[]);

#endif
