# Space Invaders `invaders.h` Instructions
## Daniel Rose

The guide I was reading seems to display the hex dump quite
differently than mine (on Arch Linux, 07/2021) so I've decided to
decipher the first few instructions myself.

```
0000000 0000 c300 18d4 0000 c5f5 e5d5 8cc3 0000
0000010 c5f5 e5d5 803e 7232 2120
```

Which is, at least in the example, this:

```
0000000 00 00 00 c3 d4 18 00 00 f5 c5 d5 e5 c3 8c 00 00
0000010 f5 c5 d5 e5 3e 80 32 72 20
```

Maybe that is completely expected, but as this is my first time that
felt quite strange.

```asm
0000 00 NOP
0001 00 NOP
0002 00 NOP
0003 c3 d4 18 JMP $18d4
0006 00 NOP
0007 00 NOP
0008 f5 PUSH PSW
0009 c5 PUSH B
000a d5 PUSH D
000b e5 PUSH H
000c c3 8c 00 JMP $008c
000f 00 NOP
0010 f5 PUSH PSW
0011 c5 PUSH B
0012 d5 PUSH D
0013 e5 PUSH H
0014 3e 80 MVI A,#0x80
0015 32 72 20 STA $2072
```

I only looked at the written table once, for the MVI. Otherwise, I
don't think I did bad for translating that first time!
