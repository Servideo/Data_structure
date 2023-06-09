import { Node } from "./node.js";
export class Stack {
    #top;
    #size;
    constructor() {
        this.#top = null;
        this.#size = 0;
    }
    peek() {
        if (this.isEmpty())
            throw new Error("Stack empty.");
        return this.#top;
    }
    size() {
        return this.#size;
    }
    push(data) {
        const newNode = new Node(data);
        this.#size++;
        if (this.isEmpty()) {
            this.#top = newNode;
            return;
        }
        newNode.next = this.#top;
        this.#top = newNode;
    }
    pop() {
        if (this.isEmpty())
            throw new Error("Stack empty.");
        this.#top = this.#top.next;
        this.#size--;
    }
    isEmpty() {
        return this.#top == null ? true : false;
    }
    clear() {
        this.#top = null;
        this.#size = 0;
    }
    toString() {
        if (this.isEmpty())
            return "[]";
        let msg = "";
        let current = this.#top;
        msg += `${current.data}`;
        current = current.next;
        while (current) {
            msg += ` ${current.data}`;
            current = current.next;
        }
        return msg;
    }
}
//# sourceMappingURL=stack.js.map