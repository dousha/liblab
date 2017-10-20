#ifndef LIBLAB_TREE_H
#define LIBLAB_TREE_H

typedef
struct binary_tree_node {
	void* content;
	struct binary_tree_node* left;
	struct binary_tree_node* right;
}
binary_tree_node_t;

#endif //LIBLAB_TREE_H
