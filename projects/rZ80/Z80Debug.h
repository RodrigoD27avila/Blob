#ifndef   _Z80DEBUG_H_INCLUDED_
#define   _Z80DEBUG_H_INCLUDED_

const char *TableOpDebug[256] = {
	"0nop"            , "14ld bc, #0x%04x", "0ld (bc), a"    , "0inc bc", "0inc b"   , "0dec b"   , "12ld b, #0x%02x"   , "0rlca",
	"0ex af af\'"     , "0add hl, bc"    , "0ld a, (bc)"    , "0dec bc", "0inc c"   , "0dec c"   , "12ld c, #0x%02x"   , "0rrca",
	"0djnz"           , "14ld de, #0x%04x", "0ld (de), a"    , "0inc de", "0inc d"   , "0dec d"   , "12ld d, #0x%02x"   , "0rla" ,
	"12jr, #0x%02x"    , "0add hl, de"    , "0ld a, (de)"    , "0dec de", "0inc e"   , "0dec e"   , "12ld e, #0x%02x"   , "0rra" ,
	"12jr nz, #0x%02x" , "14ld hl, #0x%04x", "14ld 0x%04x$, hl", "0inc hl", "0inc h"   , "0dec h"   , "12ld h, #0x%02x"   , "0daa" ,
	"12jr z, #0x%02x"  , "0add hl, hl"    , "14ld hl, 0x%04x$", "0dec hl", "0inc l"   , "0dec l"   , "12ld l, #0x%02x"   , "0cpl" ,
	"12jr nc, #0x%02x" , "14ld sp, #0x%04x", "14ld 0x%04x$, a" , "0inc sp", "0inc (hl)", "0dec (hl)", "12ld (hl), #0x%02x", "0scf" ,
	"12jr c, #0x%02x"  , "0add hl, sp"    , "14ld a, 0x%04x$" , "0dec sp", "0inc a"   , "0dec a"   , "12ld a, #0x%02x"   , "0ccf" ,

	"0ld b, b", "0ld b, c", "0ld b, d", "0ld b, e", "0ld b, h", "0ld b, l", "0ld b, (hl)", "0ld b, a",
	"0ld c, b", "0ld c, c", "0ld c, d", "0ld c, e", "0ld c, h", "0ld c, l", "0ld c, (hl)", "0ld c, a",
	"0ld d, b", "0ld d, c", "0ld d, d", "0ld d, e", "0ld d, h", "0ld d, l", "0ld d, (hl)", "0ld d, a",
	"0ld e, b", "0ld e, c", "0ld e, d", "0ld e, e", "0ld e, h", "0ld e, l", "0ld e, (hl)", "0ld e, a",
	"0ld h, b", "0ld h, c", "0ld h, d", "0ld h, e", "0ld h, h", "0ld h, l", "0ld h, (hl)", "0ld h, a",
	"0ld l, b", "0ld l, c", "0ld l, d", "0ld l, e", "0ld l, h", "0ld l, l", "0ld l, (hl)", "0ld l, a",

	"0ld (hl), b", "0ld (hl), c", "0ld (hl), d", "0ld (hl), e", "0ld (hl), h", "0ld (hl), l", "0halt", "0ld (hl), a",

	"0ld a, b", "0ld a, c", "0ld a, d", "0ld a, e", "0ld a, h", "0ld a, l", "0ld a, (hl)", "0ld a, a",

	"0add a, b", "0add a, c", "0add a, d", "0add a, e", "0add a, h", "0add a, l", "0add a, (hl)", "0add a, a",
	"0adc a, b", "0adc a, c", "0adc a, d", "0adc a, e", "0adc a, h", "0adc a, l", "0adc a, (hl)", "0adc a, a",
	"0sub a, b", "0sub a, c", "0sub a, d", "0sub a, e", "0sub a, h", "0sub a, l", "0sub a, (hl)", "0sub a, a",
	"0sbc a, b", "0sbc a, c", "0sbc a, d", "0sbc a, e", "0sbc a, h", "0sbc a, l", "0sbc a, (hl)", "0sbc a, a",

	"0and b", "0and c", "0and d", "0and e", "0and h", "0and l", "0and (hl)", "0and a",
	"0xor b", "0xor c", "0xor d", "0xor e", "0xor h", "0xor l", "0xor (hl)", "0xor a",
	"0or b" , "0or c" , "0or d" , "0or e" , "0or h" , "0or l" , "0or (hl)" , "0or a" ,
	"0cp b" , "0cp c" , "0cp d" , "0cp e" , "0cp h" , "0cp l" , "0cp (hl)" , "0cp a" ,

	"0ret nz", "0pop bc"   , "14jp nz, 0x%04x$", "14jp  0x%04x$" , "14call nz, 0x%04x$", "0push bc"     , "12add #0x%02x", "0rst 0x0$" ,
	"0ret z" , "0ret"      , "14jp z, 0x%04x$" , nullptr        , "14call z, 0x%04x$" , "14call 0x%04x$", "12adc #0x%02x", "0rst 0x80$",
	"0ret nc", "0pop de"   , "14jp nc, 0x%04x$", "0out a"       , "14call nc, 0x%04x$", "0push de"     , "12sub #0x%02x", "0rst 0x10$",
	"0ret c" , "0exx"      , "14jp c, 0x%04x$" , "0in a"        , "14call c, 0x%04x$" , nullptr        , "12sbc #0x%02x", "0rst 0x18$",
	"0ret po", "0pop hl"   , "14jp po, 0x%04x$", "0ex (sp) hl"  , "14call po, 0x%04x$", "0push hl"     , "12and #0x%02x", "0rst 0x20$",
	"0ret pe", "0jp hl"    , "14jp pe, 0x%04x$", "0ex de hl"    , "14call pe, 0x%04x$", nullptr        , "102xor #0x%02x", "0rst 0x28$",
	"0ret p" , "0pop af"   , "14jp p, 0x%04x$" , "0di"          , "14call p, 0x%04x$" , "0push af"     , "12or #0x%02x" , "0rst 0x30$",
	"0ret m" , "0ld sp, hl", "14jp m, 0x%04x$" , "0ei"          , "14call m, 0x%04x$" , nullptr        , "12cp #0x%02x" , "0rst 0x38$",
};


