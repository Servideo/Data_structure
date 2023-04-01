from module.linked_list import Linked_list
from time import perf_counter

def main():
    llist = Linked_list()

    try:
        element = input('Ingresa los elementos a la lista:\n').split()
        if len(element) == 0:
            raise Exception('No se reciben espacios en blanco')
        # inserto los elementos de la lista element en llist
        for i in element:
            llist.insert_end(i)
        print(f'lista sin invertir\n{llist}')
        print(f'tamaño: {llist.get_size()}')
        # usando recursividad
        # start = perf_counter()
        # llist.set_head(llist.reverse(llist.get_head()))
        # usando un while
        llist.reserve()
        # end = perf_counter() - start
        # print(f'tiempo transcurrido: {end:0.4f}')
        print(f'lista invertida\n{llist}')

    except Exception as e:
        print(e)


if __name__ == '__main__':
    main()
