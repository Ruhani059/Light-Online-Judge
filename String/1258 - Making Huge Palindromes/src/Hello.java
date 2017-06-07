
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Ruhani
 */
public class Hello {
    
    public static int [] compute_prefix_function (String P) 
    {
//        System.out.println(P);
        int pi[] = new int[P.length()];
        int i=1, k=-1;
        pi[0] = -1;

        for (int q = 1; q < P.length(); q++) {
            while (k > -1 && P.charAt(k+1) != P.charAt(q)) {                
                k = pi[k];
            }
            if( P.charAt(k+1) == P.charAt(q) )
            {
                k++;
            }
            pi[q] = k;
        }
//        for (int ll = 0; ll < pi.length; ll++) {System.out.print(pi[ll]+" ");}System.out.println("");
        return pi;
    }

    public static int kmp_matcher(String T, String P) {
        int kount = 0;
        int n = T.length(), m = P.length(),q=-1;
        int [] pi = new int[P.length()];
        pi = compute_prefix_function(P);

        for (int i = 0; i < n; i++) {
//            System.out.println(i+"\t"+T.charAt(i)+"\t"+q+"\t");
            while (q > -1 && P.charAt(q+1) != T.charAt(i)) {                
                q = pi[q];
            }
            if( P.charAt(q+1) == T.charAt(i) )
            {
                q++;
            }
            if(q == m-1)
            {
                kount++;
                q = pi[q];
                
//                System.out.println(i-(m-1));
            }
        }
        return kount;
    }
    
    public static String reverse (String T)
    {
        String string = T.substring(T.length()-1, T.length());
        for (int i = 1; i < T.length(); i++) {
            string += String.valueOf(T.charAt(T.length()-i-1));
        }
        return string;
    }

    public static boolean equal(int [] a, int [] b)
    {
        for (int ll = 0; ll < a.length; ll++) {
            if(a[ll]!=b[ll])
                return false;
        }
        return true;
    }
    public static void main(String[] args) throws FileNotFoundException {
//        Scanner in = new Scanner(new File("input.txt"));
        Scanner in = new Scanner(System.in);
        int tCase = Integer.parseInt(in.nextLine());
//        System.out.println(tCase);
        
        for (int i = 1; i <= tCase; i++) {
            String TString, PString;
       
//            TString = T[i]; 
//            PString = reverse(TString);

            int nCase = Integer.parseInt(in.nextLine());
//            System.out.println(nCase);
            System.out.println("Case "+i+":");
            TString = in.nextLine(); 
//            System.out.println(TString);
            for (int jj = 1; jj <= nCase; jj++) {
                PString = in.nextLine();
//                System.out.println(PString);
    //            System.out.println(TString+"\t"+PString);

                System.out.println(kmp_matcher(TString,PString));
            }
        }

    }
    
}
