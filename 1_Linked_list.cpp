//program for linked list using pointer 
#include<iostream>
using namespace std;

struct linklist 
{
    int data;
    struct linklist *next;   //where node containing data and next(address part of same type next one)
    
};
typedef struct linklist list;   //updating name of datatype
list *head; //creating variable or object of structure...

void create(list *);
void ins(list *);
void dele(list *);
void disp(list *);      //we have to pass list variable i.e. head hence argument also list type

int main()
{
    int ch; //choice
    head = NULL;    //assign head = NULL becuse we don't have any memory space or address

    do{

        cout<<endl<<"MENU OF LINKLIST...";
        cout<<endl<<endl<<"Enter 1. create";
        cout<<endl<<"Enter 2. insert";
        cout<<endl<<"Enter 3. delete";
        cout<<endl<<"Enter 4. display";
    cout<<endl<<endl<<"Enter your choice...";
    cin>>ch;

    switch(ch)
    {
        case 1: 
            create(head);   //calling function and passing head as argument i.e. NULL
            break;
        case 2:
            ins(head);
            break;
        case 3:
            dele(head);
            break;
        case 4:
            disp(head);
            break;
    }
  }while(ch>=1 && ch<=4);

  //----start function body...
}
    void create(list *node)     //passing stucture list variable head i.e. containing NULL
    {
        if(node == NULL)        //creating 1st node or head node
        {
            head = new list;    //assign new list to head i.e. address

            cout<<endl<<"Enter the data to it...";
            cin>>head->data;        //directly inserting data to head

            head -> next = NULL;    //then assign it's next part NULL i.e. address part...
        }
        else{
            cout<<endl<<"List i.e.(head) / 1st node already created please insert...";
            }
    }

    void ins(list *node)
    {
        if(node == NULL)    //always check is head node created or not... 
            {
                cout<<endl<<"plz create the list i.e. 1st node...";
            }
        else{
                while(node -> next != NULL)    //we have to create nodes or insert node to list
                    node = node->next;  //if node not containg NUll(address part) then move to next node
                
                
                //if node containging NUll then assing it new list i.e. new address of next node
                node->next = new list;  //now next part i.e address updated NUll to some ramdom addrs

                cout<<endl<<"Enter the data to the next node or (ins data on that address)";
                cin>>node->next ->data;      //here we storing data on that node's next i.e address of next node 

                node->next->next = NULL; //then update NULL to node's next (next node address) his next =NUll

        }
    }

    void dele(list *node)
    {
        if(node == NULL)    //check is there any node or not in list if not then disply msg 
        {
            cout<<endl<<"we don't have any node we can't delete (node conataing Null) or plz create";
        }

        else{   //if we have only one node i.e. head in list then do these

                if(node->next == NULL)
                {
                    cout<<endl<<"we deleting 1st node "<<node->data;

                    free(node);         //we freeing node form list i.e. deleting 
                    head = NULL;    //then just assign head = NUll i.e. 1st node
                }

                else{       //if list containing multiple nodes then just check node's next i.e. next node it's next containg NULL or not
                        while(node-> next -> next != NULL)//untill we get null node just iterate loop
                            node= node ->next;  //then just move to next node address and assing that adrs to node
                    
                        free(node->next);       //node -> next (address of next node is freeing or deleting)
                        node ->next= NULL;          //then just assing current node by NULL

                   }

            }
    }

    void disp(list *node)
    {
        if(node == NULL)    //check is there any node or not in list if not then disply msg 
        {
            cout<<endl<<"its empty ...";
        }
        else{
                cout<<endl<<"element in the list are...";
                while(node != NULL)
                {
                    cout<<"\t"<< node->data <<" -> ";
                    node=node->next;    //for iteration on list go to next node address

                }
        }
        cout<<" NULL ";

    }





