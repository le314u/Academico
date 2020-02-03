package rc5;
import java.io.*;

public class Enc {
    
    public void encrypt() throws Exception{
        KeyExp ke = new KeyExp();                
        String s[] = ke.compute();
        System.out.println("Texto a criptografar");
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("metade A do texto = ");
        //Pega um bloco de tamanho 32
        String a = fullfill0(Long.toBinaryString(Long.parseLong(br.readLine(), 16)));
        //Pega um bloco de tamanho 32
        System.out.print("metade B do texto = ");
        String b = fullfill0(Long.toBinaryString(Long.parseLong(br.readLine(), 16)));
        a = add(a, fullfill0(s[0]));
        b = add(b, fullfill0(s[1]));
        int tmp = 0;
        //Round/Ciclo do algoritimo rc5
        for (int i = 1; i <= 12; i++) {
            //tamanho do deslocamento
            tmp = Integer.parseInt(""+Long.parseLong(b,2)%32); 
            //Ou exclusivo
            a = xor(a, b);           
            //Shift Left (temp até o final)+ inicio até final
            a = a.substring(tmp)+a.substring(0,tmp);
            //Operador Add
            a = add(a, fullfill0(s[2 * i]));  
            
            //Inverte a ordem dos blocos
            //tamanho do deslocamento
            tmp = Integer.parseInt(""+Long.parseLong(a,2)%32);
            //Ou exclusivo
            b = xor(b, a);
            //Shift Left (temp até o final)+ inicio até final
            b = b.substring(tmp)+b.substring(0,tmp);
            //Operador Add
            b = add(b, fullfill0(s[(2 * i)+1]));
            System.out.println(i+" iteração = "+(Long.toHexString(Long.parseLong(a,2)))+(Long.toHexString(Long.parseLong(b,2))));
        }
        //Concatena os 2 blocos
        String out = a+b;
        System.out.println("Saída = "+(Long.toHexString(Long.parseLong((out.substring(0,32)),2)))+(Long.toHexString(Long.parseLong((out.substring(32)),2))));
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
    //Operação de add com 'x' e 'y' tendo 32 bits
    public String add(String x, String y) {
        String result = "";
        boolean carry = false;
        for (int i = x.length()- 1; i >= 0; i--) {                      
            if((x.charAt(i) == y.charAt(i) && carry == false)|| (x.charAt(i) != y.charAt(i)  && carry == true)){
                result = "0"+result;                
            }else{
                result = "1"+result;
            }
            if((x.charAt(i) == '1' && y.charAt(i) == '1') || 
                    (x.charAt(i) == '1' && y.charAt(i) == '1' && carry == true) || 
                    (x.charAt(i) !=  y.charAt(i) && carry == true)){carry = true;}
            else{carry = false;}
        }       
        return result;
    }
}
