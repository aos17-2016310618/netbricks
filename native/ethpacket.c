#include <rte_config.h>
#include <rte_ether.h>
#include <rte_memcpy.h>
#include "mempool.h"

// 数据报相关操作
// 设置数据包内容
void set_packet_data(mbuf_array_t array, int cnt, int offset, void* data, int size) {
	for (int i = 0; i < cnt; i++) {
		void* dest = rte_pktmbuf_mtod_offset(array[i], void*, offset);
		rte_memcpy(dest, data, size);
	}
}

// 设置数据包在buffer中的offset
void set_packet_data_at_offset(mbuf_array_t array, int* offsets, int cnt, void* data, int size) {
	for (int i = 0; i < cnt; i++) {
		void* dest = rte_pktmbuf_mtod_offset(array[i], void*, offsets[i]);
		rte_memcpy(dest, data, size);
	}
}

//设置数据包中以太网的类型
void set_ether_type(mbuf_array_t array, int cnt, uint16_t ether) {
	for (int i = 0; i < cnt; i++) {
		struct ether_hdr* hdr =
			rte_pktmbuf_mtod(array[i],
				struct ether_hdr*);
		hdr->ether_type = ether;
	}
}
