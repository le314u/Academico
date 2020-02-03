#install.packages('MASS')
library('MASS')

GausPivoteamento <- function(MatrizA,MatrizB){
	#Inicialização
	TamanhoDoVetor <- length(MatrizB) 
	VetorSwapA <- rep(c(NaN),TamanhoDoVetor)
	VetorSwapB <- NaN;

	#Vai da Primeira Até a penultima linha zerando-as
	for (Pivo in 1:(TamanhoDoVetor - 1)) {
		IndiceMaior <- Pivo;
		Maior <- MatrizA[Pivo,Pivo];

		#Faz As Trocas da linha Pivo
		for (SwapIndice in (Pivo):(TamanhoDoVetor)) {			
			if(SwapIndice == Pivo){
				next;
			}else{
				if(abs(Maior)<abs(MatrizA[SwapIndice,Pivo])){
					IndiceMaior <- SwapIndice
					Maior <- MatrizA[SwapIndice,Pivo]

				}
			}
		}		
		#Swap A
		VetorSwapA <- MatrizA[Pivo,]		
		MatrizA[Pivo,] <- MatrizA[IndiceMaior,]		
		MatrizA[IndiceMaior,] <- VetorSwapA

		#Swap B
		VetorSwapB <- MatrizB[Pivo]		
		MatrizB[Pivo] <- MatrizB[IndiceMaior]		
		MatrizB[IndiceMaior] <- VetorSwapB

		print(MatrizA)

		for (LinhaTrabalhada in (Pivo+1):(TamanhoDoVetor)) {
			Escalar <- MatrizA[LinhaTrabalhada,Pivo] /MatrizA[Pivo,Pivo]
			for (Coluna in 1:TamanhoDoVetor) {
				MatrizA[LinhaTrabalhada,Coluna] <- MatrizA[LinhaTrabalhada,Coluna]-(Escalar*MatrizA[Pivo,Coluna])
			}
			MatrizB[LinhaTrabalhada]<-MatrizB[LinhaTrabalhada]-(Escalar*MatrizB[Pivo])
		}
	}
	return (list("Matriz"=MatrizA,"Vetor"=MatrizB))
}

SubsRetro <- function(MatrizA,VetorB,Tamanho){
	MatrizX <- rep(NA,Tamanho)
	MatrizX[Tamanho] <- VetorB[Tamanho]/MatrizA[Tamanho,Tamanho]
	for(k in (Tamanho-1):1){
		
		Somatorio <- 0
		for(j in (k+1):Tamanho){
			Somatorio <-Somatorio+MatrizA[k,j]*MatrizX[j]
		}
		MatrizX[k] <- (VetorB[k]-Somatorio)/MatrizA[k,k]
	}
	return(MatrizX)
}

#Define as Matrizes
MatrizA <- matrix(c(4,4,4,1,3,1,2,6,3),3,3)
MatrizB <- c(59,97,66)
MatrizA


Triangular <- GausPivoteamento(MatrizA,MatrizB);
Resultado <- SubsRetro(Triangular$Matriz,Triangular$Vetor,length(MatrizB));

Resultado

