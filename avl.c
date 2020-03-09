#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 20

struct avl {
	struct avl *left, *right;
	int element, height ,key;   // AVL trees node
};
//struct avl  insert(struct avl *n, int key );
//struct avl  search(struct avl number);
//struct avl  deletion(struct avl num);
//struct avl height(struct avl *h);
void preorder(struct avl *root)
{
	if(root != NULL)
	{
		printf("\n\t\t -->  %d\n" ,root->key);
		preorder(root->left);
		preorder(root->right); 
	}
}

struct avl* minimum(struct avl* node) 
{ 
  struct avl* dir = node; 

  while (dir->left != NULL) 
    dir = dir->left; 

  return dir; 
} 


int maximum(int a, int b)
{
	return (a > b ? a: b); 
}
int heightfunc(struct avl* h)
{
	if(h==NULL)
		return (0) ;
	return (h->height ) ;
}
struct avl *newnode(int key)
{
	struct avl* node = (struct avl* )malloc(sizeof(struct avl));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return (node);
}

struct avl *lr(struct avl *x)
{
	struct avl *y = x->right;
	struct avl *z = y->left;
	y->left = x;
	x->right = z;
	x->height = maximum(heightfunc(x->left), heightfunc(x->right)) + 1;
	y->height = maximum(heightfunc(y->left), heightfunc(y->right)) + 1;
	return y;
}

struct avl *rr(struct avl *y)
{
	struct avl *x = y->left;
        struct avl *z = x->right;

        x->left = y;
        y->right = z;
        x->height = maximum(heightfunc(x->left), heightfunc(x->right)) + 1;
        y->height = maximum(heightfunc(y->left), heightfunc(y->right)) + 1;
        return x;
}

int getbal(struct avl *n)
{
	if (n==NULL)
		return 0;
	return heightfunc(n->left) - heightfunc(n->right);
}

struct avl* insertN(struct avl* node, int key) 
{ 
  if (node == NULL) 
    return(newnode(key)); 

  if (key < node->key) ////key 
    node->left = insertN(node->left, key); 
  else if (key > node->key) 
    node->right = insertN(node->right, key); 
  else
    return node; 

  node->height = 1 + maximum(heightfunc(node->left), 
            heightfunc(node->right)); 

  int balanceFactor = getbal(node); 

  if (balanceFactor > 1)
  {
    if (key < node->left->key)
    {
      return rr(node);
    }
    else if (key > node->left->key)
    {
      node->left = lr(node->left);
      return lr(node);
    }
  }
  if (balanceFactor < -1)
  {
    if (key > node->right->key)
    {
      return lr(node);
    }
    else if (key < node->right->key)
    {
      node->left = rr(node->left);
      return lr(node);
    }
  }

  return node ;
}

struct avl* deleteN(struct avl* root, int key)
{

  if (root == NULL)
    return root;

  if ( key < root->key )  ////key
    root->left = deleteN(root->left, key);

  else if( key > root->key )
    root->right = deleteN(root->right, key);
  else
  {
    if( (root->left == NULL) || (root->right == NULL) )
    {
      struct avl *temp = root->left ? root->left :
                      root->right;

      if (temp == NULL)
      {
        temp = root;
        root = NULL;
      }
      else
      *root = *temp;

      free(temp);
    }
    else
    {
      struct avl* temp = minimum(root->right);

      root->key = temp->key;

      root->right = deleteN(root->right, temp->key);
    }
  }

  if (root == NULL)
  return root;

  root->height = 1 + maximum(heightfunc(root->left),
            heightfunc(root->right));

  int balanceFactor = getbal(root);

  if (balanceFactor > 1)
  {
    if (getbal(root->left) >= 0)
    {
      return rr(root);
    }
    else
    {
      root->left = lr(root->left);
      return rr(root);
    }
  }

  if (balanceFactor < -1)
  {
    if (getbal(root->right) <= 0)
    {
      return lr(root);
    }
    else
    {
      root->right = rr(root->right);
      return lr(root);
    }
  }
  return root;
}



struct avl *search(struct avl *number)
{
	if (number != 0)
	{
		printf(" ");
	}
}


void printline(int n )
{
	for(int i=0;i<n*(2-1);i++)
		printf("======");
	printf("\n");
}


int randon_acc(int oo)
{
	int i;
	for(i=1;i<10;i++)
	{
		oo = rand() % 100 + 1;
	}
	return oo;
}
void displaytre(int n)
{
	int i,j,k=0;
	printf("\nJust for FUN\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<n-i ;j++, k=0)
		{
			if(j==10 || j!=i)
				printf(" %d",                 randon_acc(j+30) ) ;
		//		printf(" 🌱🌴");
			
			else
				break;
		}
		while(k!=2*i-1)
		{

			//printf("🌴");
			++k;
			if(k!=9 || k > 6){
				//break;
//				if(k>4 || k < 15)

			}
		}
		printf("\n");
	}
}


int main()
{
	int ch,number,del ;
	struct avl *nod = NULL;
	while(1)
	{
		printline(10);
		printf("\n\t\tEnter your choice\n");
		printf("\n\t\t1.INSERTION\n\n\t\t2.DELETION\n\n\t\t3.DISPLAY() [  `PREORDER` ]\n\n\t\t4.EXIT\n\n\t\t5.Display FALLING TREE \n");
		printline(10);
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				printline(10);
				printf("\n\nEnter the Element you Want to Enter\n");
				scanf("%d", &number);
				printline(10);
				nod  = insertN(nod , number);
				printf("\n\t\tTREE \n");
				preorder(nod);
				break;
			case 2 :
				printf("Enter NUmber To Remove() \n");
				scanf("%d", &del);
			       	printline(10);
		       		deleteN(nod,  del );
		 		preorder(nod);		
				printf("\n");
				break;
			case 3:
				printline(10);
				printf("\n\t\t\tAVL TREES LIST\n");
				preorder( nod );
				printline(10);
				break;
			case 5: displaytre(20);
				break;
			case 4: printf("\n\t\t[  BYE ]  \n\t\t[ Thank you ] \n");
			       	exit(EXIT_FAILURE);
			default :
				printline(5);
				printf("You Enter the Wrong Option\n ");
				printline(5);
		}
		 //char *chh;
		 //chh = (char *) malloc(sizeof(ch));
		//if(ch != isdigit(chh) )
		//	break;
	}
	
	
}
