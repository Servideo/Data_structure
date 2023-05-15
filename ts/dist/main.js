import { LinkedList } from "./module/linkedList.js";
function split(str, separator = " ") {
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
const main = () => {
    const p = document.getElementById("param");
    let input = prompt("escribe una lista de elementos");
    let llist = split(input);
    console.log(`lista: ${llist.toString()}`);
    p.innerHTML += `lista: ${llist.toString()}<br>`;
    try {
        input = prompt("escribe un indice: ");
        let index = parseInt(input);
        llist.pop(index);
        console.log(`elemento removido de la posición (${index}).`);
    }
    catch (e) {
        console.log(e.message);
        console.log("el elemento no pudo ser removido.");
    }
    llist.reverse();
    console.log(`lista: ${llist.toString()}`);
    p.innerHTML += `Lista: <br>${llist.toString()}<br>`;
};
main();
//# sourceMappingURL=main.js.map