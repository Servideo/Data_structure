from module.linked_list import Linked_list

def orden_expo(array:list[any], llist:Linked_list) -> None:
    index1:int = 0
    index2:int = len(array) - 1
    change:bool = False
    while index1 <= index2:
        if change:
            llist.add(array[index2])
            index2 -=1
            change = False
            continue
        llist.add(array[index1])
        index1 +=1
        change = True
    

def main() -> None:
    llname:Linked_list = Linked_list()
    lname:list[str] = input().split(" ")
    orden_expo(lname,llname)
    print(f"{llname}",end="")

if __name__ == "__main__":
    main()