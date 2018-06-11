#ifndef _CONFIG_TABLE_H_
#define _CONFIG_TABLE_H_

struct calf_ct {
        struct calf_ce* entries;
        char* name;
        int cnt;
        int entry_size;
};

struct calf_ce {
		uint32_t match; /* match field */
        uint32_t tag;
        char* note;
        //uint8_t action; /* Action to be performed */
        //uint16_t destination; /* where to go next */
};

#endif
