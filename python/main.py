from module.linked_list import Linked_list


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
        print(f'tamaño: {llist.size}')
        llist.reserve()
        print(f'lista invertida\n{llist}')

    except Exception as e:
        print(e)


if __name__ == '__main__':
    main()
