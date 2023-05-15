import {Node} from "./node.js"
import {LinkedList} from "./linkedList.js"

export class DoublyLinkedList<T> extends LinkedList<T>{
    #head: Node<T> | null;
    #tail: Node<T> | null;
    #size: number;
    constructor(){
        super();
        this.#head = this.#tail = null;
        this.#size = 0;
    }

    add(data: T): void {
        const newNode: Node<T> = new Node(data);
        if(this.isEmpty()){
            this.#head = this.#tail = newNode;
            return;
        }
        newNode.prev = this.#tail;
        this.#tail!.next = newNode;
        this.#tail = newNode;
    }

    pop(index: number): void {
        if(this.isEmpty() || index > this.#size)
            throw new RangeError("list index out range.");
        const size: number = this.size();
        this.#size--;
        if(index == 0){
            this.#head!.next!.prev = this.#head!.prev;
            this.#head = this.#head!.next;
            return; 
        }
        else if(index == size - 1){
            this.#tail!.prev = this.#tail!.next;
            this.#tail = this.#tail!.prev;
            return;
        }
        let temp: Node<T>  = this.#head!.next!;
        let prev: Node<T> = this.#head!;
        for(let i = 1; i < index; i++){
            prev = temp;
            temp = temp!.next!;
        }
        temp!.next!.prev = prev;
        prev!.next = temp!.next;
    }

    reverse(): void {
        if (this.isEmpty()) throw new Error("List empty.");
        this.#tail = this.#head;
        let prev: Node<T> | null = this.#head!.prev;
        let current: Node<T> | null = this.#head;
        let next: Node<T> | null;
        while (current) {
          next = current.next;
          current.next = prev;
          current!.prev = next;
          prev = current;
          current = next;
        }
        this.#head = prev;
    }
}