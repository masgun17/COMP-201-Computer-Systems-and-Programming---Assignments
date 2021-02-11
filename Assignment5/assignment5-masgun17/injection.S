
injection:     file format elf32-i386


Disassembly of section .init:

08049000 <_init>:
 8049000:	f3 0f 1e fb          	endbr32 
 8049004:	53                   	push   %ebx
 8049005:	83 ec 08             	sub    $0x8,%esp
 8049008:	e8 03 01 00 00       	call   8049110 <__x86.get_pc_thunk.bx>
 804900d:	81 c3 f3 2f 00 00    	add    $0x2ff3,%ebx
 8049013:	8b 83 fc ff ff ff    	mov    -0x4(%ebx),%eax
 8049019:	85 c0                	test   %eax,%eax
 804901b:	74 02                	je     804901f <_init+0x1f>
 804901d:	ff d0                	call   *%eax
 804901f:	83 c4 08             	add    $0x8,%esp
 8049022:	5b                   	pop    %ebx
 8049023:	c3                   	ret    

Disassembly of section .plt:

08049030 <.plt>:
 8049030:	ff 35 04 c0 04 08    	pushl  0x804c004
 8049036:	ff 25 08 c0 04 08    	jmp    *0x804c008
 804903c:	0f 1f 40 00          	nopl   0x0(%eax)
 8049040:	f3 0f 1e fb          	endbr32 
 8049044:	68 00 00 00 00       	push   $0x0
 8049049:	e9 e2 ff ff ff       	jmp    8049030 <.plt>
 804904e:	66 90                	xchg   %ax,%ax
 8049050:	f3 0f 1e fb          	endbr32 
 8049054:	68 08 00 00 00       	push   $0x8
 8049059:	e9 d2 ff ff ff       	jmp    8049030 <.plt>
 804905e:	66 90                	xchg   %ax,%ax
 8049060:	f3 0f 1e fb          	endbr32 
 8049064:	68 10 00 00 00       	push   $0x10
 8049069:	e9 c2 ff ff ff       	jmp    8049030 <.plt>
 804906e:	66 90                	xchg   %ax,%ax
 8049070:	f3 0f 1e fb          	endbr32 
 8049074:	68 18 00 00 00       	push   $0x18
 8049079:	e9 b2 ff ff ff       	jmp    8049030 <.plt>
 804907e:	66 90                	xchg   %ax,%ax

Disassembly of section .plt.sec:

08049080 <printf@plt>:
 8049080:	f3 0f 1e fb          	endbr32 
 8049084:	ff 25 0c c0 04 08    	jmp    *0x804c00c
 804908a:	66 0f 1f 44 00 00    	nopw   0x0(%eax,%eax,1)

08049090 <puts@plt>:
 8049090:	f3 0f 1e fb          	endbr32 
 8049094:	ff 25 10 c0 04 08    	jmp    *0x804c010
 804909a:	66 0f 1f 44 00 00    	nopw   0x0(%eax,%eax,1)

080490a0 <__libc_start_main@plt>:
 80490a0:	f3 0f 1e fb          	endbr32 
 80490a4:	ff 25 14 c0 04 08    	jmp    *0x804c014
 80490aa:	66 0f 1f 44 00 00    	nopw   0x0(%eax,%eax,1)

080490b0 <__isoc99_scanf@plt>:
 80490b0:	f3 0f 1e fb          	endbr32 
 80490b4:	ff 25 18 c0 04 08    	jmp    *0x804c018
 80490ba:	66 0f 1f 44 00 00    	nopw   0x0(%eax,%eax,1)

Disassembly of section .text:

080490c0 <_start>:
 80490c0:	f3 0f 1e fb          	endbr32 
 80490c4:	31 ed                	xor    %ebp,%ebp
 80490c6:	5e                   	pop    %esi
 80490c7:	89 e1                	mov    %esp,%ecx
 80490c9:	83 e4 f0             	and    $0xfffffff0,%esp
 80490cc:	50                   	push   %eax
 80490cd:	54                   	push   %esp
 80490ce:	52                   	push   %edx
 80490cf:	e8 23 00 00 00       	call   80490f7 <_start+0x37>
 80490d4:	81 c3 2c 2f 00 00    	add    $0x2f2c,%ebx
 80490da:	8d 83 40 d3 ff ff    	lea    -0x2cc0(%ebx),%eax
 80490e0:	50                   	push   %eax
 80490e1:	8d 83 d0 d2 ff ff    	lea    -0x2d30(%ebx),%eax
 80490e7:	50                   	push   %eax
 80490e8:	51                   	push   %ecx
 80490e9:	56                   	push   %esi
 80490ea:	c7 c0 8f 92 04 08    	mov    $0x804928f,%eax
 80490f0:	50                   	push   %eax
 80490f1:	e8 aa ff ff ff       	call   80490a0 <__libc_start_main@plt>
 80490f6:	f4                   	hlt    
 80490f7:	8b 1c 24             	mov    (%esp),%ebx
 80490fa:	c3                   	ret    
 80490fb:	66 90                	xchg   %ax,%ax
 80490fd:	66 90                	xchg   %ax,%ax
 80490ff:	90                   	nop

