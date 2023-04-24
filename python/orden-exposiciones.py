from module.linked_list import Linked_list

def orden_expo(array:list[any], llist:Linked_list) -> None:
    count1 = 0
    count = len(array) - 1
    flag:bool = False
    while count1 <= count:
        if flag:
            llist.add(array[count])
            count -=1
            flag = False
            continue
        llist.add(array[count1])
        count1 +=1
        flag = True
    

def main() -> None:
    llname:Linked_list = Linked_list()
    lname:list[str] = input().split(" ")
    orden_expo(lname,llname)
    print(f"{llname}",end="")

if __name__ == "__main__":
    main()