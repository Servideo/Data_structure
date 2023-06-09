import { LinkedList } from "./module/linkedList.js";
import { DoublyLinkedList } from "./module/doublylinked.js";
function splitToLinkedList(str, separator = " ") {
    let llist = new LinkedList();
    let start = 0;
    let end = str.indexOf(separator);
    while (end != -1) {
        llist.add(str.substring(start, end));
        start = end + separator.length;
        end = str.indexOf(separator, start);
    }
    llist.add(str.substring(start));
    return llist;
}
function split(str, separator = " ") {
    let llist = new DoublyLinkedList();
    let start = 0;
    let end = str.indexOf(separator);
    while (end != -1) {
        llist.add(str.substring(start, end));
        start = end + separator.length;
        end = str.indexOf(separator, start);
    }
    llist.add(str.substring(start));
    return llist;
}
const main = () => {
    const p = document.getElementById("param");
    let input;
    do {
        input = prompt("escribe una lista de elementos: ");
    } while (!input);
    let llist = split(input);
    p.innerHTML += `<br>Primer elemento: ${llist.head().data}<br>`;
    p.innerHTML += `<br>Ultimo elemento: ${llist.tail().data} <br> `;
    p.innerHTML += `lista: ${llist.toString()}<br>`;
    try {
        do {
            input = prompt("escribe un indice: ");
        } while (!input);
        let index = parseInt(input);
        llist.pop(index);
        alert(`Elemento removido de la posición (${index}).`);
    }
    catch (e) {
        alert(`${e.message}\nEl elemento no pudo ser removido.`);
    }
    llist.reverse();
    p.innerHTML += `<br>Primer elemento: ${llist.head().data}<br>`;
    p.innerHTML += `<br>Ultimo elemento: ${llist.tail().data} <br> `;
    p.innerHTML += `lista: ${llist.toString()}<br>`;
};
main();
//# sourceMappingURL=main.js.map