#include "../Include/Node.h"

namespace TomasMo {

	Node::Node()
		: Parent(nullptr), Letter('\0'), IsWord(false)
	{
		memset(Children, 0, ALPHABET_SIZE * sizeof(void*));
	}

	Node::Node(Node* parent, char letter)
		: Parent(parent), Letter(letter), IsWord(false)
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

	bool Node::operator==(const Node& rhs) const
	{
		if (Letter != rhs.Letter) return false;
		if (IsWord != rhs.IsWord) return false;
		
		for(unsigned i=0; i<ALPHABET_SIZE; i++)
		{
			if(!((!Children[i] && !rhs.Children[i]) || (Children[i] && *Children[i] == *rhs.Children[i])))
			{
				return false;
			}
		}
		return true;
	}
}