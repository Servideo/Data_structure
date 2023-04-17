from module.linked_list import Linked_list
def main() -> None:
    llname:Linked_list = Linked_list()
    lname:list[str] = input().split(' ')
    count1 = 0
    count = len(lname) - 1
    flag:bool = False
    while count1 <= count:
        if flag:
            llname.insert_end(lname[count])
            count -=1
            flag = False
            continue
        llname.insert_end(lname[count1])
        count1 +=1
        flag = True
    llname.show()

if __name__ == "__main__":
    main()