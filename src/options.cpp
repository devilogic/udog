#include "options.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//#define _GNU_SOURCE		/* 为了支持getopt_long */
#include <getopt.h>

void usage() {
	printf("udog [options] files...\n");
	printf("http://www.nagapt.com\n");
	show_version();
}

void show_version() {
	printf("V%s\n", UDOG_VERSION_STRING);
}

void show_help() {
	printf("\t----------------------------------------\n");
	printf("\t|==== Android Native Lib Cracker ====|\n");
	printf("\t----------------------------------------\n");
	printf("udog [options]\n");
	printf("-l, --load <file>                   load so file\n");
	printf("-d, --dump <file>                   dump load so to file\n");
	printf("-h, --help                          show help\n");
	printf("-v, --version                       show version\n");
	printf("http://www.nagapt.com\n");
	show_version();
	printf("\n");
}

struct options_t* handle_arguments(int argc, char* argv[]) {
	static struct options_t opts;
	memset(&opts, 0, sizeof(opts));
	opts.call_dt_init = true;
	opts.call_dt_init_array = true;
	opts.call_dt_finit = true;
	opts.call_dt_finit_array = true;
	opts.load_pre_libs = true;
	opts.load_needed_libs = true;

	int opt;
	int longidx;
	int load = 0, dump = 0, help = 0, version = 0,
		debug = 0;

	if (argc == 1) {
		return NULL;
	}

	const char* short_opts = "l:hvd:";
	struct option long_opts[] = {
		{ "load", 1, &load, 1 },
	 	{ "dump", 1, &dump, 2 },
		{ "help", 0, &help, 3 },
		{ "version", 0, &version, 4 },
		{ "debug", 0, &debug, 5 },
	 	{ 0, 0, 0, 0 }
	};

	while ((opt = getopt_long(argc, argv, short_opts, long_opts, &longidx)) != -1) {
		switch (opt) {
		case 0:
			if (load == 1) {
				opts.load = true;
				strcpy(opts.target_file, optarg);
			} else if (dump == 2) {
				opts.dump = true;
				strcpy(opts.dump_file, optarg);
			} else if (help == 3) {
				opts.help = true;
			} else if (version == 4) {
				opts.version = true;
			} else if (debug == 5) {
				opts.debug = true;
			} else {
				//printf("unknow options: %c\n", optopt);
				return NULL;
			}
			break;
		case 'l':
			opts.load = true;
			strcpy(opts.target_file, optarg);
			break;
		case 'h':
			opts.help = true;
			break;
		case 'v':
			opts.version = true;
			break;
		case 'd':
			opts.dump = true;
			strcpy(opts.dump_file, optarg);
			break;
		case '?':
			//printf("unknow options: %c\n", optopt);
			return NULL;
			break;
		case ':':
			//printf("option need a option\n");
			return NULL;
			break;
		}/* end switch */
	}/* end while */

	return &opts;
}



