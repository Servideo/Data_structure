from module.linked_list import Linked_list
def split(text:str, sep:str = ' ') -> Linked_list:
    number = Linked_list()
    start = 0
    end = text.find(sep)
    while end != -1:
        number.add(int(text[start:end]))
        start = end + len(sep)
        end = text.find(sep, start)
    number.add(int(text[start:]))
    return number

def remove_common(llist1:Linked_list, llist2:Linked_list) -> None:
    index1 = 0
    index2 = llist2.size - 1
    while index1 < llist1.size and index2 >= 0:
        if index1 == 0 and llist1.get(index1) == llist2.get(index2):
            llist1.pop(index1)
            llist2.pop(index2)
            index2 = llist2.size - 1
            continue
        elif llist1.get(index1) == llist2.get(index2):
            llist1.pop(index1)
            llist2.pop(index2)
            index1 -= 1
            continue
        index1 += 1
        index2 -= 1

            
def main():
    text1 = input()
    text2 = input()
    lnumber1 = split(text1)
    lnumber2 = split(text2)
    remove_common(lnumber1, lnumber2)
    print(f'{lnumber1}\n{lnumber2}',end='')    
        
if __name__ =="__main__":
    main()