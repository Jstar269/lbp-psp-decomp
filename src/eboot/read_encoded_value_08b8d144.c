/* LBPMATCH module=EBOOT.BIN start=0x08b8d144 end=0x08b8d280 symbol=FUN_08b8d144 lang=c99 cc=gcc404xs-O2 rodata=0x08bd8d58 */
/* Hand-written reconstruction from the disassembly (lane lbp10c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
/* GCC unwind-pe.h read_encoded_value_with_base: DWARF pointer encoding decoder. */
typedef unsigned int Ptr;
union unaligned {
    void *ptr;
    unsigned u2 __attribute__((mode(HI)));
    unsigned u4 __attribute__((mode(SI)));
    unsigned u8 __attribute__((mode(DI)));
    signed s2 __attribute__((mode(HI)));
    signed s4 __attribute__((mode(SI)));
    signed s8 __attribute__((mode(DI)));
} __attribute__((packed));
extern const unsigned char *FUN_08b8d0b8(const unsigned char *p, Ptr *out);
extern const unsigned char *FUN_08b8d0ec(const unsigned char *p, Ptr *out);
extern void FUN_08b9ca68(void) __attribute__((noreturn));
const unsigned char *FUN_08b8d144(unsigned char encoding, Ptr base, const unsigned char *p, Ptr *val)
{
    union unaligned *u = (union unaligned *)p;
    Ptr result;
    if (encoding == 0x50) {
        Ptr a = (Ptr)p;
        a = (a + 3) & -4;
        result = *(Ptr *)a;
        p = (const unsigned char *)(a + 4);
    } else {
        switch (encoding & 0x0f) {
        case 0:
            result = (Ptr)u->ptr;
            p += 4;
            break;
        case 1: {
            Ptr tmp;
            p = FUN_08b8d0b8(p, &tmp);
            result = tmp;
            break;
        }
        case 2:
            result = u->u2;
            p += 2;
            break;
        case 3:
            result = u->u4;
            p += 4;
            break;
        case 4:
            result = u->u8;
            p += 8;
            break;
        case 9: {
            Ptr tmp;
            p = FUN_08b8d0ec(p, &tmp);
            result = tmp;
            break;
        }
        case 10:
            result = u->s2;
            p += 2;
            break;
        case 11:
            result = u->s4;
            p += 4;
            break;
        case 12:
            result = u->s8;
            p += 8;
            break;
        default:
            FUN_08b9ca68();
        }
        if (result != 0) {
            result += ((encoding & 0x70) == 0x10 ? (Ptr)u : base);
            if (encoding & 0x80)
                result = *(Ptr *)result;
        }
    }
    *val = result;
    return p;
}