const char *TableOpCBDebug[256] = {

	"0rlc b", "0rlc c", "0rlc d", "0rlc e", "0rlc h", "0rlc l", "0rlc (hl)", "0rlc a",
        "0rrc b", "0rrc c", "0rrc d", "0rrc e", "0rrc h", "0rrc l", "0rrc (hl)", "0rrc a",
        "0rl b" , "0rl c" , "0rl d" , "0rl e" , "0rl h" , "0rl l" , "0rl (hl)" , "0rl a" ,
        "0rr b" , "0rr c" , "0rr d" , "0rr e" , "0rr h" , "0rr l" , "0rr (hl)" , "0rr a" ,
        "0sla b", "0sla c", "0sla d", "0sla e", "0sla h", "0sla l", "0sla (hl)", "0sla a",
        "0sra b", "0sra c", "0sra d", "0sra e", "0sra h", "0sra l", "0sra (hl)", "0sra a",

        "0sll b", "0sll c", "0sll d", "0sll e", "0sll h", "0sll l", "0sll (hl)", "0sll a",

        "0srl b", "0srl c", "0srl d", "0srl e", "0srl h", "0srl l", "0srl (hl)", "0srl a",

        "0bit 0, b", "0bit 0, c", "0bit 0, d", "0bit 0, e", "0bit 0, h", "0bit 0, l", "0bit 0, (hl)", "0bit 0, a",
        "0bit 1, b", "0bit 1, c", "0bit 1, d", "0bit 1, e", "0bit 1, h", "0bit 1, l", "0bit 1, (hl)", "0bit 1, a",
        "0bit 2, b", "0bit 2, c", "0bit 2, d", "0bit 2, e", "0bit 2, h", "0bit 2, l", "0bit 2, (hl)", "0bit 2, a",
        "0bit 3, b", "0bit 3, c", "0bit 3, d", "0bit 3, e", "0bit 3, h", "0bit 3, l", "0bit 3, (hl)", "0bit 3, a",
        "0bit 4, b", "0bit 4, c", "0bit 4, d", "0bit 4, e", "0bit 4, h", "0bit 4, l", "0bit 4, (hl)", "0bit 4, a",
        "0bit 5, b", "0bit 5, c", "0bit 5, d", "0bit 5, e", "0bit 5, h", "0bit 5, l", "0bit 5, (hl)", "0bit 5, a",
        "0bit 6, b", "0bit 6, c", "0bit 6, d", "0bit 6, e", "0bit 6, h", "0bit 6, l", "0bit 6, (hl)", "0bit 6, a",
        "0bit 7, b", "0bit 7, c", "0bit 7, d", "0bit 7, e", "0bit 7, h", "0bit 7, l", "0bit 7, (hl)", "0bit 7, a",

        "0res 0, b", "0res 0, c", "0res 0, d", "0res 0, e", "0res 0, h", "0res 0, l", "0res 0, (hl)", "0res 0, a",
        "0res 1, b", "0res 1, c", "0res 1, d", "0res 1, e", "0res 1, h", "0res 1, l", "0res 1, (hl)", "0res 1, a",
        "0res 2, b", "0res 2, c", "0res 2, d", "0res 2, e", "0res 2, h", "0res 2, l", "0res 2, (hl)", "0res 2, a",
        "0res 3, b", "0res 3, c", "0res 3, d", "0res 3, e", "0res 3, h", "0res 3, l", "0res 3, (hl)", "0res 3, a",
        "0res 4, b", "0res 4, c", "0res 4, d", "0res 4, e", "0res 4, h", "0res 4, l", "0res 4, (hl)", "0res 4, a",
        "0res 5, b", "0res 5, c", "0res 5, d", "0res 5, e", "0res 5, h", "0res 5, l", "0res 5, (hl)", "0res 5, a",
        "0res 6, b", "0res 6, c", "0res 6, d", "0res 6, e", "0res 6, h", "0res 6, l", "0res 6, (hl)", "0res 6, a",
        "0res 7, b", "0res 7, c", "0res 7, d", "0res 7, e", "0res 7, h", "0res 7, l", "0res 7, (hl)", "0res 7, a",

        "0set 0, b", "0set 0, c", "0set 0, d", "0set 0, e", "0set 0, h", "0set 0, l", "0set 0, (hl)", "0set 0, a",
        "0set 1, b", "0set 1, c", "0set 1, d", "0set 1, e", "0set 1, h", "0set 1, l", "0set 1, (hl)", "0set 1, a",
        "0set 2, b", "0set 2, c", "0set 2, d", "0set 2, e", "0set 2, h", "0set 2, l", "0set 2, (hl)", "0set 2, a",
        "0set 3, b", "0set 3, c", "0set 3, d", "0set 3, e", "0set 3, h", "0set 3, l", "0set 3, (hl)", "0set 3, a",
        "0set 4, b", "0set 4, c", "0set 4, d", "0set 4, e", "0set 4, h", "0set 4, l", "0set 4, (hl)", "0set 4, a",
        "0set 5, b", "0set 5, c", "0set 5, d", "0set 5, e", "0set 5, h", "0set 5, l", "0set 5, (hl)", "0set 5, a",
        "0set 6, b", "0set 6, c", "0set 6, d", "0set 6, e", "0set 6, h", "0set 6, l", "0set 6, (hl)", "0set 6, a",
        "0set 7, b", "0set 7, c", "0set 7, d", "0set 7, e", "0set 7, h", "0set 7, l", "0set 7, (hl)", "0set 7, a",
};

