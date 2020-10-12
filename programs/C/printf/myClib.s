
myClib.o:     file format elf32-littleriscv


Disassembly of section .text:

00000000 <_ZL10write_charc>:
   0:	fd010113          	addi	sp,sp,-48
   4:	02812623          	sw	s0,44(sp)
   8:	03010413          	addi	s0,sp,48
   c:	00050793          	mv	a5,a0
  10:	fcf40fa3          	sb	a5,-33(s0)
  14:	000007b7          	lui	a5,0x0
  18:	00078793          	mv	a5,a5
  1c:	fef42623          	sw	a5,-20(s0)
  20:	fdf44703          	lbu	a4,-33(s0)
  24:	fec42783          	lw	a5,-20(s0)
  28:	00e7a023          	sw	a4,0(a5) # 0 <_ZL10write_charc>
  2c:	fec42783          	lw	a5,-20(s0)
  30:	0007a703          	lw	a4,0(a5)
  34:	fdf44783          	lbu	a5,-33(s0)
  38:	40f707b3          	sub	a5,a4,a5
  3c:	0017b793          	seqz	a5,a5
  40:	0ff7f793          	andi	a5,a5,255
  44:	00078663          	beqz	a5,50 <.L2>
  48:	00100793          	li	a5,1
  4c:	0080006f          	j	54 <.L3>

00000050 <.L2>:
  50:	00000793          	li	a5,0

00000054 <.L3>:
  54:	00078513          	mv	a0,a5
  58:	02c12403          	lw	s0,44(sp)
  5c:	03010113          	addi	sp,sp,48
  60:	00008067          	ret

00000064 <_ZL4itoaijjjPcj>:
  64:	fb010113          	addi	sp,sp,-80
  68:	04112623          	sw	ra,76(sp)
  6c:	04812423          	sw	s0,72(sp)
  70:	05010413          	addi	s0,sp,80
  74:	fca42623          	sw	a0,-52(s0)
  78:	fcb42423          	sw	a1,-56(s0)
  7c:	fcc42223          	sw	a2,-60(s0)
  80:	fcd42023          	sw	a3,-64(s0)
  84:	fae42e23          	sw	a4,-68(s0)
  88:	faf42c23          	sw	a5,-72(s0)
  8c:	fbc42783          	lw	a5,-68(s0)
  90:	fef42623          	sw	a5,-20(s0)
  94:	fe042423          	sw	zero,-24(s0)
  98:	fc842703          	lw	a4,-56(s0)
  9c:	01000793          	li	a5,16
  a0:	00e7f663          	bgeu	a5,a4,ac <.L5>
  a4:	00000793          	li	a5,0
  a8:	1c40006f          	j	26c <.L6>

000000ac <.L5>:
  ac:	fcc42783          	lw	a5,-52(s0)
  b0:	0207d063          	bgez	a5,d0 <.L13>
  b4:	fc042783          	lw	a5,-64(s0)
  b8:	00079c63          	bnez	a5,d0 <.L13>
  bc:	00100793          	li	a5,1
  c0:	fef42423          	sw	a5,-24(s0)
  c4:	fcc42783          	lw	a5,-52(s0)
  c8:	40f007b3          	neg	a5,a5
  cc:	fcf42623          	sw	a5,-52(s0)

000000d0 <.L13>:
  d0:	fcc42783          	lw	a5,-52(s0)
  d4:	fc842583          	lw	a1,-56(s0)
  d8:	00078513          	mv	a0,a5
  dc:	00000097          	auipc	ra,0x0
  e0:	000080e7          	jalr	ra # dc <.L13+0xc>
  e4:	00050793          	mv	a5,a0
  e8:	fef42023          	sw	a5,-32(s0)
  ec:	fe042703          	lw	a4,-32(s0)
  f0:	00900793          	li	a5,9
  f4:	00e7cc63          	blt	a5,a4,10c <.L8>
  f8:	fe042783          	lw	a5,-32(s0)
  fc:	0ff7f793          	andi	a5,a5,255
 100:	03078793          	addi	a5,a5,48
 104:	0ff7f713          	andi	a4,a5,255
 108:	0300006f          	j	138 <.L9>

0000010c <.L8>:
 10c:	fc442783          	lw	a5,-60(s0)
 110:	00078663          	beqz	a5,11c <.L10>
 114:	04100793          	li	a5,65
 118:	0080006f          	j	120 <.L11>

0000011c <.L10>:
 11c:	06100793          	li	a5,97

00000120 <.L11>:
 120:	fe042703          	lw	a4,-32(s0)
 124:	0ff77713          	andi	a4,a4,255
 128:	00e787b3          	add	a5,a5,a4
 12c:	0ff7f793          	andi	a5,a5,255
 130:	ff678793          	addi	a5,a5,-10
 134:	0ff7f713          	andi	a4,a5,255

