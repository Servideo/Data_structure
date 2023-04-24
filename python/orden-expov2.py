from module.linked_list import Linked_list



def split(text:str, sep:str = ' ') -> Linked_list:
    llist:Linked_list = Linked_list()
    start = 0
    end = text.find(sep)
    while end != -1:
        llist.add(text[start:end])
        start = end + len(sep)
        end = text.find(sep, start)
    llist.add(text[start:])
    return llist
    
    
def orden_expo(llist1:Linked_list, llist2:Linked_list) -> None:
    index1 = 0
    index2 = llist1.size - 1
    change:bool = False
    while index1 <= index2:
        if change:
            llist2.add(llist1.get(index2))
            index2 -= 1
            change = False
            continue
        llist2.add(llist1.get(index1))
        index1 += 1
        change = True
    

def main() -> None:
    lexpo:Linked_list = Linked_list()
    nickname:str = input()
    lperson:Linked_list = split(nickname)
    orden_expo(lperson, lexpo)
    print(f"{lexpo}",end="")

if __name__ == "__main__":
    main()