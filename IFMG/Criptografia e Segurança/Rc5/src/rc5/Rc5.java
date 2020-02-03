
package rc5;

import java.io.*;
public class Rc5 {
    public static void main(String[] args) throws Exception{    
        System.out.println("Rc5 32/12/32");
        System.out.println("Entradas devem ser em Hexadecimal!");
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Criptografar");
        Enc enc = new Enc();
        enc.encrypt();
        System.out.println("Descriptografar");
        Dec dec = new Dec();
        dec.decrypt();
    }
}
