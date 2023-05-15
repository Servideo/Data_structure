import { LinkedList } from "./module/linkedList.js";
import { DoublyLinkedList } from "./module/doublylinked.js";

// function split(str: string, separator: string = " "): LinkedList<string> {
//   let llist: LinkedList<string> = new LinkedList();
//   let start: number = 0;
//   let end: number = str.indexOf(separator);
//   while (end != -1) {
//     llist.add(str.substring(start, end));
//     start = end + separator.length;
//     end = str.indexOf(separator, start);
//   }
//   llist.add(str.substring(start));
//   return llist;
// }

function split(str: string, separator: string = " "): DoublyLinkedList<string> {
  let llist: DoublyLinkedList<string> = new DoublyLinkedList();
  let start: number = 0;
  let end: number = str.indexOf(separator);
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
  let llist = split(input!);
  p!.innerHTML += `<br>Primer elemento: ${llist.head().data}<br>`;
  p!.innerHTML += `<br>Ultimo elemento: ${llist.tail().data} <br> `;
  p!.innerHTML += `lista: ${llist.toString()}<br>`;
  try {
    input = prompt("escribe un indice: ");
    let index = parseInt(input!);
    llist.pop(index);
    alert(`elemento removido de la posición (${index}).`);
  } catch (e: any) {
    alert( `${e.message}\nEl elemento no pudo ser removido.` );
  }
  llist.reverse();
  p!.innerHTML += `<br> Lista: ${llist.toString()}<br>`;
};

main();
