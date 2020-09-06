#!/bin/bash

aux=($@)

declare soma=0
declare mult=1

for (( i=0; i<${#aux[@]}; i++ ))
do
	soma=$(echo "$soma + ${aux[$i]}" | bc)
	mult=$(echo "$mult * ${aux[$i]}" | bc)
#	soma=$[ $soma + ${aux[$i]} ]
#	mult=$[ $mult * ${aux[$i]} ]		
	
done

echo "Soma = $soma, Mult = $mult"

