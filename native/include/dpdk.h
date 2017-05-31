#ifndef __DPDK_H__
#define __DPDK_H__
/* Call this from the main thread on ZCSI to initialize things */
// 系统初始化，初始化EAL
int init_system(int core);

/* Called from all secondary threads on ZCSI */
// 初始化线程
int init_thread(int tid, int core);
#include "mempool.h"
#endif
