import{Node} from './node'

export class LinkedList{
    constructor()
    {
        this.head = null;
        this.size = 0;
    }

    insertEnd(head)
    {
        let newNode = new Node(head);

        if (this.head == null)
        {
            this.head = newNode;
            // actualiza el tamaño de la lista
            this.size ++;
            return;
        }
        let lastNode = this.head;
        while (lastNode.next != null)
        {
            lastNode = lastNode.next;
        }
        lastNode.next = newNode;
        this.size ++;
    }
    print(){
        let msg='';
        if(this.head == null) return;
        let temp = this.head;
        while(temp)
        {
            if (msg.trim().length == 0)
            {
                msg = `${temp.data} `;
                temp = temp.next;
                continue
            }
            temp = temp.next;
        }
        return msg;
    }

    reverse(head)
    {
        if(head.data == null || head == null) return head;
        let res = this.reverse(head.next);
        head.next.next = head;
        head.next = null;
        return res;
    }

}
