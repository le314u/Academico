Binarização Adaptativa ocorre por meio de kernels ou seja uma matriz de convolução de dimensões impares que passara por cima da imagem de origem e gera um pixel na imagem destino.
Se imaginariamente  tivermos 3 camadas sobrepostas:
1º imagem origem
2º kernel 
3º imagem de destino

o kernel vai se movimentando por toda a imagem fazendo os calculos necessários adotando todos os pixes que estão 'a baixo dele na 1º camada < imagem original> e joga a saida para o pixel da 3º camada que esta em cima do pixel central do kernel.


O efeito do filtro gaussiano é suavizar (smoothing ou blur) a imagem. O resultado será tão mais
suave quanto maior o desvio padrão ( standard deviation) da Gaussiana usada.
Desvios padrões maiores também fazem com que a máscara ( convolution kernels) deva ser maior para uma representação adequada.


Por não ter todos os pesos iguais como o filtro de média, o filtro Gaussiano faz uma
suavização mais delicada (gentler smoothing) preservando mais os contornos que o
de média.
Uma das melhores justificativas para seu uso e seu melhor desempenho se
relaciona com sua resposta no dominio das frequências (frequency response).
A maioria dos filtros de suavização (o de mediana é uma exceção) é baseado na
convolução, agindo como passa baixa no domínio das freqüências (lowpass
frequency filters) . Isso significa que removem freqüências espaciais depois de um
certo valor.


Fontes:
http://www.ic.uff.br/~aconci/gabor.pdf
http://professor.luzerna.ifc.edu.br/ricardo-antonello/wp-content/uploads/sites/8/2017/02/Livro-Introdu%C3%A7%C3%A3o-a-Vis%C3%A3o-Computacional-com-Python-e-OpenCV.pdf
https://www.youtube.com/watch?v=mSb_rGWfeWM 