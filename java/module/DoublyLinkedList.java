package module;

public class DoublyLinkedList<T> {
    private Node<T> head;
    private Node<T> tail;
    private int size;
    public DoublyLinkedList(){
        this.head = this.tail = null;
        this.size = 0;
    }

    public Node<T> getHead(){
        return this.head;
      }
    
    public Node<T> getTail(){
        return this.tail;
      }
    
    public int getSize() {
        return this.size;
      }
    public Node<T> get(int index) {
        if (index > this.size || index < 0)
          throw new IndexOutOfBoundsException("List index out range.");
        Node<T> current = this.head;
        if (index == 0) return current; else if (
          index == this.size - 1
        ) return this.tail;
        current = current.next;
        for (int i = 1; i < index; i++) current = current.next;
        return current;

      }

    public boolean isEmpty() {
        if (this.head == null) return true;
        return false;
      }

    public void clear(){
        this.head = this.tail = null;
        this.size = 0;
      }

    public void add(T data){
        Node<T> newData = new Node<>(data);
        this.size++;
        if(this.isEmpty()){
            this.head = this.tail = newData;
            return;
        }
        newData.prev = this.tail;
        this.tail.next = newData;
        this.tail = newData;
    }

    public void pop(int index){
        if(index > this.size || index < 0)  
          throw new IndexOutOfBoundsException("List index out range.");
        int size = this.getSize();
        this.size--;
        if (index == 0){
           this.head.next.prev = this.head.prev;
            this.head = this.head.next;
            return;
        }
        else if(index == size - 1){
            this.tail.prev.next = this.tail.next;
            this.tail = this.tail.prev;
            return;
        }
        Node<T> temp = this.head.next;
        Node<T> prev = temp.prev;
        for(int i = 1; i < index; i++){
            prev = temp;
            temp = temp.next;
        }
        prev.next = temp.next;
        temp.next.prev = prev;

    }

    public String toString() {
        if (this.isEmpty()) return "[]";
        Node<T> current = this.head;
        String msg = String.valueOf(current.data);
        current = current.next;
        while (current != null) {
          msg += " " + String.valueOf(current.data);
          current = current.next;
        }
        return msg;
      }
    
      public void reverse() {
        if (this.isEmpty() || this.size < 2) return;
        this.tail = this.head;
        Node<T> prev = this.head.prev;
        Node<T> current = this.head;
        Node<T> next;
        while (current != null) {
          next = current.next;
          current.next = prev;
          current.prev = next;
          prev = current;
          current = next;
        }
        this.head = prev;
      }
}
