#include "options.h"
#include <stdlib.h>

struct options_t* handle_arguments(int argc, char* argv[]) {
	static struct options_t opts;
	memset(&opts, 0, sizeof(opts));
	opts.call_dt_init = false;
	opts.call_dt_init_array = false;
	opts.call_dt_finit = false;
	opts.call_dt_finit_array = false;
	opts.load_pre_libs = false;
	opts.load_needed_libs = false;
	opts.not_call_any_if_loader_is_not_main = false;

	return &opts;
}



