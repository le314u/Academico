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
                


def sub():
    for rw in [0]:
        for tape in [1]:
            for oldRead in range(0,10):# Tem digito flutuante
                for buff in [0,1]:# Tem digito flutuante
                    for newRead in range(0,10):# Tem digito flutuante
                        estadoA=str(rw)+str(tape)+str(buff)+str(oldRead)
                        if(oldRead - buff < newRead):
                            auxOldRead = oldRead+10
                        else:
                            auxOldRead = oldRead
                        estadoB="10"+str(str(0 if auxOldRead <10 else 1))+str(auxOldRead-newRead-buff)
                        print(
                            estadoA,
                            "Z",
                            newRead,
                            "i",
                            "--",
                            estadoB,
                            "Z",
                            newRead,
                            "e",
                            "\t; ",str(oldRead),"-",str(buff),"-",str(newRead),"=",str(auxOldRead-newRead-buff), "Pega emprestado", str(0 if auxOldRead <10 else 1)
                        )
                    estadoA=str(rw)+str(tape)+str(buff)+str(oldRead)
                    estadoB="10"+ ("0" if buff == 0  else '' )+str( ( buff*10+oldRead )-1 )
                    print(
                        estadoA,
                        "Z",
                        "$s",
                        "i",
                        "--",
                        estadoB,
                        "Z",
                        "$s",
                        "i",
                        "\t; ",str(oldRead),"-",str(buff),"-",str(0),"=",str(oldRead-buff), "Pega emprestado", str(0 if auxOldRead <10 else 1)
                    )
                    print('\n')


                
