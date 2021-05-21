struct nodecirc
{
  int val;
  struct nodecirc *next;
};
struct nodecirc *empezar = NULL;
struct nodecirc *test = NULL;
struct nodecirc *create_cll(struct nodecirc *, int jugadores);
struct nodecirc *create_cll(struct nodecirc *empezar)
{
  int num = 0;
 struct nodecirc *new_node, *ptr;
while(num<4)
{
 new_node = (struct nodecirc*)malloc(sizeof(struct nodecirc));
 new_node -> val = num;
 if(empezar == NULL)
 {
 new_node -> next = new_node;
 empezar = new_node;
 }
 else
 { ptr = empezar;
 while(ptr -> next != empezar){
 ptr = ptr -> next;}
 ptr -> next = new_node;
 new_node -> next = empezar;
 }
 num++;
 delay(10);
}
return empezar;
}