00000138 <.L9>:
 138:	fec42783          	lw	a5,-20(s0)
 13c:	00178693          	addi	a3,a5,1
 140:	fed42623          	sw	a3,-20(s0)
 144:	00e78023          	sb	a4,0(a5)
 148:	fcc42783          	lw	a5,-52(s0)
 14c:	fc842583          	lw	a1,-56(s0)
 150:	00078513          	mv	a0,a5
 154:	00000097          	auipc	ra,0x0
 158:	000080e7          	jalr	ra # 154 <.L9+0x1c>
 15c:	00050793          	mv	a5,a0
 160:	fcf42623          	sw	a5,-52(s0)
 164:	fcc42783          	lw	a5,-52(s0)
 168:	00f05463          	blez	a5,170 <.L12>
 16c:	f65ff06f          	j	d0 <.L13>

00000170 <.L12>:
 170:	fec42703          	lw	a4,-20(s0)
 174:	fbc42783          	lw	a5,-68(s0)
 178:	40f707b3          	sub	a5,a4,a5
 17c:	fef42223          	sw	a5,-28(s0)

00000180 <.L15>:
 180:	fe442703          	lw	a4,-28(s0)
 184:	fb842783          	lw	a5,-72(s0)
 188:	02f77463          	bgeu	a4,a5,1b0 <.L14>
 18c:	fec42783          	lw	a5,-20(s0)
 190:	00178713          	addi	a4,a5,1
 194:	fee42623          	sw	a4,-20(s0)
 198:	03000713          	li	a4,48
 19c:	00e78023          	sb	a4,0(a5)
 1a0:	fe442783          	lw	a5,-28(s0)
 1a4:	00178793          	addi	a5,a5,1
 1a8:	fef42223          	sw	a5,-28(s0)
 1ac:	fd5ff06f          	j	180 <.L15>

000001b0 <.L14>:
 1b0:	fe842783          	lw	a5,-24(s0)
 1b4:	00078c63          	beqz	a5,1cc <.L16>
 1b8:	fec42783          	lw	a5,-20(s0)
 1bc:	00178713          	addi	a4,a5,1
 1c0:	fee42623          	sw	a4,-20(s0)
 1c4:	02d00713          	li	a4,45
 1c8:	00e78023          	sb	a4,0(a5)

000001cc <.L16>:
 1cc:	fec42783          	lw	a5,-20(s0)
 1d0:	00078023          	sb	zero,0(a5)
 1d4:	fec42703          	lw	a4,-20(s0)
 1d8:	fbc42783          	lw	a5,-68(s0)
 1dc:	40f707b3          	sub	a5,a4,a5
 1e0:	fcf42e23          	sw	a5,-36(s0)
 1e4:	fe042223          	sw	zero,-28(s0)

000001e8 <.L18>:
 1e8:	fdc42783          	lw	a5,-36(s0)
 1ec:	0017d793          	srli	a5,a5,0x1
 1f0:	fe442703          	lw	a4,-28(s0)
 1f4:	06f77a63          	bgeu	a4,a5,268 <.L17>
 1f8:	fbc42703          	lw	a4,-68(s0)
 1fc:	fe442783          	lw	a5,-28(s0)
 200:	00f707b3          	add	a5,a4,a5
 204:	0007c783          	lbu	a5,0(a5)
 208:	fcf40da3          	sb	a5,-37(s0)
 20c:	fdc42703          	lw	a4,-36(s0)
 210:	fe442783          	lw	a5,-28(s0)
 214:	40f707b3          	sub	a5,a4,a5
 218:	fff78793          	addi	a5,a5,-1
 21c:	fbc42703          	lw	a4,-68(s0)
 220:	00f70733          	add	a4,a4,a5
 224:	fbc42683          	lw	a3,-68(s0)
 228:	fe442783          	lw	a5,-28(s0)
 22c:	00f687b3          	add	a5,a3,a5
 230:	00074703          	lbu	a4,0(a4)
 234:	00e78023          	sb	a4,0(a5)
 238:	fdc42703          	lw	a4,-36(s0)
 23c:	fe442783          	lw	a5,-28(s0)
 240:	40f707b3          	sub	a5,a4,a5
 244:	fff78793          	addi	a5,a5,-1
 248:	fbc42703          	lw	a4,-68(s0)
 24c:	00f707b3          	add	a5,a4,a5
 250:	fdb44703          	lbu	a4,-37(s0)
 254:	00e78023          	sb	a4,0(a5)
 258:	fe442783          	lw	a5,-28(s0)
 25c:	00178793          	addi	a5,a5,1
 260:	fef42223          	sw	a5,-28(s0)
 264:	f85ff06f          	j	1e8 <.L18>

00000268 <.L17>:
 268:	fdc42783          	lw	a5,-36(s0)

0000026c <.L6>:
 26c:	00078513          	mv	a0,a5
 270:	04c12083          	lw	ra,76(sp)
 274:	04812403          	lw	s0,72(sp)
 278:	05010113          	addi	sp,sp,80
 27c:	00008067          	ret

