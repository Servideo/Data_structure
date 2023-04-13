from .node import Node


class Linked_list:

    def __init__(self):
        self.__head: Node | None = None
        self.__size = 0

    # getter
    @property
    def head(self) -> Node:
        return self.__head.data

    @property
    def size(self) -> int:
        return self.__size
    
    def insert_end(self, head: any) -> None:
        new_data = Node(head)
        if self.__head is None:
            self.__head = new_data
            # actualiza el tamaño de la lista
            self.__size += 1
            return
        last = self.__head
        while last.next:
            last = last.next
        last.next = new_data
        self.__size += 1

    def __str__(self) -> str:
        msg: str = ''
        if self.__head is None:
            return
        temp = self.__head
        while temp:
            msg += f'{temp.data} '
            temp = temp.next
        return msg

    def reserve(self) -> None:
        prev = None
        current = self.__head

        while current:
            next = current.next
            current.next = prev
            prev = current
            current = next

        self.__head = prev