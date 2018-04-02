#ifndef _CONFIG_TABLE_H_
#define _CONFIG_TABLE_H_

struct mess_ct {
        struct flow_table_entry* entry;
        char* name;
        int cnt;
        int entry_size;
};

struct mess_ce {
		uint32_t match; /* match field */
        uint8_t action; /* Action to be performed */
        uint16_t destination; /* where to go next */
};

#endif
