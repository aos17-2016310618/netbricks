#ifndef __PMD_H__
#define __PMD_H__

// 获取轮训块
int num_pmd_ports();


int get_pmd_ports(struct rte_eth_dev_info* info, int len);
void enumerate_pmd_ports();

// 初始化以太网端口
int init_pmd_port(int port, int rxqs, int txqs, int rxq_core[], int txq_core[],
		int nrxd, int ntxd, int loopback, int tso, int csumoffload);

// 释放以太网端口
int free_pmd_port(int port);

// 从端口队列接收数据包
int recv_pkts(int port, int qid, mbuf_array_t pkts, int len);

// 从端口发送数据包
int send_pkts(int port, int qid, mbuf_array_t pkts, int len);
#endif
