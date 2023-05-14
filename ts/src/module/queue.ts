import {Node} from "./node.js"

class Queue<T>{
    #front: Node<T> | null;
    #rear: Node<T> | null;
    #size: number;
    #maxSize: number;

    constructor(maxSize: number = 0){
        this.#front = this.#rear = null;
        this.#maxSize = maxSize;
        this.#size = 0;
    }

    front(): Node<T> {
        if(this.isEmpty())
            throw new Error("List empty");
        return this.#front!;
    }

    back(): Node<T>{
        if(this.isEmpty())
            throw new Error("List empty");
        return this.#rear!;
    }

    size(): number{
        return this.#size;
    }

    MaxSize(): number{
        return this.#maxSize;
    }

    setMaxSize(maxSize: number){
        if(maxSize < this.#maxSize)
            return;
        this.#maxSize = maxSize;
    }

    enqueue(data: T): void{
        if(this.#maxSize > 0 && this.#size > this.#maxSize)
            return;
        const newNode: Node<T> = new Node(data);
        this.#size++;
        if(this.isEmpty()){
            this.#front = this.#rear = newNode;
            return;
        }
        this.#rear!.next = newNode;
        this.#rear = newNode;
    }

    dequeue(): void{
        if(this.isEmpty())
            throw new Error("List empty");
        this.#front = this.#front!.next;
        if(this.#front == null)
            this.#rear = null;
    }

    isEmpty(): boolean {
        if (this.#front == null) return true;
        return false;
    }

    clear():void {
        this.#front = this.#rear = null;
        this.#maxSize = this.#size = 0;
    }

    toString(): string {
        if(this.isEmpty()) return "[]";
        let msg = '';
        let current = this.#front!;
        msg += `${current.data}`;
        current = current!.next!;
        while(current){
            msg += ` ${current.data}`;
            current = current!.next!;
        }
        return msg;
    }
}