import { LinkedList } from "./module/linkedlist.js";



function main() {
  let llist = new LinkedList();
  try
  {
    let element = '1 2 3 4 5'.split(' ');
    if (element.length == 0) throw new Error('No se reciben espacios en blanco');
    element.forEach(i => llist.insertEnd(i)); 
    console.log(`lista sin invertir\n${llist.print()}`);
    console.log(`tamaño ${llist.size}`);
    let start = performance.now();
    // llist.head = llist.reverse(llist.head);
    llist.reverse();
    // let end = performance.now() - start; 
    // console.log(`Tiempo estimado: ${end}`)
    console.log(`Lista invertida:\n${llist.print()}`)
  }catch(e)
  {
    console.log(e);
  }
}

main();
