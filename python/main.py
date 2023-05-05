from module.linked_list import Linked_list


def main():
    llist = Linked_list()

    try:
        element: list[str] = input(
            'Ingresa los elementos a la lista:\n').split()
        if len(element) == 0:
            raise Exception('No se reciben espacios en blanco')
        # inserto los elementos de la lista element en llist
        for i in element:
            llist.add(i)
        print(f'Lista sin invertir: {llist} ', end='')
        print(f'tamaño: {llist.size}')
        llist.reverse()
        print(f'Lista invertida: {llist}', end='')

    except Exception as e:
        print(e)


if __name__ == '__main__':
    main()
