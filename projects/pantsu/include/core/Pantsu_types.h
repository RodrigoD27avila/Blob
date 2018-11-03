#ifndef PANTSU_TYPES_INCLUDED
#define PANTSU_TYPES_INCLUDED

typedef __pmagic PMagic;

typedef __pint8  PInt8 ;
typedef __pint16 PInt16;
typedef __pint32 PInt32;
typedef __pint64 PInt64;

typedef __puint8  PUInt8 ;
typedef __puint16 PUInt16;
typedef __puint32 PUInt32;
typedef __puint64 PUInt64;

typedef PInt8  PChar;
typedef PInt16 PShort;
typedef PInt32 PInt;
typedef PInt64 PLong;

typedef PUInt8  PUChar;
typedef PUInt16 PUShort;
typedef PUInt32 PUInt;
typedef PUInt64 PULong;

typedef PUInt8 PByte;

enum PBool {FALSE=0, TRUE=1};

typedef __pfloat  PFloat;
typedef __pdouble PDouble;

typedef PError PInt8;

#endif /*PANTSU_TYPES_INCLUDED*/
