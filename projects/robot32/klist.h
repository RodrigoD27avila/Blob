#ifndef KLIST_H_INCLUDED
#define KLIST_H_INCLUDED

struct K_node {
	struct K_node *next;
	void    data;
};

struct K_list {
	struct K_node *head;
	unsigned int kmemb;
};

struct K_list *k_list_new(unsigned int kmemb);
struct K_node *k_node_new(struct K_list *l);

void           k_list_add(struct K_list *l, void *data);
struct K_node *k_list_get(struct K_list *l, void *data);
void           k_list_remove(struct K_list *l, void *data);
int            k_list_empty(struct K_list *l);
void           k_list_destroy(struct K_list *l);

#endif /* KLIST_H_INCLUDED */
