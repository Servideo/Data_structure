from module.linked_list import Linked_list
from time import perf_counter


def split(text: str, sep: str = ' ') -> Linked_list:
    number: Linked_list = Linked_list()
    start: int = 0
    end: int = text.find(sep)
    while end != -1:
        number.add(int(text[start:end]))
        start = end + len(sep)
        end = text.find(sep, start)
    number.add(int(text[start:]))
    return number

def day_to_sell(llist: Linked_list) -> None:
    lday: Linked_list = Linked_list()
    maximun_size = llist.size
    limit = llist.size
    for _ in range(maximun_size):
        count: int = 0
        if limit - 1 == 0:
            lday.add(count)
            break
        
        for j in range(1, limit):
            if llist.get(0).data > llist.get(j).data and j != llist.size - 1:
                count += 1
                continue
            
            elif llist.get(j).data > llist.get(0).data:
                count += 1
                break
            
            elif j == llist.size - 1:
                if llist.get(0).data > llist.get(j).data:
                    count = 0
                    break
                
                elif llist.get(0).data == llist.get(j).data:
                    count = 0
                    break
                
            count += 1
        lday.add(count)
        llist.pop(0)
        limit = llist.size
    print(lday, end='')


def main() -> None:
    lnumber: Linked_list = Linked_list()
    number: str = input()
    lnumber: Linked_list = split(number)
    start: int = perf_counter()
    day_to_sell(lnumber)
    end: int = round(perf_counter() - start, 7)
    print(f'\nTiempo estimado: {end}')


if __name__ == "__main__":
    main()
