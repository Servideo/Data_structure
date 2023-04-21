from .node import Node


class Linked_list:

    def __init__(self):
        self.__head: Node | None = None
        self.__last: Node | None = None
        self.__size = 0

    # getter
    @property
    def size(self) -> int:
        return self.__size
    # metodos
    def is_empty(self) -> bool:
        if(self.__head is None): return True
        return False
    
    def get(self, index: int) -> any:
        if index == 0:
            return self.__head.data
        elif index == self.size - 1:
            return self.__last
        current: Node = self.__head.next
        for i in range(1, self.size - 1):
            current = current.next
        return current.data

    def insert_end(self, data: any) -> None:
        new_data = Node(data)
        # actualiza el tamaño de la lista
        self.__size += 1
        if self.is_empty():
            self.__head = new_data
            return
        elif self.__last is None:
            self.__last = new_data
            self.__head.next = self.__last
            return
        self.__last.next = new_data
        self.__last = new_data

    def __str__(self) -> str:
        if self.is_empty(): return "Lista vacia"
        msg:str
        temp = self.__head
        msg = f'{temp.data}'
        temp = temp.next
        while temp:
            msg += f' {temp.data}'
            temp = temp.next
        return msg

    def reserve(self) -> None:
        if self.is_empty():
            return
        self.__last = self.__head
        prev = None
        current = self.__head
        while current:
            next = current.next
            current.next = prev
            prev = current
            current = next
            
        self.__head = prev
