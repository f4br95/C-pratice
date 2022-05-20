#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

typedef struct {
  int Chave;
  char Nome[30];
  /* outros componentes */
} TipoItem;

typedef struct TipoCelula *TipoApontador;

typedef struct TipoCelula {
  TipoItem Item;
  TipoApontador Prox;
} TipoCelula;

typedef struct {
  TipoApontador Fundo, Topo;
  int Tamanho;
} TipoPilha;








void FPVazia(TipoPilha *Pilha)
{ Pilha->Topo = (TipoApontador) malloc(sizeof(TipoCelula));
  Pilha->Fundo = Pilha->Topo;
  Pilha->Topo->Prox = NULL;
  Pilha->Tamanho = 0;
} 









int Vazia(TipoPilha Pilha)
{ 
	return (Pilha.Topo == Pilha.Fundo); 
} 








void Empilha(TipoItem x, TipoPilha *Pilha)
{ 
	TipoApontador Aux;
  	Aux = (TipoApontador) malloc(sizeof(TipoCelula));
  	Pilha->Topo->Item = x;
 	Aux->Prox = Pilha->Topo;
 	Pilha->Topo = Aux;
 	Pilha->Tamanho++;
} 









void Desempilha(TipoPilha *Pilha, TipoItem *Item)
{ 
	TipoApontador q;
  int g;
  if (Vazia(*Pilha)) 
  { 
    printf("Erro: lista vazia\n"); 
    g = getchar();

    return; 
  }
  q = Pilha->Topo;
  Pilha->Topo = q->Prox;
  *Item = q->Prox->Item;
  free(q);  
	Pilha->Tamanho--;
} 








int Tamanho(TipoPilha Pilha)
{ 
	return (Pilha.Tamanho); 
} 


void Imprimir(TipoPilha Pilha)
{
  	TipoApontador p;
  	p = Pilha.Topo;
	printf("---------------------------- TOPO DA PILHA -------------------------------\n\n");
	while (p->Prox)
	{
		p = p->Prox;
    	printf("Chave = %d\n", p->Item.Chave);
    	printf("Nome  = %s\n\n", p->Item.Nome);
        
    	
    	
    }
    printf("---------------------------- FIM DA PILHA --------------------------------");
}

  	


int menu();


int main(int argc, char *argv[])
{ 
  TipoPilha pilha, pilha2;
  TipoItem item, item2;
  
  int c, opcao=0;
  char aux[30];

 
  FPVazia(&pilha);
  
  do {
        opcao = menu();

        switch(opcao)
        {
            case 1:
                system("clear");
                printf("Digite valor para empilhar: ");
                __fpurge(stdin);
                scanf("%d", &item.Chave );      
                printf("Digite um nome para vincular na chave digitada: ");
                __fpurge(stdin);
                gets(&item.Nome);                                  
                Empilha(item, &pilha);
                printf("Empilhou: %d \n", item.Chave);            
                
                printf("\n\nPressione enter para continuar!!");
                c = getchar();
                system("clear");
                
            break;
            case 2: 
                system("clear");
                printf("Desempilhar a pilha: \n");        
                Desempilha (&pilha,&item);                
                printf("Desempilhou: %d \n", item.Chave);            
                printf("Tamanho da pilha: %d\n", Tamanho(pilha));
                printf("\n\nPressione enter para continuar!!\n");
                c = getchar();
                system("clear");
                break;      
            case 3:
                system("clear");         
                Imprimir(pilha);
                printf("\n\nPressione enter para continuar!!\n");
                c = getchar();                
                break;
            case 4:
                system("clear");
                Desempilha (&pilha,&item);
                item2 = item;
                Desempilha (&pilha,&item);
                Empilha(item2, &pilha);
                Empilha(item, &pilha);
                
                 
                printf("Elementos do topo trocados \n\n"); 
                c = getchar();    
                break;      
            
            default:
                system("clear");
                printf("\n\nOpcao invalida!");
                c = getchar();
        }

  }  while(opcao!=5);
  
 
    return(0);
}

int menu()
{
  { 
        int opcao=0;
        printf("1- Empilhar valor \n");
        printf("2- Desempilhar valor \n");
        printf("3- Imprimir toda a pilha\n");
        printf("4- Trocar elementos do topo\n");
        printf("5- Sair \n");        
        scanf("%d", &opcao);
        return opcao;
}
}