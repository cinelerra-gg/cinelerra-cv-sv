#ifndef IEEE_FLOAT_H__
#define IEEE_FLOAT_H__
/* Copyright (C) 1988-1991 Apple Computer, Inc.
 * All Rights Reserved.
 *
 * Warranty Information
 * Even though Apple has reviewed this software, Apple makes no warranty
 * or representation, either express or implied, with respect to this
 * software, its quality, accuracy, merchantability, or fitness for a 
 * particular purpose.  As a result, this software is provided "as is,"
 * and you, its user, are assuming the entire risk as to its quality
 * and accuracy.
 *
 * This code may be used and freely distributed as long as it includes
 * this copyright notice and the warranty information.
 *
 * Machine-independent I/O routines for IEEE floating-point numbers.
 *
 * NaN's and infinities are converted to HUGE_VAL or HUGE, which
 * happens to be infinity on IEEE machines.  Unfortunately, it is
 * impossible to preserve NaN's in a machine-independent way.
 * Infinities are, however, preserved on IEEE machines.
 *
 * These routines have been tested on the following machines:
 *	Apple Macintosh, MPW 3.1 C compiler
 *	Apple Macintosh, THINK C compiler
 *	Silicon Graphics IRIS, MIPS compiler
 *	Cray X/MP and Y/MP
 *	Digital Equipment VAX
 *	Sequent Balance (Multiprocesor 386)
 *	NeXT
 *
 *
 * Implemented by Malcolm Slaney and Ken Turkowski.
 *
 * Malcolm Slaney contributions during 1988-1990 include big- and little-
 * endian file I/O, conversion to and from Motorola's extended 80-bit
 * floating-point format, and conversions to and from IEEE single-
 * precision floating-point format.
 *
 * In 1991, Ken Turkowski implemented the conversions to and from
 * IEEE double-precision format, added more precision to the extended
 * conversions, and accommodated conversions involving +/- infinity,
 * NaN's, and denormalized numbers.
 *
 * $Id: ieeefloat.h,v 1.1 2003/06/16 20:00:50 herman Exp $
 *
 * $Log: ieeefloat.h,v $
 * Revision 1.1  2003/06/16 20:00:50  herman
 * Initial revision
 *
 * Revision 1.1.1.1  2002/06/21 12:35:26  myrina
 *
 *
 * Revision 1.1.1.1  2001/10/01 03:14:55  heroine
 *
 *
 * Revision 1.1.1.1  2001/10/01 02:51:42  root
 *
 *
 * Revision 1.2  2001/07/04 09:51:36  uid43892
 * everything passed through 'indent *.c *.h'
 *
 * Revision 1.1.1.1  2001/07/01 06:54:10  mikecheng
 * This is v0.30 of toolame. A fresh start consisting of the dist10 code with
 * all layerI and layerIII removed.
 *
 * Revision 1.1  1993/06/11  17:45:46  malcolm
 * Initial revision
 *
 */

#include	<math.h>

typedef float Single;

#ifndef applec
typedef double defdouble;
#else /* !applec */
typedef long double defdouble;
#endif /* applec */

#ifndef THINK_C
typedef double Double;
#else /* THINK_C */
typedef short double Double;
#endif /* THINK_C */

#define	kFloatLength	4
#define	kDoubleLength	8
#define	kExtendedLength	10

extern defdouble ConvertFromIeeeSingle (char *bytes);
extern void ConvertToIeeeSingle (defdouble num, char *bytes);
extern defdouble ConvertFromIeeeDouble (char *bytes);
extern void ConvertToIeeeDouble (defdouble num, char *bytes);
extern defdouble ConvertFromIeeeExtended (char *bytes);
extern void ConvertToIeeeExtended (defdouble num, char *bytes);
#endif
