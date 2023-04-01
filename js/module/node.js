export class Node{
    #data;
    #next;
    constructor(data){
        this.#data = data;
        this.#next = null;
    }
    // getter
    getData(){
        return this.#data;
    }

    getNext(){
        return this.#next;
    }

    // setter
    setData(data){
        this.#data = data;
    }
    
    setNext(next){
        this.#next = next;
    }

}
