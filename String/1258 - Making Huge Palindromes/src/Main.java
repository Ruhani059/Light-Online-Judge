
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
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
public class Main {
    
    String T;
    String[] suffixArray;

    public Main(String T) {
//        System.out.println("Main");
        this.T = T;
        this.suffixArray = new String[T.length()+1];
    }
    
    public  String strrev (String T)
    {
        String string = T.substring(T.length()-1, T.length());
        for (int i = 1; i < T.length(); i++) {
            string += String.valueOf(T.charAt(T.length()-i-1));
        }
        return string;
    }

    public int find_Substring()
    {
//        String[] suffixArray = new String[T.length()+1];
        for (int i = 0; i < T.length(); ++i) {
            suffixArray[i] = T.substring(T.length() - 1 - i, T.length());
        }
        suffixArray[T.length()] = "";

        Arrays.sort(suffixArray);
        suffixArray[0] = strrev(T);
//        for (int i = 0; i < T.length()+1; ++i)
        {
//            System.out.println(i+"\t"+suffixArray[i]);
        }

        int max_length = 0;
        for (int i = 1; i <= T.length(); ++i) {
//                System.out.println(suffixArray[0].substring(0, j+1));
                if ( suffixArray[i].equals(suffixArray[0].substring(0, suffixArray[i].length())) ) {
                    if(max_length < suffixArray[i].length()) 
                    {
                        max_length = suffixArray[i].length();
//                        System.out.println(i+"\t"+j+"\t"+suffixArray[i].substring(0, j + 1)+"\t"+suffixArray[0].substring(0, j + 1));
//                        System.out.println(max_length);
                    }
                        
//                    break;
            }
        }
//        System.out.println(max_length);
        return max_length;
    }
    
    public void toStr(Main main1, Main main2)
    {
        for (int i = 0; i < main1.suffixArray.length; i++) {
            System.out.println(i);
            System.out.println(main1.suffixArray[i]);
            System.out.println(main2.suffixArray[i]);
        }
    }
    
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("input.txt"));
        int tCase = Integer.parseInt(in.nextLine());
        for (int i = 1; i <= tCase; i++) {
            String T = in.nextLine();
//            if(i!=tCase) continue;
            Main suffix_Array = new Main(T);
//            suffix_Array.find_Substring();
//            System.out.println(suffix_Array.find_Substring());
            System.out.println("Case "+i+": "+(T.length()+(T.length()-suffix_Array.find_Substring())));
        }

    }
}
