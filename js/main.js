import { LinkedList } from "./module/linkedlist.js";

function main() {
  let llist = new LinkedList();
  try {
    let element = prompt("Ingresa datos aquí").split(" ");
    if (element.includes(""))
      throw new Error("No se reciben espacios en blanco");
    element.forEach((i) => llist.insertEnd(i));
    console.log(`lista sin invertir\n${llist.print()}`);
    console.log(`tamaño ${llist.getSize()}`);
    llist.reverse();
    console.log(`Lista invertida:\n${llist.print()}`);
  } catch (e) {
    console.log(e.message);
  }
}

main();