const char *TableOpEDDebug[256] = {
	nullptr         , nullptr      , nullptr      , nullptr          , nullptr, nullptr , nullptr, nullptr   ,
	nullptr         , nullptr      , nullptr      , nullptr          , nullptr, nullptr , nullptr, nullptr   ,
	nullptr         , nullptr      , nullptr      , nullptr          , nullptr, nullptr , nullptr, nullptr   ,
	nullptr         , nullptr      , nullptr      , nullptr          , nullptr, nullptr , nullptr, nullptr   ,
	nullptr         , nullptr      , nullptr      , nullptr          , nullptr, nullptr , nullptr, nullptr   ,
	nullptr         , nullptr      , nullptr      , nullptr          , nullptr, nullptr , nullptr, nullptr   ,
	nullptr         , nullptr      , nullptr      , nullptr          , nullptr, nullptr , nullptr, nullptr   ,
	nullptr         , nullptr      , nullptr      , nullptr          , nullptr, nullptr , nullptr, nullptr   ,
	"0in b, (c)"    , "0out (c), b", "0sbc hl, bc", "14ld 0x%04x$, bc", "0neg" , "0retn" , "0im0" , "0ld i, a",
	"0in c, (c)"    , "0out (c), c", "0adc hl, bc", "14ld bc, 0x%04x$", "0neg" , "0reti" , "0im01", "0ld r, a",
	"0in d, (c)"    , "0out (c), d", "0sbc hl, de", "14ld 0x%04x$, de", "0neg" , "0retn" , "0im1" , "0ld a, i",
	"0in e, (c)"    , "0out (c), e", "0adc hl, de", "14ld de, 0x%04x$", "0neg" , "0retn" , "0im2" , "0ld a, r",
	"0in h, (c)"    , "0out (c), h", "0sbc hl, hl", "14ld 0x%04x$, hl", "0neg" , "0retn" , "0im0" , "0rrd"    ,
	"0in l, (c)"    , "0out (c), l", "0adc hl, hl", "14ld hl, 0x%04x$", "0neg" , "0retn" , "0im01", "0rld"    ,
	"0in (c)"       , "0out (c)"   , "0sbc hl, sp", "14ld 0x%04x$, sp", "0neg" , "0retn" , "0im1" , nullptr   ,
	"0in a, (c)"    , "0out (c), a", "0adc hl, sp", "14ld sp, 0x%04x$", "0neg" , "0retn" , "0im2" , nullptr   ,
	nullptr         , nullptr      , nullptr      , nullptr          , nullptr, nullptr , nullptr, nullptr   ,
	nullptr         , nullptr      , nullptr      , nullptr          , nullptr, nullptr , nullptr, nullptr   ,
	nullptr         , nullptr      , nullptr      , nullptr          , nullptr, nullptr , nullptr, nullptr   ,
	nullptr         , nullptr      , nullptr      , nullptr          , nullptr, nullptr , nullptr, nullptr   ,
	"0ldi"          , "0cpi"       , "0ini"       , "0outi "         , nullptr, nullptr , nullptr, nullptr   ,
	"0ldd"          , "0cpd"       , "0ind"       , "0outd"          , nullptr, nullptr , nullptr, nullptr   ,
	"0ldir"         , "0cpir"      , "0inir"      , "0otir"          , nullptr, nullptr , nullptr, nullptr   ,
	"0lddr"         , "0cpdr"      , "0indr"      , "0otdr"          , nullptr, nullptr , nullptr, nullptr   ,
	nullptr         , nullptr      , nullptr      , nullptr          , nullptr, nullptr , nullptr, nullptr   ,
	nullptr         , nullptr      , nullptr      , nullptr          , nullptr, nullptr , nullptr, nullptr   ,
	nullptr         , nullptr      , nullptr      , nullptr          , nullptr, nullptr , nullptr, nullptr   ,
	nullptr         , nullptr      , nullptr      , nullptr          , nullptr, nullptr , nullptr, nullptr   ,
	nullptr         , nullptr      , nullptr      , nullptr          , nullptr, nullptr , nullptr, nullptr   ,
	nullptr         , nullptr      , nullptr      , nullptr          , nullptr, nullptr , nullptr, nullptr   ,
	nullptr         , nullptr      , nullptr      , nullptr          , nullptr, nullptr , nullptr, nullptr   ,
	nullptr         , nullptr      , nullptr      , nullptr          , nullptr, nullptr , nullptr, nullptr   ,
};

const char *TableOpDDDebug[256] = {
	nullptr, nullptr      , nullptr          , nullptr  , nullptr   , nullptr   , nullptr         , nullptr,
	nullptr, "0add ix, bc", nullptr          , nullptr  , nullptr   , nullptr   , nullptr         , nullptr,
	nullptr, nullptr      , nullptr          , nullptr  , nullptr   , nullptr   , nullptr         , nullptr,
	nullptr, "0add ix, de", nullptr          , nullptr  , nullptr   , nullptr   , nullptr         , nullptr,

	nullptr, "14ld ix, #0%04x", "14ld p#0%04x, ix", "0inc ix" , "0inc ixh" , "0dec ixh" , "12ld ixh, #0x%02x", nullptr,
	nullptr, "0add ix, ix"   , "14ld ix, p#0%04x", "0dec ix" , "0inc ixl" , "0dec ixl" , "12ld ixl, #0x%02x", nullptr,

	nullptr, nullptr, nullptr, nullptr, "12inc (ix+0x%02x)", "12dec (ix+0x%02x)", "222ld (ix+0x%02x), #0x%02x", nullptr,

	nullptr, "0add ix, sp", nullptr, nullptr, nullptr     , nullptr     , nullptr             , nullptr,
	nullptr, nullptr      , nullptr, nullptr, "0ld b, ixh", "0ld b, ixl", "12ld b, (ix+0x%02x)", nullptr,
	nullptr, nullptr      , nullptr, nullptr, "0ld c, ixh", "0ld c, ixl", "12ld c, (ix+0x%02x)", nullptr,
	nullptr, nullptr      , nullptr, nullptr, "0ld d, ixh", "0ld d, ixl", "12ld d, (ix+0x%02x)", nullptr,
	nullptr, nullptr      , nullptr, nullptr, "0ld e, ixh", "0ld e, ixl", "12ld e, (ix+0x%02x)", nullptr,

	"0ld ixh, b", "0ld ixh, c", "0ld ixh, d", "0ld ixh, e", "0ld ixh, ixh", "0ld ixh, ixl", "12ld h, (ix+0x%02x)" , "0ld ixh, a",
	"0ld ixl, b", "0ld ixl, c", "0ld ixl, d", "0ld ixl, e", "0ld ixl, ixh", "0ld ixl, ixl", "12ld l, (ix+0x%02x)" , "0ld ixl, a",

	"12ld (ix+0x%02x), b", "12ld (ix+0x%02x), c", "12ld (ix+0x%02x), d", "12ld (ix+0x%02x), e",
        "12ld (ix+0x%02x), h", "12ld (ix+0x%02x), l", "12ld (ix+0x%02x), a", nullptr,

	nullptr, nullptr  , nullptr  , nullptr, "0ld a, ixh"  , "0ld a, ixl"  , "12ld a, (ix+0x%02x)" , nullptr ,
	nullptr, nullptr  , nullptr  , nullptr, "0add a, ixh" , "0add a, ixl" , "12add a, (ix+0x%02x)", nullptr ,
	nullptr, nullptr  , nullptr  , nullptr, "0adc a, ixh" , "0adc a, ixl" , "12adc a, (ix+0x%02x)", nullptr ,
	nullptr, nullptr  , nullptr  , nullptr, "0sub a, ixh" , "0sub a, ixl" , "12sub a, (ix+0x%02x)", nullptr ,
	nullptr, nullptr  , nullptr  , nullptr, "0sbc a, ixh" , "0sbc a, ixl" , "12sbc a, (ix+0x%02x)", nullptr ,
	nullptr, nullptr  , nullptr  , nullptr, "0and ixh"    , "0and ixl"    , "12and (ix+0x%02x)"   , nullptr ,
	nullptr, nullptr  , nullptr  , nullptr, "0xor ixh"    , "0xor ixl"    , "102xor (ix+0x%02x)"   , nullptr ,
	nullptr, nullptr  , nullptr  , nullptr, "0or ixh"     , "0or ixl"     , "12or (ix+0x%02x)"    , nullptr ,
	nullptr, nullptr  , nullptr  , nullptr, "0cp ixh"     , "0cp ixl"     , "12cp (ix+0x%02x)"    , nullptr ,

	nullptr, nullptr  , nullptr  , nullptr, nullptr , nullptr , nullptr , nullptr,
	nullptr, nullptr  , nullptr  , nullptr, nullptr , nullptr , nullptr , nullptr,
	nullptr, nullptr  , nullptr  , nullptr, nullptr , nullptr , nullptr , nullptr,
	nullptr, nullptr  , nullptr  , nullptr, nullptr , nullptr , nullptr , nullptr,

	nullptr, "0pop ix"     , nullptr  , "0ex (sp), ix", nullptr , "0push ix" , nullptr , nullptr,
	nullptr, "0jp pix"     , nullptr  , nullptr       , nullptr , nullptr    , nullptr , nullptr,
	nullptr, nullptr       , nullptr  , nullptr       , nullptr , nullptr    , nullptr , nullptr,
	nullptr, "0ld sp, ix"  , nullptr  , nullptr       , nullptr , nullptr    , nullptr , nullptr,
};

