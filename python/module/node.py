class Node:
    def __init__(self, data: any):
        self.__data = data
        self.__next = None

    # getter
    @property
    def data(self) -> any:
        return self.__data
    
    @property
    def next(self) -> any:
        return self.__next

    # setter
    @data.setter
    def data(self, data) -> None:
        self.__data = data
        
    @next.setter
    def next(self, next) -> None:
        self.__next = next
