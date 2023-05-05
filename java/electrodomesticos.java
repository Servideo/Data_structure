import module.Queue;
import java.util.Scanner;

public class electrodomesticos {

    public static Queue<String> split(String text,int limit){
        Queue<String> result = new Queue<>(limit);
        String separator = " ";
        int start = 0;
        int end = text.indexOf(separator);
        String substr;
        while(end != -1){
            substr = text.substring(start, end);
            result.enqueue(substr);
            start = end + separator.length();
            end = text.indexOf(separator, start);
        }
        substr = text.substring(start);
        result.enqueue(substr);
        return result;
    }

    public static String input(){
        String text;
        Scanner sc = new Scanner(System.in);
        text = sc.nextLine();
        sc.close();
        return text;
    }

    public static Queue<String> insertQueue() {
        String iter;
        int size;
        size = Integer.parseInt(input());
        iter = input(); 
        Queue<String> queue = split(iter, size);
        return queue;
    }

    public static String deliveryAtSmall(Queue<String> product, Queue<String> numberProduct){
        String reportOfSmall = "";
        int numberofDeliveries = numberProduct.getSize();
        for(int i = 0; i < numberofDeliveries; i++){
            int numberOfDelivery =  Integer.parseInt(numberProduct.getFront());
            Queue<String> small = new Queue<>(numberOfDelivery);
            if(product.getSize() == 0){
                if(i == 0){
                    reportOfSmall += small.toString();
                    break;
                }
                reportOfSmall += "\n" + small.toString();
                continue;
            }
            for(int j = 0; j < numberOfDelivery; j++)
            {
                if(product.getSize() == 0)
                    break;
                small.enqueue(product.getFront());
                product.dequeue();
            }
            if(i == 0){
                reportOfSmall += small.toString();
                numberProduct.dequeue();
                continue;
            }
            reportOfSmall += "\n" + small.toString();
            numberProduct.dequeue();
        }
        return reportOfSmall;
    }

    public static String SystemDelivery(int numberCase){
        String reporDelivery ="";
        for(int i = 0; i < numberCase ; i++){
            Queue<String>product = insertQueue();
            Queue<String>numberProduct = insertQueue();
            reporDelivery += deliveryAtSmall(product, numberProduct);
            product.clear();
            numberProduct.clear();
            if(numberCase > 1 && i < numberCase - 1){
                reporDelivery += "\n";
            }
        }
        return reporDelivery;
    }
    public static void main(String[] args)
    {
        int numberCase;
        String result;
        numberCase = Integer.parseInt(input());
        result = SystemDelivery(numberCase);
        System.out.print(result);
    }   
}