const char *TableOpFDDebug[256] = {
	nullptr, nullptr      , nullptr          , nullptr  , nullptr   , nullptr   , nullptr         , nullptr,
	nullptr, "0add iy, bc", nullptr          , nullptr  , nullptr   , nullptr   , nullptr         , nullptr,
	nullptr, nullptr      , nullptr          , nullptr  , nullptr   , nullptr   , nullptr         , nullptr,
	nullptr, "0add iy, de", nullptr          , nullptr  , nullptr   , nullptr   , nullptr         , nullptr,

	nullptr, "14ld iy, #0%04x", "14ld p#0%04x, iy", "0inc iy" , "0inc iyh" , "0dec iyh" , "12ld iyh, #0x%02x", nullptr,
	nullptr, "0add iy, iy"   , "14ld iy, p#0%04x", "0dec iy" , "0inc iyl" , "0dec iyl" , "12ld iyl, #0x%02x", nullptr,

	nullptr, nullptr, nullptr, nullptr, "12inc (iy+0x%02x)", "12dec (iy+0x%02x)", "222ld (iy+0x%02x), #0x%02x", nullptr,

	nullptr, "0add iy, sp", nullptr, nullptr, nullptr     , nullptr     , nullptr             , nullptr,
	nullptr, nullptr      , nullptr, nullptr, "0ld b, iyh", "0ld b, iyl", "12ld b, (iy+0x%02x)", nullptr,
	nullptr, nullptr      , nullptr, nullptr, "0ld c, iyh", "0ld c, iyl", "12ld c, (iy+0x%02x)", nullptr,
	nullptr, nullptr      , nullptr, nullptr, "0ld d, iyh", "0ld d, iyl", "12ld d, (iy+0x%02x)", nullptr,
	nullptr, nullptr      , nullptr, nullptr, "0ld e, iyh", "0ld e, iyl", "12ld e, (iy+0x%02x)", nullptr,

	"0ld iyh, b", "0ld iyh, c", "0ld iyh, d", "0ld iyh, e", "0ld iyh, iyh", "0ld iyh, iyl", "12ld h, (iy+0x%02x)" , "0ld iyh, a",
	"0ld iyl, b", "0ld iyl, c", "0ld iyl, d", "0ld iyl, e", "0ld iyl, iyh", "0ld iyl, iyl", "12ld l, (iy+0x%02x)" , "0ld iyl, a",

	"12ld (iy+0x%02x), b", "12ld (iy+0x%02x), c", "12ld (iy+0x%02x), d", "12ld (iy+0x%02x), e",
        "12ld (iy+0x%02x), h", "12ld (iy+0x%02x), l", "12ld (iy+0x%02x), a", nullptr,

	nullptr, nullptr  , nullptr  , nullptr, "0ld a, iyh"  , "0ld a, iyl"  , "12ld a, (iy+0x%02x)" , nullptr ,
	nullptr, nullptr  , nullptr  , nullptr, "0add a, iyh" , "0add a, iyl" , "12add a, (iy+0x%02x)", nullptr ,
	nullptr, nullptr  , nullptr  , nullptr, "0adc a, iyh" , "0adc a, iyl" , "12adc a, (iy+0x%02x)", nullptr ,
	nullptr, nullptr  , nullptr  , nullptr, "0sub a, iyh" , "0sub a, iyl" , "12sub a, (iy+0x%02x)", nullptr ,
	nullptr, nullptr  , nullptr  , nullptr, "0sbc a, iyh" , "0sbc a, iyl" , "12sbc a, (iy+0x%02x)", nullptr ,
	nullptr, nullptr  , nullptr  , nullptr, "0and iyh"    , "0and iyl"    , "12and (iy+0x%02x)"   , nullptr ,
	nullptr, nullptr  , nullptr  , nullptr, "0xor iyh"    , "0xor iyl"    , "102xor (iy+0x%02x)"   , nullptr ,
	nullptr, nullptr  , nullptr  , nullptr, "0or iyh"     , "0or iyl"     , "12or (iy+0x%02x)"    , nullptr ,
	nullptr, nullptr  , nullptr  , nullptr, "0cp iyh"     , "0cp iyl"     , "12cp (iy+0x%02x)"    , nullptr ,

	nullptr, nullptr  , nullptr  , nullptr, nullptr , nullptr , nullptr , nullptr,
	nullptr, nullptr  , nullptr  , nullptr, nullptr , nullptr , nullptr , nullptr,
	nullptr, nullptr  , nullptr  , nullptr, nullptr , nullptr , nullptr , nullptr,
	nullptr, nullptr  , nullptr  , nullptr, nullptr , nullptr , nullptr , nullptr,

	nullptr, "0pop iy"     , nullptr  , "0ex (sp), iy", nullptr , "0push iy" , nullptr , nullptr,
	nullptr, "0jp piy"     , nullptr  , nullptr       , nullptr , nullptr    , nullptr , nullptr,
	nullptr, nullptr       , nullptr  , nullptr       , nullptr , nullptr    , nullptr , nullptr,
	nullptr, "0ld sp, iy"  , nullptr  , nullptr       , nullptr , nullptr    , nullptr , nullptr,
};

