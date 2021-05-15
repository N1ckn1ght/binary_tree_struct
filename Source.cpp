#include <iostream>

using namespace std;

struct Node
{
	char data;
	Node* left;
	Node* right;

	Node()
	{
		data = NULL;
		left = nullptr;
		right = nullptr;
	}
	
	Node* find(char target)
	{
		if (this->data == NULL)
		{
			return nullptr;
		}
		if (this->data == target)
		{
			return this;
		}
		else if (target < this->data)
		{
			return this->left->find(target);
		}
		else
		{
			return this->right->find(target);
		}
	}

	void insert(char target)
	{
		if (this->data == NULL)
		{
			data = target;
			left = new Node();
			right = new Node();
		}
		else if (target < this->data)
		{
			this->left->insert(target);
		}
		else if (target > this->data)
		{
			this->right->insert(target);
		}
		// skip insertion if target == node data
	}

	void remove(char target)
	{
		if (this->data == target)
		{
			if (this->left->data == NULL)
			{
				if (this->right->data == NULL)
				{
					delete this->left;
					delete this->right;
					this->data = 0;
					this->left = nullptr;
					this->right = nullptr;
				}
				else
				{
					Node* tmp = this->right;
					this->left = tmp->left;
					this->right = tmp->right;
					this->data = tmp->data;
					delete tmp;
				}
			}
			else
			{
				if (this->right->data == NULL)
				{
					Node* tmp = this->left;
					this->left = tmp->left;
					this->right = tmp->right;
					this->data = tmp->data;
					delete tmp;
				}
				else
				{
					Node* tmp = this->left;
					while (tmp->left->data != NULL || tmp->right->data != NULL)
					{
						if (tmp->left->data != NULL)
						{
							tmp = tmp->left;
						}
						else
						{
							tmp = tmp->right;
						}
					}
					this->data = tmp->data;
					tmp->data = NULL;
					delete tmp->left;
					delete tmp->right;
					tmp->left = nullptr;
					tmp->right = nullptr;
				}
			}
		}
		else if (target < this->data)
		{
			this->left->remove(target);
		}
		else
		{
			this->right->remove(target);
		}
	}
};

int find(Node node, char target)
{
	if (node.find(target) == nullptr)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int main()
{
	Node root;
	root.insert('C');
	root.insert('B');
	root.insert('D');

	cout << find(root, 'C') << " " << find(root, 'A') << " " << find(root, 'D') << "\n";

	root.insert('A');
	root.insert('F');
	root.remove('D');

	cout << find(root, 'C') << " " << find(root, 'A') << " " << find(root, 'D') << "\n\n";

	Node root2;
	root2.insert('E');
	root2.insert('A');
	root2.insert('M');
	root2.insert('F');
	root2.insert('Q');
	root2.insert('G');
	root2.insert('X');
	root2.insert('W');
	root2.insert('Z');

	cout << find(root2, 'E') << " " << find(root2, 'A') << " " << find(root2, 'M') << " " << find(root2, 'F') << " " << find(root2, 'G') << " " << find(root2, 'Q') << " " << find(root2, 'X') << " " << find(root2, 'W') << " " << find(root2, 'Z') << "\n";

	root2.remove('Q');

	cout << find(root2, 'E') << " " << find(root2, 'A') << " " << find(root2, 'M') << " " << find(root2, 'F') << " " << find(root2, 'G') << " " << find(root2, 'Q') << " " << find(root2, 'X') << " " << find(root2, 'W') << " " << find(root2, 'Z') << "\n";

	root2.remove('Z');

	cout << find(root2, 'E') << " " << find(root2, 'A') << " " << find(root2, 'M') << " " << find(root2, 'F') << " " << find(root2, 'G') << " " << find(root2, 'Q') << " " << find(root2, 'X') << " " << find(root2, 'W') << " " << find(root2, 'Z') << "\n";

	root2.remove('M');

	cout << find(root2, 'E') << " " << find(root2, 'A') << " " << find(root2, 'M') << " " << find(root2, 'F') << " " << find(root2, 'G') << " " << find(root2, 'Q') << " " << find(root2, 'X') << " " << find(root2, 'W') << " " << find(root2, 'Z') << "\n";

	root2.insert('Z');

	cout << find(root2, 'E') << " " << find(root2, 'A') << " " << find(root2, 'M') << " " << find(root2, 'F') << " " << find(root2, 'G') << " " << find(root2, 'Q') << " " << find(root2, 'X') << " " << find(root2, 'W') << " " << find(root2, 'Z') << "\n";
}
