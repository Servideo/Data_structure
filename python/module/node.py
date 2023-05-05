class Node:
    def __init__(self, data: any):
        self.__prev: Node | None = None
        self.__data: any = data
        self.__next: Node | None = None

    # getter
    @property
    def data(self) -> any:
        return self.__data

    @property
    def next(self) -> any:
        return self.__next

    @property
    def prev(self) -> any:
        return self.__prev

    # setter
    @data.setter
    def data(self, data: any) -> None:
        self.__data = data

    @next.setter
    def next(self, next) -> None:
        self.__next = next

    @prev.setter
    def prev(self, prev) -> None:
        self.__prev = prev
