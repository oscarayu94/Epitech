The part of OP code corresponding to main is this one

00000000004004a0 <main>:
  4004a0:	cd 80                	int    $0x80
  4004a2:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  4004a9:	00 00 00 
  4004ac:	0f 1f 40 00          	nopl   0x0(%rax)

https://www.linuxjournal.com/article/6100

https://gist.github.com/willb/14488/80deaf4363ed408a562c53ab0e56d8833a34a8aa
