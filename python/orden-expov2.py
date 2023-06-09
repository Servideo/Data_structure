from module.doublylinked import Doubly_linked_list
from module.node import Node

def split(text:str, sep:str = ' ') -> Doubly_linked_list:
    llist:Doubly_linked_list = Doubly_linked_list()
    start = 0
    end = text.find(sep)
    while end != -1:
        llist.add(text[start:end])
        start = end + len(sep)
        end = text.find(sep, start)
    llist.add(text[start:len(text)])
    return llist
    
    
def orden_expo(list1: Doubly_linked_list) -> Doubly_linked_list:
    lexpo:Doubly_linked_list = Doubly_linked_list()
    first: Node = list1.head
    end: Node = list1.tail
    change:bool = False
    while first != end:
        if(change):
            lexpo.add(end.data)
            end = end.prev
            change = False
            continue
        lexpo.add(first.data)
        first = first.next
        change = True
    lexpo.add(end.data)
    return lexpo

def main() -> None:
    nickname:str = input()
    lperson: Doubly_linked_list = split(nickname)
    lexpo: Doubly_linked_list = orden_expo(lperson)
    print(f"{lexpo}",end="")
    c: Doubly_linked_list = lexpo.copy()
    c.add("Z")
    print(f"\n{c}")
    print(f"{lexpo}",end="")

if __name__ == "__main__":
    main()