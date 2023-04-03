import { LinkedList } from "./module/linkedlist.js";



function main() {
  let llist = new LinkedList();
  try
  {
    let element = prompt('Ingresa datos aquí').split(' ');
    if (element.includes('')) throw new Error('No se reciben espacios en blanco');
    element.forEach(i => llist.insertEnd(i)); 
    console.log(`lista sin invertir\n${llist.print()}`);
    console.log(`tamaño ${llist.getSize()}`);
    // let start = performance.now();
    // llist.setHead(llist.reverse(llist.getHead));
    llist.reverse();
    // let end = performance.now() - start; 
    // console.log(`Tiempo estimado: ${end}`)
    console.log(`Lista invertida:\n${llist.print()}`)
  }catch(e)
  {
    console.log(e.message);
  }
}

main();
