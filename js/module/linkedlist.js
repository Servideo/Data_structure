import { Node } from "./node.js";

export class LinkedList {
  #head;
  #size;
  #last;
  constructor() {
    this.#head = null;
    this.#last = null;
    this.#size = 0;
  }

  // getter
  getSize() {
    return this.#size;
  }
  get(index) {
    if (index === 0) return this.#head.getData();
    else if (index === this.#size - 1) return this.#last.getData();
    let current = this.#head.getNext();
    for (let i = 1; i < index; i++) current = current.getNext();
    return current.getData();
  }
  add(data) {
    let newNode = new Node(data);
    this.#size++;
    if (this.#head == null) {
      this.#head = newNode;
      // actualiza el tamaño de la lista
      return;
    } else if (this.#last == null) {
      this.#last = newNode;
      this.#head.setNext(this.#last);
      this.#last.setNext(this.#head);
      return;
    }
    newNode.setNext(this.#last.getNext());
    this.#last.setNext(newNode);
    this.#last = newNode;
  }
  pop(index){
    if(this.isEmpty()) return;
    if(index>= this.#size) return;
    let current = this.head;
    let prev = this.#head;
    if(index == 0){
        this.#head = current.next;
        this.#size--;
        return;
    }
    current = current.next;
    for(let i = 1; i < index; i++){
        prev = current;
        current = current.next;
    }
    if(index == this.#size - 1){
        prev.next = this.last.next;
        this.last = prev;
        this.#size--;
    }
    prev.next = current.next;
    this.#size--; 
}
  toString() {
    if (this.#head == null) return;
    let temp = this.#head;
    let msg = `${temp.getData()}`;
    temp = temp.getNext();
    while (temp != this.#head) {
      msg += ` ${temp.getData()}`;
      temp = temp.getNext();
    }
    return msg;
  }
  reverse() {
    if (this.#head == null) return;
    this.#last = this.#head;
    let prev = null;
    let current = this.#head;
    let next;
    do {
      next = current.getNext();
      current.setNext(prev);
      prev = current;
      current = next;
    } while (current != this.#head);

    this.#head.setNext(prev);
    this.#head = prev;
  }
}
