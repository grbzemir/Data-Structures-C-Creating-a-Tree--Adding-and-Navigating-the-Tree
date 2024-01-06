#include<stdlib.h>
#include<stdio.h>

struct agac

{
    int veri;
    struct agac *SolBag;
    struct agac *SagBag;

};

typedef struct agac node; // takma ad verdik!

node *agacEkle(node *agac, int x) // int x ekleyeceÄŸimiz deÄŸer!

{
    if (agac == NULL)
    
    {
    	
        node *agac = (node *)malloc(sizeof(node));
        agac->veri = x;
        agac->SolBag = NULL;
        agac->SagBag = NULL;
        return agac;
    }
    

    if (agac->veri > x)
    
    {
    	
        agac->SolBag = agacEkle(agac->SolBag, x);
    }

    else
    
    {
    	
        agac->SagBag = agacEkle(agac->SagBag, x);
    }

    return agac;
}

void Dolas(node *agac)

{
    if (agac == NULL)
    
    {
    	
        return;
        
    }

    Dolas(agac->SolBag);
    printf("%d ", agac->veri);
    Dolas(agac->SagBag);
    
}

int maksimum(node *agac) 
{

    while(agac->SagBag != NULL) // saÄŸa gidiyoruz!
    
    {
    	
        agac = agac->SagBag;
        
    }

    return agac->veri;


}

int minimum(node *agac)

{
    while(agac->SolBag !=NULL)

    {
        agac = agac->SolBag;
    }

    return agac->veri;
}


node *sil(node *agac,int silinen)
{
	if(agac==NULL)
		return NULL;

	if(agac->veri==silinen)
    {

		if(agac->SagBag==NULL&&agac->SolBag==NULL)

			return NULL;

			}

			if(agac->SagBag!=NULL)

            {
				agac->veri=minimum(agac->SagBag);
				agac->SagBag=sil(agac->SagBag,minimum(agac->SagBag));
				return agac;

			}

			agac->veri=maksimum(agac->SolBag);
			agac->SolBag=sil(agac->SolBag,maksimum(agac->SolBag));
			return agac;

   if(agac->SagBag <silinen)

   {

	agac->SagBag=sil(agac->SagBag,silinen);
	return agac;

   }

   agac->SolBag=sil(agac->SolBag,silinen);
   return agac;

   }


int main()

{
    system("color 0a");

    node *agac = NULL;

    agac = agacEkle(agac, 10);
    agac = agacEkle(agac, 20);
    agac = agacEkle(agac, 30);
    agac = agacEkle(agac, 40);
    agac = agacEkle(agac, 50);
    agac = agacEkle(agac, 60);
    agac = agacEkle(agac, 70);
    agac = agacEkle(agac, 80);
    agac = agacEkle(agac, 90);

    printf("\n");
    printf("Maksimum Deger: %d\n", maksimum(agac));
    printf("Minimum Deger: %d\n", minimum(agac));   
    agac = sil(agac, 10);
    Dolas(agac);
    printf("\n");
    agac = sil(agac, 30);
    Dolas(agac);
    agac = sil(agac , 40);
    printf("\n");
    Dolas(agac);



    return 0;
    
}
