#include <stdio.h>
#include <stdlib.h>

struct Node {
	int Value;
	int Count;
	struct Node *Left;
	struct Node *Right;
};

struct Node *Create_Node(int Value)
{
	struct Node *Ptr = new Node;
	Ptr->Value = Value;
	Ptr->Count = 0;
	Ptr->Left  = NULL;
	Ptr->Right = NULL;
	return Ptr;
}

void Insert_Node(struct Node *Root, int Value)
{
	while (1) {
		if (Value == Root->Value) {
			Root->Count += 1; return;
		}
		else if (Value < Root->Value) {
			if (Root->Left == NULL) {
				Root->Left = Create_Node(Value); return;
			} else
				Root = Root->Left;
		} else {
			if (Root->Right == NULL) {
				Root->Right = Create_Node(Value); return;
			} else
				Root = Root->Right;
		}
	}
}

void Print_Tree(struct Node *Ptr)
{
	if (Ptr == NULL)
		return;

	Print_Tree(Ptr->Left);

	printf("%d aparece %d vez(es)\n", Ptr->Value, Ptr->Count+1);

	Print_Tree(Ptr->Right);
}


void Destroy(struct Node *Root)
{
	if (Root == NULL) {
		return;
	}

	Destroy(Root->Left);
	Destroy(Root->Right);
	delete Root;
}

int main()
{
	int count, i, val;
	struct Node *root = NULL;

	scanf("%d", &count);
	for (i=0; i<count; i++) {
		scanf("%d", &val);
		if (root == NULL) {
			root = Create_Node(val);
		} else {
			Insert_Node(root, val);
		}
	}

	Print_Tree(root);

	Destroy(root);

}