08049100 <_dl_relocate_static_pie>:
 8049100:	f3 0f 1e fb          	endbr32 
 8049104:	c3                   	ret    
 8049105:	66 90                	xchg   %ax,%ax
 8049107:	66 90                	xchg   %ax,%ax
 8049109:	66 90                	xchg   %ax,%ax
 804910b:	66 90                	xchg   %ax,%ax
 804910d:	66 90                	xchg   %ax,%ax
 804910f:	90                   	nop

08049110 <__x86.get_pc_thunk.bx>:
 8049110:	8b 1c 24             	mov    (%esp),%ebx
 8049113:	c3                   	ret    
 8049114:	66 90                	xchg   %ax,%ax
 8049116:	66 90                	xchg   %ax,%ax
 8049118:	66 90                	xchg   %ax,%ax
 804911a:	66 90                	xchg   %ax,%ax
 804911c:	66 90                	xchg   %ax,%ax
 804911e:	66 90                	xchg   %ax,%ax

08049120 <deregister_tm_clones>:
 8049120:	b8 28 c0 04 08       	mov    $0x804c028,%eax
 8049125:	3d 28 c0 04 08       	cmp    $0x804c028,%eax
 804912a:	74 24                	je     8049150 <deregister_tm_clones+0x30>
 804912c:	b8 00 00 00 00       	mov    $0x0,%eax
 8049131:	85 c0                	test   %eax,%eax
 8049133:	74 1b                	je     8049150 <deregister_tm_clones+0x30>
 8049135:	55                   	push   %ebp
 8049136:	89 e5                	mov    %esp,%ebp
 8049138:	83 ec 14             	sub    $0x14,%esp
 804913b:	68 28 c0 04 08       	push   $0x804c028
 8049140:	ff d0                	call   *%eax
 8049142:	83 c4 10             	add    $0x10,%esp
 8049145:	c9                   	leave  
 8049146:	c3                   	ret    
 8049147:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
 804914e:	66 90                	xchg   %ax,%ax
 8049150:	c3                   	ret    
 8049151:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
 8049158:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
 804915f:	90                   	nop

08049160 <register_tm_clones>:
 8049160:	b8 28 c0 04 08       	mov    $0x804c028,%eax
 8049165:	2d 28 c0 04 08       	sub    $0x804c028,%eax
 804916a:	89 c2                	mov    %eax,%edx
 804916c:	c1 e8 1f             	shr    $0x1f,%eax
 804916f:	c1 fa 02             	sar    $0x2,%edx
 8049172:	01 d0                	add    %edx,%eax
 8049174:	d1 f8                	sar    %eax
 8049176:	74 20                	je     8049198 <register_tm_clones+0x38>
 8049178:	ba 00 00 00 00       	mov    $0x0,%edx
 804917d:	85 d2                	test   %edx,%edx
 804917f:	74 17                	je     8049198 <register_tm_clones+0x38>
 8049181:	55                   	push   %ebp
 8049182:	89 e5                	mov    %esp,%ebp
 8049184:	83 ec 10             	sub    $0x10,%esp
 8049187:	50                   	push   %eax
 8049188:	68 28 c0 04 08       	push   $0x804c028
 804918d:	ff d2                	call   *%edx
 804918f:	83 c4 10             	add    $0x10,%esp
 8049192:	c9                   	leave  
 8049193:	c3                   	ret    
 8049194:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
 8049198:	c3                   	ret    
 8049199:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi

080491a0 <__do_global_dtors_aux>:
 80491a0:	f3 0f 1e fb          	endbr32 
 80491a4:	80 3d 28 c0 04 08 00 	cmpb   $0x0,0x804c028
 80491ab:	75 1b                	jne    80491c8 <__do_global_dtors_aux+0x28>
 80491ad:	55                   	push   %ebp
 80491ae:	89 e5                	mov    %esp,%ebp
 80491b0:	83 ec 08             	sub    $0x8,%esp
 80491b3:	e8 68 ff ff ff       	call   8049120 <deregister_tm_clones>
 80491b8:	c6 05 28 c0 04 08 01 	movb   $0x1,0x804c028
 80491bf:	c9                   	leave  
 80491c0:	c3                   	ret    
 80491c1:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
 80491c8:	c3                   	ret    
 80491c9:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi

