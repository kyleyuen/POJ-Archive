import java.math.*;
import java.io.*;
import java.util.*;
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException{
        Scanner in=new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        BigDecimal one=new BigDecimal(1),eig=new BigDecimal(8);
        String tmp;
        while(in.hasNext())
        {
            BigDecimal res=new BigDecimal(0);
            BigDecimal last=one.divide(eig);
            tmp=in.next();
            for(int i=2;i<tmp.length();i++)
            {
                res=res.add(last.multiply(new BigDecimal(tmp.charAt(i)-48)));
                last=last.divide(eig);
            }
            System.out.println(tmp+" [8] = "+res.toString()+" [10]");
        }

    }

}