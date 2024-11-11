void std::__insertion_sort<edge*, __gnu_cxx::__ops::_Iter_comp_iter<kruskal()::{lambda(edge const&, edge const&)#1}> >(edge*, edge*, __gnu_cxx::__ops::_Iter_comp_iter<kruskal()::{lambda(edge const&, edge const&)#1}>) [clone .constprop.0]:
        cmp     rdi, OFFSET FLAT:e+12
        je      .L18
        cmp     rdi, OFFSET FLAT:e+24
        je      .L18
        sub     rdi, OFFSET FLAT:e+36
        push    r14
        and     rdi, -4
        push    r13
        lea     r13, e[rdi+36]
        push    r12
        mov     r12d, 12
        push    rbp
        push    rbx
        mov     ebx, OFFSET FLAT:e+24
        jmp     .L10
.L23:
        mov     rdx, rbx
        sub     rdx, OFFSET FLAT:e+12
        cmp     rdx, 12
        jle     .L5
        mov     rdi, r12
        mov     esi, OFFSET FLAT:e+12
        sub     rdi, rdx
        add     rdi, rbx
        call    memmove
.L6:
        add     rbx, 12
        mov     QWORD PTR e[rip+12], r14
        mov     DWORD PTR e[rip+20], ebp
        cmp     rbx, r13
        je      .L22
.L10:
        mov     ebp, DWORD PTR [rbx+8]
        cmp     ebp, DWORD PTR e[rip+20]
        mov     r14, QWORD PTR [rbx]
        jl      .L23
        lea     rax, [rbx-12]
        cmp     ebp, DWORD PTR [rbx-4]
        jge     .L11
.L9:
        mov     rdx, QWORD PTR [rax]
        mov     QWORD PTR [rax+12], rdx
        mov     edx, DWORD PTR [rax+8]
        mov     DWORD PTR [rax+20], edx
        mov     rdx, rax
        sub     rax, 12
        cmp     ebp, DWORD PTR [rax+8]
        jl      .L9
        mov     QWORD PTR [rdx], r14
        mov     DWORD PTR [rdx+8], ebp
.L24:
        add     rbx, 12
        cmp     rbx, r13
        jne     .L10
.L22:
        pop     rbx
        pop     rbp
        pop     r12
        pop     r13
        pop     r14
        ret
.L5:
        jne     .L6
        mov     rax, QWORD PTR e[rip+12]
        mov     QWORD PTR [rbx], rax
        mov     eax, DWORD PTR e[rip+20]
        mov     DWORD PTR [rbx+8], eax
        jmp     .L6
.L11:
        mov     rdx, rbx
        mov     QWORD PTR [rdx], r14
        mov     DWORD PTR [rdx+8], ebp
        jmp     .L24
.L18:
        ret
void std::__adjust_heap<edge*, long, edge, __gnu_cxx::__ops::_Iter_comp_iter<kruskal()::{lambda(edge const&, edge const&)#1}> >(edge*, long, long, edge, __gnu_cxx::__ops::_Iter_comp_iter<kruskal()::{lambda(edge const&, edge const&)#1}>) [clone .isra.0]:
        lea     rax, [rdx-1]
        push    r14
        mov     r9, rsi
        mov     r10, rcx
        mov     r11, rax
        push    rbp
        mov     rbp, rdx
        push    rbx
        shr     r11, 63
        mov     rbx, rdx
        and     ebp, 1
        add     r11, rax
        sar     r11
        mov     QWORD PTR [rsp-16], rcx
        mov     DWORD PTR [rsp-8], r8d
        cmp     rsi, r11
        jl      .L30
        jmp     .L26
.L39:
        mov     rsi, rax
.L30:
        lea     rdx, [rsi+1]
        lea     rax, [rdx+rdx]
        lea     rcx, [rax+rdx*4]
        sal     rcx, 2
        lea     rdx, [rdi+rcx]
        mov     r14d, DWORD PTR [rdx+8]
        cmp     DWORD PTR [rdi-4+rcx], r14d
        jle     .L27
        sub     rax, 1
        lea     rdx, [rax+rax*2]
        lea     rdx, [rdi+rdx*4]
.L27:
        lea     rcx, [rsi+rsi*2]
        mov     rsi, QWORD PTR [rdx]
        lea     rcx, [rdi+rcx*4]
        mov     QWORD PTR [rcx], rsi
        mov     esi, DWORD PTR [rdx+8]
        mov     DWORD PTR [rcx+8], esi
        cmp     r11, rax
        jg      .L39
        test    rbp, rbp
        je      .L40
.L31:
        lea     rsi, [rax-1]
        mov     rcx, rsi
        shr     rcx, 63
        add     rcx, rsi
        sar     rcx
        cmp     rax, r9
        jg      .L33
        jmp     .L32
.L42:
        mov     rax, QWORD PTR [rsi]
        mov     QWORD PTR [rdx], rax
        mov     eax, DWORD PTR [rsi+8]
        mov     DWORD PTR [rdx+8], eax
        lea     rdx, [rcx-1]
        mov     rax, rdx
        shr     rax, 63
        add     rax, rdx
        sar     rax
        mov     rdx, rax
        mov     rax, rcx
        cmp     r9, rcx
        jge     .L41
        mov     rcx, rdx
.L33:
        lea     rdx, [rcx+rcx*2]
        lea     rax, [rax+rax*2]
        lea     rsi, [rdi+rdx*4]
        lea     rdx, [rdi+rax*4]
        cmp     DWORD PTR [rsi+8], r8d
        jl      .L42
.L32:
        mov     QWORD PTR [rdx], r10
        mov     DWORD PTR [rdx+8], r8d
        pop     rbx
        pop     rbp
        pop     r14
        ret
.L40:
        sub     rbx, 2
        mov     rcx, rbx
        shr     rcx, 63
        add     rcx, rbx
        sar     rcx
        cmp     rcx, rax
        jne     .L31
.L34:
        add     rax, 1
        lea     rcx, [rax+rax]
        lea     rax, [rcx+rax*4]
        lea     rax, [rdi+rax*4]
        mov     rsi, QWORD PTR [rax-12]
        mov     QWORD PTR [rdx], rsi
        mov     eax, DWORD PTR [rax-4]
        mov     DWORD PTR [rdx+8], eax
        lea     rax, [rcx-1]
        lea     rdx, [rax+rax*2]
        lea     rdx, [rdi+rdx*4]
        jmp     .L31
.L41:
        mov     rdx, rsi
        mov     QWORD PTR [rdx], r10
        mov     DWORD PTR [rdx+8], r8d
        pop     rbx
        pop     rbp
        pop     r14
        ret
.L26:
        lea     rax, [rsi+rsi*2]
        lea     rdx, [rdi+rax*4]
        test    rbp, rbp
        jne     .L32
        sub     rbx, 2
        mov     rax, rbx
        shr     rax, 63
        add     rax, rbx
        sar     rax
        cmp     rsi, rax
        jne     .L32
        mov     rax, r9
        jmp     .L34
void std::__introsort_loop<edge*, long, __gnu_cxx::__ops::_Iter_comp_iter<kruskal()::{lambda(edge const&, edge const&)#1}> >(edge*, edge*, long, __gnu_cxx::__ops::_Iter_comp_iter<kruskal()::{lambda(edge const&, edge const&)#1}>) [clone .isra.0]:
        mov     rax, rsi
        sub     rax, rdi
        cmp     rax, 192
        jle     .L68
        push    r14
        mov     r14, rdx
        push    r13
        mov     r13, rsi
        push    r12
        movabs  r12, -6148914691236517205
        push    rbp
        mov     rbp, rdi
        push    rbx
        sub     rsp, 16
.L61:
        sar     rax, 2
        imul    rax, r12
        mov     rbx, rax
        sar     rax
        test    r14, r14
        je      .L74
        lea     rax, [rax+rax*2]
        mov     ecx, DWORD PTR [rbp+20]
        mov     edi, DWORD PTR [r13-4]
        sub     r14, 1
        lea     rax, [rbp+0+rax*4]
        mov     r8, QWORD PTR [rbp+0]
        mov     edx, DWORD PTR [rbp+8]
        lea     rbx, [rbp+12]
        mov     esi, DWORD PTR [rax+8]
        cmp     ecx, esi
        jge     .L49
        cmp     esi, edi
        jl      .L72
        cmp     ecx, edi
        jl      .L71
.L73:
        mov     rax, QWORD PTR [rbp+12]
        mov     DWORD PTR [rbp+8], ecx
        mov     QWORD PTR [rbp+12], r8
        mov     QWORD PTR [rbp+0], rax
        mov     DWORD PTR [rbp+20], edx
        mov     esi, DWORD PTR [r13-4]
.L53:
        mov     rax, r13
.L51:
        mov     ecx, DWORD PTR [rbp+8]
        cmp     ecx, edx
        jle     .L56
.L57:
        mov     edx, DWORD PTR [rbx+20]
        add     rbx, 12
        cmp     ecx, edx
        jg      .L57
.L56:
        sub     rax, 12
        cmp     ecx, esi
        jge     .L58
.L59:
        sub     rax, 12
        cmp     ecx, DWORD PTR [rax+8]
        jl      .L59
.L58:
        cmp     rbx, rax
        jnb     .L75
        mov     rsi, QWORD PTR [rax]
        mov     rcx, QWORD PTR [rbx]
        add     rbx, 12
        mov     QWORD PTR [rbx-12], rsi
        mov     esi, DWORD PTR [rax+8]
        mov     DWORD PTR [rbx-4], esi
        mov     esi, DWORD PTR [rax-4]
        mov     QWORD PTR [rax], rcx
        mov     DWORD PTR [rax+8], edx
        mov     edx, DWORD PTR [rbx+8]
        jmp     .L51
.L49:
        cmp     ecx, edi
        jl      .L73
        cmp     esi, edi
        jge     .L72
.L71:
        mov     rax, QWORD PTR [r13-12]
        mov     esi, edx
        mov     QWORD PTR [rbp+0], rax
        mov     eax, DWORD PTR [r13-4]
        mov     DWORD PTR [rbp+8], eax
        mov     QWORD PTR [r13-12], r8
        mov     DWORD PTR [r13-4], edx
        mov     edx, DWORD PTR [rbp+20]
        jmp     .L53
.L75:
        mov     rdx, r14
        mov     rsi, r13
        mov     rdi, rbx
        call    void std::__introsort_loop<edge*, long, __gnu_cxx::__ops::_Iter_comp_iter<kruskal()::{lambda(edge const&, edge const&)#1}> >(edge*, edge*, long, __gnu_cxx::__ops::_Iter_comp_iter<kruskal()::{lambda(edge const&, edge const&)#1}>) [clone .isra.0]
        mov     rax, rbx
        sub     rax, rbp
        cmp     rax, 192
        jle     .L43
        mov     r13, rbx
        jmp     .L61
.L72:
        mov     rcx, QWORD PTR [rax]
        mov     QWORD PTR [rbp+0], rcx
        mov     ecx, DWORD PTR [rax+8]
        mov     DWORD PTR [rbp+8], ecx
        mov     QWORD PTR [rax], r8
        mov     DWORD PTR [rax+8], edx
        mov     edx, DWORD PTR [rbp+20]
        mov     esi, DWORD PTR [r13-4]
        jmp     .L53
.L74:
        lea     r12, [rax-1]
        jmp     .L48
.L46:
        sub     r12, 1
.L48:
        lea     rax, [r12+r12*2]
        mov     rdx, rbx
        mov     rsi, r12
        mov     rdi, rbp
        mov     rcx, QWORD PTR [rbp+0+rax*4]
        mov     r8d, DWORD PTR [rbp+8+rax*4]
        mov     QWORD PTR [rsp+4], rcx
        mov     DWORD PTR [rsp+12], r8d
        call    void std::__adjust_heap<edge*, long, edge, __gnu_cxx::__ops::_Iter_comp_iter<kruskal()::{lambda(edge const&, edge const&)#1}> >(edge*, long, long, edge, __gnu_cxx::__ops::_Iter_comp_iter<kruskal()::{lambda(edge const&, edge const&)#1}>) [clone .isra.0]
        test    r12, r12
        jne     .L46
        movabs  r12, -6148914691236517205
        mov     rax, r13
        sub     rax, rbp
        cmp     rax, 12
        jle     .L43
.L47:
        sub     r13, 12
        mov     rax, QWORD PTR [rbp+0]
        mov     rcx, QWORD PTR [r13+0]
        xor     esi, esi
        mov     rbx, r13
        mov     r8d, DWORD PTR [r13+8]
        mov     rdi, rbp
        sub     rbx, rbp
        mov     QWORD PTR [r13+0], rax
        mov     eax, DWORD PTR [rbp+8]
        mov     rdx, rbx
        mov     QWORD PTR [rsp+4], rcx
        sar     rdx, 2
        mov     DWORD PTR [r13+8], eax
        imul    rdx, r12
        mov     DWORD PTR [rsp+12], r8d
        call    void std::__adjust_heap<edge*, long, edge, __gnu_cxx::__ops::_Iter_comp_iter<kruskal()::{lambda(edge const&, edge const&)#1}> >(edge*, long, long, edge, __gnu_cxx::__ops::_Iter_comp_iter<kruskal()::{lambda(edge const&, edge const&)#1}>) [clone .isra.0]
        cmp     rbx, 12
        jg      .L47
.L43:
        add     rsp, 16
        pop     rbx
        pop     rbp
        pop     r12
        pop     r13
        pop     r14
        ret
.L68:
        ret
read():
        push    rbp
        push    rbx
        sub     rsp, 8
        mov     rdi, QWORD PTR stdin[rip]
        mov     rax, QWORD PTR [rdi+8]
        mov     r8, QWORD PTR [rdi+16]
        cmp     rax, r8
        jnb     .L91
        lea     rsi, [rax+1]
        mov     QWORD PTR [rdi+8], rsi
        movzx   edx, BYTE PTR [rax]
        mov     ecx, edx
.L78:
        sub     ecx, 48
        cmp     cl, 9
        jbe     .L88
        mov     ebp, 1
        jmp     .L82
.L80:
        lea     rcx, [rsi+1]
        mov     QWORD PTR [rdi+8], rcx
        movzx   edx, BYTE PTR [rsi]
        lea     eax, [rdx-48]
        cmp     al, 9
        jbe     .L79
.L81:
        mov     rsi, rcx
.L82:
        xor     eax, eax
        cmp     dl, 45
        setne   al
        and     ebp, eax
        cmp     rsi, r8
        jb      .L80
        call    __uflow
        mov     rdi, QWORD PTR stdin[rip]
        mov     edx, eax
        sub     eax, 48
        mov     rcx, QWORD PTR [rdi+8]
        mov     r8, QWORD PTR [rdi+16]
        cmp     al, 9
        ja      .L81
.L79:
        xor     ebx, ebx
        jmp     .L86
.L84:
        mov     rcx, QWORD PTR [rdi+8]
        mov     r8, QWORD PTR [rdi+16]
.L86:
        xor     edx, 48
        lea     eax, [rbx+rbx*4]
        movsx   edx, dl
        lea     ebx, [rdx+rax*2]
        cmp     rcx, r8
        jnb     .L92
        lea     rax, [rcx+1]
        mov     QWORD PTR [rdi+8], rax
        movzx   edx, BYTE PTR [rcx]
        lea     eax, [rdx-48]
        cmp     al, 9
        jbe     .L84
.L85:
        mov     eax, ebx
        neg     eax
        test    ebp, ebp
        cmove   ebx, eax
        add     rsp, 8
        mov     eax, ebx
        pop     rbx
        pop     rbp
        ret
.L92:
        call    __uflow
        mov     edx, eax
        sub     eax, 48
        cmp     al, 9
        ja      .L85
        mov     rdi, QWORD PTR stdin[rip]
        jmp     .L84
.L88:
        mov     rcx, rsi
        mov     ebp, 1
        jmp     .L79
.L91:
        call    __uflow
        mov     rdi, QWORD PTR stdin[rip]
        mov     edx, eax
        mov     ecx, eax
        mov     rsi, QWORD PTR [rdi+8]
        mov     r8, QWORD PTR [rdi+16]
        jmp     .L78
kruskal():
        push    r14
        push    r13
        push    r12
        push    rbp
        push    rbx
        sub     rsp, 16
        movsx   rax, DWORD PTR m[rip]
        lea     rbp, [rax+3+rax*2]
        mov     r11, rax
        sal     rbp, 2
        cmp     rbp, 12
        je      .L94
        lea     rax, [rbp-12]
        mov     r14, -2
        movabs  rcx, -6148914691236517205
        mov     rdx, rax
        sar     rdx, 2
        imul    rdx, rcx
        test    rdx, rdx
        je      .L95
        bsr     rdx, rdx
        movsx   rdx, edx
        lea     r14, [rdx+rdx]
.L95:
        add     rbp, OFFSET FLAT:e
        cmp     rax, 192
        jle     .L96
        movabs  r12, -6148914691236517205
        mov     r13, rbp
.L115:
        sar     rax, 2
        imul    rax, r12
        mov     rbx, rax
        sar     rax
        test    r14, r14
        je      .L157
        lea     rdi, [rax+rax*2]
        mov     eax, DWORD PTR e[rip+32]
        mov     r8d, DWORD PTR [r13-4]
        sub     r14, 1
        lea     rsi, e[12+rdi*4]
        mov     r9, QWORD PTR e[rip+12]
        mov     edx, DWORD PTR e[rip+20]
        mov     ecx, DWORD PTR [rsi+8]
        cmp     eax, ecx
        jge     .L103
        cmp     ecx, r8d
        jl      .L152
        cmp     eax, r8d
        jl      .L151
.L153:
        mov     rcx, QWORD PTR e[rip+24]
        mov     DWORD PTR e[rip+20], eax
        mov     QWORD PTR e[rip+24], r9
        mov     QWORD PTR e[rip+12], rcx
        mov     DWORD PTR e[rip+32], edx
        mov     esi, DWORD PTR [r13-4]
.L107:
        mov     rax, r13
        mov     ebx, OFFSET FLAT:e+24
.L105:
        mov     ecx, DWORD PTR e[rip+20]
        cmp     ecx, edx
        jle     .L110
.L111:
        mov     edx, DWORD PTR [rbx+20]
        add     rbx, 12
        cmp     ecx, edx
        jg      .L111
.L110:
        sub     rax, 12
        cmp     ecx, esi
        jge     .L112
.L113:
        sub     rax, 12
        cmp     ecx, DWORD PTR [rax+8]
        jl      .L113
.L112:
        cmp     rbx, rax
        jnb     .L158
        mov     rsi, QWORD PTR [rax]
        mov     rcx, QWORD PTR [rbx]
        add     rbx, 12
        mov     QWORD PTR [rbx-12], rsi
        mov     esi, DWORD PTR [rax+8]
        mov     DWORD PTR [rbx-4], esi
        mov     esi, DWORD PTR [rax-4]
        mov     QWORD PTR [rax], rcx
        mov     DWORD PTR [rax+8], edx
        mov     edx, DWORD PTR [rbx+8]
        jmp     .L105
.L103:
        cmp     eax, r8d
        jl      .L153
        cmp     ecx, r8d
        jge     .L152
.L151:
        mov     rax, QWORD PTR [r13-12]
        mov     esi, edx
        mov     QWORD PTR e[rip+12], rax
        mov     eax, DWORD PTR [r13-4]
        mov     DWORD PTR e[rip+20], eax
        mov     QWORD PTR [r13-12], r9
        mov     DWORD PTR [r13-4], edx
        mov     edx, DWORD PTR e[rip+32]
        jmp     .L107
.L158:
        mov     rdx, r14
        mov     rsi, r13
        mov     rdi, rbx
        call    void std::__introsort_loop<edge*, long, __gnu_cxx::__ops::_Iter_comp_iter<kruskal()::{lambda(edge const&, edge const&)#1}> >(edge*, edge*, long, __gnu_cxx::__ops::_Iter_comp_iter<kruskal()::{lambda(edge const&, edge const&)#1}>) [clone .isra.0]
        mov     rax, rbx
        sub     rax, OFFSET FLAT:e+12
        cmp     rax, 192
        jle     .L116
        mov     r13, rbx
        jmp     .L115
.L152:
        mov     rax, QWORD PTR e[12+rdi*4]
        mov     QWORD PTR e[rip+12], rax
        mov     eax, DWORD PTR [rsi+8]
        mov     DWORD PTR e[rip+20], eax
        mov     QWORD PTR e[12+rdi*4], r9
        mov     DWORD PTR [rsi+8], edx
        mov     edx, DWORD PTR e[rip+32]
        mov     esi, DWORD PTR [r13-4]
        jmp     .L107
.L96:
        mov     rdi, rbp
        call    void std::__insertion_sort<edge*, __gnu_cxx::__ops::_Iter_comp_iter<kruskal()::{lambda(edge const&, edge const&)#1}> >(edge*, edge*, __gnu_cxx::__ops::_Iter_comp_iter<kruskal()::{lambda(edge const&, edge const&)#1}>) [clone .constprop.0]
.L154:
        mov     r11d, DWORD PTR m[rip]
.L94:
        test    r11d, r11d
        jle     .L93
        mov     eax, DWORD PTR n[rip]
        mov     r10d, DWORD PTR ans[rip]
        mov     edi, OFFSET FLAT:e+12
        xor     ebp, ebp
        mov     r9d, DWORD PTR tot[rip]
        mov     r8d, 1
        lea     ebx, [rax-1]
.L126:
        movsx   r12, DWORD PTR [rdi]
        movsx   rax, DWORD PTR fa[0+r12*4]
        mov     rdx, r12
        cmp     r12d, eax
        je      .L121
.L122:
        movsx   r12, DWORD PTR fa[0+rax*4]
        mov     ecx, edx
        movsx   rax, ecx
        mov     DWORD PTR fa[0+rax*4], r12d
        movsx   rax, DWORD PTR fa[0+r12*4]
        mov     rdx, r12
        cmp     eax, r12d
        jne     .L122
.L121:
        movsx   rcx, DWORD PTR [rdi+4]
        mov     rax, rcx
        movsx   rcx, DWORD PTR fa[0+rcx*4]
        cmp     eax, ecx
        je      .L123
.L124:
        mov     esi, eax
        mov     eax, DWORD PTR fa[0+rcx*4]
        movsx   rcx, esi
        mov     DWORD PTR fa[0+rcx*4], eax
        movsx   rcx, eax
        movsx   rcx, DWORD PTR fa[0+rcx*4]
        cmp     ecx, eax
        jne     .L124
.L123:
        cmp     eax, edx
        je      .L125
        add     r9d, 1
        mov     DWORD PTR fa[0+r12*4], eax
        add     r10d, DWORD PTR [rdi+8]
        cmp     r9d, ebx
        je      .L155
        mov     ebp, 1
.L125:
        add     r8d, 1
        add     rdi, 12
        cmp     r8d, r11d
        jle     .L126
        test    bpl, bpl
        je      .L93
.L155:
        mov     DWORD PTR tot[rip], r9d
        mov     DWORD PTR ans[rip], r10d
.L93:
        add     rsp, 16
        pop     rbx
        pop     rbp
        pop     r12
        pop     r13
        pop     r14
        ret
.L157:
        lea     r12, [rax-1]
        jmp     .L101
.L98:
        sub     r12, 1
.L101:
        lea     rax, [r12+r12*2]
        mov     rdx, rbx
        mov     rsi, r12
        mov     edi, OFFSET FLAT:e+12
        mov     rcx, QWORD PTR e[12+rax*4]
        mov     r8d, DWORD PTR e[20+rax*4]
        mov     QWORD PTR [rsp+4], rcx
        mov     DWORD PTR [rsp+12], r8d
        call    void std::__adjust_heap<edge*, long, edge, __gnu_cxx::__ops::_Iter_comp_iter<kruskal()::{lambda(edge const&, edge const&)#1}> >(edge*, long, long, edge, __gnu_cxx::__ops::_Iter_comp_iter<kruskal()::{lambda(edge const&, edge const&)#1}>) [clone .isra.0]
        test    r12, r12
        jne     .L98
        movabs  r12, -6148914691236517205
        mov     rax, r13
        sub     rax, rdi
        cmp     rax, 12
        jle     .L116
.L99:
        sub     r13, 12
        mov     rcx, QWORD PTR [r13+0]
        mov     r8d, DWORD PTR [r13+8]
        xor     esi, esi
        mov     rax, QWORD PTR e[rip+12]
        mov     rbx, r13
        mov     edi, OFFSET FLAT:e+12
        sub     rbx, OFFSET FLAT:e+12
        mov     QWORD PTR [rsp+4], rcx
        mov     QWORD PTR [r13+0], rax
        mov     rdx, rbx
        mov     eax, DWORD PTR e[rip+20]
        sar     rdx, 2
        mov     DWORD PTR [rsp+12], r8d
        imul    rdx, r12
        mov     DWORD PTR [r13+8], eax
        call    void std::__adjust_heap<edge*, long, edge, __gnu_cxx::__ops::_Iter_comp_iter<kruskal()::{lambda(edge const&, edge const&)#1}> >(edge*, long, long, edge, __gnu_cxx::__ops::_Iter_comp_iter<kruskal()::{lambda(edge const&, edge const&)#1}>) [clone .isra.0]
        cmp     rbx, 12
        jg      .L99
.L116:
        mov     edi, OFFSET FLAT:e+204
        call    void std::__insertion_sort<edge*, __gnu_cxx::__ops::_Iter_comp_iter<kruskal()::{lambda(edge const&, edge const&)#1}> >(edge*, edge*, __gnu_cxx::__ops::_Iter_comp_iter<kruskal()::{lambda(edge const&, edge const&)#1}>) [clone .constprop.0]
        mov     esi, OFFSET FLAT:e+204
        mov     rdi, QWORD PTR [rsi]
        mov     ecx, DWORD PTR [rsi+8]
        lea     rax, [rsi-12]
        cmp     ecx, DWORD PTR [rsi-4]
        jge     .L130
.L118:
        mov     rdx, QWORD PTR [rax]
        mov     QWORD PTR [rax+12], rdx
        mov     edx, DWORD PTR [rax+8]
        mov     DWORD PTR [rax+20], edx
        mov     rdx, rax
        sub     rax, 12
        cmp     ecx, DWORD PTR [rax+8]
        jl      .L118
        add     rsi, 12
        mov     QWORD PTR [rdx], rdi
        mov     DWORD PTR [rdx+8], ecx
        cmp     rbp, rsi
        je      .L154
.L156:
        mov     rdi, QWORD PTR [rsi]
        mov     ecx, DWORD PTR [rsi+8]
        lea     rax, [rsi-12]
        cmp     ecx, DWORD PTR [rsi-4]
        jl      .L118
.L130:
        mov     rdx, rsi
        add     rsi, 12
        mov     QWORD PTR [rdx], rdi
        mov     DWORD PTR [rdx+8], ecx
        cmp     rbp, rsi
        jne     .L156
        jmp     .L154
.LC2:
        .string "%d\n"
.LC3:
        .string "IMP0SSIBLE"
main:
        push    rbp
        push    rbx
        sub     rsp, 8
        call    read()
        mov     DWORD PTR n[rip], eax
        call    read()
        mov     esi, DWORD PTR n[rip]
        mov     DWORD PTR m[rip], eax
        test    esi, esi
        jle     .L160
        lea     edx, [rsi-1]
        cmp     edx, 2
        jbe     .L168
        mov     ecx, esi
        mov     edi, 4
        movdqa  xmm0, XMMWORD PTR .LC0[rip]
        xor     edx, edx
        shr     ecx, 2
        movd    xmm2, edi
        sal     rcx, 4
        pshufd  xmm2, xmm2, 0
.L162:
        movdqa  xmm1, xmm0
        add     rdx, 16
        paddd   xmm0, xmm2
        movups  XMMWORD PTR fa[rdx-12], xmm1
        cmp     rdx, rcx
        jne     .L162
        mov     edx, esi
        and     edx, -4
        add     edx, 1
        test    sil, 3
        je      .L160
.L161:
        movsx   rcx, edx
        mov     DWORD PTR fa[0+rcx*4], edx
        lea     ecx, [rdx+1]
        cmp     esi, ecx
        jl      .L160
        movsx   rdi, ecx
        add     edx, 2
        mov     DWORD PTR fa[0+rdi*4], ecx
        cmp     esi, edx
        jl      .L160
        movsx   rcx, edx
        mov     DWORD PTR fa[0+rcx*4], edx
.L160:
        test    eax, eax
        jle     .L164
        mov     ebx, OFFSET FLAT:e+12
        mov     ebp, 1
.L165:
        call    read()
        add     ebp, 1
        add     rbx, 12
        mov     DWORD PTR [rbx-12], eax
        call    read()
        mov     DWORD PTR [rbx-8], eax
        call    read()
        mov     DWORD PTR [rbx-4], eax
        cmp     DWORD PTR m[rip], ebp
        jge     .L165
.L164:
        call    kruskal()
        mov     eax, DWORD PTR n[rip]
        sub     eax, 1
        cmp     eax, DWORD PTR tot[rip]
        je      .L172
        mov     edi, OFFSET FLAT:.LC3
        call    puts
.L167:
        add     rsp, 8
        xor     eax, eax
        pop     rbx
        pop     rbp
        ret
.L172:
        mov     esi, DWORD PTR ans[rip]
        mov     edi, OFFSET FLAT:.LC2
        xor     eax, eax
        call    printf
        jmp     .L167
.L168:
        mov     edx, 1
        jmp     .L161
fa:
        .zero   800040
ans:
        .zero   4
tot:
        .zero   4
m:
        .zero   4
n:
        .zero   4
e:
        .zero   2400120
.LC0:
        .long   1
        .long   2
        .long   3
        .long   4
