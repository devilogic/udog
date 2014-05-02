#include "options.h"
#include <stdlib.h>

#define UNUSED __attribute__((unused))

struct options_t* handle_arguments(int argc UNUSED, char* argv[] UNUSED) {
	static struct options_t opts;
	memset(&opts, 0, sizeof(opts));
	opts.call_dt_init = true;
	opts.call_dt_init_array = true;
	opts.call_dt_finit = true;
	opts.call_dt_finit_array = true;
	opts.load_pre_libs = true;
	opts.load_needed_libs = true;
	opts.not_call_any_if_loader_is_not_main = false;

	return &opts;
}