080491d0 <frame_dummy>:
 80491d0:	f3 0f 1e fb          	endbr32 
 80491d4:	eb 8a                	jmp    8049160 <register_tm_clones>

080491d6 <transfer_money>:
 80491d6:	f3 0f 1e fb          	endbr32 
 80491da:	55                   	push   %ebp
 80491db:	89 e5                	mov    %esp,%ebp
 80491dd:	83 ec 08             	sub    $0x8,%esp
 80491e0:	83 ec 0c             	sub    $0xc,%esp
 80491e3:	68 08 a0 04 08       	push   $0x804a008
 80491e8:	e8 a3 fe ff ff       	call   8049090 <puts@plt>
 80491ed:	83 c4 10             	add    $0x10,%esp
 80491f0:	90                   	nop
 80491f1:	c9                   	leave  
 80491f2:	c3                   	ret    

080491f3 <check_password>:
 80491f3:	f3 0f 1e fb          	endbr32 
 80491f7:	55                   	push   %ebp
 80491f8:	89 e5                	mov    %esp,%ebp
 80491fa:	83 ec 78             	sub    $0x78,%esp
 80491fd:	83 ec 0c             	sub    $0xc,%esp
 8049200:	68 2f a0 04 08       	push   $0x804a02f
 8049205:	e8 86 fe ff ff       	call   8049090 <puts@plt>
 804920a:	83 c4 10             	add    $0x10,%esp
 804920d:	83 ec 08             	sub    $0x8,%esp
 8049210:	8d 45 94             	lea    -0x6c(%ebp),%eax
 8049213:	50                   	push   %eax
 8049214:	68 3f a0 04 08       	push   $0x804a03f
 8049219:	e8 92 fe ff ff       	call   80490b0 <__isoc99_scanf@plt>
 804921e:	83 c4 10             	add    $0x10,%esp
 8049221:	83 ec 08             	sub    $0x8,%esp
 8049224:	8d 45 94             	lea    -0x6c(%ebp),%eax
 8049227:	50                   	push   %eax
 8049228:	68 42 a0 04 08       	push   $0x804a042
 804922d:	e8 4e fe ff ff       	call   8049080 <printf@plt>
 8049232:	83 c4 10             	add    $0x10,%esp
 8049235:	83 ec 0c             	sub    $0xc,%esp
 8049238:	68 59 a0 04 08       	push   $0x804a059
 804923d:	e8 4e fe ff ff       	call   8049090 <puts@plt>
 8049242:	83 c4 10             	add    $0x10,%esp
 8049245:	83 ec 08             	sub    $0x8,%esp
 8049248:	8d 45 90             	lea    -0x70(%ebp),%eax
 804924b:	50                   	push   %eax
 804924c:	68 64 a0 04 08       	push   $0x804a064
 8049251:	e8 5a fe ff ff       	call   80490b0 <__isoc99_scanf@plt>
 8049256:	83 c4 10             	add    $0x10,%esp
 8049259:	8b 55 90             	mov    -0x70(%ebp),%edx
 804925c:	a1 24 c0 04 08       	mov    0x804c024,%eax
 8049261:	39 c2                	cmp    %eax,%edx
 8049263:	75 17                	jne    804927c <check_password+0x89>
 8049265:	83 ec 0c             	sub    $0xc,%esp
 8049268:	68 67 a0 04 08       	push   $0x804a067
 804926d:	e8 1e fe ff ff       	call   8049090 <puts@plt>
 8049272:	83 c4 10             	add    $0x10,%esp
 8049275:	e8 5c ff ff ff       	call   80491d6 <transfer_money>
 804927a:	eb 10                	jmp    804928c <check_password+0x99>
 804927c:	83 ec 0c             	sub    $0xc,%esp
 804927f:	68 82 a0 04 08       	push   $0x804a082
 8049284:	e8 07 fe ff ff       	call   8049090 <puts@plt>
 8049289:	83 c4 10             	add    $0x10,%esp
 804928c:	90                   	nop
 804928d:	c9                   	leave  
 804928e:	c3                   	ret    

