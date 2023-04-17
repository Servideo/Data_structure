from .node import Node


class Linked_list:

    def __init__(self):
        self.__head: Node | None = None
        self.__last: Node | None = None
        self.__size = 0

    @property
    def size(self) -> int:
        return self.__size

    def insert_end(self, data: any) -> None:
        new_data = Node(data)
        if self.__head is None:
            self.__head = new_data
            # actualiza el tamaño de la lista
            self.__size += 1
            return
        elif self.__head.next is None:
            self.__last = new_data
            self.__head.next = self.__last
            self.__last.next = self.__head
            self.__size += 1
            return
        new_data.next = self.__last.next
        self.__last.next = new_data
        self.__last = new_data
        self.__size += 1

    def show(self) -> None:
        if self.__head is None:
            return
        temp = self.__head
        print(temp.data, end='')
        temp = temp.next
        while temp != self.__head:
            print(f' {temp.data}', end='')
            temp = temp.next
        print()

    def reserve(self) -> None:
        if self.__head is None:
            return
        self.__last = self.__head
        prev = None
        current = self.__head
        while True:
            next = current.next
            current.next = prev
            prev = current
            current = next
            if current == self.__head:
                break

        self.__head.next = prev
        self.__head = prev
