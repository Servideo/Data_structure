import { Node } from "./module/node.js";

function main() {
  let node1 = new Node(4);
  node1.next = 3;

  console.log(`data: ${node1.data} next: ${node1.next} `);
}

main();
