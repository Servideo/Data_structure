from module.linked_list import Linked_list
        
def insert_value(array: list[int]) -> Linked_list:
    llist: Linked_list = Linked_list()
    for element in array:
        llist.add(element)
    return llist
        
def main() -> None:
    linput: list[int] = [int(number) for number in input().split()]
    llist1: Linked_list = insert_value(linput)
    llist2: Linked_list = insert_value(linput)
    llist2.reverse()
    llist2.pop(llist2.size - 1)
    llist1.add(4)
    print(f'Lista1: {llist1}\nLista2: {llist2}')
if __name__ == "__main__":
    main()