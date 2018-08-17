#pragma once

#include <string.h>

#define ALPHABET_SIZE 26 //TODO move to a more general place

namespace TomasMo {

	struct Node
	{
		char Letter;
		Node* Children[ALPHABET_SIZE]; //TODO test with std::vector
		Node* Parent;

		Node();
		Node(Node* parent, char letter);

		~Node();
	};
}