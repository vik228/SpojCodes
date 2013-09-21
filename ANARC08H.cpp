#include<iostream>
#include<cstdlib>
using namespace std;
class Node
{
	private:
		int object;
		Node *nextNode;
	public:
		int get()
		{
			return object;
		}
		void set(int object)
		{
			this->object=object;
		}
		Node* getNext()
		{
			return nextNode;
		}
		void setNext(Node *nextNode)
		{
			this->nextNode=nextNode;
		}
};
class clist
{
	private:
		int size;
		Node *currentNode;
		Node *lastCurrentNode;
		Node *headNode;
	public:
		clist()
		{
			size=0;
			//cout<<"HIIII\n";
			 headNode = new Node;
			//cout<<"1st line executed perfectly\n";
			headNode->setNext(NULL);
			//cout<<"2nd line executed perfectly\n";
			currentNode=NULL;
			//cout<<"3rd line executed perfectly\n";

			lastCurrentNode=NULL;
			//cout<<"Exiting\n";
		}
		//friend void traverse(clist list);
		int get()
		{
			return currentNode->get();
		}
		void addNode(int data)
		{
			Node *newNode = new Node;
			newNode->set(data);
			if(currentNode!=NULL)
			{
				newNode->setNext(headNode->getNext());
				currentNode->setNext(newNode);
				lastCurrentNode = currentNode;
				currentNode = newNode;
			}
			else
			{
				newNode->setNext(headNode->getNext());
				headNode->setNext(newNode);
				lastCurrentNode=headNode;
				currentNode=newNode;
			}
			size++;
		}
		bool next()
		{
			if(currentNode==NULL)
				return false;
			lastCurrentNode = currentNode;
			currentNode=currentNode->getNext();
			if(lastCurrentNode == currentNode)
				return false;
			else
				return true;
		}
		void remove()
		{
			if(currentNode!=NULL && currentNode!=headNode)
			{
				lastCurrentNode->setNext(currentNode->getNext());
				delete currentNode;
				currentNode = lastCurrentNode->getNext();
				size--;
			}

		}
		int length()
		{
			return size;
		}
		void start()
		{
			currentNode=headNode->getNext();
			lastCurrentNode=headNode;
		}
};
int main()
{
	int N,D;
	clist list;
	while(cin>>N>>D)
	{
		if(N==0 || D==0)
			break;
		else
		{
			for(int i=1;i<=N;i++)
			{
				//cout<<"hiii\n";
				list.addNode(i);
			}
			list.start();
			while(list.length()>1)
			{
				for(int i=1;i<D;i++)
				{
					//cout<<"HIIII\n";
					list.next();
				}
			//	cout<<"Removing:"<<list.get()<<endl;
				list.remove();
			}
			cout<<N<<" "<<D<<" "<<list.get()<<endl;
			list.remove();
		}
	}
	return 0;
}
				
		
