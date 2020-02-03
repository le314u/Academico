package rc5;

import java.io.*;

public class Dec {
     public void decrypt() throws Exception{
        KeyExp ke = new KeyExp();     
        String s[] = ke.compute();
        System.out.println("Texto a Descriptografar");
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("metade A do Texto = ");
        //Pega um bloco de tamanho 32
        String a = fullfill0(Long.toBinaryString(Long.parseLong(br.readLine(), 16)));
        System.out.print("metade B do texto = ");
        //Pega um bloco de tamanho 32
        String b = fullfill0(Long.toBinaryString(Long.parseLong(br.readLine(), 16)));        
        int tmp = 0;
        //Round/Ciclo do algoritimo rc5
        for (int i = 12; i >= 1; i--) {  
            //Operador subtração
            b = fullfill0(Long.toBinaryString((Long.parseLong(b, 2) - Long.parseLong(s[(2*i)+1], 2))));
            b = b.substring(b.length()-32);
            //Tamanho  do deslocamento
            tmp = Integer.parseInt(""+Long.parseLong(a,2)%32);
            //Shift Right
            b = b.substring(b.length()-tmp) + b.substring(0,b.length()-tmp);  
            //Operador ou exclusivo
            b = xor(b, a);
            
            //Inverte a ordem dos blocos
            
            //Operador subtração
            a = fullfill0(Long.toBinaryString((Long.parseLong(a, 2) - Long.parseLong(s[2*i], 2) ))); 
            a = a.substring(a.length()-32);
            //Tamanho  do deslocamento
            tmp = Integer.parseInt(""+Long.parseLong(b,2)%32);
            //Shift Right
            a = a.substring(a.length()-tmp) + a.substring(0,a.length()-tmp);
            //Operador ou exclusivo
            a = xor(a, b);        
            System.out.println(i+ " iteração = "+(Long.toHexString(Long.parseLong(a,2)))+(Long.toHexString(Long.parseLong(b,2))));
        }        
        a = fullfill0(Long.toBinaryString((Long.parseLong(a, 2) - Long.parseLong(s[0], 2))));
        b = fullfill0(Long.toBinaryString((Long.parseLong(b, 2) - Long.parseLong(s[1], 2))));
        //Concatena os 2 blocos
        String output = a+b;
        output = output.substring(output.length()-64);
        System.out.println("Saída = "+(Long.toHexString(Long.parseLong(output.substring(0,32),2)))+(Long.toHexString(Long.parseLong(output.substring(32),2))));
    }
    //Preenche o bloco com 0's a esuqerda para ter tamanho 32
    public String fullfill0(String x) {
        return (get0(32-x.length())+ x);
    }
    //Operação de ou exclusivo entre x e y de modo que 'x' e 'y' tenham 32 bits cada
    public String xor(String x, String y) {
        String result = "";
        for (int i = 0; i < x.length(); i++) {
            if (x.charAt(i) == y.charAt(i)) {
                result += "0";
            } else {
                result += "1";
            }

        }
        return result;
    }
    //Retorna 'n' numeros 0's
    public String get0(int len) {
        String result = "";
        for (int i = 0; i < len; i++) {
            result += "0";
        }
        return result;
    }
}