const char *TableOpDDCBDebug[256] = {

	"12rlc, (ix+0x%02x), b", "12rlc, (ix+0x%02x), c", "12rlc, (ix+0x%02x), d", "12rlc, (ix+0x%02x), e",
	"12rlc, (ix+0x%02x), h", "12rlc, (ix+0x%02x), l", "12rlc, (ix+0x%02x)"  , "12rlc, (ix+0x%02x), a",

	"12rrc, (ix+0x%02x), b", "12rrc, (ix+0x%02x), c", "12rrc, (ix+0x%02x), d", "12rrc, (ix+0x%02x), e",
	"12rrc, (ix+0x%02x), h", "12rrc, (ix+0x%02x), l", "12rrc, (ix+0x%02x)"  , "12rrc, (ix+0x%02x), a",

	"12rl, (ix+0x%02x), b" , "12rl, (ix+0x%02x), c" , "12rl, (ix+0x%02x), d" , "12rl, (ix+0x%02x), e",
	"12rl, (ix+0x%02x), h" , "12rl, (ix+0x%02x), l" , "12rl, (ix+0x%02x)"   , "12rl, (ix+0x%02x), a",

	"12rr, (ix+0x%02x), b" , "12rr, (ix+0x%02x), c" , "12rr, (ix+0x%02x), d" , "12rr, (ix+0x%02x), e",
	"12rr, (ix+0x%02x), h" , "12rr, (ix+0x%02x), l" , "12rr, (ix+0x%02x)"   , "12rr, (ix+0x%02x), a" ,

	"12sla, (ix+0x%02x), b", "12sla, (ix+0x%02x), c", "12sla, (ix+0x%02x), d", "12sla, (ix+0x%02x), e",
	"12sla, (ix+0x%02x), h", "12sla, (ix+0x%02x), l", "12sla, (ix+0x%02x)"  , "12sla, (ix+0x%02x), a",

	"12sra, (ix+0x%02x), b", "12sra, (ix+0x%02x), c", "12sra, (ix+0x%02x), d", "12sra, (ix+0x%02x), e",
	"12sra, (ix+0x%02x), h", "12sra, (ix+0x%02x), l", "12sra, (ix+0x%02x)"  , "12sra, (ix+0x%02x), a",

	"12sll, (ix+0x%02x), b", "12sll, (ix+0x%02x), c", "12sll, (ix+0x%02x), d", "12sll, (ix+0x%02x), e",
 	"12sll, (ix+0x%02x), h", "12sll, (ix+0x%02x), l", "12sll, (ix+0x%02x)"  , "12sll, (ix+0x%02x), a",

	"12srl, (ix+0x%02x), b", "12srl, (ix+0x%02x), c", "12srl, (ix+0x%02x), d", "12srl, (ix+0x%02x), e",
	"12srl, (ix+0x%02x), h", "12srl, (ix+0x%02x), l", "12srl, (ix+0x%02x)"  , "12srl, (ix+0x%02x), a",

	"12bit 0, (ix+0x%02x)", "12bit 0, (ix+0x%02x)", "12bit 0, (ix+0x%02x)", "12bit 0, (ix+0x%02x)",
	"12bit 0, (ix+0x%02x)", "12bit 0, (ix+0x%02x)", "12bit 0, (ix+0x%02x)" , "12bit 0, (ix+0x%02x)",

	"12bit 1, (ix+0x%02x)", "12bit 1, (ix+0x%02x)", "12bit 1, (ix+0x%02x)", "12bit 1, (ix+0x%02x)",
	"12bit 1, (ix+0x%02x)", "12bit 1, (ix+0x%02x)", "12bit 1, (ix+0x%02x)" , "12bit 1, (ix+0x%02x)",

	"12bit 2, (ix+0x%02x)", "12bit 2, (ix+0x%02x)", "12bit 2, (ix+0x%02x)", "12bit 2, (ix+0x%02x)",
	"12bit 2, (ix+0x%02x)", "12bit 2, (ix+0x%02x)", "12bit 2, (ix+0x%02x)" , "12bit 2, (ix+0x%02x)",

	"12bit 3, (ix+0x%02x)", "12bit 3, (ix+0x%02x)", "12bit 3, (ix+0x%02x)", "12bit 3, (ix+0x%02x)",
	"12bit 3, (ix+0x%02x)", "12bit 3, (ix+0x%02x)", "12bit 3, (ix+0x%02x)" , "12bit 3, (ix+0x%02x)",

	"12bit 4, (ix+0x%02x)", "12bit 4, (ix+0x%02x)", "12bit 4, (ix+0x%02x)", "12bit 4, (ix+0x%02x)",
	"12bit 4, (ix+0x%02x)", "12bit 4, (ix+0x%02x)", "12bit 4, (ix+0x%02x)" , "12bit 4, (ix+0x%02x)",

	"12bit 5, (ix+0x%02x)", "12bit 5, (ix+0x%02x)", "12bit 5, (ix+0x%02x)", "12bit 5, (ix+0x%02x)",
	"12bit 5, (ix+0x%02x)", "12bit 5, (ix+0x%02x)", "12bit 5, (ix+0x%02x)" , "12bit 5, (ix+0x%02x)",

	"12bit 6, (ix+0x%02x)", "12bit 6, (ix+0x%02x)", "12bit 6, (ix+0x%02x)", "12bit 6, (ix+0x%02x)",
	"12bit 6, (ix+0x%02x)", "12bit 6, (ix+0x%02x)", "12bit 6, (ix+0x%02x)" , "12bit 6, (ix+0x%02x)",

	"12bit 7, (ix+0x%02x)", "12bit 7, (ix+0x%02x)", "12bit 7, (ix+0x%02x)", "12bit 7, (ix+0x%02x)",
	"12bit 7, (ix+0x%02x)", "12bit 7, (ix+0x%02x)", "12bit 7, (ix+0x%02x)" , "12bit 7, (ix+0x%02x)",


        "12res 0, (ix+0x%02x), b", "12res 0, (ix+0x%02x), c", "12res 0, (ix+0x%02x), d", "12res 0, (ix+0x%02x), e",
	"12res 0, (ix+0x%02x), h", "12res 0, (ix+0x%02x), l", "12res 0, (ix+0x%02x)"  , "12res 0, (ix+0x%02x), a",

        "12res 1, (ix+0x%02x), b", "12res 1, (ix+0x%02x), c", "12res 1, (ix+0x%02x), d", "12res 1, (ix+0x%02x), e",
	"12res 1, (ix+0x%02x), h", "12res 1, (ix+0x%02x), l", "12res 1, (ix+0x%02x)"  , "12res 1, (ix+0x%02x), a",

        "12res 2, (ix+0x%02x), b", "12res 2, (ix+0x%02x), c", "12res 2, (ix+0x%02x), d", "12res 2, (ix+0x%02x), e",
	"12res 2, (ix+0x%02x), h", "12res 2, (ix+0x%02x), l", "12res 2, (ix+0x%02x)"  , "12res 2, (ix+0x%02x), a",

        "12res 3, (ix+0x%02x), b", "12res 3, (ix+0x%02x), c", "12res 3, (ix+0x%02x), d", "12res 3, (ix+0x%02x), e",
 	"12res 3, (ix+0x%02x), h", "12res 3, (ix+0x%02x), l", "12res 3, (ix+0x%02x)"  , "12res 3, (ix+0x%02x), a",

        "12res 4, (ix+0x%02x), b", "12res 4, (ix+0x%02x), c", "12res 4, (ix+0x%02x), d", "12res 4, (ix+0x%02x), e",
	"12res 4, (ix+0x%02x), h", "12res 4, (ix+0x%02x), l", "12res 4, (ix+0x%02x)"  , "12res 4, (ix+0x%02x), a",

        "12res 5, (ix+0x%02x), b", "12res 5, (ix+0x%02x), c", "12res 5, (ix+0x%02x), d", "12res 5, (ix+0x%02x), e",
	"12res 5, (ix+0x%02x), h", "12res 5, (ix+0x%02x), l", "12res 5, (ix+0x%02x)"  , "12res 5, (ix+0x%02x), a",

        "12res 6, (ix+0x%02x), b", "12res 6, (ix+0x%02x), c", "12res 6, (ix+0x%02x), d", "12res 6, (ix+0x%02x), e",
	"12res 6, (ix+0x%02x), h", "12res 6, (ix+0x%02x), l", "12res 6, (ix+0x%02x)"  , "12res 6, (ix+0x%02x), a",

        "12res 7, (ix+0x%02x), b", "12res 7, (ix+0x%02x), c", "12res 7, (ix+0x%02x), d", "12res 7, (ix+0x%02x), e",
	"12res 7, (ix+0x%02x), h", "12res 7, (ix+0x%02x), l", "12res 7, (ix+0x%02x)"  , "12res 7, (ix+0x%02x), a",


	"12set 0, (ix+0x%02x), b", "12set 0, (ix+0x%02x), c", "12set 0, (ix+0x%02x), d", "12set 0, (ix+0x%02x), e",
	"12set 0, (ix+0x%02x), h", "12set 0, (ix+0x%02x), l", "12set 0, (ix+0x%02x)"  , "12set 0, (ix+0x%02x), a",

        "12set 1, (ix+0x%02x), b", "12set 1, (ix+0x%02x), c", "12set 1, (ix+0x%02x), d", "12set 1, (ix+0x%02x), e",
	"12set 1, (ix+0x%02x), h", "12set 1, (ix+0x%02x), l", "12set 1, (ix+0x%02x)"  , "12set 1, (ix+0x%02x), a",

        "12set 2, (ix+0x%02x), b", "12set 2, (ix+0x%02x), c", "12set 2, (ix+0x%02x), d", "12set 2, (ix+0x%02x), e",
	"12set 2, (ix+0x%02x), h", "12set 2, (ix+0x%02x), l", "12set 2, (ix+0x%02x)"  , "12set 2, (ix+0x%02x), a",

        "12set 3, (ix+0x%02x), b", "12set 3, (ix+0x%02x), c", "12set 3, (ix+0x%02x), d", "12set 3, (ix+0x%02x), e",
	"12set 3, (ix+0x%02x), h", "12set 3, (ix+0x%02x), l", "12set 3, (ix+0x%02x)"  , "12set 3, (ix+0x%02x), a",

        "12set 4, (ix+0x%02x), b", "12set 4, (ix+0x%02x), c", "12set 4, (ix+0x%02x), d", "12set 4, (ix+0x%02x), e",
	"12set 4, (ix+0x%02x), h", "12set 4, (ix+0x%02x), l", "12set 4, (ix+0x%02x)"  , "12set 4, (ix+0x%02x), a",

        "12set 5, (ix+0x%02x), b", "12set 5, (ix+0x%02x), c", "12set 5, (ix+0x%02x), d", "12set 5, (ix+0x%02x), e",
	"12set 5, (ix+0x%02x), h", "12set 5, (ix+0x%02x), l", "12set 5, (ix+0x%02x)"  , "12set 5, (ix+0x%02x), a",

        "12set 6, (ix+0x%02x), b", "12set 6, (ix+0x%02x), c", "12set 6, (ix+0x%02x), d", "12set 6, (ix+0x%02x), e",
	"12set 6, (ix+0x%02x), h", "12set 6, (ix+0x%02x), l", "12set 6, (ix+0x%02x)"  , "12set 6, (ix+0x%02x), a",

        "12set 7, (ix+0x%02x), b", "12set 7, (ix+0x%02x), c", "12set 7, (ix+0x%02x), d", "12set 7, (ix+0x%02x), e",
	"12set 7, (ix+0x%02x), h", "12set 7, (ix+0x%02x), l", "12set 7, (ix+0x%02x)"  , "12set 7, (ix+0x%02x), a",
};

