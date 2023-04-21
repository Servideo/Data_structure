import java.util.Scanner;
import module.LinkedList;

public class app {

    public static void ordenExpo(String[] arr, LinkedList<String> llist){
        int index1 = 0;
        int index2 = arr.length - 1;
        boolean change = false;
        while(index1 <= index2){
            if (change){
                llist.add(arr[index2]);
                index2--;
                change = false;
                continue;
            }
            llist.add(arr[index1]);
            index1++;
            change = true;
        }
    }
    public static void main(String[] arg){
        Scanner sc = new Scanner(System.in);
        String input = sc.nextLine();
        String[] lnickname = input.split(" ");
        LinkedList<String> llexpo = new LinkedList<>();
        ordenExpo(lnickname, llexpo);
        System.out.print(llexpo.toString());

    }
}
