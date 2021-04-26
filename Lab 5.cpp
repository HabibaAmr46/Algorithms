
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
	int key;
	Node **next;
	Node(int key, int level){
	    this->key = key;

	next= new Node*[level+1];
	memset(next, 0, sizeof(Node*)*(level+1));
	}
};



// Class for Skip list
class SkipList
{
	int maxlevel;// Maximum level for this skip list
	float P;// P is the fraction of the nodes with level
	int level;// current level of skip list
	Node *header;// pointer to header node
public:
	SkipList(int maxlevel, float P)
	{
	    this->maxlevel = maxlevel;
        this->P = P;
        level = 0;
        header = new Node(-1, maxlevel);
	}
	int randomLevel()
	{
	    float r = (float)rand()/RAND_MAX;
        int levl = 0;
        while (r < P && levl < maxlevel)
        {
		levl++;
		r = (float)rand()/RAND_MAX;
        }
        return levl;
	}
	Node* createNode(int key, int level)
	{
	    Node *n  = new Node(key, level);
        return n;
	}
	void insertElement(int key)
	{
	    Node *curr = header;

	// create update array and initialize it
	Node *newArr[maxlevel+1];
	memset(newArr, 0, sizeof(Node*)*(maxlevel+1));

	for (int i = level; i >= 0; i--)
	{
		while (curr->next[i] != NULL &&
			curr->next[i]->key < key)
			curr = curr->next[i];
		newArr[i] = curr;
	}


	curr = curr->next[0];


	if (curr == NULL || curr->key != key)
	{

		int randomlevel = randomLevel();

		if (randomlevel > level)
		{
			for (int i=level+1;i<randomlevel+1;i++)
				newArr[i] = header;

			// Update the list current level
			level = randomlevel;
		}

		// create new node with random level generated
		Node* n = createNode(key, randomlevel);

		// insert node by rearranging pointers
		for (int i=0;i<=randomlevel;i++)
		{
			n->next[i] =newArr[i]->next[i];
			newArr[i]->next[i] = n;
		}
		cout << "Successfully Insert key " << key << "\n";
	}
	}
	void searchElement(int key)
	{
	    Node *curr = header;

    for(int i = level; i >= 0; i--)
    {
        while(curr->next[i] &&
               curr->next[i]->key < key)
            curr = curr->next[i];

    }
    curr = curr->next[0];
    if(curr and curr->key == key)
        cout<<"Found key: "<<key<<"\n";
	}
	void Print()
	{
	    cout<<"\n*****Skip List*****"<<"\n";
        for (int i=0;i<=level;i++)
        {
		Node *node = header->next[i];
		cout << "Level " << i << ": ";
		while (node != NULL)
		{
			cout << node->key<<" ";
			node = node->next[i];
		}
		cout << "\n";
        }
	}
};


// Display skip list level wise


// Driver to test above code
int main()
{
	// Seed random number generator
	srand((unsigned)time(0));

	// create SkipList object with MAXLVL and P
	SkipList s(3, 0.5);

	s.insertElement(3);
	s.insertElement(6);
	s.insertElement(7);
	s.insertElement(9);
	s.insertElement(12);
	s.insertElement(19);
	s.insertElement(17);
	s.insertElement(26);
	s.insertElement(21);
	s.insertElement(25);
	s.searchElement(19);
	s.Print();

}
