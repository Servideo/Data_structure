from .node import Node


class Linked_list:
    def __init__(self):
        self.head: Node | None = None

    def insert_end(self, data: any) -> Node | None:
        new_data = Node(data)
        if self.head is None:
            self.head = new_data
            return
        last = self.head
        while last.next:
            last = last.next
        last.set_next(new_data)

    def __str__(self) -> str:
        msg:str =''
        if self.head is None:
            return
        temp = self.head
        while temp:
            if len(msg.strip()) == 0:
                msg = f'{temp.get_data()} '
                temp = temp.next
            msg += f'{temp.get_data()} '
            temp = temp.next
        return msg
    
    def reverse(self,data:Node | None) -> str:
        if data.data is None or data.next is None:
            return data
        res = self.reverse(data.next)
        data.next.next = data
        data.next = None
        return res 

    def size(self) -> int:
        count = 0
        current = self.head
        while current:
            count +=1
            current = current.next
        return count