0804928f <main>:
 804928f:	f3 0f 1e fb          	endbr32 
 8049293:	55                   	push   %ebp
 8049294:	89 e5                	mov    %esp,%ebp
 8049296:	83 e4 f0             	and    $0xfffffff0,%esp
 8049299:	e8 55 ff ff ff       	call   80491f3 <check_password>
 804929e:	b8 00 00 00 00       	mov    $0x0,%eax
 80492a3:	c9                   	leave  
 80492a4:	c3                   	ret    

080492a5 <injectCode>:
 80492a5:	f3 0f 1e fb          	endbr32 
 80492a9:	55                   	push   %ebp
 80492aa:	89 e5                	mov    %esp,%ebp
 80492ac:	83 ec 08             	sub    $0x8,%esp
 80492af:	83 ec 0c             	sub    $0xc,%esp
 80492b2:	68 94 a0 04 08       	push   $0x804a094
 80492b7:	e8 d4 fd ff ff       	call   8049090 <puts@plt>
 80492bc:	83 c4 10             	add    $0x10,%esp
 80492bf:	e8 12 ff ff ff       	call   80491d6 <transfer_money>
 80492c4:	90                   	nop
 80492c5:	c9                   	leave  
 80492c6:	c3                   	ret    
 80492c7:	66 90                	xchg   %ax,%ax
 80492c9:	66 90                	xchg   %ax,%ax
 80492cb:	66 90                	xchg   %ax,%ax
 80492cd:	66 90                	xchg   %ax,%ax
 80492cf:	90                   	nop

080492d0 <__libc_csu_init>:
 80492d0:	f3 0f 1e fb          	endbr32 
 80492d4:	55                   	push   %ebp
 80492d5:	e8 6b 00 00 00       	call   8049345 <__x86.get_pc_thunk.bp>
 80492da:	81 c5 26 2d 00 00    	add    $0x2d26,%ebp
 80492e0:	57                   	push   %edi
 80492e1:	56                   	push   %esi
 80492e2:	53                   	push   %ebx
 80492e3:	83 ec 0c             	sub    $0xc,%esp
 80492e6:	89 eb                	mov    %ebp,%ebx
 80492e8:	8b 7c 24 28          	mov    0x28(%esp),%edi
 80492ec:	e8 0f fd ff ff       	call   8049000 <_init>
 80492f1:	8d 9d 10 ff ff ff    	lea    -0xf0(%ebp),%ebx
 80492f7:	8d 85 0c ff ff ff    	lea    -0xf4(%ebp),%eax
 80492fd:	29 c3                	sub    %eax,%ebx
 80492ff:	c1 fb 02             	sar    $0x2,%ebx
 8049302:	74 29                	je     804932d <__libc_csu_init+0x5d>
 8049304:	31 f6                	xor    %esi,%esi
 8049306:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
 804930d:	8d 76 00             	lea    0x0(%esi),%esi
 8049310:	83 ec 04             	sub    $0x4,%esp
 8049313:	57                   	push   %edi
 8049314:	ff 74 24 2c          	pushl  0x2c(%esp)
 8049318:	ff 74 24 2c          	pushl  0x2c(%esp)
 804931c:	ff 94 b5 0c ff ff ff 	call   *-0xf4(%ebp,%esi,4)
 8049323:	83 c6 01             	add    $0x1,%esi
 8049326:	83 c4 10             	add    $0x10,%esp
 8049329:	39 f3                	cmp    %esi,%ebx
 804932b:	75 e3                	jne    8049310 <__libc_csu_init+0x40>
 804932d:	83 c4 0c             	add    $0xc,%esp
 8049330:	5b                   	pop    %ebx
 8049331:	5e                   	pop    %esi
 8049332:	5f                   	pop    %edi
 8049333:	5d                   	pop    %ebp
 8049334:	c3                   	ret    
 8049335:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
 804933c:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi

08049340 <__libc_csu_fini>:
 8049340:	f3 0f 1e fb          	endbr32 
 8049344:	c3                   	ret    

08049345 <__x86.get_pc_thunk.bp>:
 8049345:	8b 2c 24             	mov    (%esp),%ebp
 8049348:	c3                   	ret    

Disassembly of section .fini:

0804934c <_fini>:
 804934c:	f3 0f 1e fb          	endbr32 
 8049350:	53                   	push   %ebx
 8049351:	83 ec 08             	sub    $0x8,%esp
 8049354:	e8 b7 fd ff ff       	call   8049110 <__x86.get_pc_thunk.bx>
 8049359:	81 c3 a7 2c 00 00    	add    $0x2ca7,%ebx
 804935f:	83 c4 08             	add    $0x8,%esp
 8049362:	5b                   	pop    %ebx
 8049363:	c3                   	ret    
