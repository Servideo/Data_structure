import java.util.Scanner;
import module.LinkedList;
public class bitcoin {
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
    public static void dayToSell(LinkedList<Integer> llist){
        int count;
        int maximunSize = llist.getSize();
        int limit = llist.getSize();
        LinkedList<Integer>llday = new LinkedList<>();

        for(int i = 0; i < maximunSize ;i++){
            count = 0;
            if(limit - 1 == 0){
               llday.add(count);
               break;
            }
            for(int j = 1; j < limit; j++){
                if(llist.get(0) > llist.get(j) && j != limit - 1){
                    count++;
                    continue;
                }else if(llist.get(j) > llist.get(0)){
                    count++;
                    break;
                }
                else if(j == limit -1 && llist.get(0) > llist.get(j)){
                    count = 0;
                    break;
                }else if(j == limit -1 && llist.get(0) == llist.get(j)){
                    count = 0;
                    break;
                }
                count++;
            }
            llday.add(count);
            llist.pop(0);
            limit = llist.getSize();
        }
        System.out.println(llday.toString());
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String text;
        text = sc.nextLine();
        LinkedList<Integer> llnumber = new LinkedList<>();
        llnumber = split(text);
        dayToSell(llnumber);
        sc.close();
    }
}
