package module;

public class Queue<T> {
    private Node<T> front;
    private Node<T> rear;
    private int maxSize;
    private int size;
        
    public Queue(int maxSize){
        this.front = null;
        this.rear = null;
        this.maxSize = maxSize;
        this.size = 0;
    }
    
    public Queue()
    {
        this.front = null;
        this.rear = null;
        this.maxSize = 0;
        this.size = 0;
    }
    
    public T getFront(){
        return this.front.data;
    }
    public T getBack(){
        return this.rear.data;
    }
    public int getSize(){
        return this.size;
    }
    
    public boolean isEmpty(){
        if (this.front == null)
            return true;
        return false;
    }
    
    public void enqueue(T data){
        if(this.maxSize != 0 && this.size >= this.maxSize)
            return;
        this.size++;
        Node<T> newNode = new Node<>(data);
        if(this.isEmpty())
        {
            this.front = this.rear = newNode;
            return;
        }
        this.rear.next = newNode;
        this.rear = newNode;
    }
    public void clear(){
        if(this.isEmpty())
            return;
        this.front = this.rear = null;
        this.maxSize = this.size = 0;
    }
    public void dequeue(){
        if(this.isEmpty())
            return;
        Node<T> current = this.front;
        this.front = current.next;
        this.maxSize--;
        this.size--;
        if (this.front == null)
            this.rear = null; 
    }

    public String toString() {
        if (this.isEmpty()) return "[]";
        Node<T> current = this.front;
        String msg = "[" + String.valueOf(current.data);
        current = current.next;
        while (current != null) {
          msg += " " + String.valueOf(current.data);
          current = current.next;
        }
        msg +="]";
        return msg;
    }
}
