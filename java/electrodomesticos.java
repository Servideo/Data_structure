import java.util.Scanner;
import module.Queue;

public class electrodomesticos {

  public static Queue<String> split(String text, int limit) {
    Queue<String> result = new Queue<>(limit);
    String separator = " ";
    int start = 0;
    int end = text.indexOf(separator);
    String substr;
    while (end != -1) {
      substr = text.substring(start, end);
      result.enqueue(substr);
      start = end + separator.length();
      end = text.indexOf(separator, start);
    }
    substr = text.substring(start);
    result.enqueue(substr);
    return result;
  }

  public static Queue<String> insertQueue() {
    Scanner sc1 = new Scanner(System.in);
    Scanner sc2 = sc1;
    String iter;
    int size;
    size = Integer.parseInt(sc1.nextLine());
    iter = sc2.nextLine();
    Queue<String> queue = split(iter, size);
    return queue;
  }

  public static String deliveryAtSmall(
    Queue<String> product,
    Queue<String> numberProduct
  ) {
    String reportOfSmall = "";
    int numberofDeliveries = numberProduct.getSize();
    for (int i = 0; i < numberofDeliveries; i++) {
      int numberOfDelivery = Integer.parseInt(numberProduct.getFront().data);
      Queue<String> small = new Queue<>(numberOfDelivery);
      if (product.getSize() == 0) {
        if (i == 0) {
          reportOfSmall += small.toString();
          break;
        }
        reportOfSmall += "\n" + small.toString();
        continue;
      }
      for (int j = 0; j < numberOfDelivery; j++) {
        if (product.getSize() == 0) break;
        small.enqueue(product.getFront().data);
        product.dequeue();
      }
      if (i == 0) {
        reportOfSmall += small.toString();
        numberProduct.dequeue();
        continue;
      }
      reportOfSmall += "\n" + small.toString();
      numberProduct.dequeue();
    }
    return reportOfSmall;
  }

  public static String SystemDelivery(int numberCase) {
    String reporDelivery = "";
    for (int i = 0; i < numberCase; i++) {
      Queue<String> product = insertQueue();
      Queue<String> numberProduct = insertQueue();
      reporDelivery += deliveryAtSmall(product, numberProduct);
      product.clear();
      numberProduct.clear();
      if (numberCase > 1 && i < numberCase - 1) {
        reporDelivery += "\n";
      }
    }
    return reporDelivery;
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int numberCase;
    String result;
    numberCase = sc.nextInt();
    result = SystemDelivery(numberCase);
    System.out.print(result);
    sc.close();
  }
}
