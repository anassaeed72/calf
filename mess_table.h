#ifndef _FLOW_TABLE_H_
#define _FLOW_TABLE_H_

struct flow_table_entry {
        uint32_t count; /* Number of packets in flow */
        uint8_t action; /* Action to be performed */
        uint16_t destination; /* where to go next */
};

#endif
