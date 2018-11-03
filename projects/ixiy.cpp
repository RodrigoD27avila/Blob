	nullptr, nullptr      , nullptr          , nullptr  , nullptr   , nullptr   , nullptr         , nullptr,
	nullptr, "0add iy, bc", nullptr          , nullptr  , nullptr   , nullptr   , nullptr         , nullptr,
	nullptr, nullptr      , nullptr          , nullptr  , nullptr   , nullptr   , nullptr         , nullptr,
	nullptr, "0add iy, de", nullptr          , nullptr  , nullptr   , nullptr   , nullptr         , nullptr,

	nullptr, "ld iy, #0%4x", "14ld p#0%4x, iy", "0inc iy" , "0inc iyh" , "0dec iyh" , "12ld iyh, #0x%2x", nullptr,
	nullptr, "0add iy, iy" , "14ld iy, p#0%4x", "0dec iy" , "0inc iyl" , "0dec iyl" , "12ld iyl, #0x%2x", nullptr,

	nullptr, nullptr, nullptr, nullptr, "12inc (iy+0x%2x)", "12dec (iy+0x%2x)", "22ld (iy+0x%2x), #0x%2x", nullptr,

	nullptr, "0add iy, sp", nullptr, nullptr, nullptr     , nullptr     , nullptr             , nullptr,
	nullptr, nullptr      , nullptr, nullptr, "0ld b, iyh", "0ld b, iyl", "12ld b, (iy+0x%2x)", nullptr,
	nullptr, nullptr      , nullptr, nullptr, "0ld c, iyh", "0ld c, iyl", "12ld c, (iy+0x%2x)", nullptr,
	nullptr, nullptr      , nullptr, nullptr, "0ld d, iyh", "0ld d, iyl", "12ld d, (iy+0x%2x)", nullptr,
	nullptr, nullptr      , nullptr, nullptr, "0ld e, iyh", "0ld e, iyl", "12ld e, (iy+0x%2x)", nullptr,

	"0ld iyh, b", "0ld iyh, c", "0ld iyh, d", "0ld iyh, e", "0ld iyh, iyh", "0ld iyh, iyl", "12ld h, (iy+0x%2x)" , "0ld iyh, a",
	"0ld iyl, b", "0ld iyl, c", "0ld iyl, d", "0ld iyl, e", "0ld iyl, iyh", "0ld iyl, iyl", "12ld l, (iy+0x%2x)" , "0ld iyl, a",

	"12ld (iy+0x%2x), b", "12ld (iy+0x%2x), c", "12ld (iy+0x%2x), d", "12ld (iy+0x%2x), e",
        "12ld (iy+0x%2x), h", "12ld (iy+0x%2x), l", "12ld (iy+0x%2x), a", nullptr,

	nullptr, nullptr  , nullptr  , nullptr, "0ld a, iyh"  , "0ld a, iyl"  , "12ld a, (iy+0x%2x)" , nullptr ,
	nullptr, nullptr  , nullptr  , nullptr, "0add a, iyh" , "0add a, iyl" , "12add a, (iy+0x%2x)", nullptr ,
	nullptr, nullptr  , nullptr  , nullptr, "0adc a, iyh" , "0adc a, iyl" , "12adc a, (iy+0x%2x)", nullptr ,
	nullptr, nullptr  , nullptr  , nullptr, "0sub a, iyh" , "0sub a, iyl" , "12sub a, (iy+0x%2x)", nullptr ,
	nullptr, nullptr  , nullptr  , nullptr, "0sbc a, iyh" , "0sbc a, iyl" , "12sbc a, (iy+0x%2x)", nullptr ,
	nullptr, nullptr  , nullptr  , nullptr, "0and iyh"    , "0and iyl"    , "12and (iy+0x%2x)"   , nullptr ,
	nullptr, nullptr  , nullptr  , nullptr, "0xor iyh"    , "0xor iyl"    , "12xor (iy+0x%2x)"   , nullptr ,
	nullptr, nullptr  , nullptr  , nullptr, "0or iyh"     , "0or iyl"     , "12or (iy+0x%2x)"    , nullptr ,
	nullptr, nullptr  , nullptr  , nullptr, "0cp iyh"     , "0cp iyl"     , "12cp (iy+0x%2x)"    , nullptr ,

	nullptr, nullptr  , nullptr  , nullptr, nullptr , nullptr , nullptr , nullptr,
	nullptr, nullptr  , nullptr  , nullptr, nullptr , nullptr , nullptr , nullptr,
	nullptr, nullptr  , nullptr  , nullptr, nullptr , nullptr , nullptr , nullptr,
	nullptr, nullptr  , nullptr  , nullptr, nullptr , nullptr , nullptr , nullptr,

	nullptr, "0pop iy"     , nullptr  , "0ex (sp), iy", nullptr , "0push iy" , nullptr , nullptr,
	nullptr, "0jp piy"     , nullptr  , nullptr       , nullptr , nullptr    , nullptr , nullptr,
	nullptr, nullptr       , nullptr  , nullptr       , nullptr , nullptr    , nullptr , nullptr,
	nullptr, "0ld sp, iy"  , nullptr  , nullptr       , nullptr , nullptr    , nullptr , nullptr,
