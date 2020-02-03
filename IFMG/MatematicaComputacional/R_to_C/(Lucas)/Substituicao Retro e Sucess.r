#install.packages('MASS')
library('MASS')

SubsRetro <- function(MAtrizA,MatrizB,Tamanho){
	MatrizX <- rep(NA,Tamanho)
	MatrizX[Tamanho] <- MatrizB[Tamanho]/MatrizA[Tamanho,Tamanho]
	for(k in (Tamanho-1):1){
		Somatorio <- 0
		for(j in (k+1):Tamanho){
			Somatorio <-Somatorio+MatrizA[k,j]*MatrizX[j]
		}
		MatrizX[k] <- (MatrizB[k]-Somatorio)/MatrizA[k,k]
	}
	return(MatrizX)
}

SubsSucess <- function(MAtrizA,MatrizB,Tamanho){
	print(MatrizA)
	MatrizX <- rep(NA,Tamanho)
	MatrizX[1] <- MatrizB[1]/MatrizA[1,1]
	for(k in 2:Tamanho){
		Somatorio <- 0
		cat("Laço")
		for(j in (1):(k-1)){
			Somatorio <-Somatorio+MatrizA[k,j]*MatrizX[j]
		cat("Somatorio",Somatorio)
		}
		cat("Somatorio",Somatorio)
		cat("\n")
		MatrizX[k] <- (MatrizB[k]-Somatorio)/MatrizA[k,k]
	}
	return(MatrizX)
}

MatrizA <- matrix(c(5,0,0,0,2,3,0,0,9,2,1,0,1,2,3,5),4,4)
MatrizA<-t(MatrizA)
MatrizB <- c(1,2,3,4)

cat(SubsSucess(t(MatrizA),(MatrizB),4))


MatrizA <- matrix(c(1,0,0,0,0,0,3,2,0,0,0,0,5,3,1,0,0,0,10,5,1,1,0,0,exp(1),0,pi,2,1,0,2,1,1,logb(3),10,5),6,6)
MatrizB <- c(1,2,3,2,1,2)
#fractions(SubsRetro(MatrizA,MatrizB,4))


