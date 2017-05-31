#ifndef __MEMPOOL_H__
#define __MEMPOOL_H__
#include <rte_config.h>
#include <rte_cycles.h>
#include <rte_timer.h>
#include <rte_ethdev.h>
#include <rte_eal.h>
#include <rte_ether.h>
#include <rte_mbuf.h>
RTE_DECLARE_PER_LCORE(int, _mempool_core);

typedef struct rte_mbuf* restrict * restrict mbuf_array_t;
/* Called by system initialization */
int init_mempool_core(int core);
// 初始化内存池
int init_mempool(int master_core,
		unsigned int mempool_size,
		unsigned int mcache_size,
		unsigned short slots);

// 初始化第二个内存池
int init_secondary_mempool(const char* mempool_name);
int find_secondary_mempool();

// 从内存池中分配一个数据包buffer。
struct rte_mbuf *mbuf_alloc();

//释放数据包buffer
void mbuf_free(struct rte_mbuf* buf);
//分配内存块
int mbuf_alloc_bulk(mbuf_array_t array, uint16_t len, int cnt);
//分配内存块
int mbuf_free_bulk(mbuf_array_t array, int cnt);

struct rte_mempool *get_pframe_pool(int coreid, int sid);
struct rte_mempool *get_mempool_for_core(int coreid);
#endif
