#include <iostream>
#include<queue>
#include<vector>
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
void print(binarytree*root)
{
	if(root==NULL)
	{
		return ;
	}
    cout<<root->data<<" ";
	print(root->left);
	print(root->right);
}
binarytree*predesscor(binarytree*root)
{
	binarytree*pre=root->left;
	while(pre->right&&pre->right!=root)
	{
		pre=pre->right;
	}
	return pre;
}
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
//MORRIS TRAVERSAL PREORDER
/*void morris(binarytree*root)
{
  binarytree*current;
  if(root==NULL)
  {
      return;
  }
  while(current!=NULL)
  {
    if(current->left==NULL)
    {
        cout<<current->data;
        current=current->right;
    }
    else
    {
        binarytree*pre=current->right;
        while(pre->right&&pre->right!=current)
           {
               pre=pre->right;
           }
            if(pre->right==NULL)
            {
              pre->right=current;
              current=current->right;
            }
            else
           {
            pre->right=NULL;
            cout<<current->data<<" ";
            current=current->right;
           }
    }
  }
}*/
void printpath(binarytree*root,int data,vector<int> s,vector<vector<int>> &v)
{
  if(root==NULL)
  {
      return ;
  }
  s.push_back(root->data);
  if(root->left==NULL&&root->right==NULL)
  {
      v.push_back(s);
  }
  if(root->left)
  {
  printpath(root->left,data,s,v);
  }
  if(root->right)
  {
  printpath(root->right,data,s,v);
  }
}

void getleaf(binarytree*root,vector<int> &s)
{
  if(root==NULL)
  {
      return;
  }
  if(root->left==NULL&&root->right==NULL)
  {
      s.push_back(root->data);
  }
  getleaf(root->left,s);
  getleaf(root->right,s);
}
int search(int in[],int ins,int ine,int data)
{
    int i;
    for( i=ins;i<ine;i++)
    {
        if(in[i]==data)
        {
            break;
        }
        
    }
    return i;
}
binarytree*helpertree(int in[],int po[],int ins,int ine,int index)
{
    if(ins>ine)
    {
        return NULL;
    }
    binarytree*root=new binarytree(po[index]);
    if(ins==ine)
    {
        return root;
    }
    int k=search(in,ins,ine,root->data);
    root->left=helpertree(in,po,ins,k-1,index+k-1-ine);
    root->right=helpertree(in,po,k+1,ine,index-1);
    
    return root;
}
binarytree*buildtree(int in[] ,int po[],int len)
{
    int index=len-1;
    return helpertree(in,po,0,len-1,index);
}
vector<int> ankit(binarytree*root)
{
    vector<int>v;
    if(root)
    {
    ankit(root->left);
    v.push_back(root->data);
    ankit(root->right);
    }
    return v;
}
int main()
{
  /*  int a[]={4,2,5,1,6,7,3};
    int b[]={4,5,2,6,7,3,1};
    int n=sizeof(a)/sizeof(a[0]);
    binarytree*root=buildtree(a,b,n);*/
    binarytree*root=takeinputlevelwise();
	print(root);
    cout<<endl;
    vector<int> v=ankit(root);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i];
    }

}