const char *TableOpFDCBDebug[256] = {

	"12rlc, (iy+0x%02x), b", "12rlc, (iy+0x%02x), c", "12rlc, (iy+0x%02x), d", "12rlc, (iy+0x%02x), e",
	"12rlc, (iy+0x%02x), h", "12rlc, (iy+0x%02x), l", "12rlc, (iy+0x%02x)"  , "12rlc, (iy+0x%02x), a",

	"12rrc, (iy+0x%02x), b", "12rrc, (iy+0x%02x), c", "12rrc, (iy+0x%02x), d", "12rrc, (iy+0x%02x), e",
	"12rrc, (iy+0x%02x), h", "12rrc, (iy+0x%02x), l", "12rrc, (iy+0x%02x)"  , "12rrc, (iy+0x%02x), a",

	"12rl, (iy+0x%02x), b" , "12rl, (iy+0x%02x), c" , "12rl, (iy+0x%02x), d" , "12rl, (iy+0x%02x), e",
	"12rl, (iy+0x%02x), h" , "12rl, (iy+0x%02x), l" , "12rl, (iy+0x%02x)"   , "12rl, (iy+0x%02x), a",

	"12rr, (iy+0x%02x), b" , "12rr, (iy+0x%02x), c" , "12rr, (iy+0x%02x), d" , "12rr, (iy+0x%02x), e",
	"12rr, (iy+0x%02x), h" , "12rr, (iy+0x%02x), l" , "12rr, (iy+0x%02x)"   , "12rr, (iy+0x%02x), a" ,

	"12sla, (iy+0x%02x), b", "12sla, (iy+0x%02x), c", "12sla, (iy+0x%02x), d", "12sla, (iy+0x%02x), e",
	"12sla, (iy+0x%02x), h", "12sla, (iy+0x%02x), l", "12sla, (iy+0x%02x)"  , "12sla, (iy+0x%02x), a",

	"12sra, (iy+0x%02x), b", "12sra, (iy+0x%02x), c", "12sra, (iy+0x%02x), d", "12sra, (iy+0x%02x), e",
	"12sra, (iy+0x%02x), h", "12sra, (iy+0x%02x), l", "12sra, (iy+0x%02x)"  , "12sra, (iy+0x%02x), a",

	"12sll, (iy+0x%02x), b", "12sll, (iy+0x%02x), c", "12sll, (iy+0x%02x), d", "12sll, (iy+0x%02x), e",
 	"12sll, (iy+0x%02x), h", "12sll, (iy+0x%02x), l", "12sll, (iy+0x%02x)"  , "12sll, (iy+0x%02x), a",

	"12srl, (iy+0x%02x), b", "12srl, (iy+0x%02x), c", "12srl, (iy+0x%02x), d", "12srl, (iy+0x%02x), e",
	"12srl, (iy+0x%02x), h", "12srl, (iy+0x%02x), l", "12srl, (iy+0x%02x)"  , "12srl, (iy+0x%02x), a",

	"12bit 0, (iy+0x%02x)", "12bit 0, (iy+0x%02x)", "12bit 0, (iy+0x%02x)", "12bit 0, (iy+0x%02x)",
	"12bit 0, (iy+0x%02x)", "12bit 0, (iy+0x%02x)", "12bit 0, (iy+0x%02x)" , "12bit 0, (iy+0x%02x)",

	"12bit 1, (iy+0x%02x)", "12bit 1, (iy+0x%02x)", "12bit 1, (iy+0x%02x)", "12bit 1, (iy+0x%02x)",
	"12bit 1, (iy+0x%02x)", "12bit 1, (iy+0x%02x)", "12bit 1, (iy+0x%02x)" , "12bit 1, (iy+0x%02x)",

	"12bit 2, (iy+0x%02x)", "12bit 2, (iy+0x%02x)", "12bit 2, (iy+0x%02x)", "12bit 2, (iy+0x%02x)",
	"12bit 2, (iy+0x%02x)", "12bit 2, (iy+0x%02x)", "12bit 2, (iy+0x%02x)" , "12bit 2, (iy+0x%02x)",

	"12bit 3, (iy+0x%02x)", "12bit 3, (iy+0x%02x)", "12bit 3, (iy+0x%02x)", "12bit 3, (iy+0x%02x)",
	"12bit 3, (iy+0x%02x)", "12bit 3, (iy+0x%02x)", "12bit 3, (iy+0x%02x)" , "12bit 3, (iy+0x%02x)",

	"12bit 4, (iy+0x%02x)", "12bit 4, (iy+0x%02x)", "12bit 4, (iy+0x%02x)", "12bit 4, (iy+0x%02x)",
	"12bit 4, (iy+0x%02x)", "12bit 4, (iy+0x%02x)", "12bit 4, (iy+0x%02x)" , "12bit 4, (iy+0x%02x)",

	"12bit 5, (iy+0x%02x)", "12bit 5, (iy+0x%02x)", "12bit 5, (iy+0x%02x)", "12bit 5, (iy+0x%02x)",
	"12bit 5, (iy+0x%02x)", "12bit 5, (iy+0x%02x)", "12bit 5, (iy+0x%02x)" , "12bit 5, (iy+0x%02x)",

	"12bit 6, (iy+0x%02x)", "12bit 6, (iy+0x%02x)", "12bit 6, (iy+0x%02x)", "12bit 6, (iy+0x%02x)",
	"12bit 6, (iy+0x%02x)", "12bit 6, (iy+0x%02x)", "12bit 6, (iy+0x%02x)" , "12bit 6, (iy+0x%02x)",

	"12bit 7, (iy+0x%02x)", "12bit 7, (iy+0x%02x)", "12bit 7, (iy+0x%02x)", "12bit 7, (iy+0x%02x)",
	"12bit 7, (iy+0x%02x)", "12bit 7, (iy+0x%02x)", "12bit 7, (iy+0x%02x)" , "12bit 7, (iy+0x%02x)",


        "12res 0, (iy+0x%02x), b", "12res 0, (iy+0x%02x), c", "12res 0, (iy+0x%02x), d", "12res 0, (iy+0x%02x), e",
	"12res 0, (iy+0x%02x), h", "12res 0, (iy+0x%02x), l", "12res 0, (iy+0x%02x)"  , "12res 0, (iy+0x%02x), a",

        "12res 1, (iy+0x%02x), b", "12res 1, (iy+0x%02x), c", "12res 1, (iy+0x%02x), d", "12res 1, (iy+0x%02x), e",
	"12res 1, (iy+0x%02x), h", "12res 1, (iy+0x%02x), l", "12res 1, (iy+0x%02x)"  , "12res 1, (iy+0x%02x), a",

        "12res 2, (iy+0x%02x), b", "12res 2, (iy+0x%02x), c", "12res 2, (iy+0x%02x), d", "12res 2, (iy+0x%02x), e",
	"12res 2, (iy+0x%02x), h", "12res 2, (iy+0x%02x), l", "12res 2, (iy+0x%02x)"  , "12res 2, (iy+0x%02x), a",

        "12res 3, (iy+0x%02x), b", "12res 3, (iy+0x%02x), c", "12res 3, (iy+0x%02x), d", "12res 3, (iy+0x%02x), e",
 	"12res 3, (iy+0x%02x), h", "12res 3, (iy+0x%02x), l", "12res 3, (iy+0x%02x)"  , "12res 3, (iy+0x%02x), a",

        "12res 4, (iy+0x%02x), b", "12res 4, (iy+0x%02x), c", "12res 4, (iy+0x%02x), d", "12res 4, (iy+0x%02x), e",
	"12res 4, (iy+0x%02x), h", "12res 4, (iy+0x%02x), l", "12res 4, (iy+0x%02x)"  , "12res 4, (iy+0x%02x), a",

        "12res 5, (iy+0x%02x), b", "12res 5, (iy+0x%02x), c", "12res 5, (iy+0x%02x), d", "12res 5, (iy+0x%02x), e",
	"12res 5, (iy+0x%02x), h", "12res 5, (iy+0x%02x), l", "12res 5, (iy+0x%02x)"  , "12res 5, (iy+0x%02x), a",

        "12res 6, (iy+0x%02x), b", "12res 6, (iy+0x%02x), c", "12res 6, (iy+0x%02x), d", "12res 6, (iy+0x%02x), e",
	"12res 6, (iy+0x%02x), h", "12res 6, (iy+0x%02x), l", "12res 6, (iy+0x%02x)"  , "12res 6, (iy+0x%02x), a",

        "12res 7, (iy+0x%02x), b", "12res 7, (iy+0x%02x), c", "12res 7, (iy+0x%02x), d", "12res 7, (iy+0x%02x), e",
	"12res 7, (iy+0x%02x), h", "12res 7, (iy+0x%02x), l", "12res 7, (iy+0x%02x)"  , "12res 7, (iy+0x%02x), a",


	"12set 0, (iy+0x%02x), b", "12set 0, (iy+0x%02x), c", "12set 0, (iy+0x%02x), d", "12set 0, (iy+0x%02x), e",
	"12set 0, (iy+0x%02x), h", "12set 0, (iy+0x%02x), l", "12set 0, (iy+0x%02x)"  , "12set 0, (iy+0x%02x), a",

        "12set 1, (iy+0x%02x), b", "12set 1, (iy+0x%02x), c", "12set 1, (iy+0x%02x), d", "12set 1, (iy+0x%02x), e",
	"12set 1, (iy+0x%02x), h", "12set 1, (iy+0x%02x), l", "12set 1, (iy+0x%02x)"  , "12set 1, (iy+0x%02x), a",

        "12set 2, (iy+0x%02x), b", "12set 2, (iy+0x%02x), c", "12set 2, (iy+0x%02x), d", "12set 2, (iy+0x%02x), e",
	"12set 2, (iy+0x%02x), h", "12set 2, (iy+0x%02x), l", "12set 2, (iy+0x%02x)"  , "12set 2, (iy+0x%02x), a",

        "12set 3, (iy+0x%02x), b", "12set 3, (iy+0x%02x), c", "12set 3, (iy+0x%02x), d", "12set 3, (iy+0x%02x), e",
	"12set 3, (iy+0x%02x), h", "12set 3, (iy+0x%02x), l", "12set 3, (iy+0x%02x)"  , "12set 3, (iy+0x%02x), a",

        "12set 4, (iy+0x%02x), b", "12set 4, (iy+0x%02x), c", "12set 4, (iy+0x%02x), d", "12set 4, (iy+0x%02x), e",
	"12set 4, (iy+0x%02x), h", "12set 4, (iy+0x%02x), l", "12set 4, (iy+0x%02x)"  , "12set 4, (iy+0x%02x), a",

        "12set 5, (iy+0x%02x), b", "12set 5, (iy+0x%02x), c", "12set 5, (iy+0x%02x), d", "12set 5, (iy+0x%02x), e",
	"12set 5, (iy+0x%02x), h", "12set 5, (iy+0x%02x), l", "12set 5, (iy+0x%02x)"  , "12set 5, (iy+0x%02x), a",

        "12set 6, (iy+0x%02x), b", "12set 6, (iy+0x%02x), c", "12set 6, (iy+0x%02x), d", "12set 6, (iy+0x%02x), e",
	"12set 6, (iy+0x%02x), h", "12set 6, (iy+0x%02x), l", "12set 6, (iy+0x%02x)"  , "12set 6, (iy+0x%02x), a",

        "12set 7, (iy+0x%02x), b", "12set 7, (iy+0x%02x), c", "12set 7, (iy+0x%02x), d", "12set 7, (iy+0x%02x), e",
	"12set 7, (iy+0x%02x), h", "12set 7, (iy+0x%02x), l", "12set 7, (iy+0x%02x)"  , "12set 7, (iy+0x%02x), a",
};

#endif //  _Z80DEBUG_H_INCLUDED_
