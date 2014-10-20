#include <stdio.h>


 void affichage(int t[],int n)
  {
      int i;
    for (i=0;i<=n-1;i++)
    {
       printf("\t tab[%d]= %d \n",i,t[i]) ;
    }
  }
  void trie_selection_croi(int t[],int n)
  {
      int i,posmin,aux,j;
       for(i=0;i<=n-2;i++)
   {
       posmin=i;
      for(j=i+1;j<=n-1;j++)
      {
        if(t[j]<t[posmin])

            posmin=j;
      }
        aux=t[posmin];
        t[posmin]=t[i];
        t[i]=aux;
   }

  }
void trie_selection_decroi(int t[],int n)
{
    int i,posmax,aux,j;
     for(i=0;i<=n-2;i++)
     {
       posmax=i;
      for(j=i+1;j<=n-1;j++)
      {
        if(t[j]>t[posmax])

            posmax=j;
      }
        aux=t[posmax];
        t[posmax]=t[i];
        t[i]=aux;
    }

}
void trie_insertion_croi(int t[],int n)
{
    int i,j,x;
    for(i=1;i<=n-1;i++)
  {
      x=t[i];
      j=i;
      while((j>0) &&(t[j-1]>x))
      {
        t[j]=t[j-1];
        j=j-1;
      }
      t[j]=x;
  }

}
void trie_insertion_decroi(int t[],int n)
{
    int i,j,x;
    for(i=1;i<=n-1;i++)
  {
      x=t[i];
      j=i;
      while((j>0) &&(t[j-1]<x))
      {
        t[j]=t[j-1];
        j=j-1;
      }
      t[j]=x;
  }

}
int testtrie(int tab[] , int n)
{
    int k=0 ,i;

   for(i=0;i<=n-1;i++)
     {if(tab[i]< tab[i+1])
        k++;

     }

     if(k==n)

        return(1);

     else

          return(0);

}
void trie_bulle_croi(int t[],int n)
{
    int taille,i,temp;
taille=n;

while((testtrie(t,n)==0)&&(taille>=2))
{
    for(i=0;i<=taille-2;i++)
    {
        if(t[i]<t[i+1])
        {
            temp=t[i];
            t[i]=t[i+1];
            t[i+1]=temp;
        }
    }
    taille=taille-1;
}

}
void trie_bulle_decroi(int t[],int n)
{
    int taille,i,temp;
taille=n;

while((testtrie(t,n)==0)&&(taille>=2))
{
    for(i=0;i<=taille-2;i++)
    {
        if(t[i]<t[i+1])
        {
            temp=t[i];
            t[i]=t[i+1];
            t[i+1]=temp;
        }
    }
    taille=taille-1;
}

}
 main()
 {
          int x,n;
          int choix;
          int s;
          printf(" \n                             Bienvenu                                       \n");
          printf("********************************************************************************\n");
          printf("donner le nb de case:");
          scanf("%d",&n);

          int t[n];
             int i;
         for(i=0;i<=n-1;i++)
         {
          printf("Donnez t[%d]= \t",i);
          scanf("%d",&t[i]);
         }

          affichage(t,n);
      do
      {

          printf("\n");

          printf("Que voulez vous faire? \n");
          printf("\n");
          printf("       1) trie selection croissant:\n");
          printf("       2) trie selection décroissant:\n");
          printf("       3) trie insertion croissant:\n");
          printf("       4) trie insertion decroissant:\n");
          printf("       5) trie a bulle croissant   :\n");
          printf("       6) trie a bulle decroissant   :\n");

          printf("\n Tapez votre choix :");
         do
         {
            scanf("%d",&choix);
            printf("\n");

         }while(( choix<1)||(choix>6)) ;


         switch(choix)
	     {

	          case 1:trie_selection_croi(t,n);
              affichage(t,n);
              break;
              case 2:trie_selection_decroi(t,n);
              affichage(t,n);
              break;
              case 3:trie_insertion_croi(t,n);
              affichage(t,n);
              break;
              case 4:trie_insertion_decroi(t,n);
              affichage(t,n);
              break;
              case 5:trie_bulle_croi(t,n);
              affichage(t,n);
              break;
              case 6:trie_bulle_decroi(t,n);
              affichage(t,n);
         }
         printf("terminer o (oui)\\n (non) : \n ");
         scanf("%d",&s);
      }while(s!=0);
}

