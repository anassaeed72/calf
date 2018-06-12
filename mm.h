#ifndef _MM_
#define _MM_
#include "../lock_free.h"
#include "hash.c"
#include "map.h"
// hashtable_t *tag_to_actor_hashmap
// hashtable_t *actor_to_node_hashmap

// uint32_t tag_to_actor_mapping(uint32_t tag);

map_uint32_t tag_to_actor_mapping;
void intialize_tag_to_actor_mapping();
int add_tag_to_tag_to_actor_mapping(char *tag, uint32_t actorID);
uint32_t* get_actor_id_from_tag_to_actor_mapping(char *tag);

map_node_lock_free_t actor_to_node_mapping;
void intialize_actor_to_node_mapping();
int add_actor_to_actor_to_node_mapping(char* actorID);
node_t* get_node_from_actor_to_node_mapping(char* actorID);

#endif  