
Wavetable.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <_ZN9Wavetable9initTableE8Waveform>:
   0:	f3 0f 1e fa          	endbr64 
   4:	83 fe 02             	cmp    $0x2,%esi
   7:	0f 84 4b 02 00 00    	je     258 <_ZN9Wavetable9initTableE8Waveform+0x258>
   d:	0f 87 cd 00 00 00    	ja     e0 <_ZN9Wavetable9initTableE8Waveform+0xe0>
  13:	85 f6                	test   %esi,%esi
  15:	0f 84 cd 01 00 00    	je     1e8 <_ZN9Wavetable9initTableE8Waveform+0x1e8>
  1b:	66 0f ef db          	pxor   %xmm3,%xmm3
  1f:	66 0f ef ed          	pxor   %xmm5,%xmm5
  23:	f3 0f 2a 5f 04       	cvtsi2ssl 0x4(%rdi),%xmm3
  28:	0f 2f dd             	comiss %xmm5,%xmm3
  2b:	0f 86 0f 03 00 00    	jbe    340 <_ZN9Wavetable9initTableE8Waveform+0x340>
  31:	f3 0f 10 35 00 00 00 	movss  0x0(%rip),%xmm6        # 39 <_ZN9Wavetable9initTableE8Waveform+0x39>
  38:	00 
  39:	48 8b 4f 08          	mov    0x8(%rdi),%rcx
  3d:	f3 0f 10 25 00 00 00 	movss  0x0(%rip),%xmm4        # 45 <_ZN9Wavetable9initTableE8Waveform+0x45>
  44:	00 
  45:	ba 01 00 00 00       	mov    $0x1,%edx
  4a:	f3 0f 10 3d 00 00 00 	movss  0x0(%rip),%xmm7        # 52 <_ZN9Wavetable9initTableE8Waveform+0x52>
  51:	00 
  52:	66 0f ef c0          	pxor   %xmm0,%xmm0
  56:	0f 28 ee             	movaps %xmm6,%xmm5
  59:	f3 44 0f 10 05 00 00 	movss  0x0(%rip),%xmm8        # 62 <_ZN9Wavetable9initTableE8Waveform+0x62>
  60:	00 00 
  62:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
  68:	f3 0f 5e c3          	divss  %xmm3,%xmm0
  6c:	0f 28 c8             	movaps %xmm0,%xmm1
  6f:	f3 0f 58 cc          	addss  %xmm4,%xmm1
  73:	0f 28 d1             	movaps %xmm1,%xmm2
  76:	0f 54 d5             	andps  %xmm5,%xmm2
  79:	0f 2e fa             	ucomiss %xmm2,%xmm7
  7c:	76 2e                	jbe    ac <_ZN9Wavetable9initTableE8Waveform+0xac>
  7e:	f3 0f 2c c1          	cvttss2si %xmm1,%eax
  82:	66 0f ef d2          	pxor   %xmm2,%xmm2
  86:	44 0f 28 d5          	movaps %xmm5,%xmm10
  8a:	44 0f 55 d1          	andnps %xmm1,%xmm10
  8e:	f3 0f 2a d0          	cvtsi2ss %eax,%xmm2
  92:	44 0f 28 ca          	movaps %xmm2,%xmm9
  96:	f3 44 0f c2 c9 06    	cmpnless %xmm1,%xmm9
  9c:	41 0f 28 ca          	movaps %xmm10,%xmm1
  a0:	45 0f 54 c8          	andps  %xmm8,%xmm9
  a4:	f3 41 0f 5c d1       	subss  %xmm9,%xmm2
  a9:	0f 56 ca             	orps   %xmm2,%xmm1
  ac:	f3 0f 5c c1          	subss  %xmm1,%xmm0
  b0:	0f 54 c6             	andps  %xmm6,%xmm0
  b3:	f3 0f 58 c0          	addss  %xmm0,%xmm0
  b7:	f3 0f 5c c4          	subss  %xmm4,%xmm0
  bb:	f3 0f 58 c0          	addss  %xmm0,%xmm0
  bf:	f3 0f 11 44 91 fc    	movss  %xmm0,-0x4(%rcx,%rdx,4)
  c5:	66 0f ef c0          	pxor   %xmm0,%xmm0
  c9:	f3 0f 2a c2          	cvtsi2ss %edx,%xmm0
  cd:	48 83 c2 01          	add    $0x1,%rdx
  d1:	0f 2f d8             	comiss %xmm0,%xmm3
  d4:	77 92                	ja     68 <_ZN9Wavetable9initTableE8Waveform+0x68>
  d6:	c3                   	retq   
  d7:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  de:	00 00 
  e0:	83 fe 03             	cmp    $0x3,%esi
  e3:	0f 85 f7 00 00 00    	jne    1e0 <_ZN9Wavetable9initTableE8Waveform+0x1e0>
  e9:	8b 4f 04             	mov    0x4(%rdi),%ecx
  ec:	85 c9                	test   %ecx,%ecx
  ee:	0f 8e 4c 02 00 00    	jle    340 <_ZN9Wavetable9initTableE8Waveform+0x340>
  f4:	41 89 c8             	mov    %ecx,%r8d
  f7:	8d 41 ff             	lea    -0x1(%rcx),%eax
  fa:	48 8b 77 08          	mov    0x8(%rdi),%rsi
  fe:	41 d1 f8             	sar    %r8d
 101:	83 f8 02             	cmp    $0x2,%eax
 104:	0f 86 47 02 00 00    	jbe    351 <_ZN9Wavetable9initTableE8Waveform+0x351>
 10a:	89 ca                	mov    %ecx,%edx
 10c:	66 41 0f 6e f8       	movd   %r8d,%xmm7
 111:	66 0f 6f 0d 00 00 00 	movdqa 0x0(%rip),%xmm1        # 119 <_ZN9Wavetable9initTableE8Waveform+0x119>
 118:	00 
 119:	66 0f 6f 15 00 00 00 	movdqa 0x0(%rip),%xmm2        # 121 <_ZN9Wavetable9initTableE8Waveform+0x121>
 120:	00 
 121:	c1 ea 02             	shr    $0x2,%edx
 124:	66 0f 6f 1d 00 00 00 	movdqa 0x0(%rip),%xmm3        # 12c <_ZN9Wavetable9initTableE8Waveform+0x12c>
 12b:	00 
 12c:	66 0f 70 e7 00       	pshufd $0x0,%xmm7,%xmm4
 131:	48 89 f0             	mov    %rsi,%rax
 134:	48 c1 e2 04          	shl    $0x4,%rdx
 138:	48 01 f2             	add    %rsi,%rdx
 13b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
 140:	66 0f 6f c1          	movdqa %xmm1,%xmm0
 144:	66 0f 6f f4          	movdqa %xmm4,%xmm6
 148:	66 0f fe ca          	paddd  %xmm2,%xmm1
 14c:	48 83 c0 10          	add    $0x10,%rax
 150:	66 0f 66 f0          	pcmpgtd %xmm0,%xmm6
 154:	66 0f 6f c6          	movdqa %xmm6,%xmm0
 158:	66 0f df c3          	pandn  %xmm3,%xmm0
 15c:	0f 5b c0             	cvtdq2ps %xmm0,%xmm0
 15f:	0f 11 40 f0          	movups %xmm0,-0x10(%rax)
 163:	48 39 d0             	cmp    %rdx,%rax
 166:	75 d8                	jne    140 <_ZN9Wavetable9initTableE8Waveform+0x140>
 168:	89 c8                	mov    %ecx,%eax
 16a:	83 e0 fc             	and    $0xfffffffc,%eax
 16d:	f6 c1 03             	test   $0x3,%cl
 170:	0f 84 d2 01 00 00    	je     348 <_ZN9Wavetable9initTableE8Waveform+0x348>
 176:	31 d2                	xor    %edx,%edx
 178:	41 39 c0             	cmp    %eax,%r8d
 17b:	66 0f ef c0          	pxor   %xmm0,%xmm0
 17f:	48 63 f8             	movslq %eax,%rdi
 182:	0f 9e c2             	setle  %dl
 185:	f3 0f 2a c2          	cvtsi2ss %edx,%xmm0
 189:	8d 50 01             	lea    0x1(%rax),%edx
 18c:	f3 0f 11 04 be       	movss  %xmm0,(%rsi,%rdi,4)
 191:	39 d1                	cmp    %edx,%ecx
 193:	0f 8e a7 01 00 00    	jle    340 <_ZN9Wavetable9initTableE8Waveform+0x340>
 199:	41 39 d0             	cmp    %edx,%r8d
 19c:	48 63 fa             	movslq %edx,%rdi
 19f:	66 0f ef c0          	pxor   %xmm0,%xmm0
 1a3:	0f 9e c2             	setle  %dl
 1a6:	83 c0 02             	add    $0x2,%eax
 1a9:	0f b6 d2             	movzbl %dl,%edx
 1ac:	f3 0f 2a c2          	cvtsi2ss %edx,%xmm0
 1b0:	f3 0f 11 04 be       	movss  %xmm0,(%rsi,%rdi,4)
 1b5:	39 c1                	cmp    %eax,%ecx
 1b7:	0f 8e 83 01 00 00    	jle    340 <_ZN9Wavetable9initTableE8Waveform+0x340>
 1bd:	41 39 c0             	cmp    %eax,%r8d
 1c0:	48 63 d0             	movslq %eax,%rdx
 1c3:	66 0f ef c0          	pxor   %xmm0,%xmm0
 1c7:	0f 9e c0             	setle  %al
 1ca:	0f b6 c0             	movzbl %al,%eax
 1cd:	f3 0f 2a c0          	cvtsi2ss %eax,%xmm0
 1d1:	f3 0f 11 04 96       	movss  %xmm0,(%rsi,%rdx,4)
 1d6:	c3                   	retq   
 1d7:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
 1de:	00 00 
 1e0:	c3                   	retq   
 1e1:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
 1e8:	8b 47 04             	mov    0x4(%rdi),%eax
 1eb:	85 c0                	test   %eax,%eax
 1ed:	0f 8e 4d 01 00 00    	jle    340 <_ZN9Wavetable9initTableE8Waveform+0x340>
 1f3:	66 0f ef ed          	pxor   %xmm5,%xmm5
 1f7:	41 54                	push   %r12
 1f9:	f2 0f 2a e8          	cvtsi2sd %eax,%xmm5
 1fd:	55                   	push   %rbp
 1fe:	8d 68 ff             	lea    -0x1(%rax),%ebp
 201:	53                   	push   %rbx
 202:	31 db                	xor    %ebx,%ebx
 204:	48 83 ec 10          	sub    $0x10,%rsp
 208:	4c 8b 67 08          	mov    0x8(%rdi),%r12
 20c:	f2 0f 11 6c 24 08    	movsd  %xmm5,0x8(%rsp)
 212:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
 218:	66 0f ef c0          	pxor   %xmm0,%xmm0
 21c:	f2 0f 2a c3          	cvtsi2sd %ebx,%xmm0
 220:	f2 0f 59 05 00 00 00 	mulsd  0x0(%rip),%xmm0        # 228 <_ZN9Wavetable9initTableE8Waveform+0x228>
 227:	00 
 228:	f2 0f 5e 44 24 08    	divsd  0x8(%rsp),%xmm0
 22e:	e8 00 00 00 00       	callq  233 <_ZN9Wavetable9initTableE8Waveform+0x233>
 233:	48 89 d8             	mov    %rbx,%rax
 236:	f2 0f 5a c0          	cvtsd2ss %xmm0,%xmm0
 23a:	f3 41 0f 11 04 9c    	movss  %xmm0,(%r12,%rbx,4)
 240:	48 83 c3 01          	add    $0x1,%rbx
 244:	48 39 e8             	cmp    %rbp,%rax
 247:	75 cf                	jne    218 <_ZN9Wavetable9initTableE8Waveform+0x218>
 249:	48 83 c4 10          	add    $0x10,%rsp
 24d:	5b                   	pop    %rbx
 24e:	5d                   	pop    %rbp
 24f:	41 5c                	pop    %r12
 251:	c3                   	retq   
 252:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
 258:	8b 4f 04             	mov    0x4(%rdi),%ecx
 25b:	85 c9                	test   %ecx,%ecx
 25d:	0f 8e dd 00 00 00    	jle    340 <_ZN9Wavetable9initTableE8Waveform+0x340>
 263:	66 0f ef c0          	pxor   %xmm0,%xmm0
 267:	f3 0f 10 35 00 00 00 	movss  0x0(%rip),%xmm6        # 26f <_ZN9Wavetable9initTableE8Waveform+0x26f>
 26e:	00 
 26f:	8d 41 ff             	lea    -0x1(%rcx),%eax
 272:	48 8b 77 08          	mov    0x8(%rdi),%rsi
 276:	f3 0f 2a c1          	cvtsi2ss %ecx,%xmm0
 27a:	0f 28 ee             	movaps %xmm6,%xmm5
 27d:	f3 0f 5e e8          	divss  %xmm0,%xmm5
 281:	0f 57 2d 00 00 00 00 	xorps  0x0(%rip),%xmm5        # 288 <_ZN9Wavetable9initTableE8Waveform+0x288>
 288:	83 f8 02             	cmp    $0x2,%eax
 28b:	0f 86 c7 00 00 00    	jbe    358 <_ZN9Wavetable9initTableE8Waveform+0x358>
 291:	89 ca                	mov    %ecx,%edx
 293:	66 0f 6f 0d 00 00 00 	movdqa 0x0(%rip),%xmm1        # 29b <_ZN9Wavetable9initTableE8Waveform+0x29b>
 29a:	00 
 29b:	0f 28 e5             	movaps %xmm5,%xmm4
 29e:	48 89 f0             	mov    %rsi,%rax
 2a1:	c1 ea 02             	shr    $0x2,%edx
 2a4:	66 0f 6f 15 00 00 00 	movdqa 0x0(%rip),%xmm2        # 2ac <_ZN9Wavetable9initTableE8Waveform+0x2ac>
 2ab:	00 
 2ac:	0f 28 1d 00 00 00 00 	movaps 0x0(%rip),%xmm3        # 2b3 <_ZN9Wavetable9initTableE8Waveform+0x2b3>
 2b3:	0f c6 e4 00          	shufps $0x0,%xmm4,%xmm4
 2b7:	48 c1 e2 04          	shl    $0x4,%rdx
 2bb:	48 01 f2             	add    %rsi,%rdx
 2be:	66 90                	xchg   %ax,%ax
 2c0:	66 0f 6f c1          	movdqa %xmm1,%xmm0
 2c4:	48 83 c0 10          	add    $0x10,%rax
 2c8:	66 0f fe ca          	paddd  %xmm2,%xmm1
 2cc:	0f 5b c0             	cvtdq2ps %xmm0,%xmm0
 2cf:	0f 59 c4             	mulps  %xmm4,%xmm0
 2d2:	0f 58 c3             	addps  %xmm3,%xmm0
 2d5:	0f 11 40 f0          	movups %xmm0,-0x10(%rax)
 2d9:	48 39 d0             	cmp    %rdx,%rax
 2dc:	75 e2                	jne    2c0 <_ZN9Wavetable9initTableE8Waveform+0x2c0>
 2de:	89 c8                	mov    %ecx,%eax
 2e0:	83 e0 fc             	and    $0xfffffffc,%eax
 2e3:	f6 c1 03             	test   $0x3,%cl
 2e6:	74 68                	je     350 <_ZN9Wavetable9initTableE8Waveform+0x350>
 2e8:	66 0f ef c9          	pxor   %xmm1,%xmm1
 2ec:	48 63 d0             	movslq %eax,%rdx
 2ef:	f3 0f 2a c8          	cvtsi2ss %eax,%xmm1
 2f3:	f3 0f 59 cd          	mulss  %xmm5,%xmm1
 2f7:	f3 0f 58 ce          	addss  %xmm6,%xmm1
 2fb:	f3 0f 11 0c 96       	movss  %xmm1,(%rsi,%rdx,4)
 300:	8d 50 01             	lea    0x1(%rax),%edx
 303:	39 d1                	cmp    %edx,%ecx
 305:	7e 39                	jle    340 <_ZN9Wavetable9initTableE8Waveform+0x340>
 307:	66 0f ef c9          	pxor   %xmm1,%xmm1
 30b:	48 63 fa             	movslq %edx,%rdi
 30e:	83 c0 02             	add    $0x2,%eax
 311:	f3 0f 2a ca          	cvtsi2ss %edx,%xmm1
 315:	f3 0f 59 cd          	mulss  %xmm5,%xmm1
 319:	f3 0f 58 ce          	addss  %xmm6,%xmm1
 31d:	f3 0f 11 0c be       	movss  %xmm1,(%rsi,%rdi,4)
 322:	39 c1                	cmp    %eax,%ecx
 324:	7e 1a                	jle    340 <_ZN9Wavetable9initTableE8Waveform+0x340>
 326:	66 0f ef c0          	pxor   %xmm0,%xmm0
 32a:	48 63 d0             	movslq %eax,%rdx
 32d:	f3 0f 2a c0          	cvtsi2ss %eax,%xmm0
 331:	f3 0f 59 c5          	mulss  %xmm5,%xmm0
 335:	f3 0f 58 c6          	addss  %xmm6,%xmm0
 339:	f3 0f 11 04 96       	movss  %xmm0,(%rsi,%rdx,4)
 33e:	c3                   	retq   
 33f:	90                   	nop
 340:	c3                   	retq   
 341:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
 348:	c3                   	retq   
 349:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
 350:	c3                   	retq   
 351:	31 c0                	xor    %eax,%eax
 353:	e9 1e fe ff ff       	jmpq   176 <_ZN9Wavetable9initTableE8Waveform+0x176>
 358:	31 c0                	xor    %eax,%eax
 35a:	eb 8c                	jmp    2e8 <_ZN9Wavetable9initTableE8Waveform+0x2e8>
 35c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000000360 <_ZN9Wavetable8getValueEf>:
 360:	f3 0f 1e fa          	endbr64 
 364:	66 0f ef c9          	pxor   %xmm1,%xmm1
 368:	f3 0f 5f c8          	maxss  %xmm0,%xmm1
 36c:	66 0f ef c0          	pxor   %xmm0,%xmm0
 370:	f3 0f 2a 47 04       	cvtsi2ssl 0x4(%rdi),%xmm0
 375:	f3 0f 59 c8          	mulss  %xmm0,%xmm1
 379:	f3 0f 58 0f          	addss  (%rdi),%xmm1
 37d:	0f 2f c8             	comiss %xmm0,%xmm1
 380:	f3 0f 11 0f          	movss  %xmm1,(%rdi)
 384:	72 17                	jb     39d <_ZN9Wavetable8getValueEf+0x3d>
 386:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
 38d:	00 00 00 
 390:	f3 0f 5c c8          	subss  %xmm0,%xmm1
 394:	0f 2f c8             	comiss %xmm0,%xmm1
 397:	73 f7                	jae    390 <_ZN9Wavetable8getValueEf+0x30>
 399:	f3 0f 11 0f          	movss  %xmm1,(%rdi)
 39d:	f3 0f 10 25 00 00 00 	movss  0x0(%rip),%xmm4        # 3a5 <_ZN9Wavetable8getValueEf+0x45>
 3a4:	00 
 3a5:	f3 0f 10 15 00 00 00 	movss  0x0(%rip),%xmm2        # 3ad <_ZN9Wavetable8getValueEf+0x4d>
 3ac:	00 
 3ad:	0f 28 c1             	movaps %xmm1,%xmm0
 3b0:	0f 28 d9             	movaps %xmm1,%xmm3
 3b3:	0f 54 c4             	andps  %xmm4,%xmm0
 3b6:	0f 2e d0             	ucomiss %xmm0,%xmm2
 3b9:	f3 0f 10 15 00 00 00 	movss  0x0(%rip),%xmm2        # 3c1 <_ZN9Wavetable8getValueEf+0x61>
 3c0:	00 
 3c1:	76 24                	jbe    3e7 <_ZN9Wavetable8getValueEf+0x87>
 3c3:	f3 0f 2c c1          	cvttss2si %xmm1,%eax
 3c7:	66 0f ef c0          	pxor   %xmm0,%xmm0
 3cb:	0f 55 e1             	andnps %xmm1,%xmm4
 3ce:	f3 0f 2a c0          	cvtsi2ss %eax,%xmm0
 3d2:	0f 28 d8             	movaps %xmm0,%xmm3
 3d5:	f3 0f c2 d9 06       	cmpnless %xmm1,%xmm3
 3da:	0f 54 da             	andps  %xmm2,%xmm3
 3dd:	f3 0f 5c c3          	subss  %xmm3,%xmm0
 3e1:	0f 28 dc             	movaps %xmm4,%xmm3
 3e4:	0f 56 d8             	orps   %xmm0,%xmm3
 3e7:	f3 0f 2c c3          	cvttss2si %xmm3,%eax
 3eb:	f3 0f 58 d3          	addss  %xmm3,%xmm2
 3ef:	48 8b 57 08          	mov    0x8(%rdi),%rdx
 3f3:	f3 0f 5c cb          	subss  %xmm3,%xmm1
 3f7:	48 98                	cltq   
 3f9:	f3 0f 10 24 82       	movss  (%rdx,%rax,4),%xmm4
 3fe:	f3 0f 2c c2          	cvttss2si %xmm2,%eax
 402:	f3 0f 5c d3          	subss  %xmm3,%xmm2
 406:	48 98                	cltq   
 408:	f3 0f 10 04 82       	movss  (%rdx,%rax,4),%xmm0
 40d:	f3 0f 5c c4          	subss  %xmm4,%xmm0
 411:	f3 0f 59 c8          	mulss  %xmm0,%xmm1
 415:	0f 28 c2             	movaps %xmm2,%xmm0
 418:	f3 0f 59 c1          	mulss  %xmm1,%xmm0
 41c:	f3 0f 58 c4          	addss  %xmm4,%xmm0
 420:	c3                   	retq   
