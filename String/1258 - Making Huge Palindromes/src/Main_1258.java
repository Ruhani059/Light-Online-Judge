
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
public class Main_1258 {
    String T;
    String P;
    int [] pi;

    public Main_1258(String T, String P) {
        System.out.println("KMP");
        this.T = T;
        this.P = P;
        this.pi = new int[P.length()];
    }
    
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

    public static boolean kmp_matcher(String T, String P) {
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
//                System.out.println(i-(m-1));
                return true;
            }
        }
        return false;
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
        String[] T = {"abcbebabcabcbacbab", "xxxyxyyxyxxxxxxxyyxxxxxxxyxxxxxxyxxxyxxxxxxxyxxxxx", "bcabcabcbacbacbab", "ababa", "prqsqrp", "prqpqrp", "anncaababaaababaaa", "ababababababab", "aaaaaaa"};
//        String T = "abababacabababababa";
//        String P = "bababababa";
//        String P = "pqrs";
        String P = "madamaam";
//        String P = "anncbaaababaaa";

//        System.out.println(T);
//        KMP kmp = new KMP(T,P);
//        kmp.kmp_matcher();
        Scanner in = new Scanner(new File("input.txt"));
//        Scanner in = new Scanner(System.in);
        int tCase = Integer.parseInt(in.nextLine());
//        in.next();
        
        for (int i = 1; i <= tCase; i++) {
            String TString, PString;
       
//            TString = T[i]; 
//            PString = reverse(TString);

            
            TString = in.nextLine(); 
            PString = reverse(TString);
//            System.out.println(TString+"\t"+PString);
            
            System.out.println(TString.length());

            if(kmp_matcher(TString,PString))
            {
//                System.out.println("No");
                System.out.println("Case "+i+": "+TString.length());
            }
            else
            {
//                System.out.println("Yes");
                int count = 0;
                boolean flag = false;
                for (int j = 0; j < TString.length(); j++) 
                {
                    if(TString.charAt(j) == TString.charAt(TString.length()-1))
                    {
                        count ++;
//                        System.out.println("No");
                        int len = ( TString.length() - j ) / 2;
//                        System.out.println(j+"\t"+len);
//                        if( kmp_matcher( TString.substring(j, TString.length()), reverse(TString.substring(j, TString.length()))) )
                        if( len!= 0 && kmp_matcher( TString.substring(j, j+len), reverse(TString.substring(TString.length() - len, TString.length()))) )
                        {
                            
//                            int count = j+PString.length();
                            System.out.println("Case "+i+": "+Integer.valueOf(j+PString.length()) );
                            flag = true;
                            break;
                        }
                    }
                }
                if(!flag)
                {
                    System.out.println("he he");
                        System.out.println("Case "+i+": "+Integer.valueOf(2*PString.length() - 1) );                    
                }
//                System.out.println(count);
            }
            
        }

        
    }
    
}
