#include <iostream>
#include<queue>
using namespace std;
class binarytree {
	public:
	int data;
	binarytree* left;
	binarytree* right;

	binarytree(int  data) {
		this->data = data;
		left = NULL;
		right = NULL;
	}

	~binarytree() {
		delete left;
		delete right;
	}
};
class BST {
	binarytree* root;

	public:

	BST() {
		root = NULL;
	}

	~BST() {
		delete root;
	}
     private:
	binarytree*deleteData(int data, binarytree* node) {
		if (node == NULL) {
			return NULL;
		}

		if (data > node->data) {
			node->right = deleteData(data, node->right);
			return node;
		} else if (data < node->data) {
			node->left = deleteData(data, node->left);
			return node;
		} else {
			if (node->left == NULL && node->right == NULL) {
				delete node;
				return NULL;
			} else if (node->left == NULL) {
				binarytree*temp = node->right;
				node->right = NULL;
				delete node;
				return temp;
			} else if (node->right == NULL) {
                binarytree*temp = node->left;
				node->left = NULL;
				delete node;
				return temp;
			} else {
				binarytree* minNode = node->right;
				while (minNode->left != NULL) {
					minNode = minNode->left;
				}
				int rightMin = minNode->data;
				node->data = rightMin;
				node->right = deleteData(rightMin, node->right);
				return node;
			}
		}
	}

	void printTree(binarytree* root) {
	    if(root==NULL)
        {

            return ;
        }
        printTree(root->left);
        cout<<root->data<<" ";
        printTree(root->right);		/*if (root == NULL) {
			return;
		}
		cout << root->data << ":";
		if (root->left != NULL) {
			cout << "L" << root->left->data;
		}

		if (root->right != NULL) {
			cout << "R" << root->right->data;
		}
		cout << endl;
		printTree(root->left);
		printTree(root->right);*/
	}

	binarytree*inserte(int data, binarytree*node) {
		if (node == NULL) {
			binarytree*newNode = new binarytree(data);
			return newNode;
		}

		if (data < node->data) {
			node->left = inserte(data, node->left);
		} else {
			node->right = inserte(data, node->right);
		}
		return node;

	}
     public:
        void insert(int data)
        {
            this->root=inserte(data,this->root);
        }
        void print()
        {
            printTree(root);
        }
        void deleted(int data)
        {
            root=deleteData(data,root);
        }
	bool hasData(int data, binarytree* node) {
		if (node == NULL) {
			return false;
		}

		if (node->data == data) {
			return true;
		} else if (data < node->data) {
			return hasData(data, node->left);
		} else {
			return hasData(data, node->right);
		}
	}

};
binarytree*takeinputlevelwise()
{
    int rootdata;
    cout<<" enter data";
    cin>>rootdata;
    if(rootdata==-1)
    {
        return NULL;
    }
    binarytree*root=new binarytree(rootdata);
    queue<binarytree*> s;
    s.push(root);
    while(s.size()!=0)
    {
        binarytree*front=s.front();
        s.pop();
        cout<<"enter left child"<<front->data<<endl;
        int leftchild;
        cin>>leftchild;
        if(leftchild!=-1)
        {
            binarytree*child=new binarytree(leftchild);
            front->left=child;
            s.push(child);
        }
        cout<<" entr right child of"<<front->data<<endl;
        int rightchild;
        cin>>rightchild;
        if(rightchild!=-1)
        {
        binarytree*child=new binarytree(rightchild);
        front->right=child;
        s.push(child);
        }
    }
    return root;
}
int main()
{
    BST b;
   b.insert(2);
   b.insert(10);
   b.insert(11);
   b.insert(4);
   //b.deleted(10);
   b.print();

}
