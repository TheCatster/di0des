#include <stdio.h>
#include <stdlib.h>

int disassemble_8080_op(unsigned char *codebuffer, int pc);

int main(int argc, char **argv) {
  FILE *f = fopen(argv[1], "rb");

  if (f == NULL) {
    printf("error: Couldn't open %s\n", argv[1]);
    exit(1);
  }

  fseek(f, 0L, SEEK_END);
  int fsize = ftell(f);
  fseek(f, 0L, SEEK_SET);

  unsigned char *buffer = malloc(fsize);

  fread(buffer, fsize, 1, f);
  fclose(f);

  int pc = 0;

  while (pc < fsize) {
    pc += disassemble_8080_op(buffer, pc);
  }

  return 0;
}

/*
 * *codebuffer is a valid pointer to 8080 assembly code
 * pc is the current offset into the code
 *
 * returns the number of bytes of the op
 */

/*
 * TODO: Finish writing out 8080 opcodes
 */

int disassemble_8080_op(unsigned char *codebuffer, int pc) {
  unsigned char *code = &codebuffer[pc];
  int opbytes = 1;

  printf("%04x ", pc);

  switch (*code) {
  case 0x00:
    printf("NOP");
    break;
  case 0x01:
    printf("LXI    B,#$%02x%02x", code[2], code[1]);
    opbytes = 3;
    break;
  case 0x02:
    printf("STAX   B");
    break;
  case 0x03:
    printf("INX    B");
    break;
  case 0x04:
    printf("INR    B");
    break;
  case 0x05:
    printf("DCR    B");
    break;
  case 0x06:
    printf("MVI    B,#$%02x", code[1]);
    opbytes = 2;
    break;
  case 0x07:
    printf("RLC");
    break;
  case 0x08:
    printf("NOP");
    break;
  case 0x09:
    printf("DAD    B");
    break;
  case 0x0a:
    printf("LDAX   B");
    break;
  case 0x0b:
    printf("DCX    B");
    break;
  case 0x0c:
    printf("INR    C");
    break;
  case 0x0d:
    printf("DCR    C");
    break;
  case 0x0e:
    printf("MVI    C,#$%02x", code[1]);
    opbytes = 2;
    break;
  case 0x0f:
    printf("RRC");
    break;
  case 0x10:
    printf("NOP");
    break;
  case 0x11:
    printf("LXI    D,#$%02x%02x", code[2], code[1]);
    opbytes = 3;
    break;
  case 0x12:
    printf("STAX   D");
    break;
  /* ........ */
  case 0x3e:
    printf("MVI    A,#0x%02x", code[1]);
    opbytes = 2;
    break;
    /* ........ */
  case 0xc3:
    printf("JMP    $%02x%02x", code[2], code[1]);
    opbytes = 3;
    break;
    /* ........ */
  }

  printf("\n");

  return opbytes;
}
