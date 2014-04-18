// static int dump_memory(soinfo* si) {
// 	FILE* fp = fopen("./dump.udog", "wb");
// 	if (fp == NULL) {
// 		return -1;
// 	}

	

// 	fflush(fp);
// 	fclose(fp);
// 	return 0;
// }


/* 简单 */
// void test_tdog_call_simple(soinfo* si) {
//     Elf32_Addr base = si->load_bias;
//     const Elf32_Phdr *phdr = si->phdr;
// 	unsigned* d;
//     int phnum = si->phnum;
// 	unsigned dynamic_count;

//     if (si->constructors_called)
//         return;

//     si->constructors_called = 1;

// 	phdr_table_get_dynamic_section(phdr, phnum, base, &si->dynamic,
//                                    &dynamic_count);
//     if (si->dynamic == NULL) {
// 		/* 如果不是重定位链接器则报错 */
// 		DL_ERR("missing PT_DYNAMIC?!");
//     } else {
// 		DEBUG("%5d dynamic = %p\n", pid, si->dynamic);
//     }

// 	/* 从动态节中提取有用的信息 */
//     for(d = si->dynamic; *d; d++){
//         DEBUG("%5d d = %p, d[0] = 0x%08x d[1] = 0x%08x\n", pid, d, d[0], d[1]);
//         switch(*d++){
//         case DT_INIT:
// 			/* 入口点 */
//             si->init_func = (void (*)(void))(base + *d);
//             DEBUG("%5d %s constructors (init func) found at %p\n",
//                   pid, si->name, si->init_func);
//             break;
//         case DT_FINI:
// 			/* 析构函数 */
//             si->fini_func = (void (*)(void))(base + *d);
//             DEBUG("%5d %s destructors (fini func) found at %p\n",
//                   pid, si->name, si->fini_func);
//             break;
//         case DT_INIT_ARRAY:
// 			/* 初始化函数队列 */
//             si->init_array = (unsigned *)(base + *d);
//             DEBUG("%5d %s constructors (init_array) found at %p\n",
//                   pid, si->name, si->init_array);
//             break;
//         case DT_INIT_ARRAYSZ:
// 			/* 初始化函数队列数量 */
//             si->init_array_count = ((unsigned)*d) / sizeof(Elf32_Addr);
//             break;
//         case DT_FINI_ARRAY:
// 			/* 析构函数队列 */
//             si->fini_array = (unsigned *)(base + *d);
//             DEBUG("%5d %s destructors (fini_array) found at %p\n",
//                   pid, si->name, si->fini_array);
//             break;
//         case DT_FINI_ARRAYSZ:
// 			/* 析构函数数量 */
//             si->fini_array_count = ((unsigned)*d) / sizeof(Elf32_Addr);
//             break;
// 		default:
// 			break;
// 		}
// 	}

// 	/* 调用初始化函数 */
//     if (si->init_func) {
//         TRACE("[ %5d Calling init_func @ 0x%08x for '%s' ]\n", pid,
//               (unsigned)si->init_func, si->name);
//         si->init_func();
//         TRACE("[ %5d Done calling init_func for '%s' ]\n", pid, si->name);
//     }

// 	/* 初始化队列 */
//     if (si->init_array) {
//         TRACE("[ %5d Calling init_array @ 0x%08x [%d] for '%s' ]\n", pid,
//               (unsigned)si->init_array, si->init_array_count, si->name);
//         call_array(si->init_array, si->init_array_count, 0);
//         TRACE("[ %5d Done calling init_array for '%s' ]\n", pid, si->name);
//     }
// }
