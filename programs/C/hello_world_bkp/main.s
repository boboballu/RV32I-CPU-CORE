
main.o:     file format elf32-littleriscv


Disassembly of section .text:

00000000 <main>:
   0:	fc010113          	addi	sp,sp,-64
   4:	02112e23          	sw	ra,60(sp)
   8:	02812c23          	sw	s0,56(sp)
   c:	04010413          	addi	s0,sp,64
  10:	000007b7          	lui	a5,0x0
  14:	00078793          	mv	a5,a5
  18:	0007a583          	lw	a1,0(a5) # 0 <main>
  1c:	0047a603          	lw	a2,4(a5)
  20:	0087a683          	lw	a3,8(a5)
  24:	00c7a703          	lw	a4,12(a5)
  28:	fcb42823          	sw	a1,-48(s0)
  2c:	fcc42a23          	sw	a2,-44(s0)
  30:	fcd42c23          	sw	a3,-40(s0)
  34:	fce42e23          	sw	a4,-36(s0)
  38:	0107c783          	lbu	a5,16(a5)
  3c:	fef40023          	sb	a5,-32(s0)
  40:	fe0400a3          	sb	zero,-31(s0)
  44:	fe040123          	sb	zero,-30(s0)
  48:	fe0401a3          	sb	zero,-29(s0)
  4c:	fe040223          	sb	zero,-28(s0)
  50:	fe0402a3          	sb	zero,-27(s0)
  54:	fe040323          	sb	zero,-26(s0)
  58:	fe0403a3          	sb	zero,-25(s0)
  5c:	fe040423          	sb	zero,-24(s0)
  60:	fe0404a3          	sb	zero,-23(s0)
  64:	fe040523          	sb	zero,-22(s0)
  68:	fe0405a3          	sb	zero,-21(s0)
  6c:	fe040623          	sb	zero,-20(s0)
  70:	fe0406a3          	sb	zero,-19(s0)
  74:	fd040793          	addi	a5,s0,-48
  78:	00078513          	mv	a0,a5
  7c:	00000097          	auipc	ra,0x0
  80:	000080e7          	jalr	ra # 7c <main+0x7c>
  84:	000007b7          	lui	a5,0x0
  88:	00078513          	mv	a0,a5
  8c:	fc440713          	addi	a4,s0,-60
  90:	00000793          	li	a5,0
  94:	00000693          	li	a3,0
  98:	00000613          	li	a2,0
  9c:	00a00593          	li	a1,10
  a0:	00000097          	auipc	ra,0x0
  a4:	000080e7          	jalr	ra # a0 <main+0xa0>
  a8:	fc440793          	addi	a5,s0,-60
  ac:	00078513          	mv	a0,a5
  b0:	00000097          	auipc	ra,0x0
  b4:	000080e7          	jalr	ra # b0 <main+0xb0>
  b8:	00000793          	li	a5,0
  bc:	00078513          	mv	a0,a5
  c0:	03c12083          	lw	ra,60(sp)
  c4:	03812403          	lw	s0,56(sp)
  c8:	04010113          	addi	sp,sp,64
  cc:	00008067          	ret

Disassembly of section .rodata:

00000000 <.LC0>:
   0:	6548                	flw	fa0,12(a0)
   2:	6c6c                	flw	fa1,92(s0)
   4:	6f57206f          	j	72ef8 <.LC0+0x72ef8>
   8:	6c72                	flw	fs8,28(sp)
   a:	2064                	fld	fs1,192(s0)
   c:	0a20293b          	0xa20293b
	...

Disassembly of section .comment:

00000000 <.comment>:
   0:	4700                	lw	s0,8(a4)
   2:	203a4343          	fmadd.s	ft6,fs4,ft3,ft4,rmm
   6:	4728                	lw	a0,72(a4)
   8:	554e                	lw	a0,240(sp)
   a:	2029                	jal	14 <main+0x14>
   c:	3031                	jal	fffff818 <main+0xfffff818>
   e:	312e                	fld	ft2,232(sp)
  10:	302e                	fld	ft0,232(sp)
	...

Disassembly of section .eh_frame:

00000000 <.eh_frame>:
   0:	0010                	0x10
   2:	0000                	unimp
   4:	0000                	unimp
   6:	0000                	unimp
   8:	00527a03          	0x527a03
   c:	7c01                	lui	s8,0xfffe0
   e:	0101                	addi	sp,sp,0
  10:	00020d1b          	0x20d1b
  14:	0024                	addi	s1,sp,8
  16:	0000                	unimp
  18:	0018                	0x18
	...
  22:	0000                	unimp
  24:	4400                	lw	s0,8(s0)
  26:	400e                	0x400e
  28:	8148                	0x8148
  2a:	8801                	andi	s0,s0,0
  2c:	4402                	lw	s0,0(sp)
  2e:	080c                	addi	a1,sp,16
  30:	0200                	addi	s0,sp,256
  32:	c1b4                	sw	a3,64(a1)
  34:	c844                	sw	s1,20(s0)
  36:	020c                	addi	a1,sp,256
  38:	4440                	lw	s0,12(s0)
  3a:	000e                	c.slli	zero,0x3

Disassembly of section .riscv.attributes:

00000000 <.riscv.attributes>:
   0:	1b41                	addi	s6,s6,-16
   2:	0000                	unimp
   4:	7200                	flw	fs0,32(a2)
   6:	7369                	lui	t1,0xffffa
   8:	01007663          	bgeu	zero,a6,14 <.riscv.attributes+0x14>
   c:	0011                	c.nop	4
   e:	0000                	unimp
  10:	1004                	addi	s1,sp,32
  12:	7205                	lui	tp,0xfffe1
  14:	3376                	fld	ft6,376(sp)
  16:	6932                	flw	fs2,12(sp)
  18:	7032                	flw	ft0,44(sp)
  1a:	0030                	addi	a2,sp,8
