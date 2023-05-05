from module.linked_list import Linked_list

def remove_common(list1:list[int], list2:list[int]) -> None:
    llist1:Linked_list = Linked_list()
    llist2:Linked_list = Linked_list()
    index1:int = 0
    index2:int = len(list2) - 1
    while index1 < len(list1) and index2 >= 0:
        if list1[index1] != list2[index2]:
            llist1.add(list1[index1])
            llist2.add(list2[index2])
        index1 += 1
        index2 -= 1
    llist2.reverse()
    print(f'{llist1}\n{llist2}',end='')
         
            
def main():
    text1:list[int] = list(map(int,input().split()))
    text2:list[int] = list(map(int,input().split()))
    remove_common(text1, text2)
        
if __name__ =="__main__":
    main()