#install.packages('MASS')
library('MASS')

Gaus <- function(MatrizA,MatrizB){
	TamanhoDoVetor <- length(MatrizB) 
	for (Pivo in 1:(TamanhoDoVetor - 1)) {
		for (LinhaTrabalhada in (Pivo+1):(TamanhoDoVetor)) {
			Escalar <- MatrizA[LinhaTrabalhada,Pivo] /MatrizA[Pivo,Pivo]
			for (Coluna in 1:TamanhoDoVetor) {
				MatrizA[LinhaTrabalhada,Coluna] <- MatrizA[LinhaTrabalhada,Coluna]-(Escalar*MatrizA[Pivo,Coluna])
			}
			MatrizB[LinhaTrabalhada]<-MatrizB[LinhaTrabalhada]-(Escalar*MatrizB[Pivo])
		}
	}
	return (MatrizA)
}

MatrizA <- matrix(c(1,3,1,5,6,19,4,33,2,4,8,9,4,15,-12,3),4,4)
MatrizB <- c(8,25,18,72)

Triangular <- Gaus(MatrizA,MatrizB)

print(MatrizA)
print(Triangular)