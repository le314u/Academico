#ifndef Check
#define Check

void Main_Transacoes(){
	int Opcao=0;
	do{
		printf("\n");
		printf("\nDigite um numero referente a açao:");
		scanf("%d",&Opcao);
	}while(Opcao<0);

	switch (Opcao)
	{
		case 1:
		break;

	}
}





void Checkin(){
	int Reserva=0,Loop=1,Check=0;
	int Configuracao=Configuracoes();

	while(Loop){
		printf("Digite o codigo da reserva:\n");
		scanf("%d",&Reserva);

	}

	do{
		printf("\nSe quer pagar na Entrada ou Saida digite o respecitivo codigo:\n");
		Verde("1")
		printf(" para ");
		Verde("Entrada\n")
		Vermelho("2")
		printf(" para ");
		Vermelho("Saida\n")
		scanf("%d",&Check);
	}while(Check<1 || Check>2);


	


}

#endif