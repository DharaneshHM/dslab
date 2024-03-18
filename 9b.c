#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node     
{
int coef, px, py, pz,flag;
struct node *link;
};
typedef struct node * NODE;
NODE create_list(NODE head) 
{
int i,n,cf,px,py,pz;
printf("Enter the number of terms : ");
  scanf("%d",&n);54
for(i=1;i<=n;i++)
{
printf("Enter the Co-ef, px, py, pz : ");
scanf("%d %d %d %d",&cf,&px,&py,&pz);
insert(head,cf,px,py,pz);
}
return head;
}/*End of create_list()*/
insert(NODE head,int cof,int x,int y, int z) //inserting term to poly
{
NODE cur,tmp;
tmp= (NODE)malloc(sizeof(struct node)); 
  int cf,px,py,pz; cur=head->link;
tmp->coef=cof;
tmp->px=x;
tmp->py=y;
tmp->pz=z;
tmp->flag=0;
while(cur->link!=head) 
cur=cur->link;
cur->link=tmp;
tmp->link=head;
}
NODE add_poly(NODE h1,NODE h2,NODE h3)
{
NODE cur1,cur2,scf; 
  cur1=h1->link;
  cur2=h2->link;
while(cur1 != h1) 
if(cur2 == h2)
cur2=h2->link;
while(cur2 != h2) 
{
if(cur1->px == cur2->px && cur1->py == cur2->py && cur1->pz == cur2->pz) 
{          
scf = cur1->coef + cur2->coef;
  insert(h3,scf,cur1->px,cur1->py,cur1->pz);
  cur2->flag=1;55
cur2=h2->link;
  break;
}
cur2=cur2->link;
}
if(cur1 == h1)
break;
if(cur2 == h2)  
  insert(h3,cur1->coef,cur1->px,cur1->py,cur1->pz);
cur1=cur1->link;
}
cur2=h2->link;
while(cur2 != h2) 
{
if(cur2->flag==0)
insert(h3,cur2->coef,cur2->px,cur2->py,cur2->pz);
cur2=cur2->link;
}
return h3;
}
void display(NODE head)
{
NODE cur;
if(head->link==head) //if poly is empty
{
printf("List is empty\n"); return;
}
cur=head->link;
while(cur != head) //display all terms till end
{
if(cur->coef > 0)
printf(" +%dx^%dy^%dz^%d ",cur->coef,cur->px,cur->py,cur->pz); 
else if (cur->coef < 0)
printf(" %dx^%dy^%dz^%d ",cur->coef,cur->px,cur->py,cur->pz); 
  cur=cur->link;
}
printf("\n");
}
void main()
{
int choice,data,item,pos; NODE head1,head2,head3; head1=(NODE)malloc(sizeof(struct node));
head1->link=head1;
//poly1
head2=(NODE)malloc(sizeof(struct node));
head2->link=head2;
//poly2
head3=(NODE)malloc(sizeof(struct node));
//poly3
head3->link=head3;
printf("\n1.Create Polynomial 1\n"); 
  head1=create_list(head1);
printf("\n2.Create Polynomial 2\n");
  head2=create_list(head2);
printf("\nPolynomial 1 is :");
  display(head1);
printf("\nPolynomial 2 is :"); 
  display(head2);
head3=add_poly(head1,head2,head3);
printf("\nAddition of two Polynomial is :");
  display(head3);
}
