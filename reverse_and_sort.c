#include<stdio.h>
#include<stdlib.h>
struct node{                                      // structure for a node
        int data;
        struct node* next;                  
}*head=NULL;
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
//function to reverse a linked list
void reverse(){
      if(head==NULL){
            printf("list is empty\n");
      }
      else{
        struct node*prev=NULL;
        struct node* current=head;
        struct node* next_node=head;
        while(next_node!=NULL){
              next_node=next_node->next;
              current->next=prev;
              prev=current;
              current=next_node;
        }
         head=prev;
        
       }
}
// the function to sort a linked list in ascending order
void sort(){
          int temp;
         if(head==NULL){
                 printf("the list is empty\n");

         }
         else{
                  struct node*current=head;
                  struct node*index=NULL;
                  while(current!=NULL){
                         index=current->next;
                  
                           while(index!=NULL){
                           if(current->data>index->data){
                                temp=current->data;
                                current->data=index->data;
                                index->data=temp;

                     }
                     index=index->next;
                  }
                  current=current->next;
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
//main function
void main(){
        int choice,item1,i=0;
        printf("===== REVERSING AND SORTING A LINKED LIST\n");
        printf("for convinience insertion only takes place at the back\n");
        while(i!=13){
        printf("\nthe operations are\n 1.INSERT \n 2.REVERSE \n 3.SORT \n 4.DISPLAY \n 5.EXIT\n ");
        printf("enter the option\n");
        scanf("%d", &choice);
        switch(choice){
             case 1:
                          printf("enter the element to be inserted\n");
                    scanf("%d", &item1);
                    insertback(item1);
                    break;

            case 2:
                        reverse();
                        break;

             case 3:
                        sort();
                        break;           

            case 4:
                      display();
                      break;

           case 5: 
                      printf("EXITING THE PROGRAM!");
                      i=13;

        }
        }



}