00000280 <_ZL12write_stringPc>:
 280:	fd010113          	addi	sp,sp,-48
 284:	02112623          	sw	ra,44(sp)
 288:	02812423          	sw	s0,40(sp)
 28c:	03010413          	addi	s0,sp,48
 290:	fca42e23          	sw	a0,-36(s0)
 294:	fe042623          	sw	zero,-20(s0)
 298:	00100793          	li	a5,1
 29c:	fef42423          	sw	a5,-24(s0)

000002a0 <.L21>:
 2a0:	fec42783          	lw	a5,-20(s0)
 2a4:	fdc42703          	lw	a4,-36(s0)
 2a8:	00f707b3          	add	a5,a4,a5
 2ac:	0007c783          	lbu	a5,0(a5)
 2b0:	04078063          	beqz	a5,2f0 <.L20>
 2b4:	fec42783          	lw	a5,-20(s0)
 2b8:	fdc42703          	lw	a4,-36(s0)
 2bc:	00f707b3          	add	a5,a4,a5
 2c0:	0007c783          	lbu	a5,0(a5)
 2c4:	00078513          	mv	a0,a5
 2c8:	00000097          	auipc	ra,0x0
 2cc:	000080e7          	jalr	ra # 2c8 <.L21+0x28>
 2d0:	00050713          	mv	a4,a0
 2d4:	fe842783          	lw	a5,-24(s0)
 2d8:	00f777b3          	and	a5,a4,a5
 2dc:	fef42423          	sw	a5,-24(s0)
 2e0:	fec42783          	lw	a5,-20(s0)
 2e4:	00178793          	addi	a5,a5,1
 2e8:	fef42623          	sw	a5,-20(s0)
 2ec:	fb5ff06f          	j	2a0 <.L21>

000002f0 <.L20>:
 2f0:	00000513          	li	a0,0
 2f4:	00000097          	auipc	ra,0x0
 2f8:	000080e7          	jalr	ra # 2f4 <.L20+0x4>
 2fc:	00050713          	mv	a4,a0
 300:	fe842783          	lw	a5,-24(s0)
 304:	00f777b3          	and	a5,a4,a5
 308:	fef42423          	sw	a5,-24(s0)
 30c:	fe842783          	lw	a5,-24(s0)
 310:	00078513          	mv	a0,a5
 314:	02c12083          	lw	ra,44(sp)
 318:	02812403          	lw	s0,40(sp)
 31c:	03010113          	addi	sp,sp,48
 320:	00008067          	ret

Disassembly of section .comment:

00000000 <.comment>:
   0:	4700                	lw	s0,8(a4)
   2:	203a4343          	fmadd.s	ft6,fs4,ft3,ft4,rmm
   6:	4728                	lw	a0,72(a4)
   8:	554e                	lw	a0,240(sp)
   a:	2029                	jal	14 <_ZL10write_charc+0x14>
   c:	3031                	jal	fffff818 <.L20+0xfffff528>
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
  14:	0020                	addi	s0,sp,8
  16:	0000                	unimp
  18:	0018                	0x18
	...
  22:	0000                	unimp
  24:	4400                	lw	s0,8(s0)
  26:	300e                	fld	ft0,224(sp)
  28:	8844                	0x8844
  2a:	4401                	li	s0,0
  2c:	080c                	addi	a1,sp,16
  2e:	0200                	addi	s0,sp,256
  30:	c850                	sw	a2,20(s0)
  32:	020c                	addi	a1,sp,256
  34:	4430                	lw	a2,72(s0)
  36:	000e                	c.slli	zero,0x3
  38:	0028                	addi	a0,sp,8
  3a:	0000                	unimp
  3c:	003c                	addi	a5,sp,8
	...
  46:	0000                	unimp
  48:	4400                	lw	s0,8(s0)
  4a:	500e                	0x500e
  4c:	8148                	0x8148
  4e:	8801                	andi	s0,s0,0
  50:	4402                	lw	s0,0(sp)
  52:	080c                	addi	a1,sp,16
  54:	0300                	addi	s0,sp,384
  56:	0200                	addi	s0,sp,256
  58:	44c1                	li	s1,16
  5a:	0cc8                	addi	a0,sp,596
  5c:	5002                	0x5002
  5e:	0e44                	addi	s1,sp,788
  60:	0000                	unimp
  62:	0000                	unimp
  64:	0024                	addi	s1,sp,8
  66:	0000                	unimp
  68:	0068                	addi	a0,sp,12
	...
  72:	0000                	unimp
  74:	4400                	lw	s0,8(s0)
  76:	300e                	fld	ft0,224(sp)
  78:	8148                	0x8148
  7a:	8801                	andi	s0,s0,0
  7c:	4402                	lw	s0,0(sp)
  7e:	080c                	addi	a1,sp,16
  80:	0200                	addi	s0,sp,256
  82:	c188                	sw	a0,0(a1)
  84:	c844                	sw	s1,20(s0)
  86:	020c                	addi	a1,sp,256
  88:	4430                	lw	a2,72(s0)
  8a:	000e                	c.slli	zero,0x3

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
