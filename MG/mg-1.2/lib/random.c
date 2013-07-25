/**************************************************************************
 *
 * random.c -- pseudo random number generator
 * Copyright (C) 1994  Chris Wallace (csw@bruce.cs.monash.edu.au)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 * $Id$
 *
 **************************************************************************/

/*
$Log$
*/

static char *RCSID = "$Id$";

/*
 *	A random number generator called as a function by
 *	random (iseed)	or	irandm (iseed)
 *	The parameter should be a pointer to a 2-element long vector.
 *	The first function returns a double uniform in 0 .. 1.
 *	The second returns a long integer uniform in 0 .. 2**31-1
 *	Both update iseed[] in exactly the same way.
 *	iseed[] must be a 2-element integer vector.
 *	The initial value of the second element may be anything.
 *
 *	The period of the random sequence is 2**32 * (2**32-1)
 *	The table mt[0:127] is defined by mt[i] = 69069 ** (128-i)
 */

#define MASK ((long) 593970775)
/*	or in hex, 23674657	*/

#define SCALE ((double) 1.0 / (1024.0 * 1024.0 * 1024.0 * 2.0))
/*	i.e. 2 to power -31	*/

static long mt [128] =   {
      902906369,
     2030498053,
     -473499623,
     1640834941,
      723406961,
     1993558325,
     -257162999,
    -1627724755,
      913952737,
      278845029,
     1327502073,
    -1261253155,
      981676113,
    -1785280363,
     1700077033,
      366908557,
    -1514479167,
     -682799163,
      141955545,
     -830150595,
      317871153,
     1542036469,
     -946413879,
    -1950779155,
      985397153,
      626515237,
      530871481,
      783087261,
    -1512358895,
     1031357269,
    -2007710807,
    -1652747955,
    -1867214463,
      928251525,
     1243003801,
    -2132510467,
     1874683889,
     -717013323,
      218254473,
    -1628774995,
    -2064896159,
       69678053,
      281568889,
    -2104168611,
     -165128239,
     1536495125,
      -39650967,
      546594317,
     -725987007,
     1392966981,
     1044706649,
      687331773,
    -2051306575,
     1544302965,
     -758494647,
    -1243934099,
      -75073759,
      293132965,
    -1935153095,
      118929437,
      807830417,
    -1416222507,
    -1550074071,
      -84903219,
     1355292929,
     -380482555,
    -1818444007,
     -204797315,
      170442609,
    -1636797387,
      868931593,
     -623503571,
     1711722209,
      381210981,
     -161547783,
     -272740131,
    -1450066095,
     2116588437,
     1100682473,
      358442893,
    -1529216831,
     2116152005,
     -776333095,
     1265240893,
     -482278607,
     1067190005,
      333444553,
       86502381,
      753481377,
       39000101,
     1779014585,
      219658653,
     -920253679,
     2029538901,
     1207761577,
    -1515772851,
     -236195711,
      442620293,
      423166617,
    -1763648515,
     -398436623,
    -1749358155,
     -538598519,
     -652439379,
      430550625,
    -1481396507,
     2093206905,
    -1934691747,
     -962631983,
     1454463253,
    -1877118871,
     -291917555,
    -1711673279,
      201201733,
     -474645415,
      -96764739,
    -1587365199,
     1945705589,
     1303896393,
     1744831853,
      381957665,
     2135332261,
      -55996615,
    -1190135011,
     1790562961,
    -1493191723,
      475559465,
          69069
		};

double 
random (long is [2])
{
	long it, leh, nit;

	it = is [0];
	leh = is [1];
	if (it <= 0)	
		it = (it + it) ^ MASK;
	else
		it = it + it;
	nit = it - 1;
/*	to ensure all-ones pattern omitted    */
	leh = leh * mt[nit & 127] + nit;
	is [0] = it;    is [1] = leh;
	if (leh < 0) leh = ~leh;
	return (SCALE * ((long) (leh | 1)));
}



long 
irandm (long is [2])
{
	long it, leh, nit;

	it = is [0];
	leh = is [1];
	if (it <= 0)	
		it = (it + it) ^ MASK;
	else
		it = it + it;
	nit = it - 1;
/*	to ensure all-ones pattern omitted    */
	leh = leh * mt[nit & 127] + nit;
	is [0] = it;    is [1] = leh;
	if (leh < 0) leh = ~leh;
	return (leh);
}
