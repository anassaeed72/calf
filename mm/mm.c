#include "mm.h"
#include "../schduler/schdule.c"
void initialize_tag_to_actor_mapping(){
	map_init(&tag_to_actor_mapping);
	uint32_t actorID = 10;
	// map_set(&tag_to_actor_mapping,"tag", actorID);
}

char* convert_uint_32t_to_char(uint32_t input){
	char *str = malloc(32);
	snprintf(str, 32, "%d", input);
	return str;
}


int add_tag_to_tag_to_actor_mapping(char *tag, uint32_t actorID){
	return map_set(&tag_to_actor_mapping,tag, actorID);
}

uint32_t* get_actor_id_from_tag_to_actor_mapping(char *tag){
	return map_get(&tag_to_actor_mapping,tag);
}


void intialize_actor_to_node_mapping(){
	map_init(&actor_to_node_mapping);
}

int add_actor_to_actor_to_node_mapping_uint32_t(uint32_t actorID){

	return add_actor_to_actor_to_node_mapping(convert_uint_32t_to_char(actorID));
}

int add_actor_to_actor_to_node_mapping(char* actorID){
	list * _list = create_queue();
	// printf("List created\n");
	return map_set(&actor_to_node_mapping, actorID,_list);
}

list* get_node_from_actor_to_node_mapping(char* actorID){
	return map_get(&actor_to_node_mapping,actorID);	
}

void add_pkt(void *pkt ){
	printf("ADD PKT called\n");
	char* tag = "tag"; // get tag from pkt
	uint32_t* actorID = get_actor_id_from_tag_to_actor_mapping(tag);
	// printf("Actor ID is %d\n", *actorID);
	list* _list = get_node_from_actor_to_node_mapping(convert_uint_32t_to_char(*actorID));
	if (_list == NULL)
	{
		/* code */
		printf("List is null\n");
	}
	enqueue(pkt, _list);
	printf("After enqueue\n");
	// call schduler that actor (ActorID) has work
	mainFunc(*_list);

}

void add_actor(uint32_t tag, uint32_t actorID){
	add_tag_to_tag_to_actor_mapping(convert_uint_32t_to_char(tag),actorID);
	add_actor_to_actor_to_node_mapping(convert_uint_32t_to_char(actorID));
}	
void* get_mm_pkt(char* actorID){

	return dequeue(get_node_from_actor_to_node_mapping(actorID));
}

void* get_mm_pkt_uint_32t(uint32_t actorID){
	return get_mm_pkt(convert_uint_32t_to_char(actorID));
}

void populate_tables(){
	char* tag = "tag";
	uint32_t actorID = 123;
	add_tag_to_tag_to_actor_mapping(tag,actorID);

	add_actor_to_actor_to_node_mapping_uint32_t(actorID);
}
void initialize_tables(){
	initialize_tag_to_actor_mapping();
	intialize_actor_to_node_mapping();

}




int main(int argc, char const *argv[])
{
	/* code */
	// char* tag = "123";
	// uint32_t actorID =987;
	// add_tag_to_tag_to_actor_mapping(tag,actorID);
	// uint32_t *result = get_actor_id_from_tag_to_actor_mapping(tag);
	// printf("%d\n",*result );




	// int res = add_actor_to_actor_to_node_mapping(tag);
	// printf("%d\n",res );
	// list** res1 = get_node_from_actor_to_node_mapping(tag);
	// if (res1 ==NULL)
	// {
	// 	printf("NULL\n");
	// }

	printf("Starting Simulation\n");
	initialize_tables();
	populate_tables();
	 int a = 102;
    void *ptr = &a;
    add_pkt(&ptr);
    // add_pkt(&ptr);
    // add_pkt(&ptr);
    // add_pkt(&ptr);
    // add_pkt(&ptr);
    // add_pkt(&ptr);

	return 0;
}