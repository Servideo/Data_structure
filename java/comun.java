import module.LinkedList;
import java.util.Scanner;
public class comun {
    public static LinkedList<Integer> split(String text){
        String sep = " ";
        LinkedList<Integer> number = new LinkedList<>();
        int start = 0;
        int end = text.indexOf(sep);
        while(end != -1){
            number.add(Integer.parseInt(text.substring(start, end)));
            start = end + sep.length();
            end = text.indexOf(sep, start);
        }
        number.add(Integer.parseInt(text.substring(start)));
        return number;
    }
    public static void removeCommon(LinkedList<Integer> llist1, LinkedList<Integer> llist2){
        int index1 = 0;
        int index2 = llist2.getSize() - 1;
        while(index1 < llist1.getSize() && index2 >= 0){
            if(index1 == 0 && llist1.get(index1) == llist2.get(index2)){
                llist1.pop(index1);
                llist2.pop(index2);
                index2 = llist2.getSize() - 1;
                continue;
            }
            if(llist1.get(index1) == llist2.get(index2)){
                llist1.pop(index1);
                llist2.pop(index2);
                index1--;
                continue;
            }
            index1++;
            index2--;
        }
    }

    public static void main(String[] args) {
        Scanner sc1 = new Scanner(System.in);
        Scanner sc2 = sc1;
        String input1 = sc1.nextLine();
        String input2 = sc2.nextLine();
        LinkedList<Integer> lnumber1 = split(input1);
        LinkedList<Integer> lnumber2 = split(input2);
        removeCommon(lnumber1, lnumber2);
        System.out.printf("%s\n%s", lnumber1.toString(),lnumber2.toString());
        sc1.close();
        sc2.close();


    }
}
