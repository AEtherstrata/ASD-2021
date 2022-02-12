#ifndef _OBJECT_H
#define _OBJECT_H

/* Forward declarations */

typedef struct NODE_STRUCT node;
typedef struct EDGE_STRUCT edge;

typedef struct NODE_LIST nodeList;
typedef struct EDGE_LIST edgeList;

typedef struct TREE_NODE treeNode;

typedef	struct QUEUE_STRUCT queue;

/* * * * * * * * * * * */

typedef struct TREE_NODE {

	struct TREE_NODE*		parent;
	struct TREE_NODE*		left;
	struct TREE_NODE*		right;
	node*					info;

} treeNode;

typedef	struct QUEUE_STRUCT {

	int			head;
	int			tail;
	node**		array;
	int			size;

} queue;

/* Minimal implementation of a graph structure */

typedef struct NODE_STRUCT {

	int				id;
	int				color;
	edgeList*		edges;		// List of edges associated with this node
	nodeList*		pos;		// Position of this node in the nodes list

} node;

typedef struct EDGE_STRUCT {

	int				id;	
	node*			from;		// Source node pointer
	node*			to;			// Target node pointer
	edgeList*		pos;		// Position of this edge in the graph edges list
	edgeList*		frompos;	// Position of this edge in the source node edges list
	edgeList*		topos;		// Position of this edge in the target node edges list

} edge;

typedef struct NODE_LIST {

	node*			info;
	nodeList*		next;
	nodeList*		prev;
	
} nodeList;

typedef struct EDGE_LIST {

	edge*			info;
	edgeList*		next;
	edgeList*		prev;

} edgeList;

typedef struct GRAPH_STRUCT {

	int				nodeCount;
	int				edgeCount;
	nodeList*		nodes;
	edgeList*		edges;

} graph;

#endif