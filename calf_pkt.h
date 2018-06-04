#include <rte_mbuf.h>
struct calf_pkt {
	struct rte_mbuf *m;
        uint32_t src_addr;
        uint32_t dst_addr;
        uint16_t src_port;
        uint16_t dst_port;
	uint32_t meta;
};

//struct calf_pkt* calf_pkt_create(struct rte_mbuf *m, uint32_t src_addr, uint32_t dst_addr, uint32_t src_port, uint32_t dst_port, uint32_t meta)
inline struct calf_pkt* calf_pkt_create(struct rte_mbuf *m, uint32_t src_addr, uint32_t dst_addr, uint32_t meta)
{
	struct calf_pkt* pkt; 
	pkt = (struct calf_pkt*)rte_calloc("packet", 1, sizeof(struct calf_pkt), 0);
	pkt->m = m;
	pkt->src_addr = src_addr;
	pkt->dst_addr = dst_addr;
	//pkt->src_port = src_port;
	//pkt->dst_port = dst_port;
	pkt->meta = meta;
	return pkt;
};
