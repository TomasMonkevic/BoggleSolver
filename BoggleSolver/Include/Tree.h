#pragma once

namespace TomasMo {

	class Tree
	{
	private:
		struct Node
		{
			char Letter;
			Node* Children[26]; //TODO test with std::vector
			Node* Parent;

			~Node()
			{
				for (unsigned i = 0; i < 26; i++)
				{
					delete Children[i];
				}
			}
		};

		Node* _root;

	public:
		Tree();
		Tree(const char* pathToDictionary);
		~Tree();

		void Back();
		void Next(char letter);

		void AddWord(const char* word);
		const char* GetTraversedWord();
	};
}
