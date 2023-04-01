from .node import Node


class Linked_list:
    
    def __init__(self):
        self.__head: Node | None = None
        self.__size = 0
        
        # getter
    def get_head(self) -> Node:
        return self.__head
    
    def get_size(self) -> int:
        return self.__size
    # setter
    def set_head(self,head) -> None:
        self.__head = head
    
    def insert_end(self, head: any) -> None:
        new_data = Node(head)
        if self.__head is None:
            self.__head = new_data
            # actualiza el tamañp de la lista
            self.__size += 1
            return
        last = self.__head
        while last.get_next() != None:
            last = last.get_next()
        last.set_next(new_data)
        self.__size += 1

    def __str__(self) -> str:
        msg: str = ''
        if self.__head is None:
            return
        temp = self.__head
        while temp is not None:
            if len(msg.strip()) == 0:
                msg = f'{temp.get_data()} '
            else:
                msg += f'{temp.get_data()} '
            temp = temp.get_next()
        return msg

    # usuando recursividad

    # def reverse(self, head: Node | None) -> Node:
    #     if head.get_data() is None or head.get_next() is None:
    #         return head
    #     res = self.reverse(head.get_next())
    #     head.get_next().set_next(head)
    #     head.set_next(None)
    #     return res

    # usando un while
    
    def reserve(self) -> None:
        prev = None
        current = self.__head
        
        while current is not None:
            next = current.get_next()
            current.set_next(prev)  
            prev = current
            current = next

        self.__head = prev

