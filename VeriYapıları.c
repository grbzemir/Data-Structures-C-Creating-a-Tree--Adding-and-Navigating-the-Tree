#include<stdlib.h>
#include<stdio.h>

struct agac

{
    int veri;
    struct agac *SolBag;
    struct agac *SagBag;

};

typedef struct agac node; // takma ad verdik!

node *agacEkle(node *agac, int x) // int x ekleyeceğimiz değer!

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

int main()

{
    system("color 0a");

    node *kok = NULL;

    kok = agacEkle(kok, 10);
    kok = agacEkle(kok, 20);
    kok = agacEkle(kok, 30);
    kok = agacEkle(kok, 40);
    kok = agacEkle(kok, 50);
    kok = agacEkle(kok, 60);
    kok = agacEkle(kok, 70);
    kok = agacEkle(kok, 80);
    kok = agacEkle(kok, 90);

    Dolas(kok);

    return 0;
    
}
