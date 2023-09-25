#include<iostream>
#include<string>
using namespace std;
class mapnode
{
  public:
  string key;
  int data;
  mapnode*next;
  mapnode(string key ,int data)
  {
      this->key=key;
      this->data=data;
      next=NULL;
  }
  ~mapnode()
  {
      delete next;
  }
};
class ourmap
{
    mapnode**bucket;
    int count;
    int numbucket;
    public:
    ourmap()
    {
        count=0;
        numbucket=5;
        bucket=new mapnode*[numbucket];
        for(int i=0;i<numbucket;i++)
        {
            bucket[i]==NULL;
        }
    }
    ~ourmap()
    {
        for(int i=0;i<numbucket;i++)
        {
            delete bucket[i];
        }
        delete []bucket;
    }
    private:
    int getbucketindex(string key)
    {
        int hashcode=0;
        int hashcoeff=0;
        for(int i=0;i<key.length()-1;i++)
        {
            hashcode+=key[i]*hashcoeff;
            hashcode=hashcode%numbucket;
            hashcoeff=hashcoeff*37;
            hashcoeff=hashcoeff%numbucket;
        }
        return hashcode%numbucket;
    }
    public:
    void insert(string key ,int data)
    {
        int bucketindex=getbucketindex(key);
        mapnode*head=bucket[bucketindex];
        while(head!=NULL)
        {
            if(head->key==key)
            head->data=data;
            return ;
        }
        head=head->next;
        head=bucket[bucketindex];
        mapnode*temp=new mapnode(key,data);
        temp->next=head;
        bucket[bucketindex]=temp;
        count++;
    }
};
int main()
{

}