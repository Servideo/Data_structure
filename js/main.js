import { LinkedList } from "./module/linkedlist.js";

function main() {
  let llist = new LinkedList();
  try
  {
    let element = '1'.split('');
    if (element.length == 0) throw new Error('No se reciben espacios en blanco')
    element.map(llist.insertEnd);
    console.log(`lista sin invertir\n${llist.print()}`);
    console.log(`tamaño ${llist.size}`)
    llist.head = llist.reverse(llist.head)
    console.log(`lista invertida ${llist}`);
  }catch(e)
  {
    console.log(e);
  }
}

main();
