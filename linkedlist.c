#include<stdio.h>
#include<stdlib.h>
struct node
{ 
     int data;
     struct node* next;
}*head=NULL;
// the function to insert at front
void insertfront(int item){
    struct node* new;
    new=(struct node*)malloc(sizeof(struct node));               //syntax to dynamically allocate memory for a new node
    new->data=item;
    if(head==NULL){
          head=new;
          new->next=NULL;
    }
    else{
           new->next=head;
           head=new;
    }
}
// the function to insert at the back of a linked list
void insertback(int item){
          struct node*new_node=(struct node*)malloc(sizeof(struct node));
          new_node->data=item;
          if(head==NULL){
                 head=new_node;
          }
          else{
                  struct node* ptr=head;
                  while(ptr->next!=NULL){
                         ptr=ptr->next;
                  }
                 ptr->next=new_node;
                 new_node->next=NULL;
          }

}
// function to insert at a after a particular position position
void insertafter(int item, int pos){
       struct node* ptr=head;
       while(ptr->data!=pos){
               ptr=ptr->next;
               
       }
       if(head==NULL){
                 printf("the list is empty\n");
       }
       else{
              struct node* new;
              new=(struct node*)malloc(sizeof(struct node));
              new->next=ptr->next;
              ptr->next=new;
              new->data=item;
       }


       }

// function to display before a linked list
void insertbefore(int item, int pos){
        if(head==NULL){
               printf("the list is empty\n");
               return;
        }
        else{
               struct node*ptr=head;
               struct node* new=(struct node*)malloc(sizeof(struct node));
               while(ptr->next->data!=pos){
                         ptr=ptr->next;
               }
               new->next=ptr->next;
               ptr->next=new;
               new->data=item;
        }
}
//function to delete from the front
void deletef(){
         if(head==NULL){
              printf("the list is empty");
         }

         else{
                  struct node* temp=head;
                  head=head->next;
                  free(temp);

         }
}

//function to delete from back
void deleteb(){
       if(head==NULL){
               printf("the list is empty");

       }
       else if(head->next==NULL){
              head=NULL;
              free(head);
       }
       else{
               struct node*temp;
               struct node*ptr=head;
               while(ptr->next!=NULL){
                        temp=ptr;
                        ptr=ptr->next;
               }
               temp->next=NULL;
               
               free(ptr);

       }
}

// function to delete a particular element
void deleteany(int pos){
        
        if(pos==0){
                     deletef();
        }
        else{
                
                        struct node*prev=NULL;
                        struct node*temp=head;
                for(int i=0;i<pos;i++){
                     prev=temp;
                     temp=temp->next;
                        
                }
                if(temp==NULL){
                        printf("the position does not exist\n");

                }
                else if(temp->next==NULL){
                       deleteb();

                }
                else if(head==NULL){
                         printf("the list is empty\n");
                          

                }
                else{
                         prev->next=temp->next;
                         free(temp);
                }
                }
        }
           
       

 

//the function to display a linked list
void display(){
     
         struct node* ptr=head;
         if(head==NULL){
                
                    printf("the list is empty\n");
                    return;
         }
       else{
                    while (ptr!=NULL)
                    {
                        printf("%d\t",ptr->data);
                        ptr=ptr->next;
                    }
                    
       }
}
// the main function
void main(){
      int choice,i=0,item1,pos1;
      printf("===== LINKED LIST =====\n");
      while(i!=13){
      printf("\nthe operations are \n 1.insert at front\n 2.insert at the back\n 3.insert after a particular element \n 4.insert before an element\n 5.delete from front\n 6.delete from back\n 7.delete from anywhere\n 8.display\n 9.exit\n");
      scanf("%d",&choice);
      switch(choice){
           case 1:
                      printf("enter the element to be inserted\n");
                      scanf("%d",&item1);
                      insertfront(item1);
                      break;
            case 2:
                    printf("enter the element to be inserted\n");
                    scanf("%d", &item1);
                    insertback(item1);
                    break;

            case 3:
                       printf("enter the element to be inserted\n");
                       scanf("%d",&item1 );
                       printf("\nenter the element after which the insertion should take place\n");
                       scanf("%d", &pos1);
                       insertafter(item1,pos1);
                       break;

            case 4:
                       printf("enter the element to be inserted\n");
                       scanf("%d", &item1);
                       printf("enter the element before which the insertion should take place\n");
                       scanf("%d", &pos1);
                       insertbefore(item1,pos1);
                       break;

             case 5:
                       deletef();   
                       break; 

             case 6:
                            deleteb();
                            break;  

             case 7: 
                          printf("enter the position to be deleted given that the index starts from 0\n");
                          scanf("%d", &pos1);
                          deleteany(pos1);
                          break;                                        

            case 8:

                      display();
                      break;          
            case 9:
                       printf("exiting the program\n");
                       i=13;
                       break;
                       
              
        
      }
      }
}
