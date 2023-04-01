import { Node } from "./node.js";

export class LinkedList {
  #head;
  #size;
  constructor() {
    this.#head = null;
    this.#size = 0;
  }

      // getter
      getHead(){
        return this.#head;
    }

    getSize(){
        return this.#size;
    }

    // setter
    setHead(head){
        this.#head = head;
    }

  insertEnd(head) {
    let newNode = new Node(head);

    if (this.#head == null) {
      this.#head = newNode;
      // actualiza el tamaño de la lista
      this.#size++;
      return;
    }
    let lastNode = this.#head;
    while (lastNode.getNext() != null) {
      lastNode = lastNode.getNext();
    }
    lastNode.setNext(newNode);
    this.#size++;
  }
  print() {
    let msg='';
    if (this.#head == null) return;
    let temp = this.#head;
    while (temp != null) {
      if (msg.trim().length == 0) {
        msg = `${temp.getData()} `;
      }else{
        msg += `${temp.getData()} `;
      }
      temp = temp.getNext();
    }
    return msg;
  }
  // usando recursividad
  // reverse(head)
  // {
  //     if(head.getData() == null || head.getNext() == null) return head;
  //     let res = this.reverse(head.getNext());
  //     head.getNext().setNext(head);
  //     head.setNext(null);
  //     return res;
  // }

  // usando un while
  reverse() {
    let prev = null;
    let current = this.#head;
    let next;
    while (current != null) {
      next = current.getNext();
      current.setNext(prev);
      prev = current;
      current = next;
    }
    this.#head = prev;
  }
}
