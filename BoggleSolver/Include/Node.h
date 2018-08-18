#pragma once

#include <string.h>

#define ALPHABET_SIZE 26 //TODO move to a more general place

namespace TomasMo {

	struct Node
	{
		char Letter; //not needed because can be determined from child index
		Node* Children[ALPHABET_SIZE]; //TODO test with std::vector
		Node* Parent;

		Node();
		Node(Node* parent, char letter);

		~Node();

		//not yet used but might be useful
		bool operator==(const Node& rhs) const;
	};
}