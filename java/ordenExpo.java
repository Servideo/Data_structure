import java.util.Scanner;
import module.LinkedList;

public class ordenExpo {

    public static LinkedList<String> split(String str){
        LinkedList<String> llist = new LinkedList<>();
        String sep = " ";
        int start = 0;
        int end = str.indexOf(sep);
        while(end != -1){
            llist.add(str.substring(start, end));
            start = end + sep.length();
            end = str.indexOf(sep, start);
        }
        llist.add(str.substring(start));
        return llist;
    }
    public static void insertList(LinkedList<String> llist1, LinkedList<String> llist2){
        int index1 = 0;
        int index2 = llist1.getSize() - 1;
        boolean change = false;
        while(index1 <= index2){
            if (change){
                llist2.add(llist1.get(index2).data);
                index2--;
                change = false;
                continue;
            }
            llist2.add(llist1.get(index1).data);
            index1++;
            change = true;
        }
    }
    public static void main(String[] arg){
        Scanner sc = new Scanner(System.in);
        String name = sc.nextLine();
        LinkedList<String> person = split(name);
        LinkedList<String> lexpo = new LinkedList<>();
        insertList(person, lexpo);
        System.out.print(lexpo.toString());
        sc.close();
    }
}
