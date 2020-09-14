#        ; Se primeira Fita == 0
#        0100 Z 1 i -- 1001 Z 1 i      ; 0+1 = 1
#        0100 Z 9 i -- 1009 Z 9 i      ; 0+9 = 9
#        ; Se primeira Fita == 0     +1 flutuando
#        0110 Z 0 i -- 1001 Z 0 i      ; 0+0+1 = 1
#        0110 Z 9 i -- 1010 Z 9 i      ; 0+9+1 = 10

def soma():
    for rw in [0]:
        for tape in [1]:
            for oldRead in range(0,10):# Tem digito flutuante
                for buff in [0,1]:# Tem digito flutuante
                    for newRead in range(0,10):# Tem digito flutuante
                        zero=''
                        if(oldRead+newRead+buff < 10 ):
                            zero="0"
                        else:
                            zero=""
                        estadoA=str(rw)+str(tape)+str(buff)+str(oldRead)
                        estadoB="10"+zero+str(oldRead+newRead+buff)
                        print(
                            estadoA,
                            "Z",
                            newRead,
                            "i",
                            "--",
                            estadoB,
                            "Z",
                            newRead,
                            "i",
                            "\t; ",str(oldRead),"+",str(buff),"+",str(newRead),"=",str(oldRead+newRead+buff)
                        )
                print('\n')

#0000 Z 0 i -- 0100 Z 0 e
def compareDigits():
    for tape in ['Y','Z']:
        for number1 in range(0,10):
            for number2 in range(0,10):
                if(tape == 'Y'):
                    stateOld = "0"+"0"+"0"+"0"
                    stateNew = "0"+"1"+"0"+str(number1)
                    if(number2 != 0):
                        break
                if(tape == 'Z'):
                    stateOld = "0"+"1"+"0"+str(number2)
                    stateNew = "1"+"1"+str(number1)+str(number2)
                
                print(
                    stateOld,
                    tape,
                    number1,
                    "i",
                    "--",
                    stateNew,
                    tape,
                    number1,
                    "i"
                )

    
                    