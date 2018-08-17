#include "../Include/Node.h"

namespace TomasMo {

	Node::Node()
		: Parent(nullptr), Letter('\0')
	{
		memset(Children, 0, ALPHABET_SIZE * sizeof(void*));
	}

	Node::Node(Node* parent, char letter)
		: Parent(parent), Letter(letter)
	{
		memset(Children, 0, ALPHABET_SIZE * sizeof(void*));
	}

	Node::~Node()
	{
		for (unsigned i = 0; i < ALPHABET_SIZE; i++)
		{
			delete Children[i];
		}
	}
}