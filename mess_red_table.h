#ifndef _RED_TABLE_H_
#define _RED_TABLE_H_

struct mess_rt {
        struct red_table_entry* entry;
        char* name;
        int cnt;
        int entry_size;
};

struct red_table_entry {
        uint32_t count; /* Number of packets in flow */
        uint8_t action; /* Action to be performed */
        uint16_t destination; /* where to go next */
};

#endif
