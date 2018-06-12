#include "mm.h"

void initialize_tag_to_actor_mapping(){
	map_init(&tag_to_actor_mapping);
}



int add_tag_to_tag_to_actor_mapping(char *tag, uint32_t actorID){
	return map_set_(tag_to_actor_mapping,tag, actorID, sizeof(actorID));
}

uint32_t* get_actor_id_from_tag_to_actor_mapping(char *tag){
	return map_get_(tag_to_actor_mapping,tag);
}

void intialize_actor_to_node_mapping(){
	map_init(&actor_to_node_mapping);
}


int add_actor_to_actor_to_node_mapping(char* actorID){
	list *_list = create_queue();
	return map_set_(actor_to_node_mapping, actorID,_list,sizeof(_list));
}

node_t* get_node_from_actor_to_node_mapping(char* actorID){
	return map_get_(actor_to_node_mapping,actorID);	
}

// void add_pkt(void *pkt ){
// 	uint32_t tag = pkt->tag;
// 	uint32_t actorID = get_actor_id_from_tag_to_actor_mapping(tag);
// 	node_t* list = get_node_from_actor_to_node_mapping(actorID);
// 	enqueue(pkt, list);
// }

// void add_actor(uint32_t tag, uint32_t actorID){
// 	add_tag_to_tag_to_actor_mapping(tag,actorID);
// 	add_actor_to_actor_to_node_mapping(actorID);
// }	

// void* get_mm_pkt(uint32_t actorID){
// 	return dequeue(get_node_from_actor_to_node_mapping(actorID));
// }