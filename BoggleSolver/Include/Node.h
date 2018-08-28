#pragma once

#include <string.h>

#define ALPHABET_SIZE 26

namespace TomasMo {

	struct Node
	{
		char Letter; //not needed because can be determined from child index
		bool IsWord;
		Node* Children[ALPHABET_SIZE];
		Node* Parent;

		Node();
		Node(Node* parent, char letter);

		~Node();

		//not yet used but might be useful
		bool operator==(const Node& rhs) const;
	};
}