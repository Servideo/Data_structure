from .node import Node


class Linked_list:
    def __init__(self):
        self.head: Node | None = None
        self.size = 0

    def insert_end(self, head: any) -> None:
        new_data = Node(head)
        if self.head is None:
            self.head = new_data
            # actualiza el tamañp de la lista
            self.size +=1
            return
        last = self.head
        while last.next:
            last = last.next
        last.set_next(new_data)
        self.size +=1

    def __str__(self) -> str:
        msg: str = ''
        if self.head is None:
            return
        temp = self.head
        while temp:
            if len(msg.strip()) == 0:
                msg = f'{temp.get_data()} '
                temp = temp.next
                # nos permite evitar un error de null
                continue
            msg += f'{temp.get_data()} '
            temp = temp.next
        return msg

    def reverse(self, head: Node | None) -> any:
        if head.data is None or head.next is None:
            return head
        res = self.reverse(head.next)
        head.next.next = head
        head.next = None
        return res