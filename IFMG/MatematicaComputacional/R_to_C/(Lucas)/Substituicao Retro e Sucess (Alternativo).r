#install.packages('MASS')
library('MASS')
MatrizA <- matrix(c(5,0,0,0,2,3,0,0,9,2,1,0,1,2,3,5),4,4)
MatrizB <- c(1,2,3,4)
MatrizX <- solve(MatrizA,MatrizB)

MatrizX <- solve(t(MatrizA),(MatrizB))
cat(MatrizX)