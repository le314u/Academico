#Testar Equivalencia
import automata
#########################################################3
##
##      Sala de Aulas
##
#########################################################3
afS1 = automata.Automata()
v1 = afS1.addState(name="1",initial=True, final=True)
v2 = afS1.addState(name="2", initial=False, final=False)
v3 = afS1.addState(name="3", initial=False, final=False)
v4 = afS1.addState(name="4", initial=False, final=False)
v5 = afS1.addState(name="5", initial=False, final=False)
v6 = afS1.addState(name="6", initial=False, final=False)
afS1.addTransition(v1, 'a', v1)
afS1.addTransition(v1, 'b', v2)
afS1.addTransition(v2, 'b', v4)
afS1.addTransition(v2, 'a', v3)
afS1.addTransition(v3, 'a', v5)
afS1.addTransition(v3, 'b', v6)
afS1.addTransition(v4, 'a', v1)
afS1.addTransition(v4, 'b', v2)
afS1.addTransition(v5, 'a', v3)
afS1.addTransition(v5, 'b', v4)
afS1.addTransition(v6, 'a', v5)
afS1.addTransition(v6, 'b', v6)

#Aceita  a(aa)*
afS2 = automata.Automata()
v1 = afS2.addState(name="1",initial=True,final=False)
v2 = afS2.addState(name="2",initial=False, final=True)
afS2.addTransition(v1, 'a', v2)
afS2.addTransition(v1, 'b', v1)
afS2.addTransition(v2, 'a', v1)
afS2.addTransition(v2, 'b', v2)

#Aceita  (bb)*
afS3 = automata.Automata()
v1 = afS3.addState(name="1",initial=True, final=True)
v2 = afS3.addState(name="2",initial=False, final=False)
afS3.addTransition(v1, 'b', v2)
afS3.addTransition(v1, 'a', v1)
afS3.addTransition(v2, 'b', v1)
afS3.addTransition(v2, 'a', v2)


afS4 = automata.Automata()
v1 = afS4.addState(name="1",initial=True, final=False)
v2 = afS4.addState(name="2",initial=False, final=False)
v3 = afS4.addState(name="3",initial=False, final=True)
v4 = afS4.addState(name="4",initial=False, final=False)
afS4.addTransition(v1, 'aab', v2)
#afS4.addTransition(v2, 'ab', v2)
afS4.addTransition(v2, 'abb', v3)
afS4.addTransition(v3, '', v1)
afS4.addTransition(v3, 'aba', v3)
afS4.addTransition(v3, '', v4)
afS4.addTransition(v4, '', v2)
afS4.addTransition(v4, 'ba', v2)
afS4.addTransition(v4, 'b', v4)

avaliacao1 = False
avaliacao2 = False
avaliacao3 = True

if(avaliacao1 == True):

    print("\n\nAVALIAÇÃO 1\n\n")

    print("ESTADOS EQUIVALENTES")
    print(afS1.stateEquivalent(),"\n")

    afMin = afS1.minimize()
    print("Minimização",afMin,"\n")

    print("Equivalentes:",afMin.equivalence(afS1))

if(avaliacao2 == True):

    print("\n\nAVALIAÇÃO 2\n\n")

    mult = afS2.multiplica(afS3)
    print("Multiplicação \n",mult,"\n")

    int = afS2.intercession(afS3)
    print("Interceção \n",int,"\n")

    uni = afS2.union(afS3)
    print("Uniao \n",uni,"\n")

    dif1 = afS2.diference(afS3)
    print("Diferença 1-2 \n",dif1,"\n")

    dif2 = afS3.diference(afS2)
    print("Diferença 2-1 \n",dif2,"\n")

    neg = afS3.inverter()
    print("Negação \n",neg,"\n")


if(avaliacao3 == True):
        
    print("\n\nAVALIAÇÃO 3\n\n")
    afn1 = afS4.convAFextended2AFN()
    print("AFex -> AFNlambda \n",afn1,"\n")

    afn2 = afn1.convAFLambda2AFN()
    print("AFlamb -> AFN \n",afn2,"\n")

    afd = afn2.convAFN2AFD()
    print("AFN -> AFD \n",afd,"\n")    
    
    print("\n\n",afd.minimize(),"\n")
    
    int = afS2.intercession(afS3)
    print("AFD -> ER",afS2.convAFD2ER())
