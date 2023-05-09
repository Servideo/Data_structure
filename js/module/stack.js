"use strict";

import Node  from "./node";

export class Stack{
    #top;
    #size;
    constructor(){
        this.#top = null;
        this.#size = 0;
    }

    peek(){
        return this.#top;
    }

    getSize(){
        return this.#size; 
    }

    isEmpty() {
        if (this.this.#top == null) return true;
        return false;
    }

    push(data){
        let newNode = new Node(data);
        this.#size++;
        if(this.isEmpty()){
            this.#top = newNode;
            return;
        }
        newNode.setNext(this.#top);
        this.#top = newNode;
    }

    pop(){
        if(this.isEmpty()) return;
        let temp = this.#top;
        this.#top = temp.getNext();
        this.#size--;
        delete(temp);
    }
    clear() {
        this.#top = null;
        this.#size = 0;
      }
      toString() {
        if (this.isEmpty()) return "[]";
        let temp = this.#top;
        let msg = `${temp.getData()}`;
        temp = temp.getNext();
        while (temp) {
          msg += ` ${temp.getData()}`;
          temp = temp.getNext();
        }
        return msg;
      }